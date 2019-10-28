#include "Tokenizer.hpp"
#include <sstream>

void Tokenizer::next_char()
{
	if (m_cur_index  + 1 < m_ss.size())
	{
		++m_cur_index;
		m_cur_char = m_ss[m_cur_index];
	}
	else
	{
		m_cur_char = '\0';
		std::cerr << "Index is more then ss.size. " << "Index : " << cur_index() << ", size " << m_ss.size() << std::endl;
	}
}

void Tokenizer::next_token()
{
	using TYPE = Token::TYPE;
	while (is_blank(cur_char()))
	{
		next_char();
	}

	switch (cur_char())
	{
	case '\0':
		m_token = Token("", TYPE::END);
		break;
	case 'v':
		if (try_take_token("var", TYPE::VAR))
		{
			break;
		}
	case ':':
		next_char();
		m_token = Token(":", TYPE::COLLON);
		break;
	case ';':
		next_char();
		m_token = Token(";", TYPE::SEMICOLLON);
		break;
	case ',':
		next_char();
		m_token = Token(",", TYPE::COMMA);
		break;
	case 'i':
		if (try_take_token("integer", TYPE::TYPE))
		{
			break;
		}
	case 'r':
		if (try_take_token("real", TYPE::TYPE))
		{
			break;
		}
	case 'c':
		if (try_take_token("char", TYPE::TYPE))
		{
			break;
		}
	case 'b':
		if (try_take_token("boolean", TYPE::TYPE))
		{
			break;
		}
	default:
		if (std::isalpha(cur_char()))
		{
			std::stringstream ss;
			while (std::isalnum(cur_char()))
			{
				ss << cur_char();
				next_char();
			}
			m_token = Token(ss.str(), TYPE::NAME);
		}
		else
		{
			std::cerr << "Unkown token" << std::endl;
		}
		break;
	}
}

bool Tokenizer::check(std::string const& s)
	{
		if (s.empty() || m_ss.empty())
		{
			return false;
		}

		if (cur_index() + s.size() - 1 == m_ss.size())
		{
			bool ans = true;
			mark();
			for (auto c : s)
			{
				ans &= cur_char() == c;
				next_char();
			}
			if (cur_index() + s.size() - 1 < m_ss.size() - 1)
			{
				ans &= !std::isalnum(cur_char());
			}
			back(); 
			return ans;
		}
		return false;
	}