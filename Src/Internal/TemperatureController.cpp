/*************************************************************************************************
 * @file TemperatureController.cpp
 *
 * @brief Concrete implementation of @ref TemperatureController class.
 *
 *************************************************************************************************/

#include "Internal/TemperatureController.hpp"

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

    TemperatureController::TemperatureController(std::shared_ptr<IAppliance> cooler,
                                                 std::shared_ptr<IAppliance> heater)
        : _cooler(cooler),
          _heater(heater)
    {
        if (nullptr == cooler)
        {
            throw XArgumentNull("TemperatureController::cooler");
        }

        if (nullptr == heater)
        {
            throw XArgumentNull("TemperatureController::heater");
        }
    }

    TemperatureController::~TemperatureController() = default;

    // #endregion

    // #region Public Methods

    void TemperatureController::Initialize(const ISystemConfig &systemConfig)
    {
        _minTemperature = systemConfig.GetMinTemperatureRange();
        _maxTemperature = systemConfig.GetMaxTemperatureRange();
    }

    void TemperatureController::RegulateTemperature(float currentTemperature)
    {
        /**
         * - Start heater if temperature is less then min allowed and only if not running already.
         * - Start cooler if temperature is greater then max allowed and only if not running already.
         * - If already in range, stop both heater and cooler.
         */
        if (currentTemperature < _minTemperature)
        {
            if (!_heater->IsRunning())
            {
                _heater->Start();
            }
        }
        else if (currentTemperature > _maxTemperature)
        {
            if (!_cooler->IsRunning())
            {
                _cooler->Start();
            }
        }
        else
        {
            if (_heater->IsRunning())
            {
                _heater->Stop();
            }

            if (_cooler->IsRunning())
            {
                _cooler->Stop();
            }
        }
    }
    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS