/*************************************************************************************************
 * @file ITemperatureManager.hpp
 *
 * @brief Interface to define member contracts to manage a temperature.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATUREMANAGER_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATUREMANAGER_HPP

#include "CommonConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface ITemperatureManager
     *
     * @brief Interface to define member contracts and operations to manage a temperature.
     */
    interface ITemperatureManager
    {
        DECLARE_INTERFACE_DEFAULTS(ITemperatureManager)

        /**
         * @brief Begin temperature monitoring and controlling session.
         *
         * @throw TBD
         */
        virtual void Begin() = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATUREMANAGER_HPP