/*************************************************************************************************
 * @file ISessionManager.hpp
 *
 * @brief Interface to define member contracts to manage a temperature monitor sessions.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ISESSIONMANAGER_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ISESSIONMANAGER_HPP

#include "CommonConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface ISessionManager
     *
     * @brief Interface to define member contracts and operations to manage a unique session.
     */
    interface ISessionManager
    {
        DECLARE_INTERFACE_DEFAULTS(ISessionManager)

        /**
         * @brief Begin temperature monitor session.
         *
         * @throw TBD
         */
        virtual void Begin() = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ISESSIONMANAGER_HPP