/*************************************************************************************************
 * @file ISystemConfigMutable.hpp
 *
 * @brief Interface to define member contracts to access and update system configurations.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_ISYSTEMCONFIGMUTABLE_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_ISYSTEMCONFIGMUTABLE_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ISystemConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace EntityInterfaces
{
    /**
     * @interface ISystemConfigMutable
     *
     * @brief Allows modification of system entity data through set methods.
     */
    interface ISystemConfigMutable : public ISystemConfig
    {
        DECLARE_INTERFACE_DEFAULTS(ISystemConfigMutable)

        /**
         * @brief Set the minimum temperature to regulate.
         *
         * @return const float
         */
        virtual void SetMinTemperatureRange(float temperature) noexcept = 0;

        /**
         * @brief Set the maximum temperature to regulate.
         *
         * @return const float
         */
        virtual void SetMaxTemperatureRange(float temperature) noexcept = 0;

        /**
         * @brief Set the cooling intensity.
         *
         * @return const float
         */
        virtual void SetCoolingIntensity(float intensity) noexcept = 0;

        /**
         * @brief Set the heating intensity.
         *
         * @return const float
         */
        virtual void SetHeatingIntensity(float intensity) noexcept = 0;

        /**
         * @brief Set the intensity to be used by temperature simulator.
         *
         * @return const float
         */
        virtual void SetSimulationIntensity(float intensity) noexcept = 0;
    };
} // namespace EntityInterfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_ISYSTEMCONFIGMUTABLE_HPP