@echo off

mkdir build
set ORIGINAL_PATH="%CD%"
cd build
echo %CD%
"%CMAKE_BIN%\cmake.exe" .. -G "Visual Studio 16 2019"

cd %ORIGINAL_PATH%