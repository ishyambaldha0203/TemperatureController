/*************************************************************************************************
 * @file ITemperatureObserver.hpp
 *
 * @brief Interface to define member contracts for temperature observers/subscribers.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATUREOBSERVER_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATUREOBSERVER_HPP

#include "CommonConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface ITemperatureObserver
     *
     * @brief Interface used by the owner of a topic to notify subscribers.
     */
    interface ITemperatureObserver
    {
        DECLARE_INTERFACE_DEFAULTS(ITemperatureObserver)

        /**
         * @brief Function called on room temperature update events.
         *
         * @param temperature Updated room temperature value.
         */
        virtual void OnUpdate(float temperature) = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATUREOBSERVER_HPP
