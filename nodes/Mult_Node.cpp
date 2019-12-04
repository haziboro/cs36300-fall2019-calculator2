#include "Mult_Node.h"

//constructor
Mult_Node::Mult_Node(Node* left, Node* right)
	:Binary_Node::Binary_Node(left, right) {}

//operate
int Mult_Node::operate(int a, int b)
{
	return a * b;
}