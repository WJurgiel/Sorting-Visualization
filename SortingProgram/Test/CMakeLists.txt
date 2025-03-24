if(BUILD_TESTING)
    add_executable(AppTest AppTest.cpp)
    target_link_libraries(AppTest PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(AppTest)
endif()