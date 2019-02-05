//Header file for the execute commands

#ifndef Divide_COMMAND_H
#define Divide_COMMAND_H

#include "Expr_Command.h"
#include "Stack.h"

//Divide Command
class Divide_Command : public Expr_Command {
public:
	//Constructor
	Divide_Command(Stack <int> & s) : s_(s) { }

	//Divide Execute command pops two, divides them, and pushes them back onto stack
	virtual void execute(void) {
		int n2 = s_.pop(), n1 = s_.pop();
		s_.push(n1 / n2);
	}

private:
	Stack <int> & s_;
};

#endif