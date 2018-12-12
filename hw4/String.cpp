#include "String.h"
// #include <iostream>
#include <cstring>

using namespace std;

String::String() : str(new char[1]), size(0) {}

String::String(const String &str) : str(new char[str.length() + 1]()), size(str.length()) {

	this->str = (size) ? strcpy(this->str, str.c_str()) : 0;
}

String::String(const char *str) : size(strlen(str)) {

	this->str = (str) ? strdup(str) : nullptr;
}

String::String(size_t n, char c) : str(new char[n + 1]), size(n) {

	for (size_t i = 0; i < n; i++) {
		str[i] = c;
	}
	str[n] = '\0';
}

size_t
String::length() const { return size; }

char*
String::c_str() const { return str; }

String&
String::append(const String &str) {

	if(!str.c_str())
		return *this;

	size += str.length();
	
	char *newStr = new char[size + 1];
	strcpy(newStr, this->str);
	strcat(newStr, str.c_str());
	delete[] this->str;
	this->str = newStr;

	return *this;
}

String&
String::append(const char *str) {

	if(!str)
		return *this;

	size += strlen(str);
	char *newStr = new char[size + 1];
	strcpy(newStr, this->str);
	strcat(newStr, str);
	delete[] this->str;
	this->str = newStr;

	return *this;
}

int
String::compare(const String &str) const {

	return strcmp(this->c_str(), str.c_str());
}

void
String::resize(size_t n, char c /*= '\0'*/) {

	char *newStr = new char[n + 1];
	strncpy(newStr, str, n);
	if (n > size) {
		for (size_t i = 0; i < n - size; i++) {
			newStr[size + i] = c;
		}
	}
	newStr[n] = '\0';

	delete[] this->str;
	this->str = newStr;

	size = n;
}

ostream&
operator<<(ostream &out, String const &rhs) {

	return out << rhs.c_str();
}