#pragma once

#include <cstddef>
#include <iostream>

using namespace std;

class String {

	char	*str;
	size_t	size;

public:
	
	String();
	String(const String &str);
	String(const char *str);
	String(size_t n, char c);

	~String();

	
	
	size_t	length() const;
	char	*c_str() const;
	String	&append(const String &str);
	String	&append(const char *str);
	int		compare(const String &str) const;
	int		compare(const char *str) const;
	void	resize(size_t n, char c = '\0');
	void	clear();
	void	swap(String &str);
	int		substr(const String &str, size_t n, size_t len) const;
	int		substr(const char *str, size_t n, size_t len) const;
	String	&insert(size_t pos, const String &str);
	String	&insert(size_t pos, const char *str);
	String	&insert(size_t pos, const String &str, size_t subpos, size_t sublen);
	String	&insert(size_t pos, const char *str, size_t subpos, size_t sublen);

	String	&operator=(const String &rhs);
	String	operator+(const String &rhs) const;
	String	operator+(const char *rhs) const;
	String	&operator+=(const String &rhs);
	String	&operator+=(const char *rhs);
	bool	operator==(const String &b) const;
	bool	operator!=(const String &b) const;


};

String		operator+(const char *lhs, const String &rhs);
ostream		&operator<<(ostream &out, const String &rhs);
istream		&operator>>(istream &in, String &rhs);