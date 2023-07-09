/*************************************************************************************************
 * @file SystemConfigProcessor.cpp
 *
 * @brief Concrete implementation of @ref SystemConfigProcessor class.
 *
 * To prepare data entity/struct from provided input settings.
 *
 *************************************************************************************************/

#include "Internal/SystemConfigProcessor.hpp"

#include "Interfaces/Entities/ISystemConfigMutable.hpp"

#include "Exceptions/XArgumentNull.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::EntityInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::FactoryInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

namespace
{
    namespace Default
    {
        constexpr const float MinTemperature = 20.0f;            ///< Min temperature to start heater.
        constexpr const float MaxTemperature = 21.0f;            ///< Max temperature to start cooler.
        constexpr const float CoolingIntensity = 0.10f;          ///< Temperature lowered by heater per simulation cycle.
        constexpr const float HeatingIntensity = 0.10f;          ///< Temperature raised by heater per simulation cycle.
        constexpr const float SimulationIntensity = 0.5f;        ///< Used by simulator to generate random temperature between -0.5f to +0.5f.
        constexpr const uint32_t SimulationTimeCycleSeconds = 1; ///< Timing to be used bu simulator to update temperature.
        constexpr const uint32_t SensorTimeCycleSeconds = 1;     ///< Timing to be used by sensor to read the temperature.
    }
}

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    SystemConfigProcessor::SystemConfigProcessor(std::shared_ptr<ISystemConfigFactory> configFactory)
        : _configFactory(configFactory)
    {
        if (nullptr == _configFactory)
        {
            throw XArgumentNull("SystemConfigProcessor::configFactory");
        }
    }

    SystemConfigProcessor::~SystemConfigProcessor() = default;

    // #endregion

    // #region Public Methods

    std::shared_ptr<ISystemConfig> SystemConfigProcessor::PrepareConfig(const std::string &input)
    {
        if (input.empty())
        {
            throw XInvalidArgument("SystemConfigProcessor::PrepareConfig::input is empty string.");
        }

        // TODO: Validate input, including data format.

        // TODO: De-serialize input data.

        // Create the instance of system config.
        std::shared_ptr<ISystemConfig> systemConfig;
        _configFactory->Create(systemConfig);

        // Cast to mutable entity to update the elements of entity.
        std::shared_ptr<ISystemConfigMutable> systemConfigMutable =
            std::static_pointer_cast<ISystemConfigMutable>(systemConfig);

        // Set default config value.
        systemConfigMutable->SetMinTemperatureRange(Default::MinTemperature);
        systemConfigMutable->SetMaxTemperatureRange(Default::MaxTemperature);
        systemConfigMutable->SetCoolingIntensity(Default::CoolingIntensity);
        systemConfigMutable->SetHeatingIntensity(Default::HeatingIntensity);
        systemConfigMutable->SetSimulationIntensity(Default::SimulationIntensity);

        return systemConfig;

        // #endregion
    }
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS