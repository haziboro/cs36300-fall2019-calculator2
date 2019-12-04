#include "Node.h"

//constructor
Node::Node()
	:data_(0),
	//COMMENT: Use nullptr instead as it is a c++11 keyword.
	//RESPONSE: Did it
	left_(nullptr),
	right_(nullptr),
	var_(false)
{

}

//constructor
Node::Node(int num)
	:data_(num),
	left_(nullptr),
	right_(nullptr),
	var_(false)
{

}

//constructor
Node::Node(std::string var)
	:data_(0),
	left_(nullptr),
	right_(nullptr),
	var_(true)
{

}

//constructor
Node::Node(Node * left)
	:data_(0),
	left_(left),
	right_(nullptr),
	var_(false)
{

}

//constructor
Node::Node(Node* left, Node* right)
	:data_(0),
	left_(left),
	right_(right),
	var_(false)
{

}

//get_left
Node* Node::get_left()
{
	return left_;
}

//get_right
Node* Node::get_right()
{
	return right_;
}

//set_data
void Node::set_data(int a)
{
	data_ = a;
}

//get_data
int Node::get_data()
{
	return data_;
}

//is_var
bool Node::is_var()
{
	return var_;
}

//operate
int Node::operate() { throw 5; }
//operate
int Node::operate(int a) { throw 5; }
//operate
int Node::operate(int a, int b) { throw 5; }