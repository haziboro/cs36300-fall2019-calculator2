#include "Client.h"
#include "Visitor.h"
#include "Builder.h"

int main()
{
	Stack<Node*> root_;
	Builder builder(root_);
	Visitor visitor(root_);

	Client* c = new Client(&builder, &visitor);
	delete[] c;

	return 0;
}
