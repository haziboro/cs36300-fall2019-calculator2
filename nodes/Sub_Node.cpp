#include "Sub_Node.h"

//constructor
Sub_Node::Sub_Node(Node* left, Node* right)
	:Binary_Node::Binary_Node(left, right) {}

//operate
int Sub_Node::operate(int a, int b)
{
	return a - b;
}