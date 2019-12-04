#include "Add_Node.h"

//constructor
Add_Node::Add_Node(Node* left, Node* right)
	:Binary_Node::Binary_Node(left, right) {}

//operate
int Add_Node::operate(int a, int b)
{
	return a + b;
}