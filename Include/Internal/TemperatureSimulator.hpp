/*************************************************************************************************
 * @file TemperatureSimulator.hpp
 *
 * @brief Declarations for the concrete class @ref TemperatureSimulator.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATURESIMULATOR_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATURESIMULATOR_HPP

#include "CommonConfig.hpp"

#include <atomic>
#include <future>

#include "Interfaces/ITemperatureSimulator.hpp"
#include "Interfaces/Entities/ISystemConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class TemperatureSimulator
     *
     * @brief Concrete implementation of temperature simulator.
     */
    class TemperatureSimulator : public Interfaces::ITemperatureSimulator
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new temperature simulator object.
         */
        TemperatureSimulator(std::shared_ptr<EntityInterfaces::ISystemConfig> systemConfig);

        /**
         * @brief Destroy the temperature simulator object.
         */
        virtual ~TemperatureSimulator() override;

        // #endregion

        // #region ITemperatureSimulator Implementation

        virtual float GetTemperature() const override;

        virtual void Start(float startingTemperature) override;

        virtual void Stop() override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(TemperatureSimulator)

        /**
         * @brief To access system level configuration data.
         */
        std::shared_ptr<EntityInterfaces::ISystemConfig> _systemConfig;

        /**
         * @brief Stop the manual simulation of room temperature.
         */
        bool _isStopEvent;

        /**
         * @brief Hold real time current temperature value.
         */
        std::atomic<float> _currentTemperature;

        /**
         * @brief To keep alive the and running simulator in background.
         */
        std::future<void> _simulatorFuture;
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATURESIMULATOR_HPP
