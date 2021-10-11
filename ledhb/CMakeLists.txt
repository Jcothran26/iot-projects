# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include(pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C++ standards
project(ledhb C CXX ASM)
SET(CMAKE_C_Standard 11)
SET(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

# Tell CMake where to find the executable source file
add_executable(ledhb
	ledhb.c
	)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(ledhb)

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(ledhb pico_stdlib hardware_adc)
