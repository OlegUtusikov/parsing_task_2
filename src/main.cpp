#include "Analizator.hpp"
#include <string.h>

int main()
{
	Analizator a;
	a.parse("var i \t \t \t:integer; a, b   : char; realB, realinteger: real;").print();
	a.parse("var d, c, n \t \t\t \t , jf,k ,h,t    : boolean;").print();
	a.parse("var  c  : 			       char;").print();
	a.parse("\n       	var i: \r \n \t  integer;").print();
	a.parse("  var ttt : integer;").print();
	return 0;
}
