#include <iostream>

#include "Compiler.h"
#include "DeepClientCppWrapper.h"
#include <cling/Interpreter/Interpreter.h>
#include <cling/Interpreter/Value.h>

std::string Compiler::compileAndExecute(const std::string &code, DeepClientCppWrapper* deepClient) {
    cling::Interpreter interp = cling::Interpreter(0, nullptr);

    interp.declare(code);

    const char *result;
    if (interp.process(result)) {
        std::string resultStr = result;
        return resultStr;
    } else {
        return "Execution failed.";
    }
    return "Execution failed.";
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
