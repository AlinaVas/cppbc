#include "String.h"
// #include <iostream>

using namespace std;

int main() {

	// String s;
	// if (*(s.c_str()) == '\0')
	// 	cout << "hohoho\n";

	String a(3, '#');
	cout << a << endl;

	a.resize(8, '*');
	cout << a << endl;
	cout << a.length() << endl;

	String b("UNIT");
	cout << b << endl;
	cout << b.length() << endl;

	b.append(" Factory");
	cout << b << endl;
	cout << b.length() << endl;

	cout << b.compare("UNIT Factory") << endl;

	String d(a);
	cout << d << endl;
	if (*(d.c_str()) == '\0')
		cout << "hohoho\n";

	cout << "substr found at " << b.substr(String("UNIT Factory**"), 5, 7) << " pos of String" << endl;
}