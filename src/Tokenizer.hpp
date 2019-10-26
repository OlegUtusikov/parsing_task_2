#pragma once

#include <string>
#include <iostream>
#include "Token.hpp"

class Tokenizer {
public:
	Tokenizer(std::string const& ss) : m_ss(ss), m_cur_index(0)
	{
		next_char();
	}

	void next_token();
	
	Token getToken() const
	{
		return m_token;
	}

	std::size_t cur_index() const
	{
		return m_cur_index;
	}

private:
	std::string m_ss;
	std::size_t m_cur_index;
	char m_cur_char;
	Token m_token;

	void next_char();
};