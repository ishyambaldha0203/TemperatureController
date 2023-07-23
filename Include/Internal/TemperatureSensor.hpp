/*************************************************************************************************
 * @file TemperatureSensor.hpp
 *
 * @brief Declarations for the concrete class @ref RoomTemperatureSimulator.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATURESENSOR_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATURESENSOR_HPP

#include "CommonConfig.hpp"

#include <future>
#include <vector>

#include "Interfaces/ITemperatureSensor.hpp"
#include "Interfaces/ITemperatureSimulator.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class TemperatureSensor
     *
     * @brief Concrete implementation of temperature manager.
     */
    class TemperatureSensor : public Interfaces::ITemperatureSensor
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new temperature manager object.
         * 
         * @param temperatureSimulator 
         */
        explicit TemperatureSensor(std::shared_ptr<Interfaces::ITemperatureSimulator> temperatureSimulator);

        /**
         * @brief Destroy the temperature manager object.
         */
        virtual ~TemperatureSensor() override;

        // #endregion

        // #region ITemperatureSensor Implementation

        virtual void RegisterObservers(Internal::TemperatureChangeCallback callback) override;

        virtual void Start() override;

        virtual void Stop() override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(TemperatureSensor)

        // #region Private Members

        /**
         * @brief Real time temperature simulator.
         */
        std::shared_ptr<Interfaces::ITemperatureSimulator> _temperatureSimulator;

        /**
         * @brief Stop the manual simulation of room temperature.
         */
        bool _isStopEvent;

        /**
         * @brief List of observer for temperature change events.
         */
        std::vector<TemperatureChangeCallback> _observers;

        /**
         * @brief To keep alive the and running simulator in background.
         */
        std::future<void> _sensorFuture;

        // #endregion

        // #region Private Methods

        /**
         * @brief Notify all the registered observers.
         * 
         * @param temperature Updated temperature.
         */
        void NotifyObservers(float temperature);

        // #endregion
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATURESENSOR_HPP
