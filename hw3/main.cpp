#include "date.h"
#include <iostream>

int main() {

	Date a;
	std::cout << "a: " << a << std::endl;

	Date b("2018.02.28");
	std::cout << "b: " << b << std::endl;

	Date c;
	std::cin >> c;
	std::cout << "c: " << c << std::endl;

	Date d = b - c;
	std::cout << "(b - c): " << d << std::endl;
}
