// Person.h
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_PERSON_H
#define PARTYDB_PERSON_H

#include "Birthdate.h"
#include "Name.h"
#include "OrderStrategy.h"

template <int S>
class Person
{
private:
	Birthdate birthday;
	Name name;

	inline Person parsePersonIn(const string& line);
	inline Birthdate parseBirthdate(const string& raw_birthday);
	inline int lastIndexIn(const string& str, const char& character);
	
public:
	// Default constructor should not be directly used other than as a type-specifier
	inline Person();
	inline Person(const string& new_name, const Birthdate& new_birthday);
	inline Person(const string& raw_data_entry);

	inline Birthdate getBirthday() const;
	inline Name getName() const;

	inline bool operator== (const Person& right) const;
	inline bool operator>  (const Person& right) const;
};

#ifndef PARTYDB_PERSON_CPP
#include "Person.cpp"
#endif

#endif