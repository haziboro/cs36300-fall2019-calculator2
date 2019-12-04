#include "Mod_Node.h"

//constructor
Mod_Node::Mod_Node(Node* left, Node* right)
	:Binary_Node::Binary_Node(left, right) {}

//operate
int Mod_Node::operate(int a, int b)
{
	if (b == 0) {
		throw 2;
	}
	else {
		return a % b;
	}
}