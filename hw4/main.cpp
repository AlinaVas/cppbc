#include "String.h"

using namespace std;

int main() {

	String a(3, '#');
	cout << a << endl;

	a.resize(8, '*');
	cout << a << endl;
	cout << a.length() << endl;

	String a1(a);
	cout << a1 << endl;

	String b("Hello");
	cout << b << endl;
	cout << b.length() << endl;

	b.append(" World");
	cout << b << endl;
	cout << b.length() << endl;

	cout << b.compare("Hello World") << endl;

	cout << "substr found at " << b.substr(String("let's make the World a better place"), 15, 5) << " pos of a String" << endl;

	try {
		b.insert(11, String("!!!"));
		cout << b << endl;
	}
	catch (exception &e) {
		cout << "b: " << "Error : " << e.what() << endl;
	}
	
	try {
		b.insert(5, "this is a comma sign ,", 21, 1);
		cout << "b: " << b << endl;
	}
	catch (exception &e) {
		cout << "Error : " << e.what() << endl;
	}

	a = b;
	cout << "a: " << a << endl;
	if (a == b)
		cout << "a and b are equal" << endl;
	if (a != b)
		cout << "a and b are not equal" << endl;

	a.clear();
	a = b + " operator+";
	cout << a << endl;
	cout << a.length() << endl;

	a += " operator+=";
	cout << a << endl;
	cout << a.length() << endl;

	a.resize(13);
	cout << "Resized a: " << a << endl;

	String c;
	cout << "Enter a string you want to create:" << endl;
	cin >> c;
	cout << "Your string:" << endl << c << endl;

	
	cout << "* before swap *" << endl << "a: " << a << endl << "c: " << c << endl;
	a.swap(c);
	cout << "* after swap *" << endl << "a: " << a << endl << "c: " << c << endl;

	c = "[char array] + " + c + " + [another char array]";
	cout << c << endl;
}