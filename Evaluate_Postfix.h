//header File for Evalaute Postfix

#ifndef EVALUATE_POSTFIX_H
#define EVALUATE_POSTFIX_H

#include "Array_Iter.h"
#include "Expr_Command.h"


class Evaluate_Postfix{
public:
	bool evaluate_postfix(Array_Iterator<Expr_Command*> & iter);
};
#endif