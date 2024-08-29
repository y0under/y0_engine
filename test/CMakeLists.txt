# for test

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(y0_engine_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lib/googletest/googletest)

set(ENGINE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/../src/y0_core/math)
set(ENGINE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/../include)

message(STATUS "include: " ${ENGINE_INCLUDE_DIR})

include_directories(${ENGINE_INCLUDE_DIR})

add_library(y0_vector3 ${ENGINE_SOURCE_DIR}/Vector3.cc)

add_executable(math_test ./y0_core/math/Vector3_test.cc)

target_link_libraries(math_test y0_vector3 gtest_main)
