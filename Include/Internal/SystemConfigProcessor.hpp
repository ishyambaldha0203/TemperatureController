/*************************************************************************************************
 * @file SystemConfigProcessor.hpp
 *
 * @brief Declarations for the concrete class @ref SystemConfigProcessor.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERNAL_SYSTEMCONFIGPROCESSOR_HPP
#define _TEMPERATURE_CONTROLLER_INTERNAL_SYSTEMCONFIGPROCESSOR_HPP

#include "CommonConfig.hpp"

#include "Interfaces/ISystemConfigProcessor.hpp"
#include "Interfaces/Factories/IObjectFactories.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class SystemConfigProcessor
     *
     * @brief Concrete implementation of system setting level setting.
     */
    class SystemConfigProcessor : public Interfaces::ISystemConfigProcessor
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new system config processor object.
         *
         * @param[in] configFactory A factory to create system config data entity from provided input payload.
         *
         * @throw XArgumentNull If input params are null.
         */
        SystemConfigProcessor(std::shared_ptr<FactoryInterfaces::ISystemConfigFactory> configFactory);

        /**
         * @brief Destroy the system config processor object.
         */
        virtual ~SystemConfigProcessor() override;

        // #endregion

        // #region ISystemConfigProcessor Implementation

        virtual std::shared_ptr<EntityInterfaces::ISystemConfig> PrepareConfig(const std::string &input) override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(SystemConfigProcessor)

        // #region Private Members

        /**
         * @brief Factory to create system config data entity after deserialization of input data.
         */
        std::shared_ptr<FactoryInterfaces::ISystemConfigFactory> _configFactory;

        // #endregion
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_SYSTEMCONFIGPROCESSOR_HPP
