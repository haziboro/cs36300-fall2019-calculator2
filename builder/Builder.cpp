//Header File, includes more details about all below implementations
#include "Builder.h"

//constructor
Builder::Builder(Stack<Node*> & s)
	:s_(s) {}

//destructor
Builder::~Builder()
{
	demolish();
}

//build_num
void Builder::build_operand(std::string n)
{
	Node* new_node = new Node(n);
	s_.push(new_node);
}

//build_add
void Builder::build_add()
{
	Node* new_node = new Node("+");
	
	new_node->right_ = make_child();
	new_node->left_  = make_child();

	s_.push(new_node);

}

//build_sub
void Builder::build_sub()
{
	Node* new_node = new Node("-");

	new_node->right_ = make_child();
	new_node->left_ = make_child();

	s_.push(new_node);
}

//build_div
void Builder::build_div()
{
	Node* new_node = new Node("/");

	new_node->right_ = make_child();
	new_node->left_ = make_child();

	s_.push(new_node);
}

//build_mult
void Builder::build_mult()
{
	Node* new_node = new Node("*");

	new_node->right_ = make_child();
	new_node->left_ = make_child();

	s_.push(new_node);
}

//build_mod
void Builder::build_mod()
{
	Node* new_node = new Node("%");

	new_node->right_ = make_child();
	new_node->left_ = make_child();

	s_.push(new_node);
}

//demolish
void Builder::demolish()
{
	Node* trash;
	while (s_.is_empty() == false) {
		trash = s_.top();
		s_.pop();
		delete trash;
	}
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