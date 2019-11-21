#include "client/Client.h"
#include "visitor/Visitor.h"
#include "builder/Builder.h"

int main()
{
	Stack<Node*> root_;

	Builder builder(root_);
	Visitor visitor(root_);
	Client c(&builder, &visitor);

	return 0;
}
