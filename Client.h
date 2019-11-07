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

	//1 - Invalid operation
	//2 - Invalid Operation using zero
	//3 - No operation to solve
	void handler(int e);

private:
	std::string infix_;
	Queue<std::string> *postfix_;
	Abst_Builder * builder_;
	Abst_Visitor * visitor_;


};

#endif  // !defined _CLIENT_H_