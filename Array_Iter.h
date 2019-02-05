//This file holds the code for the array iterator

#ifndef ARRAY_ITER_H
#define ARRAY_ITER_H

#include "Array.h"

template <typename T>
class Array_Iterator {
public:
	Array_Iterator(Array <T> & a)
		: a_(a), curr_(0) { }
	
	~Array_Iterator(void) { }

	bool is_done(void) { 
		return this->curr_ >= this->a_.cur_size_; 
	}
	bool advance(void) { 
		++ this->curr_; 
	}
	T & operator * (void) { 
		return this->a_.data_[this->curr_]; 
	}
	T * operator -> (void) { 
		return &this->a_.data_[this->curr_]; 
	}

private:
	Array <T> & a_;
	size_t curr_;
};
#endif