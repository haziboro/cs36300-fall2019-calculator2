#include <sstream>
#include "../nodes/Node.h"

#ifndef _ABST_VISITOR_H_
#define _ABST_VISITOR_H_

//COMMENT: This should be in a .h file.
//RESPONSE: fixed it

//interface to define Visitor functions
class Abst_Visitor
{
public:

	virtual int solve() = 0;

	virtual int in_order(Node* n) = 0;

protected:
	//prevent default construction, copy-contruction, and assignment outside of subclasses
	Abst_Visitor() {};
	Abst_Visitor(const Abst_Visitor&) {};
	const Abst_Visitor& operator = (const Abst_Visitor&) {};
};

#endif  // !defined _ABST_VISITOR_H_