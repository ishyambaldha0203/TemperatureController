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
     * @brief Concrete implementation of temperature manager.
     */
    class DisplayManager : public Interfaces::IDisplayManager
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new temperature manager object.
         */
        DisplayManager();

        /**
         * @brief Destroy the temperature manager object.
         */
        virtual ~DisplayManager() override;

        // #endregion

        // #region IDisplayManager Implementation

        virtual void PopulateText(const std::string& data) override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(DisplayManager)
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_DISPLAYMANAGER_HPP
