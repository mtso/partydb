// Person.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_PERSON_CPP
#define PARTYDB_PERSON_CPP

#ifndef PARTYDB_PERSON_H
#include "Person.h"
#endif

template <int S>
Person<S>::Person()
	: birthday(Birthdate())
	, name(Name(""))
{
}

template <int S>
Person<S>::Person(const string& new_name, const Birthdate& new_birthday)
	: birthday(new_birthday)
	, name(Name(new_name))
{
}

template <int S>
Person<S>::Person(const string& raw_data_entry)
{
	Person<S> new_data = parsePersonIn(raw_data_entry);
	name = new_data.getName();
	birthday = new_data.getBirthday();
}

template <int S>
Birthdate Person<S>::getBirthday() const
{
	return birthday;
}

template <int S>
Name Person<S>::getName() const
{
	return name;
}

template <int S>
bool Person<S>::operator== (const Person& right) const
{
	return birthday == right.birthday && name == right.name;
}

// BY_BIRTHDAY should compare both fields because birthdays can repeat
// whereas the rule for names is that names cannot repeat
template <>
bool Person<BY_BIRTHDAY>::operator== (const Person& right) const
{
	return birthday == right.birthday && name == right.name;
}

template <>
bool Person<BY_NAME>::operator== (const Person& right) const
{
	return name == right.name;
}

// By the same token, the operator > 
// also needs to compare both fields

template <>
bool Person<BY_BIRTHDAY>::operator> (const Person<BY_BIRTHDAY>& right) const
{
	if (birthday == right.birthday) {
		// If birthdays are equal,
		// return the name that comes before the other in the ASCII table
		return name > right.name;
	}
	return birthday > right.birthday;
}

template <>
bool Person<BY_NAME>::operator> (const Person<BY_NAME>& right) const
{
	return name > right.name;
}


template <int S>
Person<S> Person<S>::parsePersonIn(const string& line)
{
	int space_index = lastIndexIn(line, ' ');
	string name = line.substr(0, space_index);
	string raw_birthday = line.substr(space_index + 1, line.length() - space_index - 1);

	Birthdate birthday = parseBirthdate(raw_birthday);
	return Person<S>(name, birthday);
}

template <int S>
Birthdate Person<S>::parseBirthdate(const string& raw_birthday)
{
	string month = raw_birthday.substr(0, 2);
	string day = raw_birthday.substr(3, 2);
	string year = raw_birthday.substr(6, 4);
	return Birthdate(stoi(month), stoi(day), stoi(year));
}

template <int S>
int Person<S>::lastIndexIn(const string& str, const char& character)
{
	int index = -1;
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] == character) {
			index = i;
		}
	}
	return index;
}
#endif