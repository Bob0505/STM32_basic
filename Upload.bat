echo off

REM refs : C:\Users\bob-0\.arduinocdt\packages\arduino\hardware\stm32\STM32F1\
REM 		boards.txt
REM 		platform.txt
REM "{path}/{cmd} {serial.port.file} {upload.altID} {upload.usbID} {build.path}/{build.project_name}.bin"

set TOOL_PATH="C:/Users/bob-0/.arduinocdt/packages/arduino/hardware/stm32/tools/win"
SET STM32BIN="C:/WorkSpace/Code/STM32_basic/Release/STM32_basic.bin"

echo %DATE% %TIME%

call %TOOL_PATH%/serial_upload.bat COM4 {upload.altID} {upload.usbID} %STM32BIN%
pause