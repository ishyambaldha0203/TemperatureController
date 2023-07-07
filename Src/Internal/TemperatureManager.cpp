/*************************************************************************************************
 * @file TemperatureManager.cpp
 *
 * @brief Concrete implementation of @ref TemperatureManager class.
 *
 *************************************************************************************************/

#include "Internal/TemperatureManager.hpp"

#include "Exceptions/XBaseException.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    TemperatureManager::TemperatureManager() = default;

    TemperatureManager::~TemperatureManager() = default;

    // #endregion

    // #region Public Methods

    void TemperatureManager::Begin()
    {
        std::cout << "Temperature monitoring and controlling has started !!!" << std::endl;
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS