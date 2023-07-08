/**********************************************************************
 * @file IApplianceFactory.hpp
 *
 * @brief Provides abstract factory to create concrete class instances all the appliances.
 *
 *********************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_FACTORIES_IAPPLIANCEFACTORYT_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_FACTORIES_IAPPLIANCEFACTORYT_HPP

#include "CommonConfig.hpp"

#include "Interfaces/IAppliance.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace FactoryInterfaces
{
    /**
     * @interface IApplianceFactory
     *
     * @brief Factory interface for concrete classes that implements @ref IApplianceFactory.
     */
    interface IApplianceFactory
    {
        DECLARE_INTERFACE_DEFAULTS(IApplianceFactory)

        /**
         * @brief Pointer to the interface that is the output of the factory.
         */
        using InterfaceSharedPointer = std::shared_ptr<Interfaces::IAppliance>;

        /**
         * @brief Create a concrete instance surfaced as pointer to its interfaces.
         *
         * @param[out] objectPtr pointer to the concrete class object referred through interface.
         */
        virtual void CreateCooler(InterfaceSharedPointer &objectPtr) = 0;

        /**
         * @brief Create a concrete instance surfaced as pointer to its interfaces.
         *
         * @param[out] objectPtr pointer to the concrete class object referred through interface.
         */
        virtual void CreateHeater(InterfaceSharedPointer &objectPtr) = 0;
    };
} // namespace FactoryInterfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // _TEMPERATURE_CONTROLLER_INTERFACES_FACTORIES_IAPPLIANCEFACTORYT_HPP
