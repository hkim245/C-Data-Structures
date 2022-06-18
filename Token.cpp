/**
 * @file Token.cpp
 * @author Dr. Schwesinger
 */
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Token.h"

std::string opToString(Operator o) {
    std::string result;
    switch(o) {
        case ADD:
            result = "ADD";
            break;
        case SUBTRACT:
            result = "SUBTRACT";
            break;
        case MULTIPLY:
            result = "MULTIPLY";
            break;
        case DIVIDE:
            result = "DIVIDE";
            break;
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Token& t) {
    std::string type;
    switch (t.tag) {
        case OPERATOR:
            os << "OPERATOR: " << opToString(t.o) << std::endl;
            break;
        case OPERAND:
            os << "OPERAND: " << t.d << std::endl;
            break;
        case LPAREN:
            os << "LPAREN" << std::endl;
            break;
        case RPAREN:
            os << "RPAREN" << std::endl;
            break;
        default:
            throw std::logic_error("Invalid token");
            break;
    }
    return os;
}

std::vector<Token> tokenize(std::string s) {
    std::stringstream ss(s);
    std::vector<Token> result; 

    while (ss) {
        Token t;
        if (ss.peek() == ' ') {
            ss.get();
            continue;
        }
        if (isalnum(ss.peek())) {
            ss >> t.d;
            t.tag = OPERAND;
        }
        else {
            char op;
            ss >> op;
            t.d = 0;
            if (op == '(') {
                t.tag = LPAREN;
            }
            else if (op == ')') {
                t.tag = RPAREN;
            }
            else if (op == '*') {
                t.o = MULTIPLY;
                t.tag = OPERATOR;
            }
            else if (op == '/') {
                t.o = DIVIDE;
                t.tag = OPERATOR;
            }
            else if (op == '+') {
                t.o = ADD;
                t.tag = OPERATOR;
            }
            else if (op == '-') {
                t.o = SUBTRACT;
                t.tag = OPERATOR;
            }
            else {
                throw std::logic_error("Invalid token");
            }
        }
        result.push_back(t);
    }
    result.pop_back();
    return result;
}

