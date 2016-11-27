// Name.h
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_NAME_H
#define PARTYDB_NAME_H

#include <string>
using namespace std;

class Name
{
private:
	string value;

public:
	Name();
	Name(const string& new_name);

	string getValue() const;

	bool operator== (const Name& right) const;
	bool operator> (const Name& right) const;
};

#endif