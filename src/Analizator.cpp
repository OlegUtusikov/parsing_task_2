#include "Analizator.hpp"


void Analizator::print_error() const
{
	std::cerr << "Invalid token: " << tr.cur_token().value() << " . Type: " << tr.cur_token().type_str() << std::endl;
}

void Analizator::print_info(std::string const& s) const
{
	std::cerr << s << " " << tr.cur_token().value() << " " << tr.cur_token().type_str() << " " << tr.cur_index() << std::endl;
}

Node Analizator::parse(std::string const& s)
{
	tr.init(s);
	tr.next_token();
	return var();
}

Node Analizator::var()
{
	if (tr.cur_token().type() == TYPE::VAR)
	{
		Node res = Node(tr.cur_token().str());
		tr.next_token();
		res.add_child(block());
		return res;
	}
	else
	{
		return Node(tr.cur_token().str());
	}
}

Node Analizator::block()
{
	Node res = Node("BLOCK");
	if (tr.cur_token().type() == TYPE::NAME)
	{
		res.add_child(v());
		if (tr.cur_token().type() == TYPE::SEMICOLLON)
		{
			res.add_child(Node(tr.cur_token().str()));
			tr.next_token();
			res.add_child(block());
			return res;
		}
		else
		{
			return Node(tr.cur_token().str());
		}
	}
	else if (tr.cur_token().type() == TYPE::END)
	{
		return Node(tr.cur_token().str());
	}
	return Node(tr.cur_token().str());
}

Node Analizator::v()
{
	Node res = Node("V");
	if (tr.cur_token().type() == TYPE::NAME)
	{
		res.add_child(Node(tr.cur_token().str()));
		tr.next_token();
		if (tr.cur_token().type() == TYPE::COLLON)
		{
			res.add_child(Node(tr.cur_token().str()));
			tr.next_token();
			if (tr.cur_token().type() == TYPE::TYPE)
			{
				res.add_child(Node(tr.cur_token().str()));
				tr.next_token();
				return res;
			}
			else
			{
				return Node(tr.cur_token().str());
			}
			
		}
		else if (tr.cur_token().type() == TYPE::COMMA)
		{
			res.add_child(Node(tr.cur_token().str()));
			tr.next_token();
			res.add_child(v());
			return res;
		}
		return Node(tr.cur_token().str());
	}
	return Node(tr.cur_token().str());
}