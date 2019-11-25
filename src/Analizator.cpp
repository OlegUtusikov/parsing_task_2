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
		Node res = Node("VAR");
		tr.next_token();
		res.add_child(block());
		if (tr.cur_token().type() == TYPE::END)
		{
			res.add_child(Node(tr.cur_token()));
		}
		else
		{
			Token error = tr.cur_token();
			error.set_type(Token::TYPE::ERROR);
			return Node(error);
		}
		return res;
	}
	else
	{
		return Node(tr.cur_token());
	}
}

Node Analizator::block()
{
	Node res = Node("BLOCK");
	if (tr.cur_token().type() == TYPE::NAME || tr.cur_token().type() == TYPE::NAME_TYPE)
	{
		res.add_child(v());
		if (tr.cur_token().type() == TYPE::SEMICOLLON)
		{
			res.add_child(Node(tr.cur_token()));
			tr.next_token();
			if (tr.cur_token().type() !=  TYPE::END)
			{
				res.add_child(block());
			}
			return res;
		}
		else
		{	
			Token error = tr.cur_token();
			error.set_type(Token::TYPE::ERROR);
			return Node(error);
		}
	}
	else
	{
		Token error = tr.cur_token();
		error.set_type(Token::TYPE::ERROR);
		return Node(error);
	}
}

Node Analizator::v()
{
	Node res = Node("V");
	if (tr.cur_token().type() == TYPE::NAME)
	{
		res.add_child(Node(tr.cur_token()));
		tr.next_token();
		if (tr.cur_token().type() == TYPE::COMMA)
		{
			res.add_child(Node(tr.cur_token()));
			tr.next_token();
			res.add_child(v());
			return res;
		}
		else 
		{
			Token error = tr.cur_token();
			error.set_type(Token::TYPE::ERROR);
			return Node(error);
		}
	}
	else if (tr.cur_token().type() == TYPE::NAME_TYPE) {
		res.add_child(Node(tr.cur_token()));
		tr.next_token();
		return res;
	} else {
		Token error = tr.cur_token();
		error.set_type(Token::TYPE::ERROR);
		return Node(error);
	}
}