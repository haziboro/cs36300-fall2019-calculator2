#include "Var_Node.h"

//Var_Node
Var_Node::Var_Node(std::string var)
	:Node::Node(var)
{
	set_data(tolower(int(var.at(0))));
}