// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>
#include "Array.h"

//
//Defaut Constructor of Array
//
template <typename T>
Array <T>::Array (void) : max_size_(0), cur_size_(0)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length) :cur_size_(length), max_size_(length)
{
	T* data_ = new T[length];
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill) : cur_size_(length), max_size_(length)
{
	T*data_ = new T[length];
	data_ = &fill;					//data is set to the address of fill
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array) //: cur_size_ = length, this->max_size_ = length
{
	cur_size_ = array.cur_size_;
	T* data_ = new T[array.cur_size_];
	this->data_ = *array.data_;
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	delete[] data_;
	data_ = nullptr;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if (this != &rhs)
	{
		size_t _size;		//for the size of the array
		size_t i = 0;			//holds number of iterations
		T ch;			//takes in contents for array

		//gets size of array
		std::cout << "Enter in the size of the array: ";
		std::cin >> _size;

		//fills in array
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
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	//Trys to go to data at index, if it dne then throws out of range error;
	try {
		this->data_.at(index);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << " Out of Range error: " << oor.what() << '\n';
		exit(0);
	}

	//If success returns data at that index
	return this->data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	//Trys to go to data at index, if it dne then throws out of range error;
	try {
		this->data_.at(index);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << " Out of Range error: " << oor.what() << '\n';
		exit(0);
	}

	//If success returns data at that index
	return this->data_[index];
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
	//Trys to go to data at index, if it dne then throws out of range error;
	try {
		this->data_.at(index);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << " Out of Range error: " << oor.what() << '\n';
	}

	return this->data_[index];	//if data is within scope then return value
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
	//Trys to go to data value
	try {
		this->data_.at(index);
	}
	//If it is outside the range then it catches the exception
	catch (const std::out_of_range& oor) {
		std::cerr << " Out of Range error: " << oor.what() << '\n';
		exit(0);
	}

	this->data_[index] = value; 		//sets value to indexed position
	std::cout << "Memory changed to " << value << "at location" << index << std::endl;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size > max_size_) {
		T* newT_ = new T(cur_size_);				//creates new dynamic array to copy from
		memcpy(newT_, this->data_, sizeof(new_size));	//Copies the new dynamic array
		max_size_ = new_size;							//sets the new max size
		delete [] data_;								//deletes old array
		data_ = nullptr;

		char* data_ = new char(max_size_);						//Initializes data again with values of array newArr
		memcpy(this->data_, newT_, sizeof(new_size));	//Copies the new dynamic array into the old dynamic array

		delete (newT_);									//Frees memory
	}
	if (new_size > 0) {
		cur_size_ = new_size;
	}
}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
	size_t _index = 0; //sets index
	while(_index != max_size_ || value != this->data_[_index]) {	//loops until either index reaches max size or character is found
		_index++;
	}
	if (_index == max_size_) {									//If character is not found then return a -1 to inform user
		return -1;
	}
	else {													//else return index
		return _index;
	}
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
	//Checks to make sure that start is within range 
	try {
		this->data_.at(start);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << " Out of Range error: " << oor.what() << '\n';
	}
	while (start != (cur_size_ + 1) || val != this->data_[start]) { 	//loops until either index reaches max size or character is found
		start++;
	}

	if (start == (cur_size_ + 1)) {									//If character is not found then return a -1 to inform user
		return -1;
	}
	else {													//else return index
		return start;
	}
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if (this != &rhs)
	{

		//we test to see if the size of the rhs matches the lhs
		if (sizeof(rhs) == cur_size_) {
			//next we check if both sides match in terms of data
			size_t _index = 0;
			//loops until either data is not the same or index is greater than cur_size_
			while (this->data_[_index] == rhs[_index] || _index > cur_size_) {
				_index++;
			}
			//if index surpasses cur_size_ then then values are the same and their is equality
			if (_index > cur_size_) {
				return true;
			}
		}
	}
	//if sizes are not the same then their is inequality 
	return false;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	//we test to see if the size of the rhs does not match the lhs
	if (sizeof(rhs) == cur_size_) {
		//next we check if both sides match in terms of data
		size_t _index = 0;
		//loops until either data is not the same or index is greater than cur_size_
		while (this->data_[_index] != rhs[_index] || _index > cur_size_) {
			_index++;
		}
		//if index surpasses cur_size_ then then values are the same and their is equality
		if (_index > cur_size_) {
			return false;
		}
	}

	//if sizes are not the same then their is inequality 
	return true;
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
	//Checks to see if the max_size_ has been reached
	if (cur_size_ != max_size_) {
		this->data_[cur_size_] = value;	//if the max size has not been reached then add ch to the array
		cur_size_++;					//increases the size of cur_size_
	}
}
