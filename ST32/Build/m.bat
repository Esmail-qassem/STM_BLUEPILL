@echo off
setlocal


set PATH=%PATH%;C:\Program Files (x86)\GNU Arm Embedded Toolchain\10 2021.10\bin
set GIT_BASH="C:\Program Files\Git\bin\bash.exe"

if "%1" =="-j" (
    %GIT_BASH% -c "make all"
) else if "%1" == "clean" (
    %GIT_BASH% -c "make clean"
)else if "%1" == "flash" (
    %GIT_BASH% -c "make flash"
)else if "%1" == "erase" (
    %GIT_BASH% -c "make erase"
)

endlocal


