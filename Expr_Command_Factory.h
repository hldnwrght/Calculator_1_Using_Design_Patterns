//header file for abstract factory

#ifndef EXPR_COMMAND_FACTORY_H
#define EXPR_COMMAND_FACTORY_H

#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Number_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"
#include "Parenthesis_Command.h"


class Expr_Command_Factory
{
public:
	Expr_Command_Factory(void) {}
	virtual ~Expr_Command_Factory(void) = 0;
	virtual Number_Command * create_number_command(int num) = 0;
	virtual Add_Command * create_add_command(void) = 0;
	virtual Subtract_Command * create_subtract_command(void) = 0;
	virtual Divide_Command * create_divide_command(void) = 0;
	virtual Multiply_Command * create_multiply_command(void) = 0;
	virtual Modulo_Command * create_modulo_command(void) = 0;
	//virtual Left_Parenthesis_Command * create_left_parenthesis_command(int num) = 0;
	//virtual Right_Parenthesis_Command * create_right_parenthesis_command(void) = 0;

private:
	// prevent the following operations
	Expr_Command_Factory(const Expr_Command_Factory &);
	const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};
#endif