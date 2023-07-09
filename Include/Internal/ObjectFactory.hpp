/*************************************************************************************************
 * @file ObjectFactory.hpp
 *
 * @brief Declarations for the concrete class @ref ObjectFactory.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_OBJECTFACTORY_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_OBJECTFACTORY_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Factories/IApplianceFactory.hpp"
#include "Interfaces/Factories/IObjectFactories.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class ObjectFactory
     *
     * @brief Concrete implementation of main object factory.
     */
    class ObjectFactory : public FactoryInterfaces::IApplianceFactory,
                          public FactoryInterfaces::IDisplayManagerFactory,
                          public FactoryInterfaces::IProgramFactory,
                          public FactoryInterfaces::ISystemConfigProcessorFactory,
                          public FactoryInterfaces::ITemperatureControllerFactory,
                          public FactoryInterfaces::ITemperatureManagerFactory,
                          public FactoryInterfaces::ITemperatureSensorFactory,
                          public FactoryInterfaces::ITemperatureSimulatorFactory,
                          public FactoryInterfaces::IApplianceConfigFactory,
                          public FactoryInterfaces::ISystemConfigFactory,
                          public std::enable_shared_from_this<ObjectFactory>
    {
        // #region Type Aliases

        using ApplianceFactoryInterfacePtr = FactoryInterfaces::IApplianceFactory::InterfaceSharedPointer;
        using DisplayManagerFactoryInterfacePtr = FactoryInterfaces::IDisplayManagerFactory::InterfaceSharedPointer;
        using ProgramFactoryInterfacePtr = FactoryInterfaces::IProgramFactory::InterfaceSharedPointer;
        using ISystemConfigProcessorFactoryInterfacePtr = FactoryInterfaces::ISystemConfigProcessorFactory::InterfaceSharedPointer;
        using TemperatureControllerFactoryInterfacePtr = FactoryInterfaces::ITemperatureControllerFactory::InterfaceSharedPointer;
        using TemperatureManagerFactoryInterfacePtr = FactoryInterfaces::ITemperatureManagerFactory::InterfaceSharedPointer;
        using TemperatureSensorFactoryInterfacePtr = FactoryInterfaces::ITemperatureSensorFactory::InterfaceSharedPointer;
        using TemperatureSimulatorFactoryInterfacePtr = FactoryInterfaces::ITemperatureSimulatorFactory::InterfaceSharedPointer;
        using ApplianceConfigFactoryInterfacePtr = FactoryInterfaces::IApplianceConfigFactory::InterfaceSharedPointer;
        using SystemConfigFactoryInterfacePtr = FactoryInterfaces::ISystemConfigFactory::InterfaceSharedPointer;

        // #endregion

    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new Factory object
         */
        ObjectFactory();

        /**
         * @brief Destroy the Object Factory object
         */
        virtual ~ObjectFactory() override;

        // #endregion

        // #region Implementation of Factories

        virtual void Create(DisplayManagerFactoryInterfacePtr &objectPtr) override;
        virtual void Create(ProgramFactoryInterfacePtr &objectPtr) override;
        virtual void Create(ISystemConfigProcessorFactoryInterfacePtr &objectPtr) override;
        virtual void Create(TemperatureControllerFactoryInterfacePtr &objectPtr) override;
        virtual void Create(TemperatureManagerFactoryInterfacePtr &objectPtr) override;
        virtual void Create(TemperatureSensorFactoryInterfacePtr &objectPtr) override;
        virtual void Create(TemperatureSimulatorFactoryInterfacePtr &objectPtr) override;
        virtual void Create(ApplianceConfigFactoryInterfacePtr &objectPtr) override;
        virtual void Create(SystemConfigFactoryInterfacePtr &objectPtr) override;
        virtual void CreateCooler(ApplianceFactoryInterfacePtr &objectPtr) override;
        virtual void CreateHeater(ApplianceFactoryInterfacePtr &objectPtr) override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(ObjectFactory)

        // #region Private Members

        /**
         * @brief To create singleton instance of appliance config.
         */
        std::shared_ptr<EntityInterfaces::IApplianceConfig> _applianceConfig;

        /**
         * @brief To create singleton instance of system config.
         */
        std::shared_ptr<EntityInterfaces::ISystemConfig> _systemConfig;

        /**
         * @brief To create singleton instance of temperature simulator.
         */
        std::shared_ptr<Interfaces::ITemperatureSimulator> _temperatureSimulator;

        /**
         * @brief This is to inject the common factory through constructor of all the other required classes.
         *
         * @return The shared pointer of ObjectFactory itself.
         */
        std::shared_ptr<ObjectFactory> Self();

        // #endregion
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_OBJECTFACTORY_HPP
