/*************************************************************************************************
 * @file ITemperatureSimulator.hpp
 *
 * @brief Interface to define member contracts to simulate the natural room temperature.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATURESIMULATOR_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATURESIMULATOR_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ISystemConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface ITemperatureSimulator
     *
     * @brief Interface to define member contracts and operations to simulate temperature naturally.
     */
    interface ITemperatureSimulator
    {
        DECLARE_INTERFACE_DEFAULTS(ITemperatureSimulator)

        /**
         * @brief Initialize the simulator to update the temperature accordingly.
         *
         * @param systemConfig entity that contains system level configurations.
         */
        virtual void Initialize(const EntityInterfaces::ISystemConfig &systemConfig) = 0;

        /**
         * @brief Get the temperature value.
         *
         * @return A current temperature value.
         */
        virtual float GetTemperature() const = 0;

        /**
         * @brief Start generating real time temperature value.
         *
         * @param currentTemperature A temperature from where it diversify.
         */
        virtual void Start(float startingTemperature) = 0;

        /**
         * @brief Stop the temperature simulator.
         */
        virtual void Stop() = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATURESIMULATOR_HPP