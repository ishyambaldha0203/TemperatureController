################################################################
# SOURCE
################################################################
### NOTE: This file should list all source files regardless of where in the directory tree they reside.
### The main CMake file does not know nor care where the sources are.
target_sources(${TEMPERATURE_CONTROLLER_TEST_TARGET_NAME}
    PRIVATE
        # Src/Internal
        "${CMAKE_CURRENT_LIST_DIR}/Internal/SystemConfigProcessorTests.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/../../Src/Internal/SystemConfigProcessor.cpp"

        "${CMAKE_CURRENT_LIST_DIR}/Internal/SystemConfigReaderTests.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/../../Src/Internal/SystemConfigReader.cpp"

        "${CMAKE_CURRENT_LIST_DIR}/Internal/TemperatureControllerTests.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/../../Src/Internal/TemperatureController.cpp"

        "${CMAKE_CURRENT_LIST_DIR}/Internal/TemperatureManagerTests.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/../../Src/Internal/TemperatureManager.cpp"
)