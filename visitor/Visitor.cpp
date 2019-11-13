//Header File, includes more details about all below implementations
#include "Visitor.h"

//constructor
Visitor::Visitor(Stack<Node*> & s)
	:s_(s) {}

//solve
int Visitor::solve()
{
	int result = in_order(s_.top());
	return result;
}

//in_order
int Visitor::in_order(Node* n)
{
	if (n->right_ == NULL) {
		if (n->left_ == NULL) {
			return converter(n->data_);  //if left and right children are NULL, return integer value of operand
		}
		return operate(n->data_, in_order(n->left_));	//if right child is NULL but left child contains Node, return integer value of unary operation
	}
	return operate(n->data_, in_order(n->left_), in_order(n->right_));	//if neither child is NULL, return result of binary operation
}

//operate
int Visitor::operate(std::string op, int a, int b) 
{
	if (op == "+") {
		return a + b;
	}
	else if (op == "-") {
		return a - b;
	}
	else if (op == "*") {
		return a * b;
	}
	else if (b == 0) {		//prevents divide/mod by zero errors
		throw 2;
	}
	else if (op == "/") {
		return a / b;
	}
	else if (op == "%") {
		return a % b;
	}
}

//operate
int Visitor::operate(std::string op, int a)
{
	throw 5;
	return 0;
}

//converter
int Visitor::converter(std::string num)
{
	std::stringstream s(num);
	int x = 0;
	s >> x;
	if (s.fail()) {
		return var_handler(num);
	}
	return x;
}

//var_handler
int Visitor::var_handler(std::string var)
{
	return 0;
}