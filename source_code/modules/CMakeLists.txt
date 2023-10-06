add_subdirectory(wifi)

# Set the project name
project (modules)

# Add a library with the above sources
add_library(${PROJECT_NAME} wifi/scan_wifi.c)
add_library(sub::wifi ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
        hardware_vreg
        hardware_pio
        pico_stdlib
        )

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/wifi
)