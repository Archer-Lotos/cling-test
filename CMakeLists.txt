cmake_minimum_required(VERSION 3.22.1)
project(cling_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        cling_include
)

add_executable(cling_cpp main.cpp
        DeepClientCppWrapper.cpp
        Compiler.cpp
#        cling_lib/Interpreter/Interpreter.cpp
)

add_library(libclangBasic STATIC IMPORTED)
set_target_properties(libclangBasic PROPERTIES
        IMPORTED_LOCATION "libraries/libclangBasic.a"
        LINKER_LANGUAGE CXX
)

target_link_libraries(cling_cpp PRIVATE libclangBasic)
