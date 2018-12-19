#include "String.h"
#include <cstring>
#include <stdexcept>

using namespace std;

String::String() : str(new char[1]), size(0) {}

String::String(const String &src) : str(new char[src.length() + 1]), size(src.length()) {

	str = strcpy(str, src.c_str());
}

String::String(const char *src) : size(strlen(src)) {

	str = new char[size + 1];
	if (!src || !size)
		*str = '\0';
	else
		strcpy(str, src);
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
String::append(const String &src) {

	size += src.length();
	
	char *newStr = new char[size + 1];
	strcpy(newStr, str);
	strcat(newStr, src.c_str());
	delete[] str;
	str = newStr;

	return *this;
}

String&
String::append(const char *src) {

	size += strlen(src);
	char *newStr = new char[size + 1];
	strcpy(newStr, str);
	strcat(newStr, src);
	delete[] str;
	str = newStr;

	return *this;
}

int
String::compare(const String &src) const {

	return strcmp(str, src.c_str());
}

int
String::compare(const char *src) const {

	return strcmp(str, src);
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

	delete[] str;
	str = newStr;

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
String::swap(String &src) {

	char *tmpStr = str;
	str = src.str;
	src.str = tmpStr;

	size_t tmpSize = size;
	size = src.size;
	src.size = tmpSize;
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
String::insert(size_t pos, const String &src) {

	if (pos > size)
		throw std::out_of_range("pos value is greater than the size of a String");
	char *newStr = new char[size + src.size + 1];
	strncpy(newStr, str, pos);
	strcat(newStr, src.str);
	strcpy(&newStr[pos + src.size], &str[pos]);

	delete[] str;
	str = newStr;
	size += src.size;
	return *this;
}

String&
String::insert(size_t pos, const char *src) {

	if (pos > size)
		throw std::out_of_range("pos value is greater than the size of a String");
	char *newStr = new char[size + strlen(src) + 1];
	strncpy(newStr, str, pos);
	strcat(newStr, src);
	strcpy(&newStr[pos + strlen(src)], &str[pos]);

	delete[] str;
	str = newStr;
	size += strlen(src);
	return *this;
}

String&
String::insert(size_t pos, const String &src, size_t subpos, size_t sublen) {

	if (pos > size)
		throw std::out_of_range("pos value is greater than the size of a String");
	if (subpos > src.size)
		throw std::out_of_range("subpos value is greater than the size of str");

	char *subStr = new char[sublen + 1];
	strncpy(subStr, &src.str[subpos], sublen);
	subStr[sublen] = '\0';
	
	char *newStr = new char[size + sublen + 1];
	strncpy(newStr, str, pos);
	strcat(newStr, subStr);
	strcpy(&newStr[pos + sublen], &str[pos]);

	delete[] subStr;
	delete[] str;
	str = newStr;
	size += sublen;
	return *this;
}

String&
String::insert(size_t pos, const char *src, size_t subpos, size_t sublen) {

	if (pos > size)
		throw std::out_of_range("pos value is greater than the size of a String");
	if (subpos > strlen(src))
		throw std::out_of_range("subpos value is greater than the size of str");

	char *subStr = new char[sublen + 1];
	strncpy(subStr, &src[subpos], sublen);
	subStr[sublen] = '\0';
	
	char *newStr = new char[size + sublen + 1];
	strncpy(newStr, str, pos);
	strcat(newStr, subStr);
	strcpy(&newStr[pos + sublen], &str[pos]);

	delete[] subStr;
	delete[] str;
	str = newStr;
	size += sublen;
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
