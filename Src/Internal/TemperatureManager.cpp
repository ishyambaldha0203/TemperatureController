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
using namespace TEMPERATURE_CONTROLLER_NS::EntityInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    TemperatureManager::TemperatureManager(std::shared_ptr<ISystemConfigProcessor> systemConfigProcessor,
                                           std::shared_ptr<ITemperatureSensor> temperatureSensor,
                                           std::shared_ptr<ITemperatureSimulator> temperatureSimulator,
                                           std::shared_ptr<ITemperatureController> temperatureController,
                                           std::shared_ptr<IDisplayManager> displayManager)
        : _systemConfigProcessor(systemConfigProcessor),
          _temperatureSensor(temperatureSensor),
          _temperatureSimulator(temperatureSimulator),
          _temperatureController(temperatureController),
          _displayManager(displayManager)
    {
        if (nullptr == systemConfigProcessor)
        {
            throw XArgumentNull("TemperatureManager::systemConfigProcessor");
        }

        if (nullptr == temperatureSensor)
        {
            throw XArgumentNull("TemperatureManager::temperatureSensor");
        }

        if (nullptr == temperatureSimulator)
        {
            throw XArgumentNull("TemperatureManager::temperatureSimulator");
        }

        if (nullptr == temperatureController)
        {
            throw XArgumentNull("TemperatureManager::temperatureController");
        }

        if (nullptr == displayManager)
        {
            throw XArgumentNull("TemperatureManager::displayManager");
        }
    }

    TemperatureManager::~TemperatureManager() = default;

    // #endregion

    // #region Public Methods

    void TemperatureManager::Begin()
    {
        // TODO: Fetch the system level configuration provided by user as an input data.

        // Process the input params to prepare test config data entity.
        std::shared_ptr<ISystemConfig> systemConfig = _systemConfigProcessor->PrepareConfig();

        _temperatureController->Initialize(*systemConfig.get());

        _displayManager->Initialize(*systemConfig.get());

        _temperatureSimulator->Initialize(*systemConfig.get());

        // Register with temperature sensor.
        _temperatureSensor->RegisterObservers([this](float temperature)
                                              {
                                                TemperatureObserverCallback(temperature);
                                              });

        // Get the median of min and max as starting point for simulator.
        float startingTemperature = (systemConfig->GetMinTemperatureRange() + systemConfig->GetMaxTemperatureRange()) / 2;

        // Start temperature simulator.
        _temperatureSimulator->Start(startingTemperature);

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

    void TemperatureManager::TemperatureObserverCallback(float temperature)
    {
        std::future<void> future =
            std::async(std::launch::async, [this, temperature]
            {
                // TODO: Observer pattern can be used to update all the observers on update events.
                _displayManager->DisplayTemperature(temperature);

                _temperatureController->RegulateTemperature(temperature);
            });
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS