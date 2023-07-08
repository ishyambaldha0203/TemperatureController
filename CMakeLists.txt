#
# This is a CMake project file for Temperature Controller application.
#
cmake_minimum_required(VERSION 3.19.0)

project(TemeratureController VERSION 0.0.0.1 LANGUAGES CXX)

################################################################
# Configurations
################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/Build/DefaultCmakeSettings.cmake)

set(CMAKE_BUILD_TYPE Debug)

################################################################
# VARIABLES
################################################################
set(TEMPERATURE_CONTROLLER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Include")
set(TEMPERATURE_CONTROLLER_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Src")
set(TEMPERATURE_CONTROLLER_TARGET_NAME temprature_controller)

################################################################
# DEPENDENCIES
################################################################
find_package(Threads REQUIRED)

################################################################
# TARGESTS
################################################################

# Add source to this project's executable.
add_executable(${TEMPERATURE_CONTROLLER_TARGET_NAME})
add_subdirectory(${TEMPERATURE_CONTROLLER_SOURCE_DIR})

################################################################
# INCLUDES
################################################################

target_include_directories(${TEMPERATURE_CONTROLLER_TARGET_NAME} PRIVATE
    ${TEMPERATURE_CONTROLLER_INCLUDE_DIR}
)

target_link_libraries(${TEMPERATURE_CONTROLLER_TARGET_NAME} PRIVATE
    Threads::Threads
)
