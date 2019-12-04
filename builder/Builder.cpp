//Header File, includes more details about all below implementations
#include "Builder.h"

//constructor
Builder::Builder(Stack<Node*> & s)
	:s_(s) {}

//destructor
Builder::~Builder()
{
	clear_stack();
}

//build_int
void Builder::build_int(std::string num)
{
	int a = converter(num);
	s_.push(new Node(a));
}

//build_var
void Builder::build_var(std::string var)
{
	if (var.length() > 1) { throw 5; }
	s_.push(new Var_Node(var));
}

//build_add
void Builder::build_add()
{
	
	Node * right = make_child();
	Node * left = make_child();

	s_.push(new Add_Node(left, right));

}

//build_sub
void Builder::build_sub()
{
	Node* right = make_child();
	Node* left = make_child();

	s_.push(new Sub_Node(left, right));
}

//build_div
void Builder::build_div()
{
	Node* right = make_child();
	Node* left = make_child();

	s_.push(new Div_Node(left, right));
}

//build_mult
void Builder::build_mult()
{
	Node* right = make_child();
	Node* left = make_child();

	s_.push(new Mult_Node(left, right));
}

//build_mod
void Builder::build_mod()
{
	Node* right = make_child();
	Node* left = make_child();

	s_.push(new Mod_Node(left, right));
}

//converter
int Builder::converter(std::string num)
{
	std::stringstream s(num);
	int x = 0;
	s >> x;
	return x;
}

//demolish
void Builder::clear_stack()
{
	Node* trash;
	while (s_.is_empty() == false) {
		trash = s_.top();
		s_.pop();
		delete_tree(trash);
	}
}

//delete_tree
void Builder::delete_tree(Node * root) 
{
	if (root == nullptr) { return; }
	delete_tree(root->get_left());
	delete_tree(root->get_right());
	delete root;
}

//make_child
Node* Builder::make_child()
{
	Node* child;
	if (s_.is_empty() == true) {
		throw 1;
	}
	child = s_.top();
	s_.pop();
	return child;
}