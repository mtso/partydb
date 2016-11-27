
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