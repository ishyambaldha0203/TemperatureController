/*************************************************************************************************
 * @file IAppliance.hpp
 *
 * @brief Interface to define member contracts for temperature control appliances.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_IAPPLIANCE_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_IAPPLIANCE_HPP

#include "CommonConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface IAppliance
     *
     * @brief Interface that represents a appliance object that can control temperature.
     */
    interface IAppliance
    {
        DECLARE_INTERFACE_DEFAULTS(IAppliance)

        /**
         * @brief Initialise the appliances with change intensity.
         *
         * @param intensity Appliance running intensity.
         */
        virtual void Initialize(float intensity) noexcept = 0;

        /**
         * @brief Start the appliance.
         */
        virtual void Start() = 0;

        /**
         * @brief Stop the appliance.
         */
        virtual void Stop() = 0;

        /**
         * @brief Check the running status of appliance.
         * 
         * @retval true If the appliance is in running state.
         * @retval false If the appliance is not running.
         */
        virtual bool IsRunning() const noexcept = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_IAPPLIANCE_HPP
