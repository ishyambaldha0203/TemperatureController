/**********************************************************************
 * @file SystemConfigReaderMock.hpp
 *
 * @brief Declaration of mocked methods for class @ref  SystemConfigReader.
 *
 * It is required only for unit testing.
 *
 *********************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_SYSTEMCONFIGREADERMOCK_HPP
#define _TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_SYSTEMCONFIGREADERMOCK_HPP

#include "CommonTestsConfig.hpp"

#include "Interfaces/ISystemConfigReader.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Test
{
    /**
     * @class SystemConfigReaderMock
     *
     * @brief A mock class for @ref  SystemConfigReader.
     */
    class SystemConfigReaderMock : public Interfaces::ISystemConfigReader
    {
    public:
        MOCK_METHOD(Interfaces::ISystemConfigReader::ConfigurationMap, ReadConfig, (const std::string &confFileName), (override));
    };
} // namespace Test
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_SYSTEMCONFIGREADERMOCK_HPP
