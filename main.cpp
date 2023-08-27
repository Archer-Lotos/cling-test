#include <iostream>

#include "Compiler.h"
#include "DeepClientCppWrapper.h"
#include "cling/Interpreter/Interpreter.h"
#include "cling/Interpreter/Value.h"

std::string Compiler::compileAndExecute(const std::string &code, DeepClientCppWrapper* deepClient) {
    cling::Interpreter interp(/*argc=*/0, /*argv=*/nullptr, /*input=*/nullptr, /*Errs=*/nullptr);

    interp.declare(code);

    cling::Value result;
    if (interp.process(result)) {
        std::string resultStr = result.toString();
        return resultStr;
    } else {
        return "Execution failed.";
    }
}


int main() {
    std::cout << "Start!" << std::endl;
    DeepClientCppWrapper deepClient("jwt_token", "gql_urn");
    std::string code = "";
    Compiler compiler;
    std::string result = compiler.compileAndExecute(code, &deepClient);
    std::cout << "Execution result: " << result << std::endl;
    return 0;
}
