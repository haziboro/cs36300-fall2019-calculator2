// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack, see header file for more info
//
template <typename T>
Stack <T>::Stack(void)
	:top_node_(&sentinel_),
	size_(0)
{

}

//
// Stack, see header file for more info
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
	:top_node_(&sentinel_)
{
	*this = stack;
}

//
// ~Stack, see header file for more info
//
template <typename T>
Stack <T>::~Stack (void)
{
	clear();
}

//
// push, see header file for more info
//
template <typename T>
void Stack <T>::push (T element)
{
	Node *new_node  = new Node;
	new_node->data_ = element;
	new_node->prev_ = top_node_;
	top_node_ = new_node;
	size_++;
}

//
// pop, see header file for more info
//
template <typename T>
void Stack <T>::pop (void)
{
	try {
		if (is_empty() == true) {
			throw empty_exception();
		}
		else {
			top_node_ = top_node_->prev_;
			size_--;
		}
	}
	catch (std::exception) {
		std::cout << "Exception: The stack is empty" << std::endl;
	
	}
}

//
// operator =, see header file for more info
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	top_node_ = rhs.top_node_;
	size_	  = rhs.size_;
	return *this;
}

//
// clear, see header file for more info
//
template <typename T>
void Stack <T>::clear (void)
{
	top_node_ = &sentinel_;
}