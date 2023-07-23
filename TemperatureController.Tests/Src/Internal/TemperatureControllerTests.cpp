/*************************************************************************************************
 * @file TemperatureControllerTests.cpp
 *
 * @brief Contains unit tests for class @ref TemperatureController.
 *
 *************************************************************************************************/

#include "CommonTestsConfig.hpp"

#include "Interfaces/Factories/IApplianceFactory.hpp"
#include "Interfaces/Factories/IObjectFactories.hpp"
#include "Internal/TemperatureController.hpp"

#include "Exceptions/XArgumentNull.hpp"

#include "Internal/Mocks/CoolerMock.hpp"
#include "Internal/Mocks/HeaterMock.hpp"

#include "Internal/Entities/Mocks/SystemConfigMock.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::EntityInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::FactoryInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Internal;
using namespace TEMPERATURE_CONTROLLER_NS::Test;
using namespace TEMPERATURE_CONTROLLER_NS::Entities::Test;

// #endregion

// #region GTest Usings

using ::testing::_;
using ::testing::NiceMock;
using ::testing::Return;

// #endregion

namespace
{
    /**
     * @class TemperatureControllerTestsFactory
     *
     * @brief Class responsible to instantiate all the required classes.
     */
    class TemperatureControllerTestsFactory
        : public ITemperatureControllerFactory,
          public IApplianceFactory
    {

    public:
        /**
         * @brief Create concrete instance of ITemperatureController.
         *
         * @param[out] result An instance of class under test, @ref TemperatureController.
         */
        void Create(ITemperatureControllerFactory::InterfaceSharedPointer &objectPtr) override
        {
            IApplianceFactory::InterfaceSharedPointer cooler;
            CreateCooler(cooler);

            IApplianceFactory::InterfaceSharedPointer heater;
            CreateHeater(heater);

            objectPtr = std::make_shared<TemperatureController>(cooler, heater);
        }

        void CreateCooler(IApplianceFactory::InterfaceSharedPointer &objectPtr) override
        {
            objectPtr = (nullptr == _cooler) ? std::make_shared<NiceMock<CoolerMock>>() : _cooler;
        }

        void CreateHeater(IApplianceFactory::InterfaceSharedPointer &objectPtr) override
        {
            objectPtr = (nullptr == _heater) ? std::make_shared<NiceMock<HeaterMock>>() : _heater;
        }

        void SetCooler(std::shared_ptr<IAppliance> cooler)
        {
            _cooler = cooler;
        }

        void SetHeater(std::shared_ptr<IAppliance> heater)
        {
            _heater = heater;
        }

    private:
        std::shared_ptr<IAppliance> _cooler;
        std::shared_ptr<IAppliance> _heater;
    };

    /**
     * @class TemperatureControllerTestFixture
     *
     * @brief Test fixture for TemperatureController.
     *
     * This class provide access to the Factory and additional default
     */
    class TemperatureControllerTestFixture : public ::testing::Test
    {
    public:
        /**
         * @brief Setup the factory. Method overriden from GTest framework class @ref ::testing::Test
         */
        void SetUp() override
        {
            _instanceFactory = std::make_shared<TemperatureControllerTestsFactory>();
        }

        std::shared_ptr<TemperatureControllerTestsFactory> GetFactory()
        {
            return _instanceFactory;
        }

        void Set(std::shared_ptr<CoolerMock> cooler)
        {
            _instanceFactory->SetCooler(cooler);
        }

        void Set(std::shared_ptr<HeaterMock> heater)
        {
            _instanceFactory->SetHeater(heater);
        }

    private:
        std::shared_ptr<TemperatureControllerTestsFactory> _instanceFactory;
    };

    // #region Unit Tests

    TEST_F(TemperatureControllerTestFixture, SuccessfulInstanceCreation)
    {
        std::shared_ptr<ITemperatureControllerFactory> tempControllerFactory = GetFactory();

        std::shared_ptr<ITemperatureController> temperatureController;
        ASSERT_NO_THROW(tempControllerFactory->Create(temperatureController));
    }

    TEST_F(TemperatureControllerTestFixture, ConstructorInvalidArgumentFailure)
    {
        // Arrange
        std::shared_ptr<TemperatureControllerTestsFactory> instanceFactory = GetFactory();

        std::shared_ptr<IAppliance> cooler;
        instanceFactory->CreateCooler(cooler);

        std::shared_ptr<IAppliance> heater;
        instanceFactory->CreateHeater(heater);

        // Act -> Assert
        ASSERT_NO_THROW(TemperatureController(cooler, heater));
        ASSERT_THROW(TemperatureController(nullptr, heater), XArgumentNull);
        ASSERT_THROW(TemperatureController(cooler, nullptr), XArgumentNull);
    }

    TEST_F(TemperatureControllerTestFixture, InitializeSuccessful)
    {
        // Arrange
        std::shared_ptr<CoolerMock> coolerMock = std::make_shared<CoolerMock>();
        Set(coolerMock);

        std::shared_ptr<HeaterMock> heaterMock = std::make_shared<HeaterMock>();
        Set(heaterMock);

        std::shared_ptr<SystemConfigMock> systemConfigMock = std::make_shared<NiceMock<SystemConfigMock>>();

        EXPECT_CALL(*systemConfigMock, GetMinTemperatureRange())
            .Times(1)
            .WillOnce(Return(20));

        EXPECT_CALL(*systemConfigMock, GetMaxTemperatureRange())
            .Times(1)
            .WillOnce(Return(25));

        float coolingIntensity = 0.10f;
        float heatingIntensity = 0.10f;

        EXPECT_CALL(*systemConfigMock, GetCoolingIntensity())
            .Times(1)
            .WillOnce(Return(coolingIntensity));

        EXPECT_CALL(*systemConfigMock, GetHeatingIntensity())
            .Times(1)
            .WillOnce(Return(heatingIntensity));

        EXPECT_CALL(*coolerMock, Initialize(coolingIntensity))
            .Times(1);

        EXPECT_CALL(*heaterMock, Initialize(heatingIntensity))
            .Times(1);

        std::shared_ptr<ITemperatureControllerFactory> configProcessorFactory = GetFactory();

        std::shared_ptr<ITemperatureController> systemConfigProcessor;
        configProcessorFactory->Create(systemConfigProcessor);

        // Act -> Assert
        EXPECT_NO_THROW(systemConfigProcessor->Initialize(*systemConfigMock));
    }

    /**
     * @brief For testing multiple dataset with invalid lines in config file using parameterized test case.
     */
    struct RegulateTemperatureTestData
    {
        float minTemp;
        float maxTemp;
        float currentTemp;
        bool isHeaterOn;
        bool isCoolerOn;
        bool isTempInRange;
        std::string testCaseName;
    };

    class TemperatureControllerTestRegulateTemperature
        : public TemperatureControllerTestFixture,
          public ::testing::WithParamInterface<RegulateTemperatureTestData>
    {
    };

    TEST_P(TemperatureControllerTestRegulateTemperature, RegulateTemperatureOnSuccessful)
    {
        RegulateTemperatureTestData testData = GetParam();

        // Arrange
        std::shared_ptr<CoolerMock> coolerMock = std::make_shared<NiceMock<CoolerMock>>();
        Set(coolerMock);

        std::shared_ptr<HeaterMock> heaterMock = std::make_shared<NiceMock<HeaterMock>>();
        Set(heaterMock);

        std::shared_ptr<SystemConfigMock> systemConfigMock = std::make_shared<NiceMock<SystemConfigMock>>();

        EXPECT_CALL(*systemConfigMock, GetMinTemperatureRange())
            .Times(1)
            .WillOnce(Return(testData.minTemp));

        EXPECT_CALL(*systemConfigMock, GetMaxTemperatureRange())
            .Times(1)
            .WillOnce(Return(testData.maxTemp));

        if (testData.isHeaterOn)
        {
            EXPECT_CALL(*heaterMock, IsRunning())
                .Times(1)
                .WillOnce(Return(false));

            EXPECT_CALL(*heaterMock, Start())
                .Times(1);
        }
        else if (testData.isCoolerOn)
        {
            EXPECT_CALL(*coolerMock, IsRunning())
                .Times(1)
                .WillOnce(Return(false));

            EXPECT_CALL(*coolerMock, Start())
                .Times(1);
        }
        else
        {
            EXPECT_CALL(*coolerMock, IsRunning())
                .Times(1)
                .WillOnce(Return(true));

            EXPECT_CALL(*heaterMock, IsRunning())
                .Times(1)
                .WillOnce(Return(true));

            EXPECT_CALL(*coolerMock, Stop())
                .Times(1);

            EXPECT_CALL(*heaterMock, Stop())
                .Times(1);
        }

        std::shared_ptr<ITemperatureControllerFactory> configProcessorFactory = GetFactory();
        std::shared_ptr<ITemperatureController> systemConfigProcessor;
        configProcessorFactory->Create(systemConfigProcessor);

        // Act -> Assert
        EXPECT_NO_THROW(systemConfigProcessor->Initialize(*systemConfigMock.get()));

        EXPECT_NO_THROW(systemConfigProcessor->RegulateTemperature(testData.currentTemp));
    }

    std::vector<RegulateTemperatureTestData> RegulateTemperatureDataList =
        {
            {20, 25, 15, true, false, false, "HeaterOnSuccess"},
            {20, 25, 30, false, true, false, "CoolerOnSuccess"},
            {20, 25, 23, false, false, true, "TemperatureInRangeSuccess"}};

    INSTANTIATE_TEST_SUITE_P(
        TemperatureControllerTestFixtureWithParam,
        TemperatureControllerTestRegulateTemperature,
        ::testing::ValuesIn(RegulateTemperatureDataList),
        [](const ::testing::TestParamInfo<RegulateTemperatureTestData> &info)
        {
            return info.param.testCaseName;
        });

    // #endregion
} // Anonymous namespace