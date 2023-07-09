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
        constexpr const float MinTemperature = 20;
        constexpr const float MaxTemperature = 24;
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

        return systemConfig;

        // #endregion
    }
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS