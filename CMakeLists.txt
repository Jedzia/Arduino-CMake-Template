cmake_minimum_required(VERSION 3.15)

# Set the project name to your project name, my project isn't very descriptive
project(Arduino-Uno-CMake-Template C CXX ASM)

include(cmake/StandardProjectSettings.cmake)

# check if we have a local cmake include file and include it if we do
# this is useful for setting our python location or st-flash as an alternative to
# environment variables
set(PYTHON "C:/Python/Python37/python")
set(PORT COM17)
set(BAUDRATE 115200)
set(OOCD openocd)
set(OOCD_FILE board/st_nucleo_f4.cfg)
set(STFLASH /home/ppkt/usr/bin/st-flash)
if (EXISTS ${CMAKE_SOURCE_DIR}/local.cmake)
    message(STATUS "Using local.cmake")
    include(${CMAKE_SOURCE_DIR}/local.cmake)
endif ()

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)
# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

#option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" ON)

# Very basic PCH example
option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if (ENABLE_PCH)
  # This sets a global PCH parameter, each project will build its own PCH, which
  # is a good idea if any #define's change
  # 
  # 
  #target_precompile_headers(project_options INTERFACE <avr/io.h> <util/delay.h>)
  target_precompile_headers(project_options INTERFACE <avr/io.h>)
endif()


## Set up some extra Conan dependencies based on our needs
## before loading Conan
#set(CONAN_EXTRA_REQUIRES "")
#set(CONAN_EXTRA_OPTIONS "")
#
#if(CPP_STARTER_USE_IMGUI)
#  set(CONAN_EXTRA_REQUIRES ${CONAN_EXTRA_REQUIRES}
#                           imgui-sfml/2.1@bincrafters/stable)
#
#  # set(CONAN_EXTRA_OPTIONS ${CONAN_EXTRA_OPTIONS} sfml:shared=False
#  # sfml:graphics=True sfml:audio=False sfml:window=True
#  # libalsa:disable_python=True)
#endif()
#
#if(CPP_STARTER_USE_SDL)
#  set(CONAN_EXTRA_REQUIRES ${CONAN_EXTRA_REQUIRES}
#                           sdl2/2.0.10@bincrafters/stable)
#  # set(CONAN_EXTRA_OPTIONS ${CONAN_EXTRA_OPTIONS} sdl2:wayland=True)
#endif()
#
#
#include(cmake/Conan.cmake)
#run_conan()
#
#if(ENABLE_TESTING)
#  enable_testing()
#  message(
#    "Building Tests. Be sure to check out test/constexpr_tests for constexpr testing"
#  )
#  add_subdirectory(test)
#endif()
#
#if(ENABLE_FUZZING)
#  message(
#    "Building Fuzz Tests, using fuzzing sanitizer https://www.llvm.org/docs/LibFuzzer.html"
#  )
#  add_subdirectory(fuzz_test)
#endif()
#
#

#include(${ArduinoCode_SOURCE_DIR}/arduino_diecimila_crosscompile.cmake)

add_subdirectory(libs)

include(cmake/Arduino.cmake)
add_subdirectory(src)
