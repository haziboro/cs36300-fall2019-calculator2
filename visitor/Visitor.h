#include "Abst_Visitor.cpp"

#ifndef _VISITOR_H_
#define _VISITOR_H_

//Creates Node elements for insertion into expression tree
class Visitor : public Abst_Visitor
{
public:
	//constructor
	Visitor(Stack<Node*> & s);

	/**
	* Return numerical value of top node of Stack s_, throws exception if not present
	*
	* @exception	3		No equation to solve
	**/
	int solve();

protected:
	/**
	* Traverse Binary expression tree recursively using in-order traversal
	* 
	* @param[in]		n		Node* to evaluate
	* @return			int		result of expression
	**/
	int in_order(Node* n);

	/**
	* Executes binary operation "op" on values "a" and "b"
	* 
	* @param[in]	op		operation to perform
	* @param[in]	a		first operand
	* @param[in]	b		second operand
	* @return		res		result of operation
	**/
	int operate(std::string op, int a, int b);

	/**
	* operate() Overload
	* Executes Unary operation "op" on value "a"
	*
	* @param[in]	op		operation to perform
	* @param[in]	a		operand
	* @return		res		result of operation
	**/
	int operate(std::string op,int a);

	/**
	* Converts numbers in string format to integers. 
	* If input string is not a number, assumes it's a variable and calls var_handler() for definition
	*
	* @param[in]	num			string to convert
	* @return		x			converted integer
	* @exception	2			invalid integer conversion
	**/
	int converter(std::string num);

	/**
	* Handles variable values and converts them into integers via user input
	* 
	* @param[in]	var		variable to define
	* @return		val		integer value of variable
	**/
	int var_handler(std::string var);

	/**
	* Requests user to input variable value, stores assignment in Sto_Var until expression is completed
	*
	* @param[in]	var		variable to define
	**/
	int request_var(std::string var);

	//deletes all stored variables
	void clear_vars();

	//Nested linked list element to hold temporary variables
	struct Sto_Var
	{
		Sto_Var(std::string var, int value);	//constructor
		std::string var_;
		int value_;
		Sto_Var* next_;
	};

private:
	//for manipulating tree nodes, root is always top element
	Stack<Node*>& s_;
	//pointer to linked list of temporary stored variables
	Sto_Var* stored_;

};

#endif  // !defined _VISITOR_H_