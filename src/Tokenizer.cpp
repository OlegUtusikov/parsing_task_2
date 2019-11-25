#include "Tokenizer.hpp"
#include <sstream>

void Tokenizer::drop_blanks()
{
	while (is_blank(cur_char()))
	{
		next_char();
	}
}

void Tokenizer::next_char()
{
	if (m_cur_index + 1 < static_cast<int>(m_ss.size()))
	{
		++m_cur_index;
		m_cur_char = m_ss[m_cur_index];
	}
	else
	{
		m_cur_char = '\0';
	}
	//std:: cout << "next "  << m_cur_char << std::endl;
}

bool Tokenizer::try_take_type()
{
	using TYPE = Token::TYPE;
	drop_blanks();
	//std::cout << "type " << cur_char() << std::endl; 
	if (cur_char() == 'i' && try_take_token("integer", TYPE::TYPE))
	{
		return true;
	}
	else if (cur_char() == 'r' && try_take_token("real", TYPE::TYPE))
	{
		return true;
	}
	else if (cur_char() == 'c' && try_take_token("char", TYPE::TYPE))
	{
		return true;
	}
	else if (cur_char() == 'b' && try_take_token("boolean", TYPE::TYPE))
	{
		return true;
	}
	else
	{
		std::stringstream ss;
		ss << cur_char();
		m_token = Token(ss.str(), TYPE::ERROR);
		return false;
	}
}

void Tokenizer::next_token()
{
	using TYPE = Token::TYPE;
	drop_blanks();
	switch (cur_char())
	{
	case '\0':
		m_token = Token("END", TYPE::END);
		break;
	case 'v':
		if (try_take_token("var", TYPE::VAR))
		{
			break;
		}
	case ';':
		next_char();
		m_token = Token(";", TYPE::SEMICOLLON);
		break;
	case ',':
		next_char();
		m_token = Token(",", TYPE::COMMA);
		break;
	default:
		if (!try_take_type())
		{
			if (std::isalpha(cur_char()))
			{
				std::stringstream ss;
				while (std::isalnum(cur_char()))
				{
					ss << cur_char();
					next_char();
				}

				drop_blanks();
				if (cur_char() == ':')
				{
					ss << cur_char();
					next_char();
					if (try_take_type())
					{
						ss << cur_token().value();
						m_token = Token(ss.str(), TYPE::NAME_TYPE);
					}
					else
					{
						std::stringstream ss;
						ss << "Expect type, but found '" << cur_token().value() << "'";
						m_token = Token(ss.str(), TYPE::ERROR);
					}
				} 
				else
				{
					m_token = Token(ss.str(), TYPE::NAME);
				}
			}
			else
			{
				std::stringstream ss;
				ss << "'" << cur_char() << "' - unkown symbol";
				m_token = Token(ss.str(), TYPE::ERROR);
			}
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

	if (cur_index() + s.size() < m_ss.size() + 1)
	{
		bool ans = true;
		mark();
		for (auto c : s)
		{
			ans &= cur_char() == c;
			if (!ans)
			{
				break;
			}
			next_char();
		}
		ans &= !std::isalnum(cur_char());
		back(); 
		return ans;
	}
	return false;
}

bool Tokenizer::try_take_token(std::string const& s, Token::TYPE type)
{
	//std::cout << "try take token " << s << std::endl;
	if (check(s))
	{
		m_token = Token(s, type);
		jump(s.size());
		return true;
	}
	return false;
}