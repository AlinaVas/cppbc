#include "golf.h"
#include <iostream>

using namespace std;

int	main()
{
	golf a;
	golf b;

	cout << endl << "==================" << endl;
	setGolf(a, "Bob", 11);
	showGolf(a);
	handicap(a, 15);
	showGolf(a);

	cout << endl << "==================" << endl;
	setGolf(b);
	showGolf(b);
}
