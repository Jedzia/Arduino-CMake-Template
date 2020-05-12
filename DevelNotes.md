    



    E:\Projects\Elektronik\Arduino\!Templates\CMake\MyArduino-CMake-Toolchain\Examples\01_hello_world\build>
    
    cmake -D CMAKE_TOOLCHAIN_FILE=../../../Arduino-toolchain.cmake -DARDUINO_INSTALL_PATH=D:/arduino-1.8.9 -G"MinGW Makefiles" ..

uncomment 

    set(ARDUINO_BOARD "Arduino/Genuino Uno [avr.uno]") # Arduino/Genuino Uno

in BoardOptions.cmake

    make
