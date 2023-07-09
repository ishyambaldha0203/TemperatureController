/*************************************************************************************************
 * @file TemperatureManager.hpp
 *
 * @brief Declarations for the concrete class @ref TemperatureManager.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREMANAGER_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREMANAGER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/IDisplayManager.hpp"
#include "Interfaces/ISystemConfigProcessor.hpp"
#include "Interfaces/ITemperatureController.hpp"
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
         * @brief  Construct a new temperature manager object.
         * 
         * It is the main manager class of the application.
         * 
         * @param systemConfigProcessor 
         * @param temperatureSensor 
         * @param temperatureSimulator 
         * @param temperatureController 
         * @param displayManager 
         */
        TemperatureManager(std::shared_ptr<Interfaces::ISystemConfigProcessor> systemConfigProcessor,
                           std::shared_ptr<Interfaces::ITemperatureSensor> temperatureSensor,
                           std::shared_ptr<Interfaces::ITemperatureSimulator> temperatureSimulator,
                           std::shared_ptr<Interfaces::ITemperatureController> temperatureController,
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
         * @brief To process and prepare data entity from user provided system level configuration.
         */
        std::shared_ptr<Interfaces::ISystemConfigProcessor> _systemConfigProcessor;

        /**
         * @brief A temperature sensor to get registered for temperature change events.
         */
        std::shared_ptr<Interfaces::ITemperatureSensor> _temperatureSensor;

        /**
         * @brief Real time temperature simulator.
         */
        std::shared_ptr<Interfaces::ITemperatureSimulator> _temperatureSimulator;

        /**
         * @brief To regulate the temperature in a configured range.
         */
        std::shared_ptr<Interfaces::ITemperatureController> _temperatureController;

        /**
         * @brief The display manager to display temperature.
         */
        std::shared_ptr<Interfaces::IDisplayManager> _displayManager;

        // #endregion

        // #region Private Methods

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
