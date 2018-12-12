#include "String.h"
// #include <iostream>

using namespace std;

int main() {

	String a;
	String b("UNIT");


	cout << b << endl;
	cout << b.length() << endl;

	// b.resize(12, '*');
	// cout << b << endl;

	String c(" Factory");
	b.append(c);
	cout << b << endl;

	String d(a);
	cout << d << endl;
	if (*(d.c_str()) == '\0')
		cout << "hohoho\n";

	// b.resize()
}