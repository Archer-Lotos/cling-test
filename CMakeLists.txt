cmake_minimum_required(VERSION 3.26)
project(cling_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(cling_test main.cpp
        DeepClientCppWrapper.cpp
        Compiler.cpp)
