// Main.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#include <iostream>
#include <fstream>
using namespace std;

#include "BinarySearchTree.h"
#include "Person.h"

// Prints people tree to cout
void printPeople(Person& person);

// outputs tree to postorder file
void outputPostorder(Person& person);

// outputs tree to breadthfirst file
void outputBreadthFirst(Person& person);

// parses a string for name and birthday
// returns a Person object
Person parsePersonIn(const string& line);

// parses a raw birthday string
// returns a Birthdate object
Birthdate parseBirthdate(const string& raw_birthday);

// returns the index of a target character in the string
int lastSpaceIndex(const string& str, const char& character);

// !!DANGER!!
// global ofstreams that should only be 
// used in the output functions
ofstream output_postorder;
ofstream output_breadthfirst;

// Generates random date values
int genMonth() {
	return rand() % 12 + 1;
}
int genDay(int month) {
	int max_days;
	switch (month) {
	case 2:
		max_days = 29; break;
	case 4: case 6: case 9: case 11:
		max_days = 30; break;
	default:
		max_days = 31; break;
	}
	return rand() % max_days + 1;
}
int genYear() {
	return rand() % 105 + 1900;
}

#include "ADT\Queue.h";
// Entry point for executable
int main()
{
	/*Queue<string> nameQ;
	ifstream names;
	names.open("..\\NAMES.DIC");
	string name;
	while (getline(names, name)) {
		nameQ.enqueue(name);
	}
	names.close();

	ofstream gen;

	int month;
	int day;
	gen.open("..\\generated.txt");
	while (!nameQ.isEmpty()) {
		month = genMonth();
		day = genDay(month);

		gen << nameQ.dequeue() << " ";
		if (month < 10) { gen << "0"; }
		gen << month << "-";
		if (day < 10) { gen << "0"; }
		gen << day << "-"
			<< genYear() << endl;
	}
	gen.close();*/

	cout << "Party DB" << endl;

	BinarySearchTree<Person> people;

	// Read in the values from the input data file
	// Place them in the people tree
	cout << "Reading input.txt file... " << endl;
	ifstream data;
	data.open("..\\input.txt");
	string line;
	while (getline(data, line)) {
		Person person = parsePersonIn(line);
		people.insert(person);
		cout << "\r                                \r";
		cout << person.getName();
	}
	data.close();
	cout << "\r                                \r";
	cout << "Success." << endl;

	cout << "Outputting postorder to 'output_postorder.txt'" << endl;
	// Traverse the tree and output to postorder file
	output_postorder.open("..\\output_postorder.txt");
	people.traversePostorder(outputPostorder);
	output_postorder.close();

	cout << "Outputting breadth-first to 'output_breadthfirst.txt'" << endl;
	// Traverse the tree and output to breadth-first file
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
	int space_index = lastSpaceIndex(line, ' ');
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

int lastSpaceIndex(const string& str, const char& character)
{
	int index = -1;
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] == character) {
			index = i;
		}
	}
	return index;
}