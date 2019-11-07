// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#include <iostream>

//
// size, see header file for more info
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return size_;
}

//
// top, see header file for more info
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	try {
		if (is_empty() == true) {
			throw empty_exception();
		}
		else {
			Node temp = *top_node_;
			return temp.data_;
		}
	}
	catch (std::exception) {
		std::cout << "Exception: The Stack is empty" << std::endl;
		return 0;
	}
}

//
// is_empty, see header file for more info
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	if (top_node_ == &sentinel_) {
		return true;
	}
	else {
		return false;
	}
}

