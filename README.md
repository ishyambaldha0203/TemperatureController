# TemperatureController
Application to monitor and maintain the temperature in a specific range.

## High-Level Design
- The SOLID principles are strictly followed, with DRY, KISS, and YAGNI as supporting principles.
- Each class has an interface that defines its responsibilities.
- Class declarations are in separate .hpp files, while class definitions are in .cpp files.
- All components are unit testable.
- An abstract factory is used to create class instances.
- The observer design pattern is used to publish temperature change events.
- **CMake is used as the build system.**
- **C++20 is used for development.** 

## Brief of Project Components
- **Temperature Manager:** Manages all operations.
- **Temperature Sensor:** Continuously reads the temperature.
- **Temperature Controller:** Controls the temperature to keep it within a specified range.
  - If the temperature drops below the minimum level, the heater is activated.
  - If the temperature rises above the maximum level, the cooler is activated.
- **Temperature Simulator:** Simulates real-time temperature with natural variations.
- **Display Manager:** Manages display-related operations, such as displaying the current temperature and other important events.
- Additional components manage user-defined configurations, such as temperature range and cooling/heating intensity.

## Directory Structure
```
TemperatureController/
├── Build
│   ├── CmakeModules
│   └── DefaultCmakeSettings.cmake
├── CMakeLists.txt
├── Include
│   ├── CommonConfig.hpp
│   ├── Exceptions
│   ├── Interfaces
│   └── Internal
├── README.md
├── Src
│   ├── CMakeLists.txt
│   ├── Internal
│   └── main.cpp
└── TemperatureController.Tests
    ├── CMakeLists.txt
    └── Src
```

## Building the Application
**NOTE: These instructions assume that you are using the command prompt to build the application.**

1. Using cmake version `3.19.0` to build the application.
2. Using C++ version `C++20` but it is compatible with C++17 as well. It is configurable from the `DefaultCmakeSettings.cmake` file.
3. Open the command prompt and navigate to the `TemperatureController` directory ($cd TemperatureController).
4. Create a new directory named `build` by entering `mkdir build`, then navigate to the `build` directory ($cd build).
5. Run the `cmake` command by entering ($cmake ..).
6. Compile the application by entering the `make` command. To speed up compilation, you can use the `-j` option followed by the number of cores you want to use, for example, ($make -j4).
7. If compilation is successful, an executable file named `temperature_controller` will be created in the `./bin/exec` directory. You can verify this by entering `ls bin/exe/temperature_controller`.

## Running the Application
**NOTE: These instructions assume that you are using the command prompt to run the application.**

1. Create a configuration file named `TemperatureController.conf`. Each line in this file represents a configurable entity.
2. Set the `MaxTemperature` and `MinTemperature` values by entering them as plain text, with the key and value separated by an equal sign (=). For example:
```
MinTemperature=23
MaxTemperature=25
```
3. Place the configuration file in the same directory from which you will execute the `temperature_controller` binary.
4. Run the application by entering `./temperature_controller.`

**Note: If a configuration file is not created, the application will run with a default temperature range of 23°C to 25°C.**

## Limitation
1. Only ‘MaxTemperature’ and ‘MinTemperature’ are currently configurable through the `TemperatureController.conf` file.
2. The configuration file name is currently hardcoded to ‘TemperatureController.conf’.
3. The configuration file path is also currently hardcoded to the current directory from where the application is being executed. So, the config file and executable file must be placed in the same directory
4. The configuration module can be extended to define the cooling/heating/simulation intensity through the config file. At the moment, it’s fixed.
5. A time at which the simulator changes the temperature is currently fixed at 1 second. It can be made configurable through a config file.
6. A time at which the sensor reads the temperature is currently fixed at 1 second. It can also be made configurable through a config file.

## Future scope
1. Implement a logging module to store logs in a log file for easier debugging and analysis.
2. Implement the value type to consistently represent temperature values across the application source code.
3. There is still scope for more comprehensive error handling.
4. Implement an Operating-System-Dependent (OSD) common configuration layer for enhanced cross-platform (xplat) support.
  - Define global cross-platform primitive types for consistent data representation.
  - Implement macros for accurate platform detection
  - Ensure multiple compiler support
5. For configuration, a rich data format such as JSON or Protobuf can be used for more flexible and efficient data storage and retrieval.

# Known Issue/Bug
Not any at the moment.
