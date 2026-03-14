cmake_minimum_required(VERSION 3.22)

enable_language(C ASM)

set(Defines_Syms 
	USE_HAL_DRIVER 
	STM32F103xB
    $<$<CONFIG:Debug>:DEBUG>
)

set(Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/../Application/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Inc
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Inc
    ${MCUDEV_ROOT}/Drivers/CMSIS/Device/ST/STM32F1xx/Include
    ${MCUDEV_ROOT}/Drivers/CMSIS/Include
)

set(Application_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/../Application/Src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Src/stm32f1xx_it.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Src/stm32f1xx_hal_msp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Src/sysmem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Src/syscalls.c
    ${MCUDEV_ROOT}/startup/stm32f1/startup_stm32f103xb.s
)

set(STM32_Drivers_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Src/system_stm32f1xx.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c
    ${MCUDEV_ROOT}/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.c
)

# Drivers Midllewares



# Link directories setup
set(LINK_DIRS

)
# Project static libraries
set(LINK_LIBS 
    ${PROJECT_NAME}_Drivers
    ${TOOLCHAIN_LINK_LIBRARIES}
    
)
# Interface library for includes and symbols
add_library(${PROJECT_NAME}_lib INTERFACE)
target_include_directories(${PROJECT_NAME}_lib INTERFACE ${Include_Dirs})
target_compile_definitions(${PROJECT_NAME}_lib INTERFACE ${Defines_Syms})

# Create STM32_Drivers static library
add_library(${PROJECT_NAME}_Drivers OBJECT)
target_sources(${PROJECT_NAME}_Drivers PRIVATE ${STM32_Drivers_Src})
target_link_libraries(${PROJECT_NAME}_Drivers PUBLIC ${PROJECT_NAME}_lib)

target_sources(${PROJECT_NAME} PRIVATE ${Application_Src})

# Link directories setup
target_link_directories(${PROJECT_NAME} PRIVATE ${LINK_DIRS})

# Add libraries to the project
target_link_libraries(${PROJECT_NAME} ${LINK_LIBS})

# Add the map file to the list of files to be removed with 'clean' target
set_target_properties(${PROJECT_NAME} PROPERTIES ADDITIONAL_CLEAN_FILES ${PROJECT_NAME}.map)

if((CMAKE_C_STANDARD EQUAL 90) OR (CMAKE_C_STANDARD EQUAL 99))
    message(ERROR "Generated code requires C11 or higher")
endif()
