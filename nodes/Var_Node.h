#include "Node.h"

#ifndef _VAR_NODE_H_
#define _VAR_NODE_H_

//Node for variable operations
class Var_Node : public Node
{
public:

	//constructor, stores variable as ASCII value
	Var_Node(std::string var);

};

#endif  // !defined _VAR_NODE_H_