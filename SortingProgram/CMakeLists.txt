cmake_minimum_required(VERSION 3.29)
project(Sorting)

set(CMAKE_CXX_STANDARD 20)

include_directories(Includes)
add_subdirectory(Source)

set(SFML_DIR "C:\\SFML\\SFML-MinGW\\lib\\cmake\\SFML")

find_package(SFML 2.6.2 COMPONENTS graphics window system REQUIRED)

add_executable(Sorting main.cpp
        Source/Entity.cpp
        Source/App.cpp
        Includes/IEvents.h
        Includes/IUpdateBuffer.h
        Source/TextLog.cpp
        Source/ISoundListener.cpp
        Source/SoundManager.cpp
        Source/SortVisualizer.cpp
        Includes/SoundManager.h
)


target_link_libraries(Sorting sfml-graphics sfml-window sfml-system sfml-audio)