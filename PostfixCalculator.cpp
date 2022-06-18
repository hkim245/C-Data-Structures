/**
 * @file PostfixCalculator.cpp
 * @author Harry Kim
 * CSC237, Fall 2018, Assignment 4
 */

#include "PostfixCalculator.h"
#include "Token.h"
#include <stack>
#include <vector>
#include <stdexcept>
using namespace std;

/**
 * Evaluate the postfix expression.
 * @param tokens a vector of tokens.
 * @return result the result of the infix expression.
 */
double PostfixCalculator::eval(vector<Token> tokens) {
    stack<double> postfix;					// Declare a stack for the postfix calculation.
    double operand1 = 0, operand2 = 0, result = 0;					// Create variables for the operands and the result of the calculation.
    int size = tokens.size();

    for (int x = 0; x < size; x++) {					// For loop through the tokens.
        if (tokens[x].tag == OPERAND) {							
            postfix.push(tokens[x].d);						// Push the operand into the postfix stack.
        }
        else {
            operand2 = postfix.top();								// Calculate the two operands with an operator.
            postfix.pop();
            operand1 = postfix.top();
            postfix.pop();
            if (tokens[x].o == ADD) {
                result = operand1 + operand2;
            }
            if (tokens[x].o == SUBTRACT) {
                result = operand1 - operand2;
            }
            if (tokens[x].o == MULTIPLY) {
                result = operand1 * operand2; 
            }
            if (tokens[x].o == DIVIDE) {
                result = operand1 / operand2;
            }
            postfix.push(result);
        }
    }    
    return result;								// The result of the calculation.
}