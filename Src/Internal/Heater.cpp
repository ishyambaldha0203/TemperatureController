/*************************************************************************************************
 * @file Heater.cpp
 *
 * @brief Concrete implementation of @ref Heater class.
 *
 *************************************************************************************************/

#include "Internal/Heater.hpp"

#include "Interfaces/Entities/IApplianceConfigMutable.hpp"

#include "Exceptions/XArgumentNull.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::EntityInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

namespace
{
    namespace Default
    {
        constexpr const float HeatingIntensity = 0.25f;
    }
}

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    Heater::Heater(std::shared_ptr<IApplianceConfig> applianceConfig,
                   std::shared_ptr<IDisplayManager> displayManager)
        : _applianceConfig(applianceConfig),
          _displayManager(displayManager),
          _isRunning(false)
    {
        if (nullptr == applianceConfig)
        {
            throw XArgumentNull("Heater::applianceConfig");
        }

        if (nullptr == displayManager)
        {
            throw XArgumentNull("Cooler::displayManager");
        }

        _heatingIntensity = Default::HeatingIntensity;
    }

    Heater::~Heater() = default;

    // #endregion

    // #region Public Methods

    void Heater::Initialize(float heatingIntensity)
    {
        if (heatingIntensity > 0)
        {
            _heatingIntensity = heatingIntensity;
        }
    }

    void Heater::Start()
    {
        _displayManager->PopulateText("\n**** Heater Started ****\n\n");

        std::shared_ptr<IApplianceConfigMutable> applianceConfigMutable =
            std::static_pointer_cast<IApplianceConfigMutable>(_applianceConfig);

        applianceConfigMutable->SetHeatingIntensity(_heatingIntensity);

        _isRunning = true;
    }

    void Heater::Stop()
    {
        _displayManager->PopulateText("\n**** Heater Stopped ****\n\n");

        std::shared_ptr<IApplianceConfigMutable> applianceConfigMutable =
            std::static_pointer_cast<IApplianceConfigMutable>(_applianceConfig);

        applianceConfigMutable->SetHeatingIntensity(0.0f);

        _isRunning = false;
    }

    bool Heater::IsRunning()
    {
        return _isRunning;
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS