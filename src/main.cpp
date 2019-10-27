#include "Tokenizer.hpp"

int main()
{
	Tokenizer tr("var i:integer; a, b: char;");
	tr.next_token();
	std::cout << tr.cur_token().value() << std::endl;
	std::cout << tr.cur_index() << std::endl;
	return 0;
}