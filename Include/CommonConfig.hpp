/*************************************************************************************************
 * @file CommonConfig.hpp
 *
 * @brief Build and configuration related common definitions.
 *
 *************************************************************************************************/
#ifndef _COMMON_CONFIG_HPP
#define _COMMON_CONFIG_HPP

#include <iostream>
#include <memory>

/**
 * @brief Begins the C++ namespace for Temperature Monitor application.
 *
 * @note It must be closed by the #END_TEMPERATURE_CONTROLLER_NS macro.
 *
 * The Temperature Monitor application code will be contained in this namespace or in nested namespaces.
 *
 * @see END_TEMPERATURE_CONTROLLER_NS
 */
#define BEGIN_TEMPERATURE_CONTROLLER_NS \
    namespace TemperatureController     \
    {

/**
 * @brief Ends the Temperature Monitor C++ namespace.
 *
 * @see BEGIN_TEMPERATURE_CONTROLLER_NS
 */
#define END_TEMPERATURE_CONTROLLER_NS \
    }

/**
 * @brief Defines the fully-qualified Temperature Monitor C++ namespace.
 *
 * Use this macro to reference the namespace in declarations.
 */
#define TEMPERATURE_CONTROLLER_NS TemperatureController

/**
 * @brief Simple convenience macro used to specifically semantically indicate declaration of an
 * abstract C++ interface.
 */
#define interface class

/**
 * @brief Convenience macro used to declare default constructs for purely abstract interface
 * declarations.
 *
 * This macro should be used at the top of an interface declaration.
 *
 * @param[in] interfaceName The name of the interface class being declared.
 */
#define DECLARE_INTERFACE_DEFAULTS(interfaceName) \
protected:                                        \
    /* ensures derivation */                      \
    interfaceName() = default;                    \
                                                  \
public:                                           \
    /* allows deletion via interface */           \
    virtual ~interfaceName() = default;

/**
 * @brief Convenience macro used to declare constructs to render a class safely uncopyable.
 *
 * This macro should be used at the top of the private section in a class declaration. It can also
 * be used to introduce the private section in a class declaration.
 *
 * @param[in] className The name of the class being declared.
 */
#define DECLARE_NON_COPYABLE_CLASS(className) \
private:                                      \
    /* remove copy ctor */                    \
    className(const className &) = delete;    \
    /* remove copy-assignment operator */     \
    className &operator=(const className &) = delete;

#endif // !_COMMON_CONFIG_HPP