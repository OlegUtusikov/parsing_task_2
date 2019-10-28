#include "Analizator.hpp"


void Analizator::print_error() const
{
	std::cerr << "Invalid token: " << tr.cur_token().value() << " . Type: " << tr.cur_token().type_str() << std::endl;
}

Node Analizator::parse(std::string const& s)
{
	tr.init(s);
	tr.next_token();
	return var();
}

Node Analizator::var()
{
	print_info("var");
	if (tr.cur_token().type() == TYPE::VAR)
	{
		Node res = Node(tr.cur_token().str());
		tr.next_token();
		res.add_child(block());
		return res;
	}
	else
	{
		return Node("ERROR");
	}
}

void Analizator::print_info(std::string const& s) const
{
	std::cerr << s << " " << tr.cur_token().value() << " " << tr.cur_token().type_str() << " " << tr.cur_index() << std::endl;
}

Node Analizator::block()
{
	print_info("bl1");
	Node res = Node("BLOCK");
	if (tr.cur_token().type() == TYPE::NAME)
	{
		res.add_child(v());
		print_info("bl2");
		if (tr.cur_token().type() == TYPE::SEMICOLLON)
		{
			res.add_child(Node(tr.cur_token().str()));
			tr.next_token();
			print_info("bl3");
			res.add_child(block());
			return res;
		}
		else
		{
			return Node("ERROR 1");
		}
	}
	else if (tr.cur_token().type() == TYPE::END)
	{
		return Node(tr.cur_token().str());
	}
	return Node("ERROR 2");
}

Node Analizator::v()
{
	print_info("v1");
	Node res = Node("V");
	if (tr.cur_token().type() == TYPE::NAME)
	{
		res.add_child(Node(tr.cur_token().str()));
		tr.next_token();
		if (tr.cur_token().type() == TYPE::COLLON)
		{
			print_info("v2");
			res.add_child(Node(tr.cur_token().str()));
			tr.next_token();
			if (tr.cur_token().type() == TYPE::TYPE)
			{
				print_info("v3");
				res.add_child(Node(tr.cur_token().str()));
				tr.next_token();
				print_info("v4");
				return res;
			}
			else
			{
				return Node("ERROR 3");
			}
			
		}
		else if (tr.cur_token().type() == TYPE::COMMA)
		{
			print_info("v5");
			res.add_child(Node(tr.cur_token().str()));
			tr.next_token();
			res.add_child(v());
			return res;
		}
		return Node("ERROR 4");
	}
	return Node("ERROR 5");
}