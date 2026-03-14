cmake_minimum_required(VERSION 3.22)

set(CHIP_TYPE "STM32F103C8T6")
set(MCU_PROJECT_NAME "MCUDev-Template")

include("${MCUDEV_ROOT}/cmake/${CHIP_TYPE}_config.cmake")

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(${MCU_PROJECT_NAME} C CXX ASM)

# Create an executable object type
add_executable(${PROJECT_NAME})

add_subdirectory(lib)

# Link directories setup
target_link_directories(${PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${PROJECT_NAME} PRIVATE
    # Add user sources here
)

# Add include paths
target_include_directories(${PROJECT_NAME} PRIVATE
    # Add user defined include paths
)

# Add project symbols (macros)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${PROJECT_NAME}
    ${PROJECT_NAME}_lib

    # Add user defined libraries
)

# Execute post-build to print size, generate hex and bin
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.bin
)