/*************************************************************************************************
 * @file ObjectFactory.cpp
 *
 * @brief Concrete implementation of a common object factory.
 *
 * It manages creation and lifespan of all the higher level object of the Temperature Monitoring application.
 *
 *************************************************************************************************/

#include "Internal/ObjectFactory.hpp"

#include "Internal/Cooler.hpp"
#include "Internal/DisplayManager.hpp"
#include "Internal/Heater.hpp"
#include "Internal/Program.hpp"
#include "Internal/TemperatureManager.hpp"
#include "Internal/TemperatureSensor.hpp"
#include "Internal/TemperatureSimulator.hpp"
#include "Internal/Entities/SystemConfig.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::FactoryInterfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Entities;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    ObjectFactory::ObjectFactory() = default;

    ObjectFactory::~ObjectFactory() = default;

    // #endregion

    // #region Public Methods

    void ObjectFactory::Create(IDisplayManagerFactory::InterfaceSharedPointer &objectPtr)
    {
        objectPtr = std::make_shared<DisplayManager>();
    }

    void ObjectFactory::Create(IProgramFactory::InterfaceSharedPointer &objectPtr)
    {
        ITemperatureManagerFactory::InterfaceSharedPointer temperatureManager;
        Create(temperatureManager);

        objectPtr = std::make_shared<Program>(temperatureManager);
    }

    void ObjectFactory::Create(ITemperatureManagerFactory::InterfaceSharedPointer &objectPtr)
    {
        ITemperatureSensorFactory::InterfaceSharedPointer temperatureSensor;
        Create(temperatureSensor);

        ITemperatureSimulatorFactory::InterfaceSharedPointer temperatureSimulator;
        Create(temperatureSimulator);

        IApplianceFactory::InterfaceSharedPointer cooler;
        CreateCooler(cooler);

        IApplianceFactory::InterfaceSharedPointer heater;
        CreateHeater(heater);

        IDisplayManagerFactory::InterfaceSharedPointer displayManager;
        Create(displayManager);

        objectPtr = std::make_shared<TemperatureManager>(temperatureSensor, temperatureSimulator, cooler, heater, displayManager);
    }

    void ObjectFactory::Create(ITemperatureSensorFactory::InterfaceSharedPointer &objectPtr)
    {
        ITemperatureSimulatorFactory::InterfaceSharedPointer temperatureSimulator;
        Create(temperatureSimulator);

        objectPtr = std::make_shared<TemperatureSensor>(temperatureSimulator);
    }

    void ObjectFactory::Create(ITemperatureSimulatorFactory::InterfaceSharedPointer &objectPtr)
    {
        if (nullptr == _temperatureSimulator)
        {
            ISystemConfigFactory::InterfaceSharedPointer systemConfig;
            Create(systemConfig);

            _temperatureSimulator = std::make_shared<TemperatureSimulator>(systemConfig);
        }

        objectPtr = _temperatureSimulator;
    }

    void ObjectFactory::Create(ISystemConfigFactory::InterfaceSharedPointer &objectPtr)
    {
        if (nullptr == _systemConfig)
        {
            _systemConfig = std::make_shared<SystemConfig>();
        }

        objectPtr = _systemConfig;
    }

    void ObjectFactory::CreateCooler(IApplianceFactory::InterfaceSharedPointer &objectPtr)
    {
        ISystemConfigFactory::InterfaceSharedPointer systemConfig;
        Create(systemConfig);

        objectPtr = std::make_shared<Cooler>(systemConfig);
    }

    void ObjectFactory::CreateHeater(IApplianceFactory::InterfaceSharedPointer &objectPtr)
    {
        ISystemConfigFactory::InterfaceSharedPointer systemConfig;
        Create(systemConfig);

        objectPtr = std::make_shared<Heater>(systemConfig);
    }

    // #endregion

    // #region Private Methods

    std::shared_ptr<ObjectFactory> ObjectFactory::Self()
    {
        return std::enable_shared_from_this<ObjectFactory>::shared_from_this();
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS
