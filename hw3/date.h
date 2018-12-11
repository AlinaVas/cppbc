#pragma once

#include <iostream>

const int monthDays[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

class Date {

	int	_day;
	int _month;
	int _year;

	Date(int);
	int	countDays(Date const &);

	public:

		Date();
		Date(std::string);

		bool		leapYear(int) const;
		int			getDay() const;
		int			getMonth() const;
		int			getYear() const;

		bool		setDate(std::string);

		friend Date	operator-(Date const &, Date const &);
		friend Date	operator+(Date const &, int);
		friend Date	operator-(Date const &, int);
};

std::ostream	&operator<<(std::ostream &, Date const &);

std::istream	&operator>>(std::istream &, Date &);