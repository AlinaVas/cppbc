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
	int		substr(const String &str, size_t n, size_t len) const;// different
	int		substr(const char *str, size_t n, size_t len) const;
	// string	&insert(size_t pos, const String &str);
	// string	&insert(size_t pos, char c);

};

ostream &operator<<(ostream &out, String const &rhs);