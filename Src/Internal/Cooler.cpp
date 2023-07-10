/*************************************************************************************************
 * @file Cooler.cpp
 *
 * @brief Concrete implementation of @ref Cooler class.
 *
 *************************************************************************************************/

#include "Internal/Cooler.hpp"

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
        constexpr const float CoolingIntensity = 0.25f;
    }
}

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    Cooler::Cooler(std::shared_ptr<IApplianceConfig> applianceConfig,
                   std::shared_ptr<IDisplayManager> displayManager)
        : _applianceConfig(applianceConfig),
          _displayManager(displayManager),
          _isRunning(false)
    {
        if (nullptr == applianceConfig)
        {
            throw XArgumentNull("Cooler::applianceConfig");
        }

        if (nullptr == displayManager)
        {
            throw XArgumentNull("Cooler::displayManager");
        }

        _coolingIntensity = Default::CoolingIntensity;
    }

    Cooler::~Cooler() = default;

    // #endregion

    // #region Public Methods

    void Cooler::Initialize(float coolingIntensity)
    {
        if (coolingIntensity > 0)
        {
            _coolingIntensity = coolingIntensity;
        }
    }

    void Cooler::Start()
    {
        _displayManager->PopulateText("\n**** Cooler Started ****\n\n");

        std::shared_ptr<IApplianceConfigMutable> applianceConfigMutable =
            std::static_pointer_cast<IApplianceConfigMutable>(_applianceConfig);

        applianceConfigMutable->SetCoolingIntensity(_coolingIntensity);

        _isRunning = true;
    }

    void Cooler::Stop()
    {
        _displayManager->PopulateText("\n**** Cooler Stopped ****\n\n");

        std::shared_ptr<IApplianceConfigMutable> applianceConfigMutable =
            std::static_pointer_cast<IApplianceConfigMutable>(_applianceConfig);

        applianceConfigMutable->SetCoolingIntensity(0.0f);

        _isRunning = false;
    }

    bool Cooler::IsRunning()
    {
        return _isRunning;
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS