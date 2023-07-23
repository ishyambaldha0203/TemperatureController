/**********************************************************************
 * @file CoolerMock.hpp
 *
 * @brief Declaration of mocked methods for class @ref Cooler.
 *
 * It is required only for unit testing.
 *
 *********************************************************************/
#ifndef _TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_COOLERMOCK_HPP
#define _TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_COOLERMOCK_HPP

#include "CommonTestsConfig.hpp"

#include "Interfaces/IAppliance.hpp"

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Test
{
    /**
     * @class CoolerMock
     *
     * @brief A mock class for @ref  Cooler.
     */
    class CoolerMock : public Interfaces::IAppliance
    {
    public:
        MOCK_METHOD(void, Initialize, (float coolingIntensity), (noexcept, override));
        MOCK_METHOD(void, Start, (), (override));
        MOCK_METHOD(void, Stop, (), (override));
        MOCK_METHOD(bool, IsRunning, (), (const, noexcept, override));
    };
} // namespace Test
END_TEMPERATURE_CONTROLLER_NS

#endif // !_TEMPERATURE_CONTROLLER_TESTS_INTERNAL_MOCKS_COOLERMOCK_HPP
