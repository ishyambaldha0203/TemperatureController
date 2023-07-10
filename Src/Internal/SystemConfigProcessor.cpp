/*************************************************************************************************
 * @file SystemConfigProcessor.cpp
 *
 * @brief Concrete implementation of @ref SystemConfigProcessor class.
 *
 * To prepare data entity/struct from provided input settings.
 *
 *************************************************************************************************/

#include "Internal/SystemConfigProcessor.hpp"

#include <fstream>
#include <unordered_map>

#include "Interfaces/Entities/ISystemConfigMutable.hpp"

#include "Exceptions/XArgumentNull.hpp"
#include "Exceptions/XConfigError.hpp"
#include "Exceptions/XFileNotFound.hpp"

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
        constexpr const char *ConfigFilePath = "config.txt";
    }

    namespace DataKeys
    {
        constexpr const char *MinimumTemperature = "MinimumTemperature";
        constexpr const char *MaximumTemperature = "MaximumTemperature";
    }
}

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    SystemConfigProcessor::SystemConfigProcessor(std::shared_ptr<ISystemConfigReader> configReader,
                                                 std::shared_ptr<ISystemConfigFactory> configFactory)
        : _configReader(configReader),
          _configFactory(configFactory)
    {
        if (nullptr == _configReader)
        {
            throw XArgumentNull("SystemConfigProcessor::configFactory");
        }

        if (nullptr == _configFactory)
        {
            throw XArgumentNull("SystemConfigProcessor::configFactory");
        }
    }

    SystemConfigProcessor::~SystemConfigProcessor() = default;

    // #endregion

    // #region Public Methods

    std::shared_ptr<ISystemConfig> SystemConfigProcessor::PrepareConfig()
    {
        // Create the instance of system config.
        std::shared_ptr<ISystemConfig> systemConfig;
        _configFactory->Create(systemConfig);

        // Cast to mutable entity to update the elements of entity.
        std::shared_ptr<ISystemConfigMutable> systemConfigMutable =
            std::static_pointer_cast<ISystemConfigMutable>(systemConfig);

        // Set default values.
        SetDefaultConfig(systemConfig);

        try
        {
            ISystemConfigReader::ConfigurationMap configMap =
                _configReader->ReadConfig(Default::ConfigFilePath);

            try
            {
                float maxTemp;
                float minTemp;

                for (auto &[key, value] : configMap)
                {
                    if (key == "MinimumTemperature")
                    {
                        minTemp = std::stof(value);
                    }
                    else if (key == "MaximumTemperature")
                    {
                        maxTemp = std::stof(value);
                    }
                    else
                    {
                        std::cerr << "[Error] Unexpected config key: " << key << std::endl;
                    }
                }

                if (minTemp >= maxTemp)
                {
                    throw XBaseException(std::string("Invalid temperature range is provide in config file -> ") + Default::ConfigFilePath);
                }

                systemConfigMutable->SetMinTemperatureRange(minTemp);
                systemConfigMutable->SetMaxTemperatureRange(maxTemp);
            }
            catch (const std::invalid_argument &ex)
            {
                throw XBaseException(std::string("Invalid config data value -> ") + ex.what());
            }
        }
        catch (const XFileNotFound &ex)
        {
            std::cerr << "[ERROR] File not found -> " << ex.what() << std::endl;
        }
        catch (const XConfigError &ex)
        {
            std::cerr << "[ERROR] Config file read error -> " << ex.what() << std::endl;
        }

        return systemConfig;
    }

    // #endregion

    // #region Private Methods

    void SystemConfigProcessor::SetDefaultConfig(std::shared_ptr<ISystemConfig> systemConfig)
    {
        // Cast to mutable entity to update the elements of entity.
        std::shared_ptr<ISystemConfigMutable> systemConfigMutable =
            std::static_pointer_cast<ISystemConfigMutable>(systemConfig);

        systemConfigMutable->SetMinTemperatureRange(Default::MinTemperature);
        systemConfigMutable->SetMaxTemperatureRange(Default::MaxTemperature);
        systemConfigMutable->SetCoolingIntensity(Default::CoolingIntensity);
        systemConfigMutable->SetHeatingIntensity(Default::HeatingIntensity);
        systemConfigMutable->SetSimulationIntensity(Default::SimulationIntensity);
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS