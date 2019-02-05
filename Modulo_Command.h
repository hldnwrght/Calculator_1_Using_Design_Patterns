//Header file for the execute commands

#ifndef MODULO_COMMAND_H
#define MODULO_COMMAND_H

#include "Expr_Command.h"
#include "Stack.h"

//Modulos Command
class Modulo_Command : public Expr_Command {
public:
	//Constructor
	Modulo_Command(Stack <int> & s) : s_(s) { }

	//Modulo Execute Command that pops two, does the modulo, and then pushes back onto stack
	virtual void execute(void) {
		int n2 = s_.pop(), n1 = s_.pop();
		s_.push(n1 % n2);
	}

private:
	Stack <int> & s_;
};

#endif