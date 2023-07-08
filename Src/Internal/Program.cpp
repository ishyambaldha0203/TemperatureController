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

    Program::Program(std::shared_ptr<ITemperatureManager> temperatureManager)
        : _temperatureManager(temperatureManager)
    {
        if (nullptr == _temperatureManager)
        {
            throw XArgumentNull("Program::temperatureManager");
        }
    }

    Program::~Program() = default;

    // #endregion

    // #region Public Methods

    int32_t Program::Run()
    {
        std::cout << "Temperature monitoring and controlling has started!!!\n\n" << std::endl;

        try
        {
            _temperatureManager->Begin();
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