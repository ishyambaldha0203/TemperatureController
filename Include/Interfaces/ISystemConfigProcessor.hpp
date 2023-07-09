/*************************************************************************************************
 * @file ISystemConfigProcessor.hpp
 *
 * @brief Interface to define member contracts to process and prepare entity for system level settings.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_ISYSTEMCONFIGPROCESSOR_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_ISYSTEMCONFIGPROCESSOR_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ISystemConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Interfaces
{
    /**
     * @interface ISystemConfigProcessor
     *
     * @brief Interface to define member contracts and operations to process system level settings.
     */
    interface ISystemConfigProcessor
    {
        DECLARE_INTERFACE_DEFAULTS(ISystemConfigProcessor)

        /**
         * @brief Process the setting data and prepare data entity.
         *
         * @todo At the moment, I am considering that system configuration is provided as stringified data.
         * It could be anything, JSON, XML etc. So we need to parse it accordingly.
         *
         * @param[in] input An input payload used to prepare a data entity.
         *
         * @return A data entity.
         *
         * @throw XInvalidArgument If input is empty.
         */
        virtual std::shared_ptr<EntityInterfaces::ISystemConfig> PrepareConfig(const std::string &input) = 0;
    };
} // namespace Interfaces
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_ISYSTEMCONFIGPROCESSOR_HPP