cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

project(main)

add_executable(main main.cpp Token.hpp Tokenizer.hpp Tokenizer.cpp Analizator.hpp Analizator.cpp Tree.hpp Tree.cpp)