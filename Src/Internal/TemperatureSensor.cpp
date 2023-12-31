/*************************************************************************************************
 * @file TemperatureSensor.cpp
 *
 * @brief Concrete implementation of @ref TemperatureSensor class.
 *
 *************************************************************************************************/

#include "Internal/TemperatureSensor.hpp"

#include <thread>

#include "Exceptions/XArgumentNull.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

namespace
{
    namespace Default
    {
        constexpr const uint32_t SensorTimeCycleSeconds = 1; ///< Timing to be used by sensor to read the temperature.
    }
}

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    TemperatureSensor::TemperatureSensor(std::shared_ptr<ITemperatureSimulator> temperatureSimulator)
        : _temperatureSimulator(temperatureSimulator),
          _isStopEvent(false)
    {
        if (nullptr == temperatureSimulator)
        {
            throw XArgumentNull("TemperatureSensor::temperatureSimulator");
        }
    }

    TemperatureSensor::~TemperatureSensor() = default;

    // #endregion

    // #region Public Methods

    void TemperatureSensor::RegisterObservers(TemperatureChangeCallback callback)
    {
        _observers.push_back(callback);
    }

    void TemperatureSensor::Start()
    {
        _sensorFuture =
            std::async(std::launch::async, [this]()
            {
                while (!_isStopEvent)
                {
                    float temperature = _temperatureSimulator->GetTemperature();

                    NotifyObservers(temperature);

                    // TODO: Get the delay value from the system configuration entity.
                    std::this_thread::sleep_for(std::chrono::seconds(Default::SensorTimeCycleSeconds));
                }
            });
    }

    void TemperatureSensor::Stop()
    {
        _isStopEvent = true;
    }

    // #endregion

    // #region Private Methods

    void TemperatureSensor::NotifyObservers(float temperature)
    {
        for (TemperatureChangeCallback &observer : _observers)
        {
            observer(temperature);
        }
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS