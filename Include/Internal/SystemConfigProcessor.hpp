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
#include "Interfaces/ISystemConfigReader.hpp"
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
         * @param[in] configReader To read the configuration from file.
         * @param[in] configFactory A factory to create system config data entity from provided input payload.
         *
         * @throw XArgumentNull If input params are null.
         */
        SystemConfigProcessor(std::shared_ptr<Interfaces::ISystemConfigReader> configReader,
                              std::shared_ptr<FactoryInterfaces::ISystemConfigFactory> configFactory);

        /**
         * @brief Destroy the system config processor object.
         */
        virtual ~SystemConfigProcessor() override;

        // #endregion

        // #region ISystemConfigProcessor Implementation

        virtual std::shared_ptr<EntityInterfaces::ISystemConfig> PrepareConfig() override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(SystemConfigProcessor)

        // #region Private Members

        /**
         * @brief To read the system configuration from file.
         */
        std::shared_ptr<Interfaces::ISystemConfigReader> _configReader;

        /**
         * @brief Factory to create system config data entity after deserialization of input data.
         */
        std::shared_ptr<FactoryInterfaces::ISystemConfigFactory> _configFactory;

        // #endregion

        /**
         * @brief Set the system configuration to default values.
         *
         * @param[in] systemConfig System configuration instance to set with.
         */
        void SetDefaultConfig(std::shared_ptr<EntityInterfaces::ISystemConfig> systemConfig);
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERNAL_SYSTEMCONFIGPROCESSOR_HPP
