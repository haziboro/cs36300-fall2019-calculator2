#include <iostream>
#include "library/Stack.h"

//Node to compose elements of arithmetic expression tree
struct Node {
	//constructor
	Node(std::string data)
		:data_(data),
		left_(NULL),
		right_(NULL) {};

	//operator or operand
	std::string data_;

	//left child
	Node* left_;

	//right child
	Node* right_;
};