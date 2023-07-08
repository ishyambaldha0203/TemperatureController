/*************************************************************************************************
 * @file ITemperaturePublisher.hpp
 *
 * @brief Interface to define member contracts of temperature publishers.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATUREPUBLISHER_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATUREPUBLISHER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/ITemperatureObserver.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface ITemperaturePublisher
     *
     * @brief Interface used by the owner of a topic to notify subscribers.
     */
    interface ITemperaturePublisher
    {
        DECLARE_INTERFACE_DEFAULTS(ITemperaturePublisher)

        /**
         * @brief Use this function as an Observer to receive notifications of this topic
         *
         * @param observer A Object implementing the @ref ITemperatureObserver that will be receive notification on update.
         */
        virtual void Register(std::shared_ptr<ITemperatureObserver> observer) = 0;

        /**
         * @brief Use this function to remove an already registered Observer to not receive
         *
         * @param observer A Object implementing the @ref ITemperatureObserver that will be receive notification on update.
         */
        virtual void Unregister(std::shared_ptr<ITemperatureObserver> observer) = 0;

        /**
         * @brief Notify all the subscriber with the updated temperature value.
         *
         * @note the a Copy of the message will be passed to each subscriber.
         *
         * @param temperature Value to pass to the subscribers.
         */
        virtual void Notify(int32_t temperature) = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // _TEMPERATURE_CONTROLLER_INTERFACES_ITEMPERATUREPUBLISHER_HPP
