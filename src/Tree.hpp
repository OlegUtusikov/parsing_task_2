#pragma once
#include <vector>
#include <string>

class Node
{
public:
	Node(): m_value("empty_node"), m_childs(0)
	{}

	Node(std::string const& s): m_value(s), m_childs(0)
	{}

	Node(std::string const& s, std::vector<Node*> const& childs): m_value(s), m_childs(m_childs)
	{}
	
	std::string get_value() const
	{
		return m_value;
	}

private:
	std::string m_value;
	std::vector<Node*> m_childs;
};
