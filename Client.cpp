//Header File, includes more details about all below implementations
#include "Client.h"

//constructor
Client::Client(Abst_Builder* builder, Abst_Visitor* visitor)
	:infix_(""),
	postfix_(new Queue<std::string>),
	builder_(builder),
	visitor_(visitor)

{

}

//destructor
Client::~Client()
{
	delete[] postfix_;
}