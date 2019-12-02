#include "Node.h"

//constructor
Node::Node(std::string data)
	:data_(data),
	//COMMENT: Use nullptr instead as it is a c++11 keyword.
	left_(NULL),
	right_(NULL)
{

}