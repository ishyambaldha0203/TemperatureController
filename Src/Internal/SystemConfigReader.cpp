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

#include <algorithm>
#include <fstream>
#include <sstream>

#include "Exceptions/XBaseException.hpp"
#include "Exceptions/XConfigError.hpp"
#include "Exceptions/XFileNotFound.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

namespace
{
    /**
     * @brief Trim the whitespaces around the provided intput string.
     * 
     * @param input An input string to be trimmed. 
     * @return A Trimmed string.
     */
    std::string Trim(const std::string &input)
    {
        std::string result = input;
        result.erase(result.begin(), std::find_if(result.begin(),
                                                  result.end(),
                                                  [](unsigned char ch)
                                                  {
                                                    return !std::isspace(ch);
                                                  }));

        result.erase(std::find_if(result.rbegin(),
                                  result.rend(),
                                  [](unsigned char ch)
                                  {
                                    return !std::isspace(ch);
                                  }).base(), result.end());
        return result;
    }
}

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
            throw XFileNotFound("Config file not found: " + confFileName);
        }

        std::string line;
        int lineNum = 0;
        while (std::getline(configFile, line))
        {
            lineNum++;

            // Ignore empty or white space only lines.
            if (line.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
            {
                continue;
            }

            size_t pos = line.find('=');

            // Check for invalid lines.
            if (pos == std::string::npos)
            {
                std::stringstream ss;
                ss << "Invalid config line #" << lineNum << ": " << line;

                throw XConfigError(ss.str());
            }

            std::string key = Trim(line.substr(0, pos));
            std::string value = Trim(line.substr(pos + 1));

            // Check for duplicate keys.
            if (configMap.count(key) > 0)
            {
                std::stringstream ss;
                ss << "Duplicate key '" << key << "' found on line #" << lineNum;

                throw XConfigError(ss.str());
            }

            configMap[key] = value;
        }

        // Close the config file.
        configFile.close();

        return configMap;
    }
    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS