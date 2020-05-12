# Development Notes and Hints for the Arduino Uno CMake Template #    


Setup local.cmake by using local.cmake.example as template.

    E:\Projects\Elektronik\Arduino\!Templates\CMake\Uno-CMake-Template\build>
    cmake -DCMAKE_TOOLCHAIN_FILE=C:/Toolchain/CMake/toolchain.local.avr.gcc.cmake -G"MinGW Makefiles" ..  
	cmake-gui -DCMAKE_TOOLCHAIN_FILE=C:/Toolchain/CMake/toolchain.local.avr.gcc.cmake -G"MinGW Makefiles" ..



    make
	make clean && make

CLion:
set -DCMAKE_TOOLCHAIN_FILE=C:/Toolchain/CMake/toolchain.local.avr.gcc.cmake and specify a avr-gcc toolchain under Toolchains

### Example `toolchain.local.avr.gcc.cmake` ###

    set(CMAKE_SYSTEM_NAME Generic)
    set(CMAKE_SYSTEM_PROCESSOR avr)
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
    
    set(OBJCOPY avr-objcopy)
    set(CMAKE_C_COMPILER avr-gcc)
    set(CMAKE_CXX_COMPILER avr-g++)
    
    #set(CMAKE_EXE_LINKER_FLAGS_INIT "--specs=rdimon.specs")
