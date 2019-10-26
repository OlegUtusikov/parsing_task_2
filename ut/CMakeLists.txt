cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

project(test)

add_subdirectory(../lib/googletest-master)
include_directories(../lib/googletest-master/googletest/include ../lib/googletest-master/googlemock/include ../src)
add_executable(test ../main.cpp ../src/Tokenizer.cpp ../src/Tokenizer.hpp test.cpp)
target_link_libraries(test gtest gtest_main)