#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Token.hpp"

class Node
{
public:
	Node(): m_value("empty_node"), m_childs(0)
	{}

	explicit Node(std::string const& str): m_value(str), m_childs(0)
	{}

	explicit Node(Token const& t): m_value(t.value()), m_childs(0)
	{
		correct = t.type() != Token::TYPE::ERROR;
	}

	Node(Token const& t, std::vector<Node> const& childs): m_value(t.value()), m_childs(m_childs)
	{
		correct = t.type() != Token::TYPE::ERROR;
	}

	std::string get_value() const
	{
		return m_value;
	}

	void add_child(Node ch)
	{
		m_childs.emplace_back(ch);
	}

	void print() const
	{	
		std::cout << "#";
		print_helper(1);
		std::cout << std::endl;
	}

	bool check() const
	{
		return check_node(*this);
	}

	bool is_correct() const { return correct; }
	
private:

	void print_helper(int cnt) const
	{
		std::cout << "---> " << m_value << std::endl;
		for (Node pCh: m_childs)
		{
			print_blanks(cnt);
			std::cout << "|";
			pCh.print_helper(cnt + 1);
		}
	}

	bool check_node(Node n) const
	{
		bool res = n.is_correct();
		for (auto ch : m_childs)
		{
			res |= ch.check();
		}
		return res;
	}

private:
	std::string m_value;
	bool correct { true };
	std::vector<Node> m_childs;

	void print_blanks(std::size_t cnt) const
	{
		for (std::size_t i = 0; i < cnt; ++i)
		{
			std::cout << "    ";
		}
	}
};
