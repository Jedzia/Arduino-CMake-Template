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
target_link_libraries(arduinocore PUBLIC arduino_options m)
target_compile_options(arduinocore
		#-w -g -fuse-linker-plugin -Wl,--gc-sections -flto
		PUBLIC -flto
		PUBLIC $<$<COMPILE_LANGUAGE:C>:-std=gnu99>
		PRIVATE -fno-fat-lto-objects
		#		INTERFACE $<$<COMPILE_LANGUAGE:C>: ${CMCU} ${CDEBUG} ${CINCS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}>
#		INTERFACE $<$<COMPILE_LANGUAGE:CXX>: ${CMCU} ${CINCS} ${COPT}>
		)
target_link_options(arduinocore PUBLIC -fuse-linker-plugin -Wl,--gc-sections -flto)
#target_compile_options(arduinocore PRIVATE
#		-g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects
		#		INTERFACE $<$<COMPILE_LANGUAGE:C>: ${CMCU} ${CDEBUG} ${CINCS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}>
		#		INTERFACE $<$<COMPILE_LANGUAGE:CXX>: ${CMCU} ${CINCS} ${COPT}>
#		)

#export library
add_library(arduino::core ALIAS arduinocore)