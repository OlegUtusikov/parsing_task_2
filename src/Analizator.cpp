#include "Analizator.hpp"

Node* Analizator::parse(std::string const& s)
{
	tr.init(s);
	tr.next_token();
	return var();
}

Node* Analizator::var()
{
	if (tr.cur_token().type() == TYPE::VAR)
	{
		std::vector<Node*> childs = {new Node(tr.cur_token().value(), {})};
		tr.next_token();
		childs.emplace_back(block());
		Node* res = new Node("S", childs);
		return res;
	}
}

Node* Analizator::block()
{
	if (tr.cur_token().type == TYPE::NAME)
	{

	}
}