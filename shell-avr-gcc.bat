@title 'AVR Embedded GCC' Shell.
@echo off
call %~dp0%config\config.bat

type %~dp0%config\WelcomeShell.txt

cd build
cmd