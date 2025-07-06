cmake_minimum_required(VERSION 3.7)

project(asteroids CXX)

include(C:/vcpkg/scripts/buildsystems/vcpkg.cmake)

option(add_test "add test" OFF)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Project Sources
add_subdirectory(src)

# Tests
if(add_test)
    enable_testing()
    add_subdirectory(tests)
endif()