/*************************************************************************************************
 * @file ITemperatureSensor.hpp
 *
 * @brief Interface to define member contracts to simulate the natural room temperature.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATURESENSOR_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATURESENSOR_HPP

#include "CommonConfig.hpp"

#include "Internal/CallbackTypes.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface ITemperatureSensor
     *
     * @brief Interface to define member contracts and operations to sense temperature naturally.
     */
    interface ITemperatureSensor
    {
        DECLARE_INTERFACE_DEFAULTS(ITemperatureSensor)

        /**
         * @brief Register the observers to get notification on temperature change events.
         * 
         * @param callback A call back to get on change events.
         */
        virtual void RegisterObservers(Internal::TemperatureChangeCallback callback) = 0;

        /**
         * @brief Start reading the temperature.
         *
         * @param currentTemperature A temperature from where it diversify.
         */
        virtual void Start() = 0;

        /**
         * @brief Stop the temperature sensor.
         */
        virtual void Stop() = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATURESENSOR_HPP