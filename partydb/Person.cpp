// Person.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#include "Person.h"

Person::Person()
	: birthday(Birthdate())
	, name("")
{
}

Person::Person(const string& new_name, const Birthdate& new_birthday)
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

bool Person::operator== (const Person& right) const
{
	return birthday == right.birthday && name == right.name;
}

bool Person::operator> (const Person& right) const
{
	//if (birthday == right.birthday) {
	//	// If birthdays are equal, 
	//	// return the name that comes before the other in the ASCII table
	//	return (strcmp(name.c_str(), right.name.c_str()) < 0);
	//}
	return birthday > right.birthday;
}