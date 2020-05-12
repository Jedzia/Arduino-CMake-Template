@title Launching Clion with 'AVR Embedded GCC' settings.
@echo off
call %~dp0%config\config.bat

set HOME=%USERPROFILE%

start "" "C:\Program Files\JetBrains\CLion\bin\clion64.exe"

@REM sleep 8 seconds
@PING localhost -n 9 >NUL
