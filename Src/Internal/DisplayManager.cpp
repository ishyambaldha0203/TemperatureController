/*************************************************************************************************
 * @file DisplayManager.cpp
 *
 * @brief Concrete implementation of @ref DisplayManager class.
 *
 *************************************************************************************************/

#include "Internal/DisplayManager.hpp"

#include <sstream>

#include "Exceptions/XBaseException.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::EntityInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    DisplayManager::DisplayManager() = default;

    DisplayManager::~DisplayManager() = default;

    // #endregion

    // #region Public Methods

    void DisplayManager::DisplayTemperature(float temperature)
    {
        std::string color;
        std::string colorStart = "\033[1;";
        std::string colorEnd = "\033[0m";
        std::string degreeCelsius = "°C";

        std::stringstream streamTemperatureRange;
        streamTemperatureRange << "[" << _minTemperature << "-" << _maxTemperature << "] ";

        if (temperature < _minTemperature)
        {
            color = "34m"; // Blue
        }
        else if (temperature > _maxTemperature)
        {
            color = "31m"; // Red
        }
        else
        {
            color = "32m"; // Green
        }

        std::string temperatureString =
            std::string("\rRoom Temperature: ") + streamTemperatureRange.str() + colorStart + color + std::to_string(static_cast<int>(temperature)) + colorEnd;

        PopulateText(temperatureString + degreeCelsius);
    }

    void DisplayManager::Initialize(const ISystemConfig &systemConfig) noexcept
    {
        _minTemperature = systemConfig.GetMinTemperatureRange();
        _maxTemperature = systemConfig.GetMaxTemperatureRange();
    }

    void DisplayManager::PopulateText(const std::string &data) noexcept
    {
        std::cout << data << std::flush;
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS