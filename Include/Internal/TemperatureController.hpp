/*************************************************************************************************
 * @file TemperatureController.hpp
 *
 * @brief Declarations for the concrete class @ref TemperatureController.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATURECONTROLLER_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATURECONTROLLER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/IAppliance.hpp"
#include "Interfaces/ITemperatureController.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class TemperatureController
     *
     * @brief Concrete implementation of temperature controller.
     */
    class TemperatureController : public Interfaces::ITemperatureController
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new temperature controller object.
         *
         * @param cooler
         * @param heater
         */
        TemperatureController(std::shared_ptr<Interfaces::IAppliance> cooler,
                              std::shared_ptr<Interfaces::IAppliance> heater);

        /**
         * @brief Destroy the temperature controller object.
         */
        virtual ~TemperatureController() override;

        // #endregion

        // #region ITemperatureController Implementation

        virtual void Initialize(const EntityInterfaces::ISystemConfig &systemConfig) override;

        virtual void RegulateTemperature(float currentTemperature) override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(TemperatureController)

        /**
         * @brief To reduce the temperature in case is goes out of upper range.
         */
        std::shared_ptr<Interfaces::IAppliance> _cooler;

        /**
         * @brief To increase the temperature if it goes out of lower range.
         */
        std::shared_ptr<Interfaces::IAppliance> _heater;

        /**
         * @brief Minimum temperature to monitor for.
         */
        float _minTemperature;

        /**
         * @brief Maximum temperature to monitor for.
         */
        float _maxTemperature;
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATURECONTROLLER_HPP
