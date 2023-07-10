/*************************************************************************************************
 * @file Program.hpp
 *
 * @brief Declarations for the concrete class @ref Program.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_PROGRAM_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_PROGRAM_HPP

#include "CommonConfig.hpp"

#include "Interfaces/IProgram.hpp"
#include "Interfaces/ITemperatureManager.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class Program
     *
     * @brief Concrete implementation of application start-up class Program.
     */
    class Program : public Interfaces::IProgram
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new Program object.
         *
         * @param[in] temperatureManager A reference of temperature manager object.
         *
         * @throw XArgumentNull If input params are null.
         */
        Program(std::shared_ptr<Interfaces::ITemperatureManager> temperatureManager);

        /**
         * @brief Destroy the Program object.
         */
        virtual ~Program() override;

        // #endregion

        // #region IProgram Implementation

        virtual int32_t Run() override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(Program)

        // #region Private Members

        /**
         * @brief A manager object to manage end-to-end monitoring and controlling the temperature.
         */
        std::shared_ptr<Interfaces::ITemperatureManager> _temperatureManager;

        // #endregion
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_PROGRAM_HPP
