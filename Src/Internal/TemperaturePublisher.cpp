/*************************************************************************************************
 * @file TemperaturePublisher.cpp
 *
 * @brief Concrete implementation of @ref TemperaturePublisher class.
 *
 *************************************************************************************************/

#include "Internal/SimulatedTemperaturePublisher.hpp"

#include "Exceptions/XBaseException.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::Exceptions;
using namespace TEMPERATURE_CONTROLLER_NS::Interfaces;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    TemperaturePublisher::TemperaturePublisher() = default;

    TemperaturePublisher::~TemperaturePublisher() = default;

    // #endregion

    // #region Public Methods

    void TemperaturePublisher::Register(std::shared_ptr<Interfaces::ITemperatureObserver> observer)
    {
        _observers.push_back(observer);
    }

    void TemperaturePublisher::Unregister(std::shared_ptr<Interfaces::ITemperatureObserver> observer)
    {
        _observers.remove(observer);
    }

    void TemperaturePublisher::Notify(int32_t temperature)
    {
        std::list<std::shared_ptr<ITemperatureObserver>>::iterator it;

        for (it = _observers.begin(); it != _observers.end(); ++it)
        {
            (*it)->OnUpdate(temperature);
        }

        // #endregion
    }
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS