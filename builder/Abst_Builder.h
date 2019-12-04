#include "../nodes/Node.h"

#ifndef _ABST_BUILDER_H_
#define _ABST_BUILDER_H_

//interface to define Builder functions
class Abst_Builder
{
public:
	virtual Node* make_child() = 0;

	virtual void build_int(std::string num) = 0;

	virtual void build_var(std::string var) = 0;

	virtual void build_add() = 0;

	virtual void build_sub() = 0;

	virtual void build_mult() = 0;

	virtual void build_div() = 0;

	virtual void build_mod() = 0;

	virtual void clear_stack() = 0;

	virtual void delete_tree(Node* root) = 0;

protected:
	//prevent default construction, copy-contruction, and assignment outside of subclasses
	Abst_Builder() {};
	Abst_Builder(const Abst_Builder&) {};
	const Abst_Builder& operator = (const Abst_Builder&) {};
};

#endif  // !defined _ABST_BUILDER_H_