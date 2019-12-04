#include "Binary_Node.h"

#ifndef _DIV_NODE_H_
#define _DIV_NODE_H_

class Div_Node : public Binary_Node
{
	
public:
	//constructor
	Div_Node(Node* left, Node* right);

	int operate(int a, int b);

};

#endif  // !defined _DIV_NODE_H_