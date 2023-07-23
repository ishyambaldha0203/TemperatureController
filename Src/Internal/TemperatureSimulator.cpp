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

namespace
{
    namespace Default
    {
        constexpr const float SimulationIntensity = 0.5f;        ///< Used by simulator to generate random temperature between -0.5f to +0.5f.
        constexpr const uint32_t SimulationTimeCycleSeconds = 1; ///< Timing to be used bu simulator to update temperature.
    }
}

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

        _simulationIntensity = Default::SimulationIntensity;
    }

    TemperatureSimulator::~TemperatureSimulator() = default;

    // #endregion

    // #region Public Methods

    void TemperatureSimulator::Initialize(const ISystemConfig &systemConfig) noexcept
    {
        _simulationIntensity = systemConfig.GetSimulationIntensity();
    }

    float TemperatureSimulator::GetTemperature() const noexcept
    {
        return _currentTemperature;
    }

    void TemperatureSimulator::Start(float startingTemperature)
    {
        _currentTemperature = startingTemperature;
        
        // To create random distribution range from current temperature.
        std::mt19937 randomNumGenerator{std::random_device{}()};

        // Generate the random number in range of -0.5 to +0.5.
        std::normal_distribution<float> distribution{0.0f, _simulationIntensity};

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

                    // TODO: Get the delay value from configuration entity.
                    std::this_thread::sleep_for(std::chrono::seconds(Default::SimulationTimeCycleSeconds));
                }
            });
    }

    void TemperatureSimulator::Stop() noexcept
    {
        _isStopEvent = true;
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS