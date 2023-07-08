/*************************************************************************************************
 * @file DisplayManager.cpp
 *
 * @brief Concrete implementation of @ref DisplayManager class.
 *
 *************************************************************************************************/

#include "Internal/DisplayManager.hpp"

#include "Exceptions/XBaseException.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    DisplayManager::DisplayManager() = default;

    DisplayManager::~DisplayManager() = default;

    // #endregion

    // #region Public Methods

    void DisplayManager::PopulateText(const std::string& data)
    {
        std::cout << data << std::flush;
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS