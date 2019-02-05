//Header File for Infix to Postfix Conversion

#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

#include "Expr_Command_Factory.h"
#include "Array_Iter.h"
#include "Expr_Command.h"

class Infix_To_Postfix {
public:
	bool infix_to_postfix(const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix);
};
#endif