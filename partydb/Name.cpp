
#include "Name.h"

Name::Name()
: value("")
{
}

Name::Name(const string& new_value)
: value(new_value)
{
}

string Name::getValue() const
{
	return value;
}

bool Name::operator== (const Name& right) const
{
	return value == right.value;
}
bool Name::operator> (const Name& right) const
{
	return (strcmp(value.c_str(), right.value.c_str()) < 0);
}

ostream& operator<< (ostream& output, const Name& name)
{
	string capitalized;
	capitalized += toupper(name.value[0]);
	capitalized += name.value.substr(1, name.value.length() - 1);
	return output << capitalized;
}