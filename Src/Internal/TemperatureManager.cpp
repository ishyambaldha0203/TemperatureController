/*************************************************************************************************
 * @file TemperatureManager.cpp
 *
 * @brief Concrete implementation of @ref TemperatureManager class.
 *
 *************************************************************************************************/

#include "Internal/TemperatureManager.hpp"

#include <future>
#include <thread>

#include "Exceptions/XArgumentNull.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    TemperatureManager::TemperatureManager(std::shared_ptr<ITemperatureSensor> temperatureSensor,
                                           std::shared_ptr<ITemperatureSimulator> temperatureSimulator,
                                           std::shared_ptr<IAppliance> cooler,
                                           std::shared_ptr<IAppliance> heater,
                                           std::shared_ptr<IDisplayManager> displayManager)
        : _temperatureSensor(temperatureSensor),
          _temperatureSimulator(temperatureSimulator),
          _cooler(cooler),
          _heater(heater),
          _displayManager(displayManager)
    {
        if (nullptr == temperatureSensor)
        {
            throw XArgumentNull("TemperatureManager::temperatureSensor");
        }

        if (nullptr == temperatureSimulator)
        {
            throw XArgumentNull("TemperatureManager::temperatureSimulator");
        }

        if (nullptr == cooler)
        {
            throw XArgumentNull("TemperatureManager::cooler");
        }

        if (nullptr == heater)
        {
            throw XArgumentNull("TemperatureManager::heater");
        }

        if (nullptr == displayManager)
        {
            throw XArgumentNull("TemperatureManager::displayManager");
        }

        _minTemperature = 21;
        _maxTemperature = 23;
        _startingTemperature = (_minTemperature + _maxTemperature) / 2;
    }

    TemperatureManager::~TemperatureManager() = default;

    // #endregion

    // #region Public Methods

    void TemperatureManager::Begin()
    {
        // Register with temperature sensor.
        _temperatureSensor->RegisterObservers([this](float temperature)
                                              {
                                                TemperatureObserverCallback(temperature);
                                              });

        // Start temperature simulator.
        _temperatureSimulator->Start(_startingTemperature);

        // Start temperature sensor.
        _temperatureSensor->Start();

        // Stay here.
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    // #endregion

    // #region Private Methods

    void TemperatureManager::ControlTemperature(float temperature)
    {
        /**
         * - Start heater if temperature is less then min allowed and only if not running already.
         * - Start cooler if temperature is greater then max allowed and only if not running already.
         * - If already in range, stop both heater and cooler.
         */
        if (temperature < _minTemperature)
        {
            if(!_heater->IsRunning())
            {
                _heater->Start();
            }
        }
        else if (temperature > _maxTemperature)
        {
            if(!_cooler->IsRunning())
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

    void TemperatureManager::DisplayTemperature(float temperature)
    {
        std::string color;
        std::string colorStart = "\033[1;";
        std::string colorEnd = "\033[0m";
        std::string degreeCelsius = "°C";

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
            std::string("\rTemperature: ") + colorStart + color + std::to_string(static_cast<int>(temperature)) + colorEnd;

        _displayManager->PopulateText(temperatureString + degreeCelsius);
    }

    void TemperatureManager::TemperatureObserverCallback(float temperature)
    {
        std::future<void> future =
            std::async(std::launch::async, [this, temperature]
            {
                DisplayTemperature(temperature);

                ControlTemperature(temperature);
            });
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS