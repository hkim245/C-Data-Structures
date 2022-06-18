/**
 * @file InfixCalculator.h
 * @author Harry Kim
 * CSC237, Fall 2018, Assignemnt 4
 */

#ifndef INFIX_CALCULATOR_H
#define INFIX_CALCULATOR_H

#include "EvalInterface.h"
#include "PostfixCalculator.h"
#include "Token.h"
#include <vector>
using namespace std;

class InfixCalculator : public EvalInterface<double>
{
private:
    PostfixCalculator pc;
	
    /**
     * Convert the infix expression to a postfix expression.
     * @param expr a vector of tokens in infix form.
     * @return result a vector of token in postfix form.
     */
    vector<Token> infixToPostfix(vector<Token> expr);
	
    /**
     * Check for balanced braces.
     * @param tokens a vector of tokens in infix form.
     * @return boolean true if the braces are balanced or false if
     * the braces are unbalanced.
     */
    bool checkParentheses(vector<Token> tokens);
	
    /**
     * Check the precedence of two operators.
     * @param operator1 an operator from the infix expression.
     * @param operator2 an operator from the operator stack
     * @return boolean true if operator1 is lower or equal in precedence
     * to operator2.
     */
    bool precedence(Token operator1, Token operator2);

public:
    /**
     * Evaluate the postfix expression.
     * @param tokens a vector of tokens.
     * @return pc.eval(infixToPostfix(tokens)) the function call to the postfix calculator.
     */
    double eval(vector<Token> tokens);
};

#endif
