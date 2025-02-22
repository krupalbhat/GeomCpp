cmake_minimum_required(VERSION 3.21)

project(GeomCppTests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
  cmake_policy(SET CMP0028 NEW)
endif()

find_package(GTest REQUIRED)

include_directories(
  ${GTEST_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/Core
)

set(TEST_FILES 
    "test_point.cpp"
    # "test_line.cpp"
    # "test_circle.cpp"
)

foreach(test_file ${TEST_FILES})
    get_filename_component(test_name ${test_file} NAME_WE)  

    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} 
        GTest::gtest_main 
        GTest::gtest 
        pthread 
        Threads::Threads
    )

    enable_testing()
    add_test(NAME ${test_name} COMMAND ${test_name})

endforeach()

add_custom_target(all_tests
    DEPENDS 
    ${TEST_FILES}
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY ADDITIONAL_MAKE_CLEAN_FILES ${TEST_FILES})
