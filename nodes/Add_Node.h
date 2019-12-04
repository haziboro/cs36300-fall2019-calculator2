#include "Binary_Node.h"

#ifndef _ADD_NODE_H_
#define _ADD_NODE_H_

class Add_Node : public Binary_Node
{

public:
	//constructor
	Add_Node(Node* left, Node* right);

	int operate(int a, int b);

};

#endif  // !defined _ADD_NODE_H_