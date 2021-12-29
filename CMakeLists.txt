cmake_minimum_required(VERSION 3.20)
project(options)

set(CMAKE_CXX_STANDARD 23)

add_executable(options main.cpp blackScholes.h blackScholes.cpp black.h black.cpp readFile.h readFile.cpp exampleFile.h)
