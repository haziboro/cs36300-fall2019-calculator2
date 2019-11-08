#include <sstream>
#include "library/Queue.h"
#include "Abst_Visitor.cpp"
#include "Abst_Builder.cpp"

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

	//destructor
	virtual ~Client();

	/**
	* Prints messages to user and checks user input for errors
	*
	* @param[in]	infix		Location to store input
	* @retval		true		attempt to solve equation
	* @retval		false		quit program
	**/
	bool request_input(std::string& infix);

	/**
	* Converts in-fix expressions into post-fix format, stores each operator/operand as a queue element.
	* throws exception if expression contains invalid characters.
	* 
	* @param[in]	infix		user input
	* @param[in]	postfix		Queue to store operators/operands in post-fix format
	* 
	* @retval		true		expression succesffully converted
	* @retval		false		expression failed to convert
	* @exception	4			Invalid Expression
	**/
	bool infix_to_postfix(const std::string& infix, Queue<std::string>& postfix);

	/**
	* Checks if a string is a number
	*
	* @param[in]	token		string to check
	* @retval		true		value is not a number
	* @retval		false		value is a number
	**/
	bool not_number(std::string token);

	/**
	* Returns precedence level of operators
	*
	* @param[in]	op			operator in string format
	* @return		integer		Number corresponding to precedent level
	**/
	int precedence(std::string op);

	/**
	* Converts post-fix arithmetic expression in to an expression tree
	* 
	* @param[in]	postfix		Postfix expression to be converted
	* @param[in]	builder		Builder object to construct expression tree
	**/
	void build(Queue<std::string> & postfix, Abst_Builder & builder);
	/**
	* Requests visitor to parse expression tree created by builder. Returns result of arithmetic expression.
	* 
	* @param[in]	visitor		Visitor to parse expression tree
	* @return		res			result of arithmetic expression
	**/
	int solve(Abst_Visitor & visitor);

	/**
	* Handles exceptions
	* 
	* @param[in]	exception#
	* cout			error message
	**/
	void handler(int e);

private:
	//Initializes input loop. Only method that utilizes class member variables.
	virtual void run_calculator();

	std::string infix_;
	Queue<std::string> *postfix_;
	Abst_Builder * builder_;
	Abst_Visitor * visitor_;


};

#endif  // !defined _CLIENT_H_