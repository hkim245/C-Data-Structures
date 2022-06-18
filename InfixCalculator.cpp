/**
 * @file InfixCalculator.cpp
 * @author Harry Kim
 * CSC237, Fall 2018, Assignment 4
 */

#include <sstream>
#include <cstdlib>
#include <stack>
#include <stdexcept>
#include <vector>
#include "InfixCalculator.h"
#include "PostfixCalculator.h"
#include "Token.h"
using namespace std;

/**
 * Convert the infix expression to a postfix expression.
 * @param tokens a vector of tokens in infix form.
 * @return result a vector of token in postfix form.
 */
vector<Token> InfixCalculator::infixToPostfix(vector<Token> tokens) {
    try {
        checkParentheses(tokens); 						// Check for balanced parentheses.
		stack<Token> operatorStack;				// Declare variables for storing the tokens.
		vector<Token> result;
		int size = tokens.size();				// Size of the vector of tokens.

		for (int x = 0; x < size; x++) {				// For loop through the tokens.
			switch (tokens[x].tag) {					// Switch on the tag of the tokens.
				case OPERAND:									
					result.push_back(tokens[x]);               // Push the token into a vector to create a postfix expression.
					break;
				case LPAREN:
					operatorStack.push(tokens[x]);							// Push the left parentheses into a vector of operators.
					break;
				case OPERATOR:
					while (!operatorStack.empty() && operatorStack.top().tag != LPAREN && precedence(tokens[x], operatorStack.top())) {					// While loop through the operator stack to store the operators into a vector according to the precedence of operators.
						result.push_back(operatorStack.top());
						operatorStack.pop();
					}
					operatorStack.push(tokens[x]);
					break;
				case RPAREN:
					while (operatorStack.top().tag != LPAREN) {							// While loop through the operator stack to check for left parentheses.
						result.push_back(operatorStack.top());
						operatorStack.pop();
					}
					operatorStack.pop();
					break;
			}    
		}
		while (!operatorStack.empty()) {
			result.push_back(operatorStack.top());
			operatorStack.pop();
		}
		return result;
	}
    catch (logic_error e) {
		cout << e.what() << endl;
    }
}

/**
 * Check the precedence of two operators.
 * @param operator1 an operator from the infix expression.
 * @param operator2 an operator from the operator stack
 * @return boolean true if operator1 is lower or equal in precedence
 * to operator2.
 */
bool InfixCalculator::precedence(Token operator1, Token operator2) {
    if (operator1.o == ADD || operator1.o == SUBTRACT) {
        if (operator2.o == MULTIPLY || operator2.o == DIVIDE || operator2.o == ADD || operator2.o == SUBTRACT) {
            return true;
        }
    }
    if (operator1.o == MULTIPLY || operator1.o == DIVIDE) {
        if (operator2.o == ADD || operator2.o == SUBTRACT) {
            return false;
        }
    }
    return true;
}

/**
 * Check for balanced braces.
 * @param tokens a vector of tokens in infix form.
 * @return boolean true if the braces are balanced or false if
 * the braces are unbalanced.
 */
bool InfixCalculator::checkParentheses(vector<Token> tokens) {
    stack<char> braces;						// Declare a stack to check for parentheses.
    int size = tokens.size();
    
    for (int x = 0; x < size; x++) {					// For loop through the tokens to check for balanced parentheses.
        if (tokens[x].tag == LPAREN) {
            braces.push('(');
        }
        if (tokens[x].tag == RPAREN) {
            if (!braces.empty()) {
                braces.pop();
            }
            else {
                throw (logic_error("The expression has unbalanced parentheses."));
            }
        }
    }
    if (braces.empty()) {
        return true;
    }
    else {
        throw (logic_error("The expression has unbalanced parentheses."));
    }
}

/**
 * Evaluate the postfix expression.
 * @param tokens a vector of tokens.
 * @return pc.eval(infixToPostfix(tokens)) the function call to the postfix calculator.
 */
double InfixCalculator::eval(vector<Token> tokens) {
    return pc.eval(infixToPostfix(tokens));				// Call the eval function in PostfixCalculator.cpp.
}
