//Header File, includes more details about all below implementations
#include "Visitor.h"

//constructor
Visitor::Visitor(Stack<Node*>& s)
	:s_(s),
	stored_(NULL){};

//solve
int Visitor::solve()
{
	if (stored_ != NULL) {
		clear_vars(stored_);
		stored_ = NULL;
	}
	if (s_.size() != 1) {
		throw 4;
	}
	int result = in_order(s_.top());

	return result;
}

//in_order
int Visitor::in_order(Node* n)
{
	if (n->get_right() == NULL) {
		if (n->get_left() == NULL) {
			//COMMENT: This is a cool design. Can you create a different design though?
			//Consider doing the string-to-int coversion in the building process.
			return check_value(n);  //if left and right children are NULL, return integer value of operand
		}
		return n->operate(in_order(n->get_left()));	//if right child is NULL but left child contains Node, return result of unary operation
	}
	return n->operate(in_order(n->get_right()), in_order(n->get_left()));	//if neither child is NULL, return result of binary operation
}

//check_value
int Visitor::check_value(Node* n)
{
	if (n->is_var() == false) {
		return n->get_data();
	}
	else {
		char a = n->get_data();
		return var_handler(std::string(1, a));
	}
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

	if (response.length() > 1) { throw 5; }

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