#include "String.h"
#include <cstring>
#include <stdexcept>

using namespace std;

String::String() : str(new char[1]), size(0) {}

String::String(const String &str) : str(new char[str.length() + 1]), size(str.length()) {

	this->str = strcpy(this->str, str.c_str());
}

String::String(const char *str) : size(strlen(str)) {

	this->str = new char[size + 1];
	if (!str || !size)
		*this->str = '\0';
	else
		strcpy(this->str, str);
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
	*str = '\0';
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

	if (!len)
		return -1;
	if (n > s.size)
		throw std::out_of_range("n value is greater than the size of a String");

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

	if (!s || !len)
		return -1;
	if (n > strlen(s))
		throw std::out_of_range("n value is greater than the size of a String");

	char *subStr = new char[len + 1];
	strncpy(subStr, &s[n], len);
	subStr[len] = '\0';
	char *pos = strstr(str, subStr);
	delete[] subStr;
	if (!pos)
		return -1;
	return pos - str;
}

String&
String::insert(size_t pos, const String &str) {

	if (pos > this->size)
		throw std::out_of_range("pos value is greater than the size of a String");
	char *newStr = new char[this->size + str.size + 1];
	strncpy(newStr, this->str, pos);
	strcat(newStr, str.str);
	strcpy(&newStr[pos + str.size], &this->str[pos]);

	delete[] this->str;
	this->str = newStr;
	this->size += str.size;
	return *this;
}

String&
String::insert(size_t pos, const char *str) {

	if (pos > this->size)
		throw std::out_of_range("pos value is greater than the size of a String");
	char *newStr = new char[this->size + strlen(str) + 1];
	strncpy(newStr, this->str, pos);
	strcat(newStr, str);
	strcpy(&newStr[pos + strlen(str)], &this->str[pos]);

	delete[] this->str;
	this->str = newStr;
	this->size += strlen(str);
	return *this;
}

String&
String::insert(size_t pos, const String &str, size_t subpos, size_t sublen) {

	if (pos > this->size)
		throw std::out_of_range("pos value is greater than the size of a String");
	if (subpos > str.size)
		throw std::out_of_range("subpos value is greater than the size of str");

	char *subStr = new char[sublen + 1];
	strncpy(subStr, &str.str[subpos], sublen);
	subStr[sublen] = '\0';
	
	char *newStr = new char[this->size + sublen + 1];
	strncpy(newStr, this->str, pos);
	strcat(newStr, subStr);
	strcpy(&newStr[pos + sublen], &this->str[pos]);

	delete[] subStr;
	delete[] this->str;
	this->str = newStr;
	this->size += sublen;
	return *this;
}

String&
String::insert(size_t pos, const char *str, size_t subpos, size_t sublen) {

	if (pos > this->size)
		throw std::out_of_range("pos value is greater than the size of a String");
	if (subpos > strlen(str))
		throw std::out_of_range("subpos value is greater than the size of str");

	char *subStr = new char[sublen + 1];
	strncpy(subStr, &str[subpos], sublen);
	subStr[sublen] = '\0';
	
	char *newStr = new char[this->size + sublen + 1];
	strncpy(newStr, this->str, pos);
	strcat(newStr, subStr);
	strcpy(&newStr[pos + sublen], &this->str[pos]);

	delete[] subStr;
	delete[] this->str;
	this->str = newStr;
	this->size += sublen;
	return *this;
}

String&
String::operator=(const String &rhs) {

	if (&rhs != this) {

		size = rhs.size;

		delete[] str;
		str = new char[size + 1];
		strcpy(str, rhs.str);
	}
	return *this;
}

String
String::operator+(const String &rhs) const {

	String s(*this);
	s.append(rhs);
	return s;
}

String
String::operator+(const char *rhs) const {

	String s(*this);
	s.append(rhs);
	return s;
}

String&
String::operator+=(const String &rhs) {

	return append(rhs);
}

String&
String::operator+=(const char *rhs) {

	return append(rhs);
}

bool
String::operator==(const String &rhs) const {

	if (!strcmp(str, rhs.str) && (size == rhs.size))
		return true;
	return false;
}

bool
String::operator!=(const String &rhs) const {

	if (!strcmp(str, rhs.str) && (size == rhs.size))
		return false;
	return true;
}

String
operator+(const char *lhs, const String &rhs) {

	String s(lhs);
	s += rhs;
	return s;
}

ostream&
operator<<(ostream &out, const String &rhs) {

	return out << rhs.c_str();
}

istream&
operator>>(istream &in, String &rhs) {

	rhs.clear(); 

	string buf;
	in >> buf;
	rhs.append(buf.c_str());

	return in;
}
