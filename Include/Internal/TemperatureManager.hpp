/*************************************************************************************************
 * @file TemperatureManager.hpp
 *
 * @brief Declarations for the concrete class @ref TemperatureManager.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREMANAGER_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREMANAGER_HPP

#include "CommonConfig.hpp"

#include <atomic>

#include "Interfaces/IAppliance.hpp"
#include "Interfaces/IDisplayManager.hpp"
#include "Interfaces/ITemperatureSensor.hpp"
#include "Interfaces/ITemperatureSimulator.hpp"
#include "Interfaces/ITemperatureManager.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class TemperatureManager
     *
     * @brief Concrete implementation of temperature manager.
     */
    class TemperatureManager : public Interfaces::ITemperatureManager
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new temperature manager object.
         */
        TemperatureManager(std::shared_ptr<Interfaces::ITemperatureSensor> temperatureSensor,
                           std::shared_ptr<Interfaces::ITemperatureSimulator> temperatureSimulator,
                           std::shared_ptr<Interfaces::IAppliance> cooler,
                           std::shared_ptr<Interfaces::IAppliance> heater,
                           std::shared_ptr<Interfaces::IDisplayManager> displayManager);

        /**
         * @brief Destroy the temperature manager object.
         */
        virtual ~TemperatureManager() override;

        // #endregion

        // #region ITemperatureManager Implementation

        virtual void Begin() override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(TemperatureManager)

        // #region Private Members

        /**
         * @brief temperature sensor to get registered for temperature change events.
         */
        std::shared_ptr<Interfaces::ITemperatureSensor> _temperatureSensor;

        /**
         * @brief Real time temperature simulator.
         */
        std::shared_ptr<Interfaces::ITemperatureSimulator> _temperatureSimulator;

        /**
         * @brief To reduce the temperature in case is goes out of upper range.
         */
        std::shared_ptr<Interfaces::IAppliance> _cooler;

        /**
         * @brief To increase the temperature if it goes out of lower range.
         */
        std::shared_ptr<Interfaces::IAppliance> _heater;

        /**
         * @brief The display manager to display temperature.
         */
        std::shared_ptr<Interfaces::IDisplayManager> _displayManager;

        /**
         * @brief A temperature to start with for simulator.
         */
        float _startingTemperature;

        /**
         * @brief Minimum temperature to monitor for.
         */
        float _minTemperature;

        /**
         * @brief Maximum temperature to monitor for.
         */
        float _maxTemperature;

        // #endregion

        // #region Private Methods

        /**
         * @brief Controls the temperature based on range.
         *
         * @param temperature A current temperature.
         */
        void ControlTemperature(float temperature);

        /**
         * @brief Display the current temperature with added colors.
         *
         * @param temperature A current temperature.
         */
        void DisplayTemperature(float temperature);

        /**
         * @brief Get called every time on temperature change event.
         *
         * @param temperature Updated temperature.
         */
        void TemperatureObserverCallback(float temperature);

        // #endregion
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREMANAGER_HPP
