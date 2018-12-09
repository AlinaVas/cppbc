#pragma once

#include <iostream>

const int monthDays[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

class Date {

	int	_day;
	int _month;
	int _year;

	Date(int);
	int	countDays(Date const & d);

	public:

		Date();
		Date(std::string);

		bool		leapYear(int) const;
		int			getDay() const;
		int			getMonth() const;
		int			getYear() const;

		bool		setDate(std::string);

		friend Date	operator-(Date const & d1, Date const & d2);
};

std::ostream	&operator<<(std::ostream &out, Date const & rhs);

std::istream	&operator>>(std::istream &in, Date & rhs);