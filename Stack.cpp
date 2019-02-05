// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h"
#include <iostream>
#include <stdexcept>

//
// Default Constructor of the Stack
//
template <typename T>
Stack <T>::Stack (void)
{

}

//
//Copy Constructor of the Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
{
	head_ = sizeof(stack.head_);				//sets head to size of stack
	stack_size_ = sizeof(stack.stack_size_);		//sets stack size to the size of stack
	stack_data_ = new T[stack.stack_size_];				//creates stack memory
	this->stack_data_ = *stack.data;	//sets up stack values
}

//
//Destructor of the ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
	delete [] stack_data_;
	stack_data_ = nullptr;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	//Checks to see if the stack is full if it is then it throws overflow
	try
	{
		if (is_full())
		{
			throw std::overflow_error("Error: Is full");
		}
	}
	catch (std::overflow_error)
	{
		std::cout << "Error: Overflow was detected" << std::endl;
		exit(0);
	}
	
	//Inserts the element onto the stack and increments the stack size
	std::cout << "Inserting Element: " << element << std::endl;
	stack_data_[++head_] = element;
	++stack_size_;
}

//
// pop
//
template <typename T>
T Stack <T>::pop (void)
{
	//Checks to see if the stack is empty if it is then throws flag
	try
	{
		if (is_empty())
		{
			throw std::underflow_error("Error: It is empty");
		}
	}
	catch (std::underflow_error)
	{
		std::cout << "Error: underflow was detected" << std::endl;
		exit(0);
	}
	

	//Pops the top element off the stack and decrements stack pointer
	std::cout << "Popping Element: " << stack_data_[head_] << std::endl;
	stack_data_[head_--];
	--stack_size_;

	return stack_data_[head_];
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (this != &rhs)
	{
		size_t _size;
		size_t i = 0;
		T ch;

		//gets size of array
		std::cout << "Enter in the size of the array: ";
		std::cin >> _size;

		//fill in array
		T* newT_ = new T(_size);
		std::cout << "Enter in the values for the array: " << std::endl;
		while (i < _size) {
			std::cin >> ch;
			newT_[i] = ch;
			i++;
		}
		return *newT_;
	}
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	//Checks to see if the stack is cleared
	if (is_empty()) 
	{
		std::cout << "Stack has already been cleared" << std::endl;
	}
	//If not then empties stack
	else 
	{
		while (!is_empty()) 
		{
			stack_data_[head_--];
		}

		std::cout << "Stack Has been Cleared" << std::endl;
	}
}
