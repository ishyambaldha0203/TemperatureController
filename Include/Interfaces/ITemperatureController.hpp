/*************************************************************************************************
 * @file ITemperatureController.hpp
 *
 * @brief Interface to define member contracts to control the temperature in specific range.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATURECONTROLLER_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATURECONTROLLER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ISystemConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface ITemperatureController
     *
     * @brief Interface to define member contracts and operations to control the temperature.
     */
    interface ITemperatureController
    {
        DECLARE_INTERFACE_DEFAULTS(ITemperatureController)

        /**
         * @brief Initialize the controller to set the edge conditions.
         *
         * @param systemConfig entity that contains system level configurations.
         */
        virtual void Initialize(const EntityInterfaces::ISystemConfig &systemConfig) = 0;

        /**
         * @brief Regulate the temperature in specific range.
         *
         * @throw TBD
         */
        virtual void RegulateTemperature(float currentTemperature) = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATURECONTROLLER_HPP