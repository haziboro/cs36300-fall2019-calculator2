//Header File, includes more details about all below implementations
#include "Client.h"

//constructor
Client::Client(Abst_Builder* builder, Abst_Visitor* visitor)
	:infix_(""),
	builder_(builder),
	visitor_(visitor)

{
	run_calculator();
}

//request_input
bool Client::request_input(std::string& infix)
{
	std::string response;
	std::cin.clear();
	std::cout << "Enter an equation to solve, or type QUIT to exit" << std::endl;
	std::getline(std::cin, response);

	if (response.compare("QUIT") == 0) {
		return false;
	}
	else {
		infix = response;
		return true;
	}
}

//infix_to_postfix
bool Client::infix_to_tree(const std::string& infix, Abst_Builder& builder)
{
	std::istringstream input(infix);//input stream
	std::string token;				//current token of stream
	Stack<std::string> opstack;		//temporary operator storage

	while (!input.eof()) {
		input >> token;
		//Operands
		if (is_operand(token) == true) {
			//numbers
			if (not_num(token) == false) {
				builder.build_int(token);
			}
			//variables
			else if (is_var(token) == true) {
				builder.build_var(token);
			}
			else {
				throw 4;
			}
		}
		//Left Parenthesis
		else if (token == "(") {
			opstack.push("(");
		}
		//Right Parenthesis
		else if (token == ")") {
			//loops until "(" is found or stack is empty
			while (opstack.is_empty() == false && opstack.top() != "(") {
				build_op(builder, opstack.top());
				opstack.pop();
			}
			if (opstack.top() == "(") {
				opstack.pop();
			}
			else {
				throw 4;
			}
		}
		//Operations
		else {
			//loops until stack is empty, stack.top() is not an operator, or stack.top() is an operator of lower precedence
			while (opstack.is_empty() == false && precedence(token) <= precedence(opstack.top())) {
				build_op(builder, opstack.top());
				opstack.pop();
			}
			opstack.push(token);
		}
	}//end while

	//loops until all values of opstack are built
	while (opstack.is_empty() == false) {
		build_op(builder, opstack.top());
		opstack.pop();
	}

	return true;
}

//is_operand
bool Client::is_operand(std::string token)
{
	if (token == "+" ||
		token == "-" ||
		token == "*" ||
		token == "/" ||
		token == "%" ||
		token == "(" ||
		token == ")") {
		return false;
	}
	else {
		return true;
	}
}

//not_num
bool Client::not_num(std::string token)
{
	std::stringstream s(token);
	int x = 0;
	s >> x;
	return s.fail();
}

//is_var
bool Client::is_var(std::string token)
{
	if (token.size() > 1) {
		return false;
	}
	else {
		return true;
	}
}

//precedence
int Client::precedence(std::string op)
{
	if (op == "*" || op == "/" || op == "%") {
		return 2;
	}
	else if (op == "+" || op == "-") {
		return 1;
	}
	else {
		return -1;
	}
}

//build_op
void Client::build_op(Abst_Builder& builder, std::string node_val)
{
	if (node_val == "+") {
		builder.build_add();
	}
	else if (node_val == "-") {
		builder.build_sub();
	}
	else if (node_val == "*") {
		builder.build_mult();
	}
	else if (node_val == "/") {
		builder.build_div();
	}
	else if (node_val == "%") {
		builder.build_mod();
	}
	else {
		throw 1;
	}
}

//handler
//1 - Invalid Operation
//2 - Invalid Operation using zero
//3 - No operation to solve
//4 - Invalid Expression
//other - Unknown error
void Client::handler(int e)
{
	if (e == 1) {
		std::cout << "Invalid Operation" << std::endl;
	}
	else if (e == 2) {
		std::cout << "Invalid Operation using zero" << std::endl;
	}
	else if (e == 3) {
		std::cout << "No Operation to solve" << std::endl;
	}
	else if (e == 4) {
		std::cout << "Invalid Expression" << std::endl;
	}
	else if (e == 5) {
		std::cout << "Invalid Variable, must be single character" << std::endl;
	}
	else {
		std::cout << "Unknown error" << std::endl;
	}
}


//run_calcualtor
void Client::run_calculator()
{
	bool run;
	bool keepGoing = true;
	//Loops until user inputs QUIT
	while (keepGoing) {
		run = request_input(infix_);
		try {
			if (run == true) {
				infix_to_tree(infix_, *builder_);
				std::cout << visitor_->solve() << std::endl;
			}
			else {
				keepGoing = false;
			}
		}//end try
		catch (int e) {
			handler(e);
			builder_->clear_stack();
		}
		catch (...)
		{
			handler(-1);
			builder_->clear_stack();
		}
		builder_->clear_stack();
	}//end while
}
