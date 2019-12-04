#include "Binary_Node.h"

#ifndef _SUB_NODE_H_
#define _SUB_NODE_H_

class Sub_Node : public Binary_Node
{

public:
	//constructor
	Sub_Node(Node* left, Node* right);

	int operate(int a, int b);

};

#endif  // !defined _SUB_NODE_H_