//This holds the express command

#ifndef EXPR_COMMAND_H
#define EXPR_COMMAND_H

#include <iostream>

class Expr_Command {
public:
	virtual void execute(void) = 0;
};

#endif