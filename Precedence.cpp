//This holds the values for precedence

#include "Precedence.h"

int Order::precedence(std::string in) {
	if (in == " % " || in == " * " || in == " / ")		//if token is equal to modulo, multiply, or divide return level 4 precedence
		return 4;
	else if (in == " + " || in == " - ")				//If token is equal to add and minus return level 3 precedence
		return 3;
	else if (in == " ) ")								//If token is equal to a right parenthesis return leve 1 precedence
		return 1;
	else if (in == " ( ")								//If token is equal to a left parenthesis return level 0 precedence
		return 0;
	else												//If token is neither of the above three it is an operand thus return operand level precedence
	{
		return 2;
	}
}