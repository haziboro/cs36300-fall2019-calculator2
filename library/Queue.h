//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
 //==============================================================================
#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>
#include <cstring>

/**
 * @class Queue
 */
template<typename T>
class Queue
{
public:
	/// Type definition of the type.
	typedef T type;

	/**
   * @class empty_exception
   *
   * Exception thrown to indicate the stack is empty.
   */
	//COMMENT: There is no need to re-define the empty exception class here.
	//You can access the empty_exception class in Stack using the :: operator, Stack::empty_exception
	//RESPONSE: Did what you said

	/// Default constructor.
	Queue(void);

	/// Copy constructor.
	Queue(const Queue& s);

	/// Destructor.
	~Queue(void);

	const Queue& operator = (const Queue& rhs);

	///adds the element to the end of the list
	void enqueue(T element);

	 /**
	* removes the element at the front of the list. If there are not elements in the
	* queue, this method throws empty_exception
	*
	* @retval		(*head_).data_
	* @exception	empty_exception The queue is empty
	*/
	T dequeue();

	/**
   * returns the number of elements in the queue.
   *
   * @return         Size of the queue.
   */
	size_t size(void) const;

	/**
   * test if the queue is empty. If the queue is empty, then this method returns
   * true. Otherwise, this method returns false
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
	bool is_empty(void) const;

	/// Remove all the elements in the queue.
	void clear(void);


private:
	/**
	 * Format for element storage in queue. Contains T data and pointer to next element.
	 * If there is no element ahead of Node, pointer directs to sentinel_
	 */
	struct Node {
		//COMMENT: Node.data_ is not a pointer, so assigning it NULL doesn't make any sense.
		//Simply create a constructor for your stuct if you want the member variables to have default values.
		////RESPONSE: removed default values
		T data_;
		Node* prev_;
	};

	///Dummy node for easier redirection of Nodes
	Node sentinel_;
	struct Node* head_;
	struct Node* tail_;
	size_t size_;



};

// include the inline files
#include "Queue.inl"
// include the source file since template class
#include "Queue.cpp"

#endif   // !defined _CS507_QUEUE_H_