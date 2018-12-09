#include "golf.h"
#include <cstring>
#include <iostream>

using namespace std;

void setGolf(golf & g, const char * name, int hc)
{
	strncpy(g.fullname, name, 39);
	g.handicap = hc;
}

int setGolf(golf & g)
{
	string	name;
	string	hc;

	cout << "Enter a full name:" << endl;
	getline(cin, name);
	strncpy(g.fullname, name.c_str(), 39);

	cout << "Enter a handicap:" << endl;
	getline(cin, hc);
	if (hc.empty())
		g.handicap = 0;
	else {
		try {
			g.handicap = stoi(hc);
		}
		catch (invalid_argument & e) {
			cout << e.what() << endl;
			g.handicap = 0;
		}
		catch (out_of_range & e) {
			cout << e.what() << endl;
			g.handicap = 0;
		}
	}
	if (name.empty())
		return 0;
	return 1;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showGolf(const golf& g)
{
	cout << "Full name: " << g.fullname << endl;
	cout << "Handicap: " << g.handicap << endl;
}
