/*************************************************************************************************
 * @file TemperaturePublisher.hpp
 *
 * @brief Declarations for the concrete class @ref TemperaturePublisher.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREPUBLISHER_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREPUBLISHER_HPP

#include "CommonConfig.hpp"

#include <list>

#include "Interfaces/ITemperaturePublisher.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class TemperaturePublisher
     *
     * @brief Concrete implementation for simulated temperature publisher.
     */
    class TemperaturePublisher : public Interfaces::ITemperaturePublisher
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new temperature manager object.
         */
        TemperaturePublisher();

        /**
         * @brief Destroy the temperature manager object.
         */
        virtual ~TemperaturePublisher() override;

        // #endregion

        // #region ITemperaturePublisher Implementation

        virtual void Register(std::shared_ptr<Interfaces::ITemperatureObserver> observer) override;

        virtual void Unregister(std::shared_ptr<Interfaces::ITemperatureObserver> observer) override;

        virtual void Notify(int32_t temperature) override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(TemperaturePublisher)

        /**
         * @brief Observers subscribed for simulated temperature change.
         */
        std::list<std::shared_ptr<Interfaces::ITemperatureObserver>> _observers;
    };

    // #endregion Implementation
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREPUBLISHER_HPP
