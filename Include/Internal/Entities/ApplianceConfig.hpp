/*************************************************************************************************
 * @file ApplianceConfig.hpp
 *
 * @brief Concrete data entity class implementing the @ref IApplianceConfig.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_ENTITIES_APPLIANCECONFIG_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_ENTITIES_APPLIANCECONFIG_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/IApplianceConfigMutable.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Entities
{
    /**
     * @class ApplianceConfig
     *
     * @brief Represents all the common configuration of appliances.
     *
     * @note This entity is allowed to grow in elements as per the requirement.
     */
    class ApplianceConfig : public EntityInterfaces::IApplianceConfigMutable
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new entity object of appliance configuration.
         */
        ApplianceConfig() = default;

        /**
         * @brief Destroy the appliance config entity object.
         */
        virtual ~ApplianceConfig() override = default;

        // #endregion

        // #region IApplianceConfig Implementation

        float GetHeatingIntensity() const noexcept override
        {
            return _heatingIntensity;
        }

        float GetCoolingIntensity() const noexcept override
        {
            return _coolingIntensity;
        }

        // #endregion

        // #region IApplianceConfigMutable Implementation

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
        DECLARE_NON_COPYABLE_CLASS(ApplianceConfig)

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

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_ENTITIES_APPLIANCECONFIG_HPP