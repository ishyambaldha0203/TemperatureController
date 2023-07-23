/**********************************************************************
 * @file SystemConfigProcessorMock.hpp
 *
 * @brief Declaration of mocked methods for class @ref SystemConfigProcessor.
 *
 * It is required only for unit testing.
 *
 *********************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_SYSTEMCONFIGPROCESSORMOCK_HPP
#define _TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_SYSTEMCONFIGPROCESSORMOCK_HPP

#include "CommonTestsConfig.hpp"

#include "Interfaces/ISystemConfigProcessor.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Test
{
    /**
     * @class SystemConfigProcessorMock
     *
     * @brief A mock class for @ref  SystemConfigProcessor.
     */
    class SystemConfigProcessorMock : public Interfaces::ISystemConfigProcessor
    {
    public:
        MOCK_METHOD(std::shared_ptr<EntityInterfaces::ISystemConfig>, PrepareConfig, (), (override));
    };
} // namespace Test
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_SYSTEMCONFIGPROCESSORMOCK_HPP
