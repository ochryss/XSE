@echo off
set "EXE_PATH=build\debug\out\TEST_GAME.exe"

call build.bat

if not exist %EXE_PATH% (
    echo ** Executable not found **
    pause
    exit /b 1
)

%EXE_PATH%
pause