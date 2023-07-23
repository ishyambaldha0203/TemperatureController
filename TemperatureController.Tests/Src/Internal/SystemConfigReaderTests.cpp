/*************************************************************************************************
 * @file SystemConfigReaderTests.cpp
 *
 * @brief Contains unit tests for class @ref SystemConfigReader.
 *
 *************************************************************************************************/

#include "CommonTestsConfig.hpp"

#include <fstream>

#include "Interfaces/Factories/IObjectFactories.hpp"
#include "Internal/SystemConfigReader.hpp"

#include "Exceptions/XConfigError.hpp"
#include "Exceptions/XFileNotFound.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::FactoryInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Internal;

// #endregion

namespace
{
    namespace Default
    {
        constexpr const char *ConfigFilename = "TemperatureController.conf";
    }

    /**
     * @class SystemConfigReaderTestsFactory
     *
     * @brief Class responsible to instantiate all the required classes.
     */
    class SystemConfigReaderTestsFactory
        : public ISystemConfigReaderFactory
    {

    public:
        /**
         * @brief Create concrete instance of ISystemConfigReader.
         *
         * @param[out] result An instance of class under test, @ref SystemConfigReader.
         */
        void Create(ISystemConfigReaderFactory::InterfaceSharedPointer &objectPtr) override
        {
            objectPtr = std::make_shared<SystemConfigReader>();
        }
    };

    /**
     * @class SystemConfigReaderTestFixture
     *
     * @brief Test fixture for SystemConfigReader.
     *
     * This class provide access to the Factory and additional default
     */
    class SystemConfigReaderTestFixture : public ::testing::Test
    {
    public:
        /**
         * @brief Setup the factory. Method overriden from GTest framework class @ref ::testing::Test
         */
        void SetUp() override
        {
            _instanceFactory = std::make_shared<SystemConfigReaderTestsFactory>();
        }

        std::shared_ptr<SystemConfigReaderTestsFactory> GetFactory()
        {
            return _instanceFactory;
        }

        void TearDown() override
        {
            remove(Default::ConfigFilename);
        }

    private:
        std::shared_ptr<SystemConfigReaderTestsFactory> _instanceFactory;
    };

    /**
     * @brief Create a sample config file for testing.
     *
     * @param filename
     */
    void CreateSampleConfigFile(const std::string &filename)
    {
        std::ofstream configFile(filename);

        configFile << "MinimumTemperature=20\n";
        configFile << "MaximumTemperature=21\n";

        configFile.close();
    }

    // #region Unit Tests

    TEST_F(SystemConfigReaderTestFixture, SuccessfulInstanceCreation)
    {
        std::shared_ptr<ISystemConfigReaderFactory> systemConfigReaderFactory = GetFactory();

        std::shared_ptr<ISystemConfigReader> systemConfigReader;
        ASSERT_NO_THROW(systemConfigReaderFactory->Create(systemConfigReader));
    }

    TEST_F(SystemConfigReaderTestFixture, ReadConfigSuccessful)
    {
        // Arrange
        SystemConfigReader::ConfigurationMap expectedOutput =
            {
                {"MinimumTemperature", "20"},
                {"MaximumTemperature", "21"}};

        CreateSampleConfigFile(Default::ConfigFilename);

        std::shared_ptr<ISystemConfigReaderFactory> systemConfigReaderFactory = GetFactory();

        std::shared_ptr<ISystemConfigReader> systemConfigReader;
        systemConfigReaderFactory->Create(systemConfigReader);

        // Act
        SystemConfigReader::ConfigurationMap actualOutput = systemConfigReader->ReadConfig(Default::ConfigFilename);

        // Assert
        EXPECT_EQ(expectedOutput, actualOutput);
    }

    TEST_F(SystemConfigReaderTestFixture, ReadConfigThrowsXFileNotFound)
    {
        // Arrange
        std::shared_ptr<ISystemConfigReaderFactory> systemConfigReaderFactory = GetFactory();

        std::shared_ptr<ISystemConfigReader> systemConfigReader;
        systemConfigReaderFactory->Create(systemConfigReader);

        // Act -> Assert
        ASSERT_THROW(systemConfigReader->ReadConfig("non_existent_config.txt"), XFileNotFound);
    }

    /**
     * @brief For testing multiple dataset with invalid lines in config file using parameterized test case.
     */
    struct InvalidConfigLineTestData
    {
        std::string invalidLine;
        std::string testCaseName;
    };

    class SystemConfigReaderInvalidLineTestWithParam
        : public SystemConfigReaderTestFixture,
          public ::testing::WithParamInterface<InvalidConfigLineTestData>
    {
    };

    TEST_P(SystemConfigReaderInvalidLineTestWithParam, ReadConfigThrowsXConfigError)
    {
        // Arrange
        InvalidConfigLineTestData data = GetParam();

        const std::string invalidFilename = Default::ConfigFilename;

        std::ofstream configFile(invalidFilename);
        configFile << data.invalidLine << "\n";
        configFile.close();

        std::shared_ptr<ISystemConfigReaderFactory> systemConfigReaderFactory = GetFactory();

        std::shared_ptr<ISystemConfigReader> systemConfigReader;
        systemConfigReaderFactory->Create(systemConfigReader);

        // Act -> Assert
        ASSERT_THROW(systemConfigReader->ReadConfig(Default::ConfigFilename), XConfigError);
    }

    std::vector<InvalidConfigLineTestData> InvalidLineList =
        {
            {"MissingEqualsSign", "MissingEqualsSign"},
            {"MinimumTemperature:20", "ColonInsteadEqual"},
            {"MinimumTemperature 20", "SpaceInsteadEqual"},
            {"MinimumTemperature-20", "DashInsteadEqual"}};

    INSTANTIATE_TEST_SUITE_P(
        SystemConfigReaderTestFixtureWithParam,
        SystemConfigReaderInvalidLineTestWithParam,
        ::testing::ValuesIn(InvalidLineList),
        [](const ::testing::TestParamInfo<InvalidConfigLineTestData> &info)
        {
            return info.param.testCaseName;
        });

    /**
     * @brief For testing multiple dataset with duplicate data keys in config file using parameterized test case.
     */
    struct DuplicateKeyTestData
    {
        std::string key;
        std::string value1;
        std::string value2;
        std::string testCaseName;
    };

    class SystemConfigReaderDuplicateKeyTestWithParam
        : public SystemConfigReaderTestFixture,
          public ::testing::WithParamInterface<DuplicateKeyTestData>
    {
    };

    TEST_P(SystemConfigReaderDuplicateKeyTestWithParam, ReadConfigThrowsXConfigError)
    {
        // Arrange
        DuplicateKeyTestData data = GetParam();

        std::ofstream configFile(Default::ConfigFilename);
        configFile << data.key << "=" << data.value1 << "\n";
        configFile << data.key << "=" << data.value2 << "\n";
        configFile.close();

        std::shared_ptr<ISystemConfigReaderFactory> systemConfigReaderFactory = GetFactory();

        std::shared_ptr<ISystemConfigReader> systemConfigReader;
        systemConfigReaderFactory->Create(systemConfigReader);

        // Act -> Assert
        ASSERT_THROW(systemConfigReader->ReadConfig(Default::ConfigFilename), XConfigError);
    }

    std::vector<DuplicateKeyTestData> DuplicateKeyDataset =
        {
            {"MinimumTemperature", "20", "21", "DuplicateMinimumTemperature"},
            {"MaximumTemperature", "30", "31", "DuplicateMaximumTemperature"}};

    INSTANTIATE_TEST_SUITE_P(
        SystemConfigReaderTestFixtureWithParam2,
        SystemConfigReaderDuplicateKeyTestWithParam,
        ::testing::ValuesIn(DuplicateKeyDataset),
        [](const ::testing::TestParamInfo<DuplicateKeyTestData> &info)
        {
            return info.param.testCaseName;
        });

    // #endregion
} // Anonymous namespace