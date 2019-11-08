#include <iostream>
#include "library/Stack.h"

#ifndef _NODE_H_
#define _NODE_H_

//Node to compose elements of arithmetic expression tree
struct Node {
	//constructor
	Node(std::string data);

	//destructor
	~Node();

	//operator or operand
	std::string data_;

	//left child
	Node* left_;

	//right child
	Node* right_;
};

#endif  // !defined _NODE_H_
