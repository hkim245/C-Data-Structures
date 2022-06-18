/**
 * @file infix_calculator.cpp
 * @author Dr. Schwesinger
 */
#include <stdexcept>
#include "InfixCalculator.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " \"infix expression\"" << std::endl;
        return -1;
    }

    std::vector<Token> tokens = tokenize(argv[1]);
    InfixCalculator ic;
    std::cout << ic.eval(tokens) << std::endl;
    return 0;
}
