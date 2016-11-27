
#include <iostream>
#include <fstream>
using namespace std;

#include "BinarySearchTree.h"
#include "Person.h"

void print(int& node)
{
	cout << node + node << endl;
}

void printPeople(Person& person)
{
	cout << person.getName() << endl;
}

bool parse(const string& line);
Person parsePersonIn(const string& line);
Birthdate parseBirthdate(const string& raw_birthday);
int charIndexIn(const string& str, const char& character);

int main()
{
	ifstream data;
	data.open("..\\input.txt");
	string line;

	while (getline(data, line)) {
		//cout << line << endl;
		Person person = parsePersonIn(line);
		cout << person.getName();
		cout << " " << person.getBirthday().getYear() << endl;
	}

	data.close();

	system("pause");
	return 0;
}

Person parsePersonIn(const string& line)
{
	int space_index = charIndexIn(line, ' ');
	string name = line.substr(0, space_index);
	string raw_birthday = line.substr(space_index + 1, line.length() - space_index - 1);

	Birthdate birthday = parseBirthdate(raw_birthday);
	return Person(name, birthday);
}

Birthdate parseBirthdate(const string& raw_birthday)
{
	//int dash_index = charIndexIn(raw_birthday, '-');
	//string month = raw_birthday.substr(0, dash_index);
	//string leftover = raw_birthday.substr(dash_index + 1, 7); // raw_birthday.length() - dash_index - 1);
	//dash_index = charIndexIn(leftover, '-');
	//string day = leftover.substr(0, dash_index);
	//string year = leftover.substr(dash_index + 1, 4);
	string month = raw_birthday.substr(0, 2);
	string day   = raw_birthday.substr(3, 2);
	string year  = raw_birthday.substr(6, 4);
	
	return Birthdate( stoi(month), stoi(day), stoi(year) );
}

int charIndexIn(const string& str, const char& character)
{
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] == character) {
			return i;
		}
	}
	return -1;
}