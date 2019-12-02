//Header File, includes more details about all below implementations
#include "Visitor.h"

//constructor
Visitor::Visitor(Stack<Node*>& s)
	:s_(s),
	stored_(NULL){};

//solve
int Visitor::solve()
{
	if (s_.size() != 1) {
		throw 4;
	}
	int result = in_order(s_.top());
	if(stored_ != NULL){ 
		clear_vars(stored_);
		stored_ = NULL;
	}
	return result;
}

//in_order
int Visitor::in_order(Node* n)
{
	if (n->right_ == NULL) {
		if (n->left_ == NULL) {
			//COMMENT: This is a cool design. Can you create a different design though?
			//Consider doing the string-to-int coversion in the building process.
			return converter(n->data_);  //if left and right children are NULL, return integer value of operand
		}
		return operate(n->data_, in_order(n->left_));	//if right child is NULL but left child contains Node, return integer value of unary operation
	}
	return operate(n->data_, in_order(n->right_), in_order(n->left_));	//if neither child is NULL, return result of binary operation
}

//operate
int Visitor::operate(std::string op, int b, int a) 
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

//Sto_Var
Visitor::Sto_Var::Sto_Var(std::string var, int value)
	:var_(var),
	value_(value),
	next_(NULL) {}

//clear_vars
void Visitor::clear_vars(Sto_Var* trash)
{
	if (trash == NULL) { return; };
	clear_vars(trash->next_);
	delete trash;
}