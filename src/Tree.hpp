#pragma once
#include <vector>
#include <string>
#include <iostream>

class Node
{
public:
	Node(): m_value("empty_node"), m_childs(0)
	{}

	Node(std::string const& s): m_value(s), m_childs(0)
	{}

	Node(std::string const& s, std::vector<Node> const& childs): m_value(s), m_childs(m_childs)
	{}

	std::string get_value() const
	{
		return m_value;
	}

	void add_child(Node ch)
	{
		m_childs.emplace_back(ch);
	}

	void print(int cnt) const
	{
		print_blanks(cnt);
		std::cout << m_value << std::endl;
		for(Node pCh: m_childs)
		{
			pCh.print(cnt + 1);
		}
	}

private:
	std::string m_value;
	std::vector<Node> m_childs;

	void print_blanks(std::size_t cnt) const
	{
		for(std::size_t i = 0; i + 2 < cnt; ++i)
		{
			std::cout << "    ";
		}
		std::cout << "|";
		std::cout << "----";
	}
};
