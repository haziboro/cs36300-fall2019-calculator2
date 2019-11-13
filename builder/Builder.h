#include "Abst_Builder.cpp"

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
	* Creates operand Node with no children, pushes Node to Stack s_.
	* 
	* @param[in]	n		Operand
	**/
	void build_operand(std::string n);

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

	//destroys tree elements
	void demolish();

private:
	/**
	* pops top node of stack and returns a pointer to it. Throws exception if stack is empty.
	*
	* @return		child		pointer to node
	* @exception	1			Invalid operation
	**/
	Node* make_child();

	Stack<Node*> & s_;
};

#endif  // !defined _BUILDER_H_