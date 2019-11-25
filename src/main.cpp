#include "Analizator.hpp"
#include <string.h>

template<typename T>
void test(int id, T expect, T actual)
{
	if (expect == actual)
	{
		std::cout << id << ") " << "PASSED" << std::endl;
	}
	else
	{
		std::cout << id << ")" << "FAILED" << std::endl;
	}
}

int main()
{
	Analizator a;
	a.parse("var i \t \t \t:integer; a, b   : char; realB, realinteger: real;").print();
	a.parse("var d, c, n \t \t\t \t , jf,k ,h,t    : boolean;").print();
	a.parse("var  c  : 			       char;").print();
	a.parse("\n       	var i: \r \n \t  integer;").print();
	a.parse("  var ttt : integer;").print();
	a.parse("  var ttt-adas : integer;").print();
	a.parse("  var ttt : cr;").print();
	a.parse("  var ttt, adas : integer; t:  boolean; rrt``: char").print();

	// TESTS
	test(1, a.parse("var i \t \t \t:integer; a, b   : char; realB, realinteger: real;").check(), true);
	test(2, a.parse("\n       	var i: \r \n \t  integer;").check(), true);
	test(3, a.parse("  var ttt-adas : integer;").check(), false);
	test(4, a.parse("  var ttt, adas : integer; t:  boolean; rrt``: char").check(), false);
	return 0;
}
