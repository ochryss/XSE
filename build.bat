@echo off

if not exist "build\debug" (
    mkdir "build\debug"
)

cmake ^
    -S . ^
    -B "build\debug" ^
    -G Ninja
::    -DCMAKE_BUILD_TYPE=Debug

if errorlevel 1 pause && exit /b 1

cmake --build "build\debug"

pause