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

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    Cooler::Cooler(std::shared_ptr<IApplianceConfig> applianceConfig)
        : _applianceConfig(applianceConfig),
          _isRunning(false)
    {
        if (nullptr == applianceConfig)
        {
            throw XArgumentNull("Cooler::applianceConfig");
        }
    }

    Cooler::~Cooler() = default;

    // #endregion

    // #region Public Methods

    void Cooler::Start()
    {
        std::cout << "\nCooler started...\n"
                  << std::endl;

        std::shared_ptr<IApplianceConfigMutable> applianceConfigMutable =
            std::static_pointer_cast<IApplianceConfigMutable>(_applianceConfig);

        applianceConfigMutable->SetCoolingIntensity(0.25f);

        _isRunning = true;
    }

    void Cooler::Stop()
    {
        std::cout << "\nCooler stopped...\n"
                  << std::endl;

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