/*************************************************************************************************
 * @file SystemConfig.hpp
 *
 * @brief Concrete data entity class implementing the @ref ISystemConfig.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_ENTITIES_SYSTEMCONFIG_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_ENTITIES_SYSTEMCONFIG_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ISystemConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Entities
{
    /**
     * @class SystemConfig
     *
     * @brief Represents all system level the configuration.
     *
     * @note This entity should grow in elements as per the requirement.
     */
    class SystemConfig : public EntityInterfaces::ISystemConfig 
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new entity object of system configuration.
         */
        SystemConfig() = default;

        /**
         * @brief Destroy the system config entity object.
         */
        virtual ~SystemConfig() override = default;

        // #endregion

        // #region ISystemConfig Implementation

        float GetHeatingIntensity() const noexcept override
        {
            return _heatingIntensity;
        }

        float GetCoolingIntensity() const noexcept override
        {
            return _coolingIntensity;
        }

        void SetCoolingIntensity(float intensity) noexcept override
        {
            _coolingIntensity = intensity;
        }

        void SetHeatingIntensity(float intensity) noexcept override
        {
            _heatingIntensity = intensity;
        }

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(SystemConfig)

        // #region Internal Data Members

        /**
         * @brief Store heating intensity value.
         */
        float _heatingIntensity;

        /**
         * @brief Store cooling intensity value.
         */
        float _coolingIntensity;

        // #endregion
    };
} // namespace Entities
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_ENTITIES_SYSTEMCONFIG_HPP