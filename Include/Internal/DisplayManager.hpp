/*************************************************************************************************
 * @file DisplayManager.hpp
 *
 * @brief Declarations for the concrete class @ref DisplayManager.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_DISPLAYMANAGER_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_DISPLAYMANAGER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/IDisplayManager.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class DisplayManager
     *
     * @brief Concrete implementation of display manager.
     */
    class DisplayManager : public Interfaces::IDisplayManager
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new display manager object.
         */
        DisplayManager();

        /**
         * @brief Destroy the display manager object.
         */
        virtual ~DisplayManager() override;

        // #endregion

        // #region IDisplayManager Implementation

        virtual void DisplayTemperature(float temperature) override;

        virtual void Initialize(const EntityInterfaces::ISystemConfig &systemConfig) noexcept override;

        virtual void PopulateText(const std::string &data) noexcept override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(DisplayManager)

        /**
         * @brief Minimum temperature to check for.
         */
        float _minTemperature;

        /**
         * @brief Maximum temperature to check for.
         */
        float _maxTemperature;
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_DISPLAYMANAGER_HPP
