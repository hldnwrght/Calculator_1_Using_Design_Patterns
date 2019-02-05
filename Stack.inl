// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return head_ + 1;			//returns current size of stack
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	return head_;				//returns top of stack
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return head_ == -1;		  //returns if it is empty
}

template <typename T>
inline
bool Stack <T>::is_full(void) const
{
	return head_ == stack_size_ - 1;	//returns if it is full
}
