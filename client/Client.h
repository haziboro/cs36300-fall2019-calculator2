#include <sstream>
#include "../visitor/Abst_Visitor.h"
#include "../builder/Abst_Builder.h"

#ifndef _CLIENT_H_
#define _CLIENT_H_

///
///Basic Arithmetic Calculator
///

class Client
{
public:
	//constructor
	Client(Abst_Builder* builder, Abst_Visitor* visitor);

	/**
	* Prints messages to user and checks user input for errors
	*
	* @param[in]	infix		Location to store input
	* @retval		true		attempt to solve equation
	* @retval		false		quit program
	**/
	bool request_input(std::string& infix);

	/**
	* Converts in-fix expressions into expression tree utilizing builder to create Nodes.
	* throws exception if expression contains invalid characters.
	* 
	* @param[in]	infix		user input
	* @param[in]	builder		builder object to construct Nodes
	* 
	* @retval		true		expression succesffully converted
	* @retval		false		expression failed to convert
	* @exception	4			Invalid Expression
	**/
	bool infix_to_tree(const std::string& infix, Abst_Builder& builder);

	/**
	* Checks if a string is a valid integer or variable operand
	*
	* @param[in]	token		string to evaluate
	* @retval		true		value is an operand
	* @retval		false		value is not an operand
	**/
	bool is_operand(std::string token);

	/**
	* Checks if a string is a number
	* 
	* @param[in]	token		string to evaluate
	* @retval		true		value is not an integer
	* @retval		false		value is an integer
	**/
	bool not_num(std::string token);

	/**
	* Checks if a string is a valid variable. Valid variables are single character strings that are not supported operators
	* 
	* @param[in]	token		string to evaluate
	* @retval		true		value is a valid variable
	* @retval		false		value is not a variable
	**/
	bool is_var(std::string token);

	/**
	* Returns precedence level of operators
	*
	* @param[in]	op			operator in string format
	* @return		integer		Number corresponding to precedent level
	**/
	int precedence(std::string op);

	/**
	* Calls builder to create appropriate operator Node containing value node_val
	* 
	* @param[in]	builder		Builder object to construct expression tree
	* @param[in]	node_val	operator/operand value to pass to builder
	**/
	void build_op(Abst_Builder & builder, std::string node_val);

	/**
	* Handles exceptions
	* 
	* @param[in]	exception#
	* cout			error message
	**/
	void handler(int e);

private:
	//Initializes input loop
	virtual void run_calculator();

	std::string infix_;
	Abst_Builder * builder_;
	Abst_Visitor * visitor_;


};

#endif  // !defined _CLIENT_H_