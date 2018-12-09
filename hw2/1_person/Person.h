#pragma once

#include <cstring>
#include <iostream>

using namespace std;

constexpr int LIMIT = 25;

class Person {
private:
	string mLastName;
	char mFirstName[LIMIT];
public:
	Person();
	Person(const string & ln, const char * fn = "Heyyou");
	
	void Show() const;
	void FormalShow() const;
};
