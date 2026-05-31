@echo off
echo ==============================
echo FirstTouchSchool Build System
echo ==============================

cd /d %~dp0

:: Step 1: Clean old build (optional but safe)
if exist build (
    echo Cleaning old build folder...
    rmdir /s /q build
)

:: Step 2: Create build folder
mkdir build
cd build

:: Step 3: Configure project (IMPORTANT)
echo Configuring CMake...
cmake .. -G "MinGW Makefiles"
if %errorlevel% neq 0 (
    echo ERROR: CMake configuration failed!
    pause
    exit /b
)

:: Step 4: Build project
echo Building project...
cmake --build .
if %errorlevel% neq 0 (
    echo ERROR: Build failed!
    pause
    exit /b
)

echo ==============================
echo BUILD SUCCESSFUL
echo ==============================

:: Step 5: Try to locate exe automatically
echo Searching for executable...

for /r %%i in (*.exe) do (
    echo FOUND EXE: %%i
)

echo ==============================
echo DONE
echo ==============================

pause