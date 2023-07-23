/*************************************************************************************************
 * @file SystemConfigProcessorTests.cpp
 *
 * @brief Contains unit tests for class @ref SystemConfigProcessor.
 *
 *************************************************************************************************/

#include "CommonTestsConfig.hpp"

#include <fstream>

#include "Interfaces/Factories/IObjectFactories.hpp"
#include "Internal/SystemConfigProcessor.hpp"
#include "Internal/Entities/SystemConfig.hpp"

#include "Exceptions/XArgumentNull.hpp"

#include "Internal/Mocks/SystemConfigReaderMock.hpp"
#include "Internal/Entities/Mocks/SystemConfigMock.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::Entities;
using namespace TEMPERATURE_CONTROLLER_NS::EntityInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::FactoryInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Internal;
using namespace TEMPERATURE_CONTROLLER_NS::Test;

// #endregion

// #region GTest Usings

using ::testing::NiceMock;
using ::testing::Return;

// #endregion

namespace
{
    namespace Default
    {
        constexpr const char *ConfigFilename = "TemperatureController.conf";
    }

    /**
     * @class SystemConfigProcessorTestsFactory
     *
     * @brief Class responsible to instantiate all the required classes.
     */
    class SystemConfigProcessorTestsFactory
        : public ISystemConfigProcessorFactory,
          public ISystemConfigReaderFactory,
          public ISystemConfigFactory,
          public std::enable_shared_from_this<SystemConfigProcessorTestsFactory>
    {

    public:
        /**
         * @brief Create concrete instance of ISystemConfigProcessor.
         *
         * @param[out] result An instance of class under test, @ref SystemConfigProcessor.
         */
        void Create(ISystemConfigProcessorFactory::InterfaceSharedPointer &objectPtr) override
        {
            ISystemConfigReaderFactory::InterfaceSharedPointer systemConfigReader;
            Create(systemConfigReader);

            objectPtr = std::make_shared<SystemConfigProcessor>(systemConfigReader, Self());
        }

        void Create(ISystemConfigReaderFactory::InterfaceSharedPointer &objectPtr) override
        {
            objectPtr = (nullptr == _configReader) ? std::make_shared<NiceMock<SystemConfigReaderMock>>() : _configReader;
        }

        void Create(ISystemConfigFactory::InterfaceSharedPointer &objectPtr) override
        {

            objectPtr = (nullptr == _systemConfig) ? std::make_shared<SystemConfig>() : _systemConfig;
        }

        void Set(std::shared_ptr<ISystemConfigReader> configReader)
        {
            _configReader = configReader;
        }

        void Set(std::shared_ptr<ISystemConfig> systemConfig)
        {
            _systemConfig = systemConfig;
        }

    private:
        std::shared_ptr<ISystemConfigReader> _configReader;
        std::shared_ptr<ISystemConfig> _systemConfig;

        /**
         * @brief To create shared pointer of this pointer.
         *
         * @return A shared pointer of class it self.
         */
        std::shared_ptr<SystemConfigProcessorTestsFactory> Self()
        {
            return std::enable_shared_from_this<SystemConfigProcessorTestsFactory>::shared_from_this();
        }
    };

    /**
     * @class SystemConfigProcessorTestFixture
     *
     * @brief Test fixture for SystemConfigProcessor.
     *
     * This class provide access to the Factory and additional default
     */
    class SystemConfigProcessorTestFixture : public ::testing::Test
    {
    public:
        /**
         * @brief Setup the factory. Method overriden from GTest framework class @ref ::testing::Test
         */
        void SetUp() override
        {
            _instanceFactory = std::make_shared<SystemConfigProcessorTestsFactory>();
        }

        std::shared_ptr<SystemConfigProcessorTestsFactory> GetFactory()
        {
            return _instanceFactory;
        }

        void Set(std::shared_ptr<SystemConfigReaderMock> configReaderMock)
        {
            _instanceFactory->Set(configReaderMock);
        }

    private:
        std::shared_ptr<SystemConfigProcessorTestsFactory> _instanceFactory;
    };

    // #region Unit Tests

    TEST_F(SystemConfigProcessorTestFixture, SuccessfulInstanceCreation)
    {
        std::shared_ptr<ISystemConfigProcessorFactory> configProcessorFactory = GetFactory();

        std::shared_ptr<ISystemConfigProcessor> systemConfigProcessor;
        ASSERT_NO_THROW(configProcessorFactory->Create(systemConfigProcessor));
    }

    TEST_F(SystemConfigProcessorTestFixture, ConstructorInvalidArgumentFailure)
    {
        // Arrange
        std::shared_ptr<SystemConfigProcessorTestsFactory> instanceFactory = GetFactory();

        std::shared_ptr<ISystemConfigReader> configReader;
        instanceFactory->Create(configReader);

        // Act -> Assert
        ASSERT_THROW(SystemConfigProcessor(nullptr, instanceFactory), XArgumentNull);
        ASSERT_THROW(SystemConfigProcessor(configReader, nullptr), XArgumentNull);
    }

    TEST_F(SystemConfigProcessorTestFixture, PrepareConfigSuccessful)
    {
        // Arrange
        std::shared_ptr<SystemConfigReaderMock> configReader = std::make_shared<SystemConfigReaderMock>();
        Set(configReader);

        ISystemConfigReader::ConfigurationMap inputConfigurations =
            {
                {"MinimumTemperature", "20"},
                {"MaximumTemperature", "21"}};

        EXPECT_CALL(*configReader, ReadConfig(Default::ConfigFilename))
            .Times(1)
            .WillOnce(Return(inputConfigurations));

        std::shared_ptr<ISystemConfigProcessorFactory> configProcessorFactory = GetFactory();

        std::shared_ptr<ISystemConfigProcessor> systemConfigProcessor;
        configProcessorFactory->Create(systemConfigProcessor);

        // Act
        std::shared_ptr<ISystemConfig> systemConfig = systemConfigProcessor->PrepareConfig();

        // Assert
        EXPECT_EQ(systemConfig->GetMinTemperatureRange(), std::stof(inputConfigurations.at("MinimumTemperature")));
        EXPECT_EQ(systemConfig->GetMaxTemperatureRange(), std::stof(inputConfigurations.at("MaximumTemperature")));
        EXPECT_EQ(systemConfig->GetHeatingIntensity(), 0.10f);
        EXPECT_EQ(systemConfig->GetCoolingIntensity(), 0.10f);
        EXPECT_EQ(systemConfig->GetSimulationIntensity(), 0.5f);
    }

    // #endregion
} // Anonymous namespace