// Birthdate.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#include "Birthdate.h"

Birthdate::Birthdate()
: month(0)
, day(0)
, year(0)
{
}

Birthdate::Birthdate(
	const int& new_month,
	const int& new_day,
	const int& new_year)
{
	if (new_month > 12 || new_month < 1) {
		throw InvalidValuesException();
	}
	month = new_month;

	if (new_year > 9999 || new_year < 1) {
		throw InvalidValuesException();
	}
	year = new_year;

	int max_days;
	switch (month) {
	case 2:
		max_days = 29;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		max_days = 30;
		break;

		// Assume the rest are either 1, 3, 5, 7, 8, 10, or 12
		// which result in a max of 31 days
	default:
		max_days = 31;
		break;
	}

	if (new_day > max_days || new_day < 1) { throw InvalidValuesException(); }
	day = new_day;
}

int Birthdate::getMonth() const
{
	return month;
}
int Birthdate::getDay() const
{
	return day;
}
int Birthdate::getYear() const
{
	return year;
}

bool Birthdate::operator== (const Birthdate& right) const
{
	return (month == right.month && day == right.day && year == right.year);
}

bool Birthdate::operator> (const Birthdate& right) const
{
	if (year == right.year) 
	{
		if (month == right.month) 
		{
			return day > right.day;
		}
		return month > right.month;
	}
	return year > right.year;
}

ostream& operator<< (ostream& output, const Birthdate& birthdate)
{
	if (birthdate.month < 10) { output << "0"; }
	output << birthdate.month << "-";
	if (birthdate.day < 10) { output << "0"; }
	output << birthdate.day << "-";
	output << birthdate.year;
	return output;
}