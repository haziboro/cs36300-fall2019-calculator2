#include "Node.h"

//constructor
Node::Node(std::string data)
	:data_(data),
	left_(NULL),
	right_(NULL)
{

}

//destructor
Node::~Node()
{
	delete[] left_, right_;
}