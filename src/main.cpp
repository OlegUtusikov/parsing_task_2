#include "Analizator.hpp"
#include <string.h>

int main()
{
	std::string tmp = "var i	:integer; a, b   : char; realB, realinteger: real;";
	Analizator a;
	Node node = a.parse(tmp);
	std::cout << "GOOD" << std::endl;
	node.print(0);
	return 0;
}
