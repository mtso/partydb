// Person.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#include "Person.h"

Person::Person(const Birthdate& new_birthday, const string& new_name)
	: birthday(new_birthday)
	, name(new_name)
{
}

Birthdate Person::getBirthday() const
{
	return birthday;
}

string Person::getName() const
{
	return name;
}