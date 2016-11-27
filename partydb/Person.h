// Person.h
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_PERSON_H
#define PARTYDB_PERSON_H

#include <string>
#include "Birthdate.h"

using namespace std;

class Person
{
private:
	Birthdate birthday;
	string name;
public:
	// Default constructor should not be directly used other than as a type-specifier
	Person();
	Person(const Birthdate& new_birthday, const string& new_name);
	Birthdate getBirthday() const;
	string getName() const;

	bool operator== (const Person& right) const;
	bool operator>  (const Person& right) const;
};

#endif