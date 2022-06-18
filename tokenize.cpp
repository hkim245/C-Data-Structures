/**
 * @file tokenize.cpp
 * @author Dr. Schwesinger
 * @brief print the tokenized output of an expression.
 */
#include <iostream>
#include <string>
#include <vector>

#include "Token.h"

/**
 * @brief parse a command line string into tokens and print a string
 * representation of the tokens.
 * @param argc the number of command line arguments
 * @param argv the command line argument strings
 * @return 0 on successful execution
 */
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " \"expression\"" << std::endl;
        return -1;
    }

    std::vector<Token> tokens = tokenize(argv[1]);
    for (unsigned int i = 0; i < tokens.size(); i++) {
        std::cout << tokens[i];
    }

    return 0;
}
