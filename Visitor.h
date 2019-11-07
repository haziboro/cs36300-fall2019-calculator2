#include "Abst_Visitor.cpp"

#ifndef _VISITOR_H_
#define _VISITOR_H_

//Creates Node elements for insertion into expression tree
class Visitor : public Abst_Visitor
{
public:
	//constructor
	Visitor(Stack<Node*> & s);

	//destructor
	~Visitor();

	/**
	* Traverse Binary expression tree using in-order traversal
	* 
	* 
	**/
	void in_order();

	/**
	* Return numerical value of top node of Stack s_, throws exception if not present
	* 
	* @exception	3		No equation to solve
	**/
	int solve();

private:
	Stack<Node*>& s_;

};

#endif  // !defined _VISITOR_H_