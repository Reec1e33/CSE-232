#include <iostream>
#include "homework8c.h"

int main() {
	LispExpression le("(   ( ) q  ( a ( b ) )  ) ( a )");
	std::cout << le.PrettyPrint();
    std::cout << '-' << std::endl;
    std::cout << "(\n (\n )\n q\n (\n a\n (\n b\n )\n )\n)\n" << std::endl;
	return 0;
}