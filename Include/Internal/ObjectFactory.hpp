/*************************************************************************************************
 * @file ObjectFactory.hpp
 *
 * @brief Declarations for the concrete class @ref ObjectFactory.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_OBJECTFACTORY_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_OBJECTFACTORY_HPP

#include "CommonConfig.hpp"

#include <memory>

#include "Interfaces/Factories/IObjectFactories.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class ObjectFactory
     *
     * @brief Concrete implementation main object factory.
     */
    class ObjectFactory : public FactoryInterfaces::IProgramFactory,
                          public FactoryInterfaces::ISessionManagerFactory,
                          public  std::enable_shared_from_this<ObjectFactory>
    {
        // #region Type Aliases

        using ProgramFactoryInterfacePtr = FactoryInterfaces::IProgramFactory::InterfaceSharedPointer;
        using SessionManagerFactoryInterfacePtr = FactoryInterfaces::ISessionManagerFactory::InterfaceSharedPointer;

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

        virtual void Create(ProgramFactoryInterfacePtr& objectPtr) override;
        virtual void Create(SessionManagerFactoryInterfacePtr& objectPtr) override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(ObjectFactory)

        // #region Private Members

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
