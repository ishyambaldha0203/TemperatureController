/*************************************************************************************************
 * @file IObjectFactories.hpp
 *
 * @brief Provides abstract factory for all the classes to create a concrete class instance.
 *
 *************************************************************************************************/

#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_FACTORIES_IOBJECTFACTORIES_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_FACTORIES_IOBJECTFACTORIES_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Factories/IGenericObjectFactoryT.hpp"

#include "Interfaces/IDisplayManager.hpp"
#include "Interfaces/IProgram.hpp"
#include "Interfaces/ISystemConfigProcessor.hpp"
#include "Interfaces/ISystemConfigReader.hpp"
#include "Interfaces/ITemperatureController.hpp"
#include "Interfaces/ITemperatureManager.hpp"
#include "Interfaces/ITemperatureSensor.hpp"
#include "Interfaces/ITemperatureSimulator.hpp"

#include "Interfaces/Entities/IApplianceConfig.hpp"
#include "Interfaces/Entities/ISystemConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace FactoryInterfaces
{
    // #region Functional Classes Factories

    /**
     * @interface IProgramFactory
     *
     * @brief Factory interface for concrete classes that implements @ref IProgram.
     */
    using IProgramFactory = IGenericObjectFactoryT<Interfaces::IProgram>;

    /**
     * @interface ISystemConfigProcessorFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ISystemConfigProcessor.
     */
    using ISystemConfigProcessorFactory = IGenericObjectFactoryT<Interfaces::ISystemConfigProcessor>;

    /**
     * @interface ISystemConfigReaderFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ISystemConfigReader.
     */
    using ISystemConfigReaderFactory = IGenericObjectFactoryT<Interfaces::ISystemConfigReader>;

    /**
     * @interface ITemperatureControllerFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ITemperatureController.
     */
    using ITemperatureControllerFactory = IGenericObjectFactoryT<Interfaces::ITemperatureController>;

    /**
     * @interface ITemperatureManagerFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ITemperatureManager.
     */
    using ITemperatureManagerFactory = IGenericObjectFactoryT<Interfaces::ITemperatureManager>;

    /**
     * @interface IDisplayManagerFactory
     *
     * @brief Factory interface for concrete classes that implements @ref IDisplayManager.
     */
    using IDisplayManagerFactory = IGenericObjectFactoryT<Interfaces::IDisplayManager>;

    /**
     * @interface ITemperatureSensorFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ITemperatureSensor.
     */
    using ITemperatureSensorFactory = IGenericObjectFactoryT<Interfaces::ITemperatureSensor>;

    /**
     * @interface ITemperatureSimulatorFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ITemperatureSimulator.
     */
    using ITemperatureSimulatorFactory = IGenericObjectFactoryT<Interfaces::ITemperatureSimulator>;

    /**
     * @interface IApplianceConfigFactory
     *
     * @brief Factory interface for concrete classes that implements @ref IApplianceConfig.
     */
    using IApplianceConfigFactory = IGenericObjectFactoryT<EntityInterfaces::IApplianceConfig>;

    /**
     * @interface ISystemConfigFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ISystemConfig.
     */
    using ISystemConfigFactory = IGenericObjectFactoryT<EntityInterfaces::ISystemConfig>;

    // #endregion

} // namespace FactoryInterfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_FACTORIES_IOBJECTFACTORIES_HPP
