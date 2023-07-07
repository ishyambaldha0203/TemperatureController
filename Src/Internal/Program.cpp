/*************************************************************************************************
 * @file Program.cpp
 *
 * @brief Concrete implementation of @ref Program class.
 *
 * It handles  Temperature Monitoring application's start-up rituals.
 *
 *************************************************************************************************/

#include "Internal/Program.hpp"

#include "Exceptions/XArgumentNull.hpp"
#include "Exceptions/XBaseException.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;
using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    Program::Program(std::shared_ptr<ISessionManager> sessionManager)
        : _sessionManager(sessionManager)
    {
        if (nullptr == _sessionManager)
        {
            throw XArgumentNull("Program::sessionManager");
        }
    }

    Program::~Program() = default;

    // #endregion

    // #region Public Methods

    int32_t Program::Run()
    {
        try
        {
            _sessionManager->Begin();
        }
        catch (const XBaseException &ex)
        {
            std::cout << "Exception caught: " << ex.what() << std::endl;

            return -1;
        }

        return 0;
    }

    // #endregion

} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS