#include <iostream>
#include "../library/Stack.h"

#ifndef _NODE_H_
#define _NODE_H_

//Node to compose elements of arithmetic expression tree
class Node {

public:
	//constructor
	Node();

	//constructor overload for variables
	Node(std::string var);

	//constructor overload for integers
	Node(int num);

	//constructor overload for unary operations
	Node(Node* left);

	//constructor overload for binary operations
	Node(Node* left, Node* right);

	//returns left child
	Node* get_left();

	//returns right child
	Node* get_right();

	/**
	* changes stored value of data_
	* 
	* @param[in]	a		value to set data to
	**/
	void set_data(int a);

	//returns integer value stored in data_
	int get_data();

	//checks if Node is a variable
	bool is_var();

	//performs arithmetic operations and returns results. throws exception if undefined.
	virtual int operate();

	//overload
	virtual int operate(int a);

	//overload
	virtual int operate(int a, int b);

private:
	//stored data
	int data_;

	//left child
	Node* left_;

	//right child
	Node* right_;

	//determines if Node possesses a variable value
	bool var_;

};

#endif  // !defined _NODE_H_
