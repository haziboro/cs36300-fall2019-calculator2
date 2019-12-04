#include "Node.h"

#ifndef _UNARY_NODE_H_
#define _UNARY_NODE_H_

//Node for Unary operations
class Unary_Node : public Node
{
public:

	//constructor
	Unary_Node(Unary_Node* left);

	//performs unary operations
	virtual int operate(int a) = 0;

};

#endif  // !defined _UNARY_NODE_H_