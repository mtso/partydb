// Birthdate.h
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_BIRTHDATE_H
#define PARTYDB_BIRTHDATE_H

#include <iostream>
using namespace std;

class Birthdate
{
private:
	int month;
	int day;
	int year;
public:

	class InvalidValuesException {
	private:
		string description = "Invalid numbers used to construct a birthday value.";
	public:
		string getDescription() const { return description; }
	};

	// Default Constructor should never be used to describe a real birthday.
	Birthdate();
	Birthdate(const int& new_month,
	          const int& new_day,
	          const int& new_year);

	int getMonth() const;
	int getDay() const;
	int getYear() const;

	bool operator== (const Birthdate& right) const;
	bool operator>  (const Birthdate& right) const;

	friend ostream& operator<< (ostream& output, const Birthdate& bday);
};
#endif