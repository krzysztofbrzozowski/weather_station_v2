cmake_minimum_required(VERSION 3.13)


include(CMakePrintHelpers)
cmake_print_variables(PICO_SDK_PATH)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C   standards
project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
#     message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
# endif()

# set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})
set(PICO_BOARD pico_w)

# Initialize the SDK
pico_sdk_init()


add_executable(${PROJECT_NAME} 
        source/main.c
        )

target_link_libraries(${PROJECT_NAME} 
        pico_stdlib            
        pico_cyw43_arch_none     
        )

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})