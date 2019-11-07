// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//for empty_exception definition
#include "Stack.h"

//
// Queue, See header file for more info
//
template <typename T>
Queue<T>::Queue(void)
	:head_(&sentinel_),
	tail_(&sentinel_),
	size_(0)
{

}

//
// Queue, See header file for more info
//
template <typename T>
Queue<T>::Queue(const Queue& queue)
	:head_(&sentinel_),
	tail_(&sentinel_)
{
	*this = queue;
}

//
// ~Queue, See header file for more info
//
template <typename T>
Queue<T>::~Queue(void)
{
	clear();
}

//
// operator =, See header file for more info
//
template <typename T>
const Queue <T>& Queue <T>::operator = (const Queue& rhs)
{
	sentinel_.prev_ = rhs.sentinel_.prev_;
	head_ = rhs.head_;
	tail_ = rhs.tail_;
	size_ = rhs.size_;
	return *this;
}


//
// enqueue, See header file for more info
//
template <typename T>
void Queue<T>::enqueue(T element)
{
	Node* new_node_ = new Node;
	new_node_->data_ = element;
	if (size_ == 0) {
		head_ = new_node_;
		tail_ = new_node_;
		sentinel_.prev_ = new_node_;
	}
	new_node_->prev_ = &sentinel_;
	tail_->prev_ = new_node_;
	tail_ = new_node_;
	size_++;
}

//
// dequeue, See header file for more info
//
template <typename T>
T Queue<T>::dequeue()
{
	try {
		if (is_empty() == true) {
			throw typename Stack<T>::empty_exception();
		}
		else {
			T temp;
			if (size_ == 1) {
				temp = tail_->data_;
				head_ = &sentinel_;
				tail_ = &sentinel_;
				sentinel_.prev_ = NULL;
			}
			else {
				temp = head_->data_;
				head_ = head_->prev_;
				sentinel_.prev_ = head_;
			}
			size_--;
			return temp;
		}
	}
	catch (std::exception) {
		std::cout << "Exception: The Queue is empty" << std::endl;
		T error = 0;
		return error;
	}
}

//
// clear, See header file for more info
//
template <typename T>
void Queue<T>::clear(void)
{
	sentinel_.prev_ = &sentinel_;
	tail_ = &sentinel_;
	head_ = &sentinel_;
	size_ = 0;
}