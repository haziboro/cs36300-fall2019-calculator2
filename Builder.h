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
	* Creates operand Node with no children, pushes Node to Stack s_
	* 
	* @param[in]	n		Operand
	**/
	void build_num(int n);

	/**
	* Creates "+" operation Node with two operands as children. Throws exception if less than two elements available
	* 
	* @exception	1		Invalid Operation
	**/
	void build_add();

	/**
	* Creates "-" operation Node with two operands as children. Throws exception if less than two elements available
	*
	* @exception	1		Invalid Operation
	**/
	void build_sub();

	/**
	* Creates "*" operation Node with two operands as children. Throws exception if less than two elements available
	*
	* @exception	1		Invalid Operation
	**/
	void build_mult();

	/**
	* Creates "/" operation Node with two operands as children. Throws exception if less than two elements available or divide by zero
	*
	* @exception	1		Invalid Operation
	* @exception	2		Cannot divide by zero
	**/
	void build_div();

	/**
	* Creates "%" operation Node with two operands as children. Throws exception if less than two elements available or Modulo by zero
	*
	* @exception	1		Invalid Operation
	* @exception	2		Cannot perform modulus on zero
	**/
	void build_mod();

private:
	Stack<Node*> & s_;
};

#endif  // !defined _BUILDER_H_