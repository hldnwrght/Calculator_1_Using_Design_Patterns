//This holds the code for evaluate postix

#include <iostream>
#include "Evaluate_Postfix.h"


//Function that iterates over the given array until empty and executes the command
bool Evaluate_Postfix::evaluate_postfix(Array_Iterator<Expr_Command*> & iter) {
	for (; !iter.is_done(); iter.advance()) {
		(*iter)->execute();
	}
	return true;
}
