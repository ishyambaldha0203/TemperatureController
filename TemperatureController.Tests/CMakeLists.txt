#
# This is a CMake project file for unit tests of temperature controller application.
#
cmake_minimum_required(VERSION 3.17.0)

project(TemeratureController VERSION 0.0.0.1 LANGUAGES CXX)

################################################################
# Configurations
################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/../Build/DefaultCmakeSettings.cmake)

################################################################################
# VARIABLES
################################################################################
set(TEMPERATURE_CONTROLLER_TEST_TARGET_NAME ${PROJECT_NAME})

set(TEMPERATURE_CONTROLLER_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Src")
set(TEMPERATURE_CONTROLLER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Include")
set(TEMPERATURE_CONTROLLER_TEST_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Src")

################################################################################
# Dependencies
################################################################################
find_package(FrameworkGtest)

################################################################################
# Targets
################################################################################
add_executable(${TEMPERATURE_CONTROLLER_TEST_TARGET_NAME})
add_subdirectory("${TEMPERATURE_CONTROLLER_TEST_SOURCE_DIR}")

target_include_directories(${TEMPERATURE_CONTROLLER_TEST_TARGET_NAME}
    PRIVATE
        "${TEMPERATURE_CONTROLLER_TEST_SOURCE_DIR}"
        "${TEMPERATURE_CONTROLLER_INCLUDE_DIR}"
)

target_link_libraries(${TEMPERATURE_CONTROLLER_TEST_TARGET_NAME}
    PRIVATE
        framework::gtest_suite
)

enable_testing()

gtest_discover_tests(${TEMPERATURE_CONTROLLER_TEST_TARGET_NAME})