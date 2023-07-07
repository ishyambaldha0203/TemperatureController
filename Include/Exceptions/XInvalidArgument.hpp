/**
 * @file XInvalidArgument.hpp
 * @brief Contains the definition for a general InvalidArgument exception
 *
 */
#ifndef _TEMPERATURE_CONTROLLER_XINVALIDARGUMENT_HPP
#define _TEMPERATURE_CONTROLLER_XINVALIDARGUMENT_HPP

#include "CommonConfig.hpp"

#include <stdexcept>

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Exceptions
{
    /**
     * @brief Exception thrown for invalid arguments passed to an Lwa library function.
     *
     * This class serves as the base class for all argument-related exception types. Code should throw one
     * of the derived specific invalid-argument-related exception types.
     */
    class XInvalidArgument : public std::invalid_argument
    {
        // Internal Aliases
        using Base = std::invalid_argument;
        using Self = XInvalidArgument;

    public:
        /**
         * @brief Construct a new XInvalidArgument object
         *
         * @param details
         */
        XInvalidArgument(const std::string &details) : Base(details)
        {
            // Do nothing.
        }

        /**
         * @brief Construct a new XInvalidArgument object
         *
         * @param other
         */
        XInvalidArgument(const Self &other) noexcept : Base(other)
        {
            // Do nothing.
        }

        /**
         * @brief Overloaded assignment operator.
         *
         * @param other
         * @return Self&
         */
        Self &operator=(const Self &other) noexcept
        {
            Base::operator=(other);
            return *this;
        }
    };
} // namespace Exceptions
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_XINVALIDARGUMENT_HPP
