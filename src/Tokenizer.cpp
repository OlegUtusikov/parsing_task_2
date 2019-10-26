#include "Tokenizer.hpp"

void Tokenizer::next_char()
{
	if (m_cur_index < m_ss.size())
	{
		m_cur_char = m_ss[m_cur_index];
		++m_cur_index;
	}
	else
	{
		std::cerr << "Index is more ss.size" << std::endl;
	}
}