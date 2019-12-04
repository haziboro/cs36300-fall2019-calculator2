#include "Div_Node.h"

//constructor
Div_Node::Div_Node(Node* left, Node* right)
	:Binary_Node::Binary_Node(left, right) {}

//operate
int Div_Node::operate(int a, int b)
{
	if (b == 0) {
		throw 2;
	}
	else {
		return a / b;
	}
}