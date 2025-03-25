if(BUILD_TESTING)
    add_executable(AppTest AppTest.cpp)
    add_executable(SortTest SortTest.cpp)

    target_include_directories(AppTest PRIVATE ${CMAKE_SOURCE_DIR}/Includes )
    target_include_directories(SortTest PRIVATE ${CMAKE_SOURCE_DIR}/Includes)

    file(GLOB_RECURSE ALL_SOURCE_FILES ${CMAKE_SOURCE_DIR}/Source/*.cpp)

    target_sources(SortTest PRIVATE ${ALL_SOURCE_FILES})
    target_sources(AppTest PRIVATE ${ALL_SOURCE_FILES})

    target_link_libraries(AppTest PRIVATE GTest::gmock_main sfml-graphics sfml-audio)
    target_link_libraries(SortTest PRIVATE GTest::gmock_main sfml-graphics sfml-audio)

    include(GoogleTest)
    gtest_discover_tests(AppTest)
    gtest_discover_tests(SortTest)
endif()