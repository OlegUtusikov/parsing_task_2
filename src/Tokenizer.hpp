#pragma once

#include <string>
#include <iostream>
#include "Token.hpp"

class Tokenizer
{
public:
	Tokenizer(std::string const& ss)
	{
		init(ss);
	}

	void init(std::string const& ss)
	{
		m_ss = ss;
		m_cur_index = -1;
		m_mark = -1;
		next_char();
	}

	void next_token();
	
	Token cur_token() const
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

	bool is_blank(char ch) const
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
		m_cur_char = m_ss[m_cur_index];
	}

	void jump(std::size_t step)
	{
		if (m_cur_index + step < m_ss.size())
		{
			m_cur_index += step;
			m_cur_char = m_ss[m_cur_index];
		}
		else
		{
			std::cerr << "Can't jump, cause step is more then len of string. Len is" <<
			             m_ss.size() << " Step is " << step << std::endl;
		}
		
	}

	bool check(std::string const& s);

	bool try_take_token(std::string const& s, Token::TYPE type)
	{
		if (check(s))
		{
			m_token = Token(s, type);
			jump(s.size());
			return true;
		}
		return false;
	}
};