#include <iostream>

#include "Compiler.h"
#include "DeepClientCppWrapper.h"
#include <cling/Interpreter/Interpreter.h>
#include <cling/Interpreter/Value.h>

std::string Compiler::compileAndExecute(const std::string &code, DeepClientCppWrapper* deepClient) {
    cling::Interpreter interp(/*argc=*/0, /*argv=*/nullptr, /*input=*/nullptr, /*Errs=*/{});

    //interp.declare(code);

    /*std::string result;
    interp.process(result);

    if (result.empty()) {
        std::cerr << "Ошибка выполнения кода." << std::endl;
    } else {
        std::cout << "Результат: " << result << std::endl;
    }*/
    return "test";
}


int main() {
    std::cout << "Start!" << std::endl;
    DeepClientCppWrapper deepClient("jwt_token", "gql_urn");
    std::string code = R"(
    int result = deepClient->calculate();
    std::cout << "Результат: " << result << std::endl;
)";
    Compiler compiler;
    std::string result = compiler.compileAndExecute(code, &deepClient);
    std::cout << "Execution result: " << result << std::endl;
    return 0;
}
