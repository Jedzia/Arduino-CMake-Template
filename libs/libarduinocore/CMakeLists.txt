# The Arduino platform library

add_library (arduinocore
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
target_include_directories(arduinocore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} variants/standard)
target_link_libraries(arduinocore PUBLIC arduino_options)

#export library
add_library(arduino::core ALIAS arduinocore)