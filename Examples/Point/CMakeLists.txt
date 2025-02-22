cmake_minimum_required(VERSION 3.14)
project(GeomCppExamples)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB EXAMPLE_SOURCES "*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

foreach(EXAMPLE_FILE ${EXAMPLE_SOURCES})
    get_filename_component(EXE_NAME ${EXAMPLE_FILE} NAME_WE)
    add_executable(${EXE_NAME} ${EXAMPLE_FILE})
    
    target_link_libraries(${EXE_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
endforeach()
