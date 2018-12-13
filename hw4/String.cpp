#include "String.h"
// #include <iostream>
#include <cstring>

using namespace std;

String::String() : str(new char[1]), size(0) {}

String::String(const String &str) : str(new char[str.length() + 1]()), size(str.length()) {

	this->str = strcpy(this->str, str.c_str());
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

String::~String() { delete[] str; }

size_t
String::length() const { return size; }

char*
String::c_str() const { return str; }

String&
String::append(const String &str) {

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

	return strcmp(this->str, str.c_str());
}

int
String::compare(const char *str) const {

	return strcmp(this->str, str);
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

void
String::clear() {

	delete[] str;
	str = new char[1];
	size = 0;
}

void
String::swap(String &str) {

	char *tmpStr = this->str;
	this->str = str.str;
	str.str = tmpStr;

	size_t tmpSize = this->size;
	this->size = str.size;
	str.size = tmpSize;
}

int
String::substr(const String &s, size_t n, size_t len) const {

	if (n >= s.size || !len)
		return -1;

	char *subStr = new char[len + 1];
	strncpy(subStr, &s.str[n], len);
	subStr[len] = '\0';
	char *pos = strstr(str, subStr);
	delete[] subStr;
	if (!pos)
		return -1;
	return pos - str;
}

int
String::substr(const char *s, size_t n, size_t len) const {

	if (!s || n >= strlen(s) || !len)
		return -1;

	char *subStr = new char[len + 1];
	strncpy(subStr, &s[n], len);
	subStr[len] = '\0';
	char *pos = strstr(str, subStr);
	delete[] subStr;
	if (!pos)
		return -1;
	return pos - str;
}


ostream&
operator<<(ostream &out, String const &rhs) {

	return out << rhs.c_str();
}


