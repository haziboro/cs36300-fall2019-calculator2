#include "Binary_Node.h"

#ifndef _MULT_NODE_H_
#define _MULT_NODE_H_

class Mult_Node : public Binary_Node
{

public:
	//constructor
	Mult_Node(Node* left, Node* right);

	int operate(int a, int b);

};

#endif  // !defined _MULT_NODE_H_