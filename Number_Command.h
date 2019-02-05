//Header file for the execute commands

#ifndef NUMBER_COMMAND_H
#define NUMBER_COMMAND_H

#include "Expr_Command.h"
#include "Stack.h"

//Number Command
class Number_Command : public Expr_Command {
public:
	//Constructor
	Number_Command(Stack <int> & s, int n)
		: s_(s), n_(n) { }

	//Number Execute Command that pushes saved integer onto stack
	void execute(void) {
		s_.push(this->n_);
	}

private:
	Stack <int> & s_;
	int n_;
};

#endif