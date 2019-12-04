#include "Binary_Node.h"

#ifndef _MOD_NODE_H_
#define _MOD_NODE_H_

class Mod_Node : public Binary_Node
{

public:
	//constructor
	Mod_Node(Node* left, Node* right);

	int operate(int a, int b);

};

#endif  // !defined _MOD_NODE_H_