//This file holds the infix to postfix class


#include "Infix_To_Postfix.h"
#include "Evaluate_Postfix.h"
#include "Precedence.h"
#include "Array_Iter.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

bool Infix_To_Postfix::infix_to_postfix(const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix) {
	std::istringstream input (infix); // create a input stream parser
	std::string token; // current token in string/stream
	Expr_Command * cmd = 0; // created command object
	Stack <std::string> value;		//seperate stack to save tokens
	Stack <Expr_Command *> temp;	//stack for saving commands
	Order prec;						//Object for precedence method
	int i = 0;						//Counter for array

	//Loops until end of infix
	while (!input.eof()) {
		input >> token;			// Parses infix and goes to next token

		//if token is equal to + then create add command, and push command onto stack and token onto seperate stack
		if (token == " + ") {
			cmd = factory.create_add_command();
			temp.push(cmd);
			value.push(token);
		}
		//if token is equal to - then create subtract command, and push command onto stack and token onto seperate stack
		else if (token == " - ") {
			cmd = factory.create_subtract_command();
			temp.push(cmd);
			value.push(token);
		}
		//if token is equal to / then create divide command, and push command onto stack and token onto seperate stack
		else if (token == " / ") {
			cmd = factory.create_divide_command();
			temp.push(cmd);
			value.push(token);
		}
		//if token is equal to * then create multiply command, and push command onto stack and token onto seperate stack
		else if (token == " * ") {
			cmd = factory.create_multiply_command();
			temp.push(cmd);
			value.push(token);
		}
		//if token is equal to % then create modulo command, and push command onto stack and token onto seperate stack
		else if (token == " % ") {
			cmd = factory.create_modulo_command();
			temp.push(cmd);
			value.push(token);
		}
		//if token is equal to ( then does the following:
		//it then saves it into the array, and pushes the command on one stack and token in the other
		else if (token == " ( ") {
			//cmd = factory.create_left_parenthesis_command(atoi(token.c_str()));		May be added on later distro
			//postfix[i] = cmd;
			//temp.push(cmd);
			value.push(token);
		}
		//If token is equal to ) then does the following:
		//it then pops both stacks and loops until left parenthesis is found
		//upon finding the left parenthesis it saves the right parenthesis command into array 
		else if (token == " ) ") {
			//cmd = factory.create_right_parenthesis_command();
			while (prec.precedence(value.top()) != 0) {
				postfix[i++] = temp.pop();
				value.pop();
			}
			//postfix[i] = cmd;
		}
		//If the value is a digit then create number command and store command on array
		else if (isdigit(atoi(token.c_str()))) {
			cmd = factory.create_number_command(atoi(token.c_str()));
			postfix[i] = cmd;
		}
		//If value is not an accepted parameter then return false and handle accordingly
		else {
			return false;
		}
	}
		//Once done check to see if stack is empty if not pop and store into array
		while (!temp.is_empty()) {
			postfix[i++] = temp.pop();
		}
	
	//Creates array iterator object to pass
	Array_Iterator<Expr_Command *> arr(postfix);

	//Create Evaluate_Postfix object and pass the object created iterator object to iterate
	Evaluate_Postfix eva;
	eva.evaluate_postfix(arr);
	return true;
}