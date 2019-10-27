#pragma once

#include <string>
#include <iostream>
#include "Token.hpp"

class Tokenizer {
public:
	Tokenizer(std::string const& ss) : m_ss(ss), m_cur_index(-1), m_mark(-1)
	{
		next_char();
	}

	void next_token();
	
	Token getToken() const
	{
		return m_token;
	}

	int cur_index() const
	{
		return m_cur_index;
	}

	char cur_char() const
	{
		return m_cur_char;
	}

private:
	std::string m_ss;
	int m_cur_index;
	char m_cur_char;
	Token m_token;
	int m_mark;

	void next_char();

	bool is_blank(char ch)
	{
		return std::isspace(static_cast<unsigned char>(ch));
	}

	void mark()
	{
		m_mark = m_cur_index;
	}

	void back()
	{
		m_cur_index = m_mark;
	}

	void jump(std::size_t step)
	{
		m_cur_index += step;
	}

	bool check(std::string const& s)
	{
		if (s.empty())
		{
			return false;
		}

		if (cur_index() + s.size() - 1 < m_ss.size())
		{
			mark();
			bool ans = true;
			for (auto c : s)
			{
				ans &= cur_char() == c;
			}
			back();
			return ans;

		}
		return false;
	}
};