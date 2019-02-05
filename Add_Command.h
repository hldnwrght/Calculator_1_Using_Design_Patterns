//Header file for the Add command

#ifndef Add_COMMAND_H
#define Add_COMMAND_H

#include "Expr_Command.h"
#include "Stack.h"

//Add Command
class Add_Command : public Expr_Command {
public:
	//Add_Command Constructor
	Add_Command(Stack <int> & s) : s_(s) { }

	//Execute Function pops off values of stack, adds, and then pushes them back
	virtual void execute(void) {
		int n2 = s_.pop(), n1 = s_.pop();
		s_.push(n1 + n2);
	}
private:
	Stack <int> & s_;
};

#endif