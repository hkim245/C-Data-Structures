/**
 * @file PostfixCalculator.h
 * @author Harry Kim
 * CSC237, Fall 2018, Assignment 4
 */
 
#ifndef POSTFIX_CALCULATOR_H
#define POSTFIX_CALCULATOR_H

#include "EvalInterface.h"
#include "Token.h"
#include <vector>
using namespace std;

class PostfixCalculator : public EvalInterface<double>
{
public:
	/**
     * Evaluate the postfix expression.
     * @param tokens a vector of tokens.
     * @return result the result of the infix expression.
     */
    double eval(vector<Token> tokens);
};

#endif
