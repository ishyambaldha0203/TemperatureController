/*************************************************************************************************
 * @file IApplianceConfig.hpp
 *
 * @brief Interface to define member contracts to access appliance's configuration at runtime.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_IAPPLIANCECONFIG_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_IAPPLIANCECONFIG_HPP

#include "CommonConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace EntityInterfaces
{
    /**
     * @interface IApplianceConfig
     *
     * @brief Represents a read-only entity that fully contains a appliance's configuration data.
     */
    interface IApplianceConfig
    {
        DECLARE_INTERFACE_DEFAULTS(IApplianceConfig)

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
    };
} // namespace EntityInterfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_IAPPLIANCECONFIG_HPP