/*************************************************************************************************
 * @file TemperatureSimulator.cpp
 *
 * @brief Concrete implementation of @ref TemperatureSimulator class.
 *
 *************************************************************************************************/

#include "Internal/TemperatureSimulator.hpp"

#include <random>
#include <thread>

#include "Exceptions/XArgumentNull.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;
using namespace TEMPERATURE_CONTROLLER_NS::EntityInterfaces;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    TemperatureSimulator::TemperatureSimulator(std::shared_ptr<IApplianceConfig> applianceConfig)
        : _applianceConfig(applianceConfig),
          _isStopEvent(false),
          _currentTemperature(0.0f)
    {
        if (nullptr == applianceConfig)
        {
            throw XArgumentNull("TemperatureSimulator::applianceConfig");
        }
    }

    TemperatureSimulator::~TemperatureSimulator() = default;

    // #endregion

    // #region Public Methods

    float TemperatureSimulator::GetTemperature() const
    {
        return _currentTemperature;
    }

    void TemperatureSimulator::Start(float startingTemperature)
    {
        _currentTemperature = startingTemperature;
        
        // To create random distribution range from current temperature.
        std::mt19937 randomNumGenerator{std::random_device{}()};

        // Generate the random number in range of -0.5 to +0.5.
        std::normal_distribution<float> distribution{0.0f, 0.5f};

        _simulatorFuture =
            std::async(std::launch::async, [this, &randomNumGenerator, &distribution, &startingTemperature]()
            {
                float temperature = startingTemperature;

                while (!_isStopEvent)
                {
                    temperature +=
                        _applianceConfig->GetHeatingIntensity() - _applianceConfig->GetCoolingIntensity() + distribution(randomNumGenerator);

                    // Update current temperature.
                    _currentTemperature.store(temperature);

                    // TODO: Get the delay value from configuration.
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
            });
    }

    void TemperatureSimulator::Stop()
    {
        _isStopEvent = true;
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS