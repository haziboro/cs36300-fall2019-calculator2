#include <sstream>
#include "Abst_Builder.h"
#include "../nodes/Add_Node.h"
#include "../nodes/Sub_Node.h"
#include "../nodes/Mult_Node.h"
#include "../nodes/Div_Node.h"
#include "../nodes/Mod_Node.h"
#include "../nodes/Var_Node.h"

#ifndef _BUILDER_H_
#define _BUILDER_H_

//Creates Node elements for insertion into expression tree
class Builder : public Abst_Builder
{
public:
	//constructor
	Builder(Stack<Node*> & s);

	//destructor
	~Builder();

	/**
	* Creates Integer Node with no children, pushes Node to Stack s_.
	*
	* @param[in]	num		Operand
	**/
	void build_int(std::string num);

	/**
	* Creates variable Node with no children, pushes Node to Stack s_. Throws exception if variable contains more than one character.
	* 
	* @param[in]	var		variable
	* @exception	5		Invalid variable
	**/
	void build_var(std::string var);

	//Creates "+" operation Node with two operands as children, pushes to stack.
	void build_add();
	
	//Creates "-" operation Node with two operands as children, pushes to stack.
	void build_sub();

	//Creates "*" operation Node with two operands as children, pushes to stack. 
	void build_mult();

	//Creates "/" operation Node with two operands as children, pushes to stack.
	void build_div();

	//Creates "%" operation Node with two operands as children, pushes to stack.
	void build_mod();

	/**
	* Converts numbers in string format to integers.
	*
	* @param[in]	num			string to convert
	* @return		x			converted integer
	**/
	int converter(std::string num);

	//destroys tree roots in stacks
	void clear_stack();

private:

	/**
	* Traverses tree using postorder traversal to deallocate all Nodes
	*
	* @param[in]	root	root of expression tree
	**/
	void delete_tree(Node* root);

	/**
	* pops top node of stack and returns a pointer to it. Throws exception if stack is empty.
	*
	* @return		child		pointer to node
	* @exception	1			Invalid operation
	**/
	Node* make_child();

	//for manipulating tree nodes, root is always top element
	Stack<Node*> & s_;
};

#endif  // !defined _BUILDER_H_