//
// Created by fox on 04.09.23.
//

#ifndef CLING_TEST_COMPILER_H
#define CLING_TEST_COMPILER_H


#include <string>
#include "DeepClientCppWrapper.h"

class Compiler {

public:
    static std::__cxx11::basic_string<char>
    compileAndExecute(const std::__cxx11::basic_string<char> &code, DeepClientCppWrapper *deepClient);
};


#endif //CLING_TEST_COMPILER_H
