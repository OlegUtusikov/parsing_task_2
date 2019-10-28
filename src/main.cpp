#include "Tokenizer.hpp"
#include <string.h>

int main()
{
	std::string tmp = "var i	:integer; a, b   : char; realB, realinteger: real;";
	Tokenizer tr(tmp);
	while (true)
	{
		Token t = tr.cur_token();
		std::cout << "VALUE: " << t.value() << " TYPE: " << t.type_str() << " Ind: " << tr.cur_index() << std::endl;
		if (t.type() == Token::TYPE::END)
		{
			break;
		}
		tr.next_token();

	}
	return 0;
}