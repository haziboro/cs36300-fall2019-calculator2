//Header File, includes more details about all below implementations
#include "Visitor.h"

//constructor
Visitor::Visitor(Stack<Node*>& s)
	:s_(s),
	stored_(NULL){};

//solve
int Visitor::solve()
{
	int result = in_order(s_.top());
	clear_vars();
	return result;
}

//in_order
int Visitor::in_order(Node* n)
{
	if (n->right_ == NULL) {
		if (n->left_ == NULL) {
			return converter(n->data_);  //if left and right children are NULL, return integer value of operand
		}
		return operate(n->data_, in_order(n->left_));	//if right child is NULL but left child contains Node, return integer value of unary operation
	}
	return operate(n->data_, in_order(n->left_), in_order(n->right_));	//if neither child is NULL, return result of binary operation
}

//operate
int Visitor::operate(std::string op, int a, int b) 
{
	if (op == "+") {
		return a + b;
	}
	else if (op == "-") {
		return a - b;
	}
	else if (op == "*") {
		return a * b;
	}
	else if (b == 0) {		//prevents divide/mod by zero errors
		throw 2;
	}
	else if (op == "/") {
		return a / b;
	}
	else if (op == "%") {
		return a % b;
	}
}

//operate
int Visitor::operate(std::string op, int a)
{
	throw 5;
	return 0;
}

//converter
int Visitor::converter(std::string num)
{
	std::stringstream s(num);
	int x = 0;
	s >> x;
	if (s.fail()) {
		return var_handler(num);
	}
	return x;
}

//var_handler
int Visitor::var_handler(std::string var)
{	
	if (stored_ != NULL) {
		Sto_Var* temp = stored_; //current stored variable to analyze
		while (temp != NULL) {
			if (temp->var_ == var) {
				return temp->value_;
			}
			else if (temp->next_ != NULL) {
				temp = temp->next_;
			}
			else {
				return request_var(var);
			}
		}//end while
	}//end if
	return request_var(var);
}

//assign_var
int Visitor::request_var(std::string var)
{
	std::string response;
	std::cin.clear();
	std::cout << var << " = ";
	std::getline(std::cin, response);

	Sto_Var* new_var = new Sto_Var(var, converter(response));
	new_var->next_ = stored_;
	stored_ = new_var;
	return stored_->value_;
}

//clear_vars
void Visitor::clear_vars()
{
	while (stored_ != NULL) {
		Sto_Var* temp = stored_->next_;
		delete stored_;
		stored_ = temp;
	}
}

//Sto_Var
Visitor::Sto_Var::Sto_Var(std::string var, int value)
	:var_(var),
	value_(value),
	next_(NULL) {}