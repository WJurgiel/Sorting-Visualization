cmake_minimum_required(VERSION 3.20)
project(Sorting)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(Includes)
add_subdirectory(Source)

include(CTest)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        SYSTEM)
FetchContent_MakeAvailable(SFML)

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
        Source/Sort.cpp
        Includes/Sort.h
        Includes/BubbleSort.h
        Source/BubbleSort.cpp
        Source/SelectionSort.cpp
        Source/InsertionSort.cpp
        Source/QuickSort.cpp
        Includes/AlgorithmType.h
        Source/SortFactory.cpp
        Source/EntityManager.cpp
)
target_compile_features(Sorting PRIVATE cxx_std_20)
target_link_libraries(Sorting PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

add_subdirectory(googletest)
add_subdirectory(Test)