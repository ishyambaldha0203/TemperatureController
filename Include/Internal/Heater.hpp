/*************************************************************************************************
 * @file Heater.hpp
 *
 * @brief Declarations for the concrete class @ref Heater.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_HEATER_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_HEATER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/IAppliance.hpp"
#include "Interfaces/IDisplayManager.hpp"
#include "Interfaces/Entities/IApplianceConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class Heater
     *
     * @brief Concrete implementation of the Heater.
     */
    class Heater : public Interfaces::IAppliance
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new Heater object.
         *
         * @param applianceConfig
         */
        Heater(std::shared_ptr<EntityInterfaces::IApplianceConfig> applianceConfig,
               std::shared_ptr<Interfaces::IDisplayManager> displayManager);

        /**
         * @brief Destroy the heater object.
         */
        virtual ~Heater() override;

        // #endregion

        // #region IAppliance Implementation

        virtual void Initialize(float intensity) noexcept override;

        virtual void Start() override;

        virtual void Stop() override;

        virtual bool IsRunning() const noexcept override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(Heater)

        /**
         * @brief To set cooling intensity with system level configuration.
         */
        std::shared_ptr<EntityInterfaces::IApplianceConfig> _applianceConfig;

        /**
         * @brief To display start stop event.
         */
        std::shared_ptr<Interfaces::IDisplayManager> _displayManager;

        /**
         * @brief Cooler running status.
         */
        bool _isRunning;

        /**
         * @brief Store the heating intensity provided by controller.
         */
        float _heatingIntensity;
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_HEATER_HPP
