/**********************************************************************
 * @file HeaterMock.hpp
 *
 * @brief Declaration of mocked methods for class @ref Heater.
 *
 * It is required only for unit testing.
 *
 *********************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_HEATERMOCK_HPP
#define _TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_HEATERMOCK_HPP

#include "CommonTestsConfig.hpp"

#include "Interfaces/IAppliance.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Test
{
    /**
     * @class HeaterMock
     *
     * @brief A mock class for @ref  Heater.
     */
    class HeaterMock : public Interfaces::IAppliance
    {
    public:
        MOCK_METHOD(void, Initialize, (float heatingIntensity), (noexcept, override));
        MOCK_METHOD(void, Start, (), (override));
        MOCK_METHOD(void, Stop, (), (override));
        MOCK_METHOD(bool, IsRunning, (), (const, noexcept, override));
    };
} // namespace Test
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_HEATERMOCK_HPP
