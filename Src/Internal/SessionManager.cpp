/*************************************************************************************************
 * @file SessionManager.cpp
 *
 * @brief Concrete implementation of @ref SessionManager class.
 *
 *************************************************************************************************/

#include "Internal/SessionManager.hpp"

#include "Exceptions/XBaseException.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    SessionManager::SessionManager() = default;

    SessionManager::~SessionManager() = default;

    // #endregion

    // #region Public Methods

    void SessionManager::Begin()
    {
        std::cout << "Temperature Monitor session started !!!" << std::endl;
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS