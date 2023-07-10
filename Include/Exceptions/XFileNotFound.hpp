/*************************************************************************************************
 * @file XFileNotFound.hpp
 *
 * @brief A file contains concrete definition of XFileNotFound.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_EXCEPTIONS_XFILENOTFOUND_HPP
#define _TEMPERATURE_CONTROLLER_EXCEPTIONS_XFILENOTFOUND_HPP

#include "CommonConfig.hpp"

#include "Exceptions/XBaseException.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Exceptions
{
    /**
     * @class XFileNotFound
     *
     * @brief Exception for file operations.
     */
    class XFileNotFound : public XBaseException
    {
    public:
        /**
         * @brief Use the XBaseException c'tor
         */
        using XBaseException::XBaseException;
    };
} // namespace Exceptions
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_EXCEPTIONS_XFILENOTFOUND_HPP