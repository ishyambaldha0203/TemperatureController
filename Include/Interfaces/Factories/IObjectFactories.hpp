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

#include "Interfaces/IProgram.hpp"
#include "Interfaces/ISessionManager.hpp"

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
     * @interface ISessionManagerFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ISessionManager.
     */
    using ISessionManagerFactory = IGenericObjectFactoryT<Interfaces::ISessionManager>;

    // #endregion

} // namespace FactoryInterfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_FACTORIES_IOBJECTFACTORIES_HPP
