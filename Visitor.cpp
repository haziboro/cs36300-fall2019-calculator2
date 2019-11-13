//Header File, includes more details about all below implementations
#include "Visitor.h"
#include <sstream>

//constructor
Visitor::Visitor(Stack<Node*> & s)
	:s_(s) {}

//destructor
Visitor::~Visitor()
{

}

//in_order
void Visitor::in_order()
{

}

//converter
int Visitor::converter(std::string token)
{
	std::stringstream s(token);
	int x = 0;
	s >> x;
	if (s.fail()) {
		throw 2;
	}
	return x;
}

//solve
int Visitor::solve()
{
	return 0;
}