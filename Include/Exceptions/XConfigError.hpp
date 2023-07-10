/*************************************************************************************************
 * @file XConfigError.hpp
 *
 * @brief A file contains concrete definition of XConfigError.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_EXCEPTIONS_XCONFIGERROR_HPP
#define _TEMPERATURE_CONTROLLER_EXCEPTIONS_XCONFIGERROR_HPP

#include "CommonConfig.hpp"

#include "Exceptions/XBaseException.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Exceptions
{
    /**
     * @class XConfigError
     *
     * @brief Exception for file operations.
     */
    class XConfigError : public XBaseException
    {
    public:
        /**
         * @brief Use the XBaseException c'tor
         */
        using XBaseException::XBaseException;
    };
} // namespace Exceptions
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_EXCEPTIONS_XCONFIGERROR_HPP