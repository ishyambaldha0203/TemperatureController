/*************************************************************************************************
 * @file ISystemConfig.hpp
 *
 * @brief Interface to define member contracts to access and update system configuration at runtime.
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
    };
} // namespace EntityInterfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_ISYSTEMCONFIG_HPP