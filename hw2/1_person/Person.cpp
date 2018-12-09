#include "Person.h"

Person::Person() {

	mLastName = "";
	mFirstName[0] = '\0';
}

Person::Person(const string & ln, const char * fn /*= "Heyyou"*/) {

	mLastName = ln;
	strcpy(mFirstName, fn);
}

void
Person::Show() const {

	cout << mFirstName << " " << mLastName;
}

void
Person::FormalShow() const {

	cout << mLastName << " " << mFirstName;
}
