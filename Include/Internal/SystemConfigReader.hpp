/*************************************************************************************************
 * @file SystemConfigReader.hpp
 *
 * @brief Declarations for the concrete class @ref SystemConfigReader.
 *
 *************************************************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_INTERFACES_SYSTEMCONFIGREADER_HPP
#define _TEMPERATURE_CONTROLLER_INTERFACES_SYSTEMCONFIGREADER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/ISystemConfigReader.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    /**
     * @class SystemConfigReader
     *
     * @brief Concrete implementation to read system level setting.
     */
    class SystemConfigReader : public Interfaces::ISystemConfigReader
    {
    public:
        // #region Type Aliases

        using ConfigurationMap = ISystemConfigReader::ConfigurationMap;

        // #endregion

        // #region Construction/Destruction

        /**
         * @brief Construct a new system config processor object.
         */
        SystemConfigReader();

        /**
         * @brief Destroy the system config processor object.
         */
        virtual ~SystemConfigReader() override;

        // #endregion

        // #region ISystemConfigReader Implementation

        virtual ConfigurationMap ReadConfig(const std::string &confFileName) override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(SystemConfigReader)
    };
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_INTERFACES_SYSTEMCONFIGREADER_HPP
