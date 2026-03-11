cmake_minimum_required(VERSION 3.20)

# Core MCU flags, CPU, instruction set and FPU setup
set(cpu_PARAMS ${cpu_PARAMS} ${CPU_FLAGS})

# Linker script
set(linker_script_SRC ${linker_script_SRC}
	${CMAKE_SOURCE_DIR}/ld/stm32f407xg_flash.ld
)

aux_source_directory(${CMAKE_SOURCE_DIR}/Libraries/CMSIS/DSP_Lib/Source DSP_Lib)
aux_source_directory(${CMAKE_SOURCE_DIR}/Libraries/STM32F4xx_StdPeriph_Driver/src Std_Lib)

# Sources
set(sources_SRCS ${sources_SRCS}
	${CMAKE_SOURCE_DIR}/startup/startup_stm32f407xx.S
	${CMAKE_CURRENT_SOURCE_DIR}/Core/syscall.c
	${CMAKE_CURRENT_SOURCE_DIR}/Core/sysmem.c
	${CMAKE_CURRENT_SOURCE_DIR}/Core/stm32f4xx_it.c
	${DSP_Lib}
	${Std_Lib}
)

# Include directories
set(include_c_DIRS ${include_c_DIRS}
	${CMAKE_CURRENT_SOURCE_DIR}/Core
	${CMAKE_SOURCE_DIR}/Libraries/CMSIS/Include
	${CMAKE_SOURCE_DIR}/Libraries/CMSIS/Device/ST/STM32F4xx/Include
	${CMAKE_SOURCE_DIR}/Libraries/STM32F4xx_StdPeriph_Driver/inc
)
set(include_cxx_DIRS ${include_cxx_DIRS})
set(include_asm_DIRS ${include_asm_DIRS})

# Symbols definition
set(symbols_c_SYMB ${symbols_c_SYMB}
	USE_STDPERIPH_DRIVER
	STM32F40_41xxx
)
set(symbols_cxx_SYMB ${symbols_cxx_SYMB})
set(symbols_asm_SYMB ${symbols_asm_SYMB})

# Link directories
set(link_DIRS ${link_DIRS})

# Link libraries
set(link_LIBS ${link_LIBS})

# Compiler options
set(compiler_OPTS ${compiler_OPTS})

# Linker options
set(linker_OPTS ${linker_OPTS})
