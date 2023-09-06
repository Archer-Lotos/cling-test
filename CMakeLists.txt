cmake_minimum_required(VERSION 3.22.1)
project(cling_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        cling_include
)

link_directories(
        libraries
)

add_executable(cling_cpp main.cpp
        DeepClientCppWrapper.cpp
        Compiler.cpp
#        cling_lib/Interpreter/Interpreter.cpp
)


target_link_libraries(cling_cpp PRIVATE libcling.so)
