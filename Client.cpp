//Header File, includes more details about all below implementations
#include "Client.h"

//constructor
Client::Client(Abst_Builder* builder, Abst_Visitor* visitor)
	:infix_(""),
	postfix_(new Queue<std::string>),
	builder_(builder),
	visitor_(visitor)

{
	run_calculator();
}

//destructor
Client::~Client()
{
	delete[] postfix_;
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
bool Client::infix_to_postfix(const std::string& infix, Queue<std::string>& postfix)
{
	std::istringstream input(infix);//input stream
	std::string token;				//current token of stream
	std::string temp;				//operand to enqeue
	Stack<std::string> opstack;		//temporary operator storage

	while (!input.eof()) {
		input >> token;
		//Numbers
		if (not_number(token) == false) {
			postfix.enqueue(token);
		}
		//Left Parenthesis
		else if (token == "(") {
			opstack.push("(");
		}
		//Right Parenthesis
		else if (token == ")") {
			//loops until "(" is found or stack is empty
			while (opstack.is_empty() == false && opstack.top() != "(") {
				postfix.enqueue(opstack.top());
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
				postfix.enqueue(opstack.top());
				opstack.pop();
			}
			opstack.push(token);
		}
	}
	//loops until all values of opstack are enqueued to postfix
	while (opstack.is_empty() == false) {
		postfix.enqueue(opstack.top());
		opstack.pop();
	}

	return true;
}

//not_number
bool Client::not_number(std::string token)
{
	std::stringstream s(token);
	int x = 0;
	s >> x;

	return s.fail();
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

//build
void Client::build(Queue<std::string>& postfix, Abst_Builder & builder)
{
	std::string node_val;	//holds node value from postfix
	while (postfix.is_empty() == false) {
		node_val = postfix.dequeue();
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
		else{
			builder.build_num(node_val);
		}
	}
}

//solve
int Client::solve(Abst_Visitor& visitor)
{
	return 0;
}

//handler
//1 - Invalid operation
//2 - Invalid Operation using zero
//3 - No operation to solve
//4 - Invalid Expression
//5 - Unknown error
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
				infix_to_postfix(infix_, *postfix_);
				build(*postfix_, *builder_);
				//std::cout << solve(*visitor_) << std::endl;
			}
			else {
				keepGoing = false;
			}
		}
		catch (int e) {
			handler(e);
			postfix_->clear();
		}
		catch (...)
		{
			handler(-1);
			postfix_->clear();
		}
	}
}
