//Header file for the multiply command

#ifndef MULTIPLY_COMMAND_H
#define MULTIPLY_COMMAND_H

#include "Expr_Command.h"
#include "Stack.h"

//Multiply Command
class Multiply_Command : public Expr_Command {
public:
	//Constructor
	Multiply_Command(Stack <int> & s) : s_(s) { }

	//Multiply Execute Command that pops two, multiplys them, and then pushes them back onto stack
	virtual void execute(void) {
		int n2 = s_.pop(), n1 = s_.pop();
		s_.push(n1 * n2);
	}

private:
	Stack <int> & s_;
};

#endif