/*************************************************************************************************
 * @file SystemConfigReader.cpp
 *
 * @brief Concrete implementation of @ref SystemConfigReader class.
 *
 * @warning It is not handling all the edge cases to read the config file.
 *
 * The data in config file must be provided added as key value pair separated by '='.
 *
 * For Example:
 *  MinimumTemperature=20
 *  MaximumTemperature=25
 *
 *************************************************************************************************/

#include "Internal/SystemConfigReader.hpp"

#include <fstream>

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    /**
     * @brief Construct a new config reader object.
     */
    SystemConfigReader::SystemConfigReader() = default;

    /**
     * @brief Destroy the a new config reader object.
     */
    SystemConfigReader::~SystemConfigReader() = default;

    // #endregion

    // #region Public Methods

    SystemConfigReader::ConfigurationMap SystemConfigReader::ReadConfig(const std::string &confFileName)
    {
        ConfigurationMap configMap;

        // Check if the config file exists.
        std::ifstream configFile(confFileName);
        if (!configFile)
        {
            std::cerr << "[Error] Config file not found: " << confFileName << std::endl;

            return configMap;
        }

        std::string line;
        while (std::getline(configFile, line))
        {
            size_t pos = line.find('=');

            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            configMap[key] = value;
        }

        // Close the config file.
        configFile.close();

        return configMap;
    }
    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS