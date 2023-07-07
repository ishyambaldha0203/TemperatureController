/*************************************************************************************************
 * @file SessionManager.hpp
 *
 * @brief Declarations for the concrete class @ref SessionManager.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_SESSIONMANAGER_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_SESSIONMANAGER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/ISessionManager.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class SessionManager
     *
     * @brief Concrete implementation of session manager.
     */
    class SessionManager : public Interfaces::ISessionManager
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new Session Manager object
         */
        SessionManager();

        /**
         * @brief Destroy the Session Manager object
         */
        virtual ~SessionManager() override;

        // #endregion

        // #region ISessionManager Implementation

        virtual void Begin() override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(SessionManager)
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_SESSIONMANAGER_HPP
