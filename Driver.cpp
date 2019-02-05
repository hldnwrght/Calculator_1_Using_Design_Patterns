//This is the main file for the basic expression evaluator

#include <iostream>
#include <string>
#include "Stack_Expr_Command_Factory.h"
#include "Infix_To_Postfix.h"
#include "Stack.h"
#include "Array_Iter.h"
#include "Array.h"

void main() {
	std::string infix;					//Creates string to take in data from getline
	std::getline(std::cin, infix);		//Gets next line and saves it into infix
	
	//While loop to loop through each line until QUIT found
	while (infix != "QUIT") {					
		Stack <int> result;								//Instantiates the Stack
		Stack_Expr_Command_Factory factory(result);		//Passes value to stack

		Array <Expr_Command *> postfix;					//Instantiates Array
		Infix_To_Postfix convert;						//Instantiates Infix_To_Postfix
		convert.infix_to_postfix(infix, factory, postfix);		//sends string, factory reference, and iterator reference
		
		int res = result.pop();									//pops off result to the stack

		//Outputs answer
		std::cout << res;

		std::getline(std::cin, infix);					//gets new line from standard in
	}
}