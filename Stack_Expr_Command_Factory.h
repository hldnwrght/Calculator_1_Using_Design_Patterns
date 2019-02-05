//This holds the stack Expression Command Factory

#ifndef STACK_EXPR_COMMAND_FACTORY_H
#define STACK_EXPR_COMMAND_FACTORY_H

#include "Expr_Command_Factory.h"
#include "Stack.h"

class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:
	Stack_Expr_Command_Factory(Stack <int> & stack_) : stack_(stack_) {}

	//creates number command and returns its object
	virtual Number_Command * create_number_command(int num) {
		return new Number_Command(this->stack_, num);
	}

	//creates add command and returns its object
	virtual Add_Command * create_add_command(void) {
		return new Add_Command(this->stack_);
	}

	//creates subtract command and returns its object
	virtual Subtract_Command * create_subtract_command(void) {
		return new Subtract_Command(this->stack_);
	}

	//creates multiply command and returns its object
	virtual Multiply_Command * create_multiply_command(void) {
		return new Multiply_Command(this->stack_);
	}

	//creates divide command and returns its object
	virtual Divide_Command * create_divide_command(void) {
		return new Divide_Command(this->stack_);
	}

	//creates modulo command and returns its object
	virtual Modulo_Command * create_modulo_command(void) {
		return new Modulo_Command(this->stack_);
	}

	/*
	//creates left parenthesis command and returns its object
	virtual Left_Parenthesis_Command * create_left_parenthesis_command(int num) {
		return new Left_Parenthesis_Command(this->stack_, num);
	}

	//creates right parenthesis command and returns its object
	virtual Right_Parenthesis_Command * create_right_parenthesis_command(void) {
		return new Right_Parenthesis_Command(this->stack_);
	}
	*/
private:
	Stack <int> & stack_;
};
#endif