//Header file for the Add command

#ifndef Subtract_COMMAND_H
#define Subtract_COMMAND_H

#include "Expr_Command.h"
#include "Stack.h"

//Subtract Command
class Subtract_Command : public Expr_Command {
public:
	//constructor
	Subtract_Command(Stack <int> & s) : s_(s) { }

	//Subtract Execute Command pops two off of the stack, subtracts them, and pushes the result back on stack
	virtual void execute(void) {
		int n2 = s_.pop(), n1 = s_.pop();
		s_.push(n1 - n2);
	}
private:
	Stack <int> & s_;
};

#endif