#include "Tokenizer.hpp"

void Tokenizer::next_char()
{
	if (m_cur_index  + 1 < m_ss.size())
	{
		++m_cur_index;
		m_cur_char = m_ss[m_cur_index];
	}
	else
	{
		std::cerr << "Index is more then ss.size. " << "Index : " << cur_index() << ", size" << m_ss.size() << std::endl;
	}
}

void Tokenizer::next_token()
{
	while (is_blank(cur_char()))
	{
		next_char();
	}
	switch (cur_char())
	{
	case 'v':
		{
			std::string s = "var";
			if (check(s))
			{
				m_token = Token(s, Token::TYPE::VAR);
				jump(s.size());
			}
		}
		break;
	
	default:
		std::cerr << "Unkown token" << std::endl;
		break;
	}
}