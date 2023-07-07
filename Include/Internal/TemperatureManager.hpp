/*************************************************************************************************
 * @file TemperatureManager.hpp
 *
 * @brief Declarations for the concrete class @ref TemperatureManager.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREMANAGER_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREMANAGER_HPP

#include "CommonConfig.hpp"

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
        TemperatureManager();

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
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_TEMPERATUREMANAGER_HPP
