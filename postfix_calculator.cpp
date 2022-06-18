/**
 * @file postfix_calculator.cpp
 * @author Dr. Schwesinger
 */
#include "PostfixCalculator.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " \"postfix expression\"" << std::endl;
        return -1;
    }

    std::vector<Token> tokens = tokenize(argv[1]);
    PostfixCalculator p;
    std::cout << p.eval(tokens) << std::endl;
    return 0;
}
