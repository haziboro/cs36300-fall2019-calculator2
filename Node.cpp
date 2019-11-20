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
	if (left_ != NULL) {
		delete left_;
	}
	if (right_ != NULL) {
		delete right_;
	}
}