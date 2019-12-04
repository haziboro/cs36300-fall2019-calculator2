#include "Abst_Visitor.h"

#ifndef _VISITOR_H_
#define _VISITOR_H_

//Creates Node elements for insertion into expression tree
class Visitor : public Abst_Visitor
{
public:
	//constructor
	Visitor(Stack<Node*> & s);

	/**
	* Evaluates expression located in s, throws exception if more than one element present
	*
	* @exception	4		Invalid expression
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
	* Checks if a node is a variable. If it is, converts to char and evaluates.
	* 
	* @param[in]		n		node to check
	* @return			val		integer value of node
	**/
	int check_value(Node * n);

	/**
	* Converts numbers in string format to integers. 
	* If input string is not a number, assumes it's a variable and calls var_handler() for definition
	*
	* @param[in]	num			string to convert
	* @return		x			converted integer
	* @exception	5			invalid integer conversion
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

	//Nested linked list element to hold temporary variables
	struct Sto_Var
	{
		Sto_Var(std::string var, int value);	//constructor
		std::string var_;
		int value_;
		Sto_Var* next_;
	};

	/**
	* deletes all stored variables
	*
	* @param[in]	trash	variable node to delete
	**/
	void clear_vars(Sto_Var* trash);

private:
	//for manipulating tree nodes, root is always top element
	Stack<Node*>& s_;
	//pointer to linked list of temporary stored variables
	Sto_Var* stored_;

};

#endif  // !defined _VISITOR_H_