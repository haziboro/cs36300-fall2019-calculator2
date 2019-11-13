#include "Client.h"
#include "Visitor.h"
#include "Builder.h"

int main()
{
	Stack<Node*> root_;
	Builder *builder = new Builder(root_);
	Visitor *visitor = new Visitor(root_);

	Client* c = new Client(builder, visitor);

	return 0;
}
