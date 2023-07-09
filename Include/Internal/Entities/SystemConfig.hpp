/*************************************************************************************************
 * @file SystemConfig.hpp
 *
 * @brief Concrete data entity class implementing the @ref ISystemConfig.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_ENTITIES_SYSTEMCONFIG_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_ENTITIES_SYSTEMCONFIG_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ISystemConfigMutable.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Entities
{
    /**
     * @class SystemConfig
     *
     * @brief Represents all system level the configuration.
     *
     * @note This entity allows to grow in elements as per the requirement.
     */
    class SystemConfig : public EntityInterfaces::ISystemConfigMutable
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

        float GetMinTemperatureRange() const noexcept override
        {
            return _minTemperature;
        }

        float GetMaxTemperatureRange() const noexcept override
        {
            return _maxTemperature;
        }

        float GetHeatingIntensity() const noexcept override
        {
            return _heatingIntensity;
        }

        float GetCoolingIntensity() const noexcept override
        {
            return _coolingIntensity;
        }

        float GetSimulationIntensity() const noexcept override
        {
            return _simulationIntensity;
        }

        // #endregion

        // #region ISystemConfigMutable Implementation

        void SetMinTemperatureRange(float temperature) noexcept override
        {
            _minTemperature = temperature;
        }

        void SetMaxTemperatureRange(float temperature) noexcept override
        {
            _maxTemperature = temperature;
        }

        void SetCoolingIntensity(float intensity) noexcept override
        {
            _coolingIntensity = intensity;
        }

        void SetHeatingIntensity(float intensity) noexcept override
        {
            _heatingIntensity = intensity;
        }

        void SetSimulationIntensity(float intensity) noexcept override
        {
            _simulationIntensity = intensity;
        }
        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(SystemConfig)

        // #region Internal Data Members

        /**
         * @brief Store minimum temperature to maintain for value.
         */
        float _minTemperature;

        /**
         * @brief Store maximum temperature to maintain for value.
         */
        float _maxTemperature;

        /**
         * @brief Store heating intensity value.
         */
        float _heatingIntensity;

        /**
         * @brief Store cooling intensity value.
         */
        float _coolingIntensity;

        /**
         * @brief Store intensity value to be used by simulator.
         */
        float _simulationIntensity;

        // #endregion
    };
} // namespace Entities
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_ENTITIES_SYSTEMCONFIG_HPP