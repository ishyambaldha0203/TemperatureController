################################################################
# SOURCE
################################################################
### NOTE: This file should list all source files regardless of where in the directory tree they reside.
### The main CMake file does not know nor care where the sources are.
target_sources(${TEMPERATURE_CONTROLLER_TARGET_NAME}
    PRIVATE
        # Src
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp

        # Src/Internal
        ${CMAKE_CURRENT_LIST_DIR}/Internal/Cooler.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/DisplayManager.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/Heater.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/ObjectFactory.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/Program.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/SystemConfigProcessor.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/SystemConfigReader.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/TemperatureController.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/TemperatureManager.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/TemperatureSensor.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/TemperatureSimulator.cpp
)
