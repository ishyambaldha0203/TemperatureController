/*************************************************************************************************
 * @file Cooler.hpp
 *
 * @brief Declarations for the concrete class @ref Cooler.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_COOLER_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_COOLER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/IAppliance.hpp"
#include "Interfaces/IDisplayManager.hpp"
#include "Interfaces/Entities/IApplianceConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class Cooler
     *
     * @brief Concrete implementation of the Cooler.
     */
    class Cooler : public Interfaces::IAppliance
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new cooler object.
         *
         * @param applianceConfig
         */
        Cooler(std::shared_ptr<EntityInterfaces::IApplianceConfig> applianceConfig,
               std::shared_ptr<Interfaces::IDisplayManager> displayManager);

        /**
         * @brief Destroy the cooler object.
         */
        virtual ~Cooler() override;

        // #endregion

        // #region IAppliance Implementation

        virtual void Initialize(float intensity) noexcept override;

        virtual void Start() override;

        virtual void Stop() override;

        virtual bool IsRunning() const noexcept override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(Cooler)

        /**
         * @brief To set cooling intensity with appliance level configuration.
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
         * @brief Store the cooling intensity provided by controller.
         */
        float _coolingIntensity;
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_COOLER_HPP
