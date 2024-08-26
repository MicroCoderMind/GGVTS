cmake_minimum_required(VERSION 3.12)

# Change your executable name to something creative!
set(NAME GGVTSPico) # <-- Name your project/executable here!
set(PICO_BOARD pico)

include(pico_sdk_import.cmake)

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_subdirectory(src)

target_compile_definitions(${NAME} PRIVATE
            PICO_DEFAULT_UART0_TX_PIN=0
            PICO_DEFAULT_UART0_RX_PIN=1
            PICO_DEFAULT_UART1_TX_PIN=4
            PICO_DEFAULT_UART1_RX_PIN=5)

#Set up files for the release packages
install(CODE "execute_process(COMMAND $ENV{HOME}/bin/picoDeploy.sh ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.elf)")

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.uf2
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
