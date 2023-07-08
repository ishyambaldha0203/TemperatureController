/*************************************************************************************************
 * @file Heater.cpp
 *
 * @brief Concrete implementation of @ref Heater class.
 *
 *************************************************************************************************/

#include "Internal/Heater.hpp"

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

    Heater::Heater(std::shared_ptr<ISystemConfig> systemConfig)
        : _systemConfig(systemConfig),
          _isRunning(false)
    {
        if (nullptr == systemConfig)
        {
            throw XArgumentNull("Heater::systemConfig");
        }
    }

    Heater::~Heater() = default;

    // #endregion

    // #region Public Methods

    void Heater::Start()
    {
        std::cout << "\nHeater started...\n" << std::endl;

        _systemConfig->SetHeatingIntensity(0.25f);

        _isRunning = true;
    }

    void Heater::Stop()
    {
        std::cout << "\nHeater stopped...\n" << std::endl;

        _systemConfig->SetHeatingIntensity(0.0f);

        _isRunning = false;
    }

    bool Heater::IsRunning()
    {
        return _isRunning;
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS