/*************************************************************************************************
 * @file Program.hpp
 *
 * @brief Declarations for the concrete class @ref Program.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_PROGRAM_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_PROGRAM_HPP

#include "CommonConfig.hpp"

#include "Interfaces/IProgram.hpp"
#include "Interfaces/ISessionManager.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class Program
     *
     * @brief Concrete implementation of application start-up class Program.
     */
    class Program : public Interfaces::IProgram
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new Program object.
         *
         * @param[in] sessionManager A reference of test session object.
         *
         * @throw XArgumentNull If input params are null.
         */
        Program(std::shared_ptr<Interfaces::ISessionManager> sessionManager);

        /**
         * @brief Destroy the Program object.
         */
        virtual ~Program() override;

        // #endregion

        // #region IProgram Implementation

        virtual int32_t Run() override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(Program)

        // #region Private Members

        /**
         * @brief A session manager object to manage end-to-end processing of test flow.
         */
        std::shared_ptr<Interfaces::ISessionManager> _sessionManager;

        // #endregion
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_PROGRAM_HPP
