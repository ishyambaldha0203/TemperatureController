/*************************************************************************************************
 * @file CallbackTypes.hpp
 *
 * @brief Type declarations for a temperature change callback function.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_CALLBACKTYPES_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_CALLBACKTYPES_HPP

#include "CommonConfig.hpp"

#include <functional>

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    using TemperatureChangeCallback = std::function<void(float)>;
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_CALLBACKTYPES_HPP