#include "date.h"
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <regex>

Date::Date() : _day(1), _month(1), _year(1970) {}

Date::Date(int days) {

	const int daysIn400Years = (400 * 365) + 97;
	_year = (days / daysIn400Years) * 400;
	days = days % daysIn400Years;

	while (days >= 365) {
		if (leapYear(++_year))
			days--;
		days -= 365;
	}

	_month = 0;
	while (days > monthDays[_month + 1])
		_month++;
	_day = days - monthDays[_month];

}

Date::Date(std::string date) : _day(1), _month(1), _year(1970) {

	if (!setDate(date))
		std::cout << "Incorrect date format. The default value was set\n";
}

bool
Date::setDate(std::string date) {

	int day, month, year;

	std::regex reg1("^\\d{2}[-.]\\d{2}[.-]\\d{4}$");
	std::regex reg2("^\\d{4}.\\d{2}.\\d{2}$");
	if (std::regex_match(date, reg1))
		sscanf(date.c_str(), "%2d%*c%2d%*c%4d", &day, &month, &year);
	else if (std::regex_match(date, reg2))
		sscanf(date.c_str(), "%4d.%2d.%2d", &year, &month, &day);
	else
		return false;
		
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2 && leapYear(year) && day > 29)
		return false;
	if (month == 2 && !leapYear(year) && day > 28)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	_day = day;
	_month = month;
	_year = year;
	return true;
}

bool
Date::leapYear(int year) const {

	if (!(year % 4) && ((year % 100) || !(year % 400)))
		return true;
	return false;
}

int
Date::getDay() const { return _day; }

int
Date::getMonth() const { return _month; }

int
Date::getYear() const { return _year; }

std::ostream&
operator<<(std::ostream &out, Date const & rhs) {

	out << std::setfill('0') << std::setw(2) << rhs.getDay() << "."
		<< std::setfill('0') << std::setw(2) << rhs.getMonth() << "." 
		<< std::setfill('0') << std::setw(4) << rhs.getYear();
	return out;
}

std::istream&
operator>>(std::istream &in, Date & rhs) {

	std::string buf;

	in >> buf;
	if (!rhs.setDate(buf))
		std::cout << "Incorrect date format. The default value was set\n";
	return in;
}

int
countDays(Date const & d) {

	int baseYear = (d.getMonth() <= 2) ? (d.getYear() - 1) : d.getYear();
	int numOfLeapYears = baseYear / 4 - baseYear / 100 + baseYear / 400;
	int days = d.getYear() * 365 + monthDays[d.getMonth() - 1] + d.getDay() + numOfLeapYears;
	return days;
}

Date
operator-(Date const & d1, Date const & d2) {

	int date1 = countDays(d1);
	int date2 = countDays(d2);
	if (date1 > date2)
		return Date(date1 - date2);
	return Date(date2 - date1);
}