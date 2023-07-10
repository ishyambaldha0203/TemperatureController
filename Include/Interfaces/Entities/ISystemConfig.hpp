/*************************************************************************************************
 * @file ISystemConfig.hpp
 *
 * @brief Interface to define member contracts to access system configuration at runtime.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_ISYSTEMCONFIG_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_ISYSTEMCONFIG_HPP

#include "CommonConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace EntityInterfaces
{
    /**
     * @interface ISystemConfig
     *
     * @brief Represents a read-only entity that fully contains a system configuration data.
     */
    interface ISystemConfig
    {
        DECLARE_INTERFACE_DEFAULTS(ISystemConfig)

        /**
         * @brief Get the read-only minimum temperature owned by this entity.
         *
         * @return Minimum temperature.
         */
        virtual float GetMinTemperatureRange() const noexcept = 0;

        /**
         * @brief Get the read-only maximum temperature owned by this entity.
         *
         * @return Maximum temperature.
         */
        virtual float GetMaxTemperatureRange() const noexcept = 0;

        /**
         * @brief Get the read-only heating intensity owned by this entity.
         *
         * @return Heating intensity.
         */
        virtual float GetHeatingIntensity() const noexcept = 0;

        /**
         * @brief Get the read-only heating intensity owned by this entity.
         *
         * @return Heating intensity.
         */
        virtual float GetCoolingIntensity() const noexcept = 0;

        /**
         * @brief Get the read-only simulation intensity owned by this entity.
         *
         * @return Simulation intensity.
         */
        virtual float GetSimulationIntensity() const noexcept = 0;
    };
} // namespace EntityInterfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_ISYSTEMCONFIG_HPP