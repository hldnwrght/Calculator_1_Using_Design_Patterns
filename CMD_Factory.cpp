//This is holds the methods for the Expr Command Factory and Stack Expr Command Factory

#include <iostream>
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"
#include "Stack.h"

Expr_Command_Factory::Expr_Command_Factory() {

}

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack <int> & stack_)
{

}

//Constructor for create_Number_Command
Number_Command * Stack_Expr_Command_Factory::create_number_command(int num) {
	Number_Command * num_cmd = new Number_Command(this->stack_);
	return num_cmd;
}

//Constructor for create_add_command
Add_Command * Stack_Expr_Command_Factory::create_add_command(void) {
	Add_Command * add_cmd = new Add_Command();
	return add_cmd;
}

//Constructor for create_subtract_command
Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command(void) {
	Subtract_Command * sub_cmd = new Subtract_Command();
	return sub_cmd;
}

//Constructor for create_multiply_command
Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command(void) {
	Multiply_Command * mul_cmd = new Multiply_Command();
	return mul_cmd;
}

//Constructor for create_divide_command
Divide_Command * Stack_Expr_Command_Factory::create_divide_command(void) {
	Divide_Command * div_cmd = new Divide_Command();
	return div_cmd;
}

//Constructor for create_modulo_command
Modulo_Command * Stack_Expr_Command_Factory::create_modulo_command(void) {
	Modulo_Command * mod_cmd = new Modulo_Command();
	return mod_cmd;
}

//Constructor for create_left_parenthesis_command
Left_Parenthesis_Command * Stack_Expr_Command_Factory::create_left_parenthesis_command(int num) {
	Left_Parenthesis_Command * lpar_cmd = new Left_Parenthesis_Command(num);
	return lpar_cmd;
}

//Constructor for create_left_parenthesis_command
Right_Parenthesis_Command * Stack_Expr_Command_Factory::create_right_parenthesis_command(void) {
	Right_Parenthesis_Command * rpar_cmd = new Right_Parenthesis_Command();
	return rpar_cmd;
}