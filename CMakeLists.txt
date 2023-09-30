cmake_minimum_required(VERSION 3.12)


include(CMakePrintHelpers)
cmake_print_variables(PICO_SDK_PATH)

# Pull in SDK (must be before project)
include($ENV{PICO_EXAMPLES}/pico_sdk_import.cmake)
# include($ENV{PICO_SDK_PATH}/pico_extras_import_optional.cmake)

project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})
set(PICO_BOARD pico)

# Initialize the SDK
pico_sdk_init()
