# The Arduino platform library

add_library (arduino_core
		CDC.cpp
		HardwareSerial.cpp
		HardwareSerial0.cpp
		HardwareSerial1.cpp
		HardwareSerial2.cpp
		HardwareSerial3.cpp
		IPAddress.cpp
		PluggableUSB.cpp
		Print.cpp
		Stream.cpp
		Tone.cpp
		USBCore.cpp
		WInterrupts.c
		WMath.cpp
		WString.cpp
		abi.cpp
		hooks.c
		main.cpp
		new.cpp
		wiring.c
		wiring_analog.c
		wiring_digital.c
		wiring_pulse.S
		wiring_pulse.c
		wiring_shift.c
)
target_include_directories(arduino_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} variants/standard)
target_link_libraries(arduino_core PUBLIC arduino_options m)
target_compile_options(arduino_core
		PUBLIC -flto -MMD
		PUBLIC $<$<COMPILE_LANGUAGE:C>:-std=gnu99>
		PRIVATE -fno-fat-lto-objects
		PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-CC>
		)
target_link_options(arduino_core PUBLIC -fuse-linker-plugin -Wl,--gc-sections -flto)

#export library
add_library(arduino::core ALIAS arduino_core)