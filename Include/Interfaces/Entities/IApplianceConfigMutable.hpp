/*************************************************************************************************
 * @file IApplianceConfigMutable.hpp
 *
 * @brief Interface to define member contracts to access and update appliance configurations.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_IAPPLIANCECONFIGMUTABLE_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_IAPPLIANCECONFIGMUTABLE_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/IApplianceConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace EntityInterfaces
{
    /**
     * @interface IApplianceConfigMutable
     *
     * @brief Allows modification of entity data through set methods.
     */
    interface IApplianceConfigMutable : public IApplianceConfig
    {
        DECLARE_INTERFACE_DEFAULTS(IApplianceConfigMutable)

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

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ENTITIES_IAPPLIANCECONFIGMUTABLE_HPP