/*************************************************************************************************
 * @file ObjectFactory.cpp
 *
 * @brief Concrete implementation of a common object factory.
 *
 * It manages creation and lifespan of all the higher level object of the Temperature Monitoring application.
 *
 *************************************************************************************************/

#include "Internal/ObjectFactory.hpp"

#include "Internal/Program.hpp"
#include "Internal/TemperatureManager.hpp"

// #region Namespace Symbols

using namespace TEMPERATURE_CONTROLLER_NS::FactoryInterfaces;

// #endregion

BEGIN_TEMPERATURE_CONTROLLER_NS
namespace Internal
{
    // #region Construction/Destruction

    ObjectFactory::ObjectFactory() = default;

    ObjectFactory::~ObjectFactory() = default;

    // #endregion

    // #region Public Methods

    void ObjectFactory::Create(IProgramFactory::InterfaceSharedPointer &objectPtr)
    {
        ITemperatureManagerFactory::InterfaceSharedPointer temperatureManager;
        Create(temperatureManager);

        objectPtr = std::make_shared<Program>(temperatureManager);
    }

    void ObjectFactory::Create(ITemperatureManagerFactory::InterfaceSharedPointer &objectPtr)
    {
        objectPtr = std::make_shared<TemperatureManager>();
    }

    // #endregion

    // #region Private Methods

    std::shared_ptr<ObjectFactory> ObjectFactory::Self()
    {
        return std::enable_shared_from_this<ObjectFactory>::shared_from_this();
    }

    // #endregion
} // namespace Internal
END_TEMPERATURE_CONTROLLER_NS
