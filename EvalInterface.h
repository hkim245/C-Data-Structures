/**
 * @file EvalInterface.h
 * @author Dr. Schwesinger
 */
#ifndef EVAL_INTERFACE_H
#define EVAL_INTERFACE_H

#include <vector>
#include <string>
#include "Token.h"

/**
 * @brief The EvalInterface is an abstract class for evaluating
 * different kinds of expressions.
 */
template <class T>
class EvalInterface
{
public:
    /**
     * @brief evaluate an expression represented as a sequence of tokens.
     * @param expr the expression to evaluate
     * @return the result of evaluating the expression
     */
    virtual T eval(std::vector<Token> expr) = 0;

    /**
     * virtual destructor so subtype destructors get called correctly
     */
    virtual ~EvalInterface() {};
};

#endif
