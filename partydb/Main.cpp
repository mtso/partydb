// Main.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#include <iostream>
#include <fstream>
using namespace std;

#include "BinarySearchTree.h"
#include "Person.h"

void printPeople(Person& person);

void outputPostorder(Person& person);
void outputBreadthFirst(Person& person);

bool parse(const string& line);
Person parsePersonIn(const string& line);
Birthdate parseBirthdate(const string& raw_birthday);
int charIndexIn(const string& str, const char& character);

ofstream output_postorder;
ofstream output_breadthfirst;

int main()
{
	BinarySearchTree<Person> people;

	ifstream data;
	data.open("..\\input.txt");
	string line;
	while (getline(data, line)) {
		Person person = parsePersonIn(line);
		people.insert(person);
	}
	data.close();

	output_postorder.open("..\\output_postorder.txt");
	people.traversePostorder(outputPostorder);
	output_postorder.close();

	output_breadthfirst.open("..\\output_breadthfirst.txt");
	people.traverseBreadth(outputBreadthFirst);
	output_breadthfirst.close();

	system("pause");
	return 0;
}

void printPeople(Person& person)
{
	cout << person.getBirthday().getMonth() << "-"
		<< person.getBirthday().getDay() << "-"
		<< person.getBirthday().getYear() << endl;
}

void outputPostorder(Person& person)
{
	Birthdate bday = person.getBirthday();
	output_postorder << person.getName() << " ";

	if (bday.getMonth() < 10) { output_postorder << "0"; }
	output_postorder << bday.getMonth() << "-";
	if (bday.getDay() < 10) { output_postorder << "0"; }
	output_postorder << bday.getDay() << "-";
	output_postorder << bday.getYear() << endl;
}

void outputBreadthFirst(Person& person)
{
	Birthdate bday = person.getBirthday();
	output_breadthfirst << person.getName() << " ";

	if (bday.getMonth() < 10) { output_breadthfirst << "0"; }
	output_breadthfirst << bday.getMonth() << "-";
	if (bday.getDay() < 10) { output_breadthfirst << "0"; }
	output_breadthfirst << bday.getDay() << "-";
	output_breadthfirst << bday.getYear() << endl;
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