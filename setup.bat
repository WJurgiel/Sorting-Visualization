@echo off
set myPath=%~dp0\SortingProgram
set buildPath=%1
if [%1]==[] set buildPath="build/"
cd /d %myPath%

if exist %buildPath%/bin/Sorting.exe (
    echo Nothing to do, exiting
    exit 0
)

cmake -S . -B %buildPath% -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Release
cmake --build %buildPath% -j 10