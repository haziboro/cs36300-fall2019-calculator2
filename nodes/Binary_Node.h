#include "Node.h"

#ifndef _BINARY_NODE_H_
#define _BINARY_NODE_H_

//Node for Binary operations
class Binary_Node : public Node
{
public:

	//constructor
	Binary_Node(Node* left, Node* right);

	//performs binary operations
	virtual int operate(int a, int b) = 0;

};

#endif  // !defined _BINARY_NODE_H_