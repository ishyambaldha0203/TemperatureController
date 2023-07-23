/**********************************************************************
 * @file SystemConfigMock.hpp
 *
 * @brief Declaration of mocked methods for class @ref SystemConfig.
 *
 * It is required for unit testing.
 *
 *********************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_TESTS_INTERNAL_ENTITIES_MOCKS_SYSTEMCONFIGMOCK_HPP
#define _TEMPERATURE_CONTROLLER_TESTS_INTERNAL_ENTITIES_MOCKS_SYSTEMCONFIGMOCK_HPP

#include "CommonTestsConfig.hpp"

#include "Interfaces/Entities/ISystemConfig.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Entities
{
    namespace Test
    {
        /**
         * @class SystemConfigMock
         *
         * @brief A mock class for @ref SystemConfig.
         */
        class SystemConfigMock : public EntityInterfaces::ISystemConfig
        {
        public:
            MOCK_METHOD(float, GetMinTemperatureRange, (), (const, noexcept, override));
            MOCK_METHOD(float, GetMaxTemperatureRange, (), (const, noexcept, override));
            MOCK_METHOD(float, GetHeatingIntensity, (), (const, noexcept, override));
            MOCK_METHOD(float, GetCoolingIntensity, (), (const, noexcept, override));
            MOCK_METHOD(float, GetSimulationIntensity, (), (const, noexcept, override));
        };
    }
}
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_TESTS_INTERNAL_ENTITIES_MOCKS_SYSTEMCONFIGMOCK_HPP
