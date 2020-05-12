
add_library (arduinocore
#	HardwareSerial.cpp
#	Print.cpp
#	wiring.c
#	wiring_shift.c
#	WInterrupts.c
#	wiring_digital.c
#	WMath.cpp
#	pins_arduino.c
#	wiring_analog.c
#	wiring_pulse.c

		wiring_pulse.S
		hooks.c
		WInterrupts.c
		wiring.c
		wiring_analog.c
		wiring_digital.c
		wiring_pulse.c
		wiring_shift.c
		abi.cpp
		CDC.cpp
		HardwareSerial.cpp
		HardwareSerial0.cpp
		HardwareSerial1.cpp
		HardwareSerial2.cpp
		HardwareSerial3.cpp
		IPAddress.cpp
		main.cpp
		new.cpp
		PluggableUSB.cpp
		Print.cpp
		Stream.cpp
		Tone.cpp
		USBCore.cpp
		WMath.cpp
		WString.cpp
)
target_include_directories(arduinocore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} variants/standard)