/*************************************************************************************************
 * @file ISystemConfigReader.hpp
 *
 * @brief Interface to define member contracts to read the system level configuration.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ISYSTEMCONFIGREADER_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ISYSTEMCONFIGREADER_HPP

#include "CommonConfig.hpp"

#include <unordered_map>

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface ISystemConfigReader
     *
     * @brief Interface to define member contracts and operations to read system level settings.
     */
    interface ISystemConfigReader
    {
        DECLARE_INTERFACE_DEFAULTS(ISystemConfigReader)

        // #region Type Aliases

        using ConfigurationMap = std::unordered_map<std::string, std::string>;

        // #endregion

        /**
         * @brief Read the configuration key-value pair from configuration file.
         *
         * @param[in] filePath A file from where to read configurations
         *
         * @return Map of key value pair of configuration.
         *
         * @throw XFileNotFound If configuration file is not found.
         */
        virtual ConfigurationMap ReadConfig(const std::string &confFileName) = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ISYSTEMCONFIGREADER_HPP