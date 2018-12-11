#include "date.h"
#include <iostream>

int main() {

	Date a;
	std::cout << "a: " << a << std::endl;

	Date b("2016.02.28");
	std::cout << "b: " << b << std::endl;

	Date c;
	std::cin >> c;
	std::cout << "c: " << c << std::endl;

	Date d = b - c;
	std::cout << "(b - c): " << d << std::endl;

	Date e = b + 1;
	std::cout << "e (b + 1 day): " << e << std::endl;

	Date f = c - 2;
	std::cout << "f (c - 2 day): " << f << std::endl;
}
