@echo off
setlocal


set PATH=%PATH%;C:\Program Files (x86)\GNU Arm Embedded Toolchain\10 2021.10\bin
set GIT_BASH="C:\Program Files\Git\bin\bash.exe"

if "%1" neq "clean" (
    %GIT_BASH% -c "make all"
) else if "%1" == "clean" (
    %GIT_BASH% -c "make clean"
)

endlocal


