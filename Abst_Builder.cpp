#include "Node.cpp"

#ifndef _ABST_BUILDER_CPP_
#define _ABST_BUILDER_CPP_

//interface to define Builder functions
class Abst_Builder
{
public:
	virtual void build_num(int n) = 0;

	virtual void build_add() = 0;

	virtual void build_sub() = 0;

	virtual void build_mult() = 0;

	virtual void build_div() = 0;

	virtual void build_mod() = 0;

protected:
	//prevent default construction, copy-contruction, and assignment outside of subclasses
	Abst_Builder() {};
	Abst_Builder(const Abst_Builder&) {};
	const Abst_Builder& operator = (const Abst_Builder&) {};
};

#endif  // !defined _ABST_BUILDER_CPP_