/*************************************************************************************************
 * @file IDisplayManager.hpp
 *
 * @brief Interface to define member contracts to manage functionalities related display.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_IDISPLAYMANAGER_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_IDISPLAYMANAGER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ISystemConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface IDisplayManager
     *
     * @brief Interface to define member contracts and operations related to display.
     */
    interface IDisplayManager
    {
        DECLARE_INTERFACE_DEFAULTS(IDisplayManager)

        /**
         * @brief To display the temperature with colored text based on temperature range.
         *
         * @param temperature Current temperature.
         */
        virtual void DisplayTemperature(float temperature) = 0;

        /**
         * @brief Initialize the display to set the config parameters.
         *
         * @param systemConfig entity that contains system level configurations.
         */
        virtual void Initialize(const EntityInterfaces::ISystemConfig &systemConfig) = 0;

        /**
         * @brief Populate the text data on display.
         *
         * @throw XInvalidArgument is data is empty.
         */
        virtual void PopulateText(const std::string &data) = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_IDISPLAYMANAGER_HPP