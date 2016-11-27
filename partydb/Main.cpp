// Main.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#include <iostream>
#include <fstream>
using namespace std;

#include "BinarySearchTree.h"
#include "Person.h"
#include "ADT\Queue.h"

// Prints people tree to cout
void printPeople(Person& person);

// outputs tree to postorder file
void outputPostorder(Person& person);

// outputs tree to breadthfirst file
void outputBreadthFirst(Person& person);

// outputs names tree to postorder file
void outputName(string& name);

// outputs birthday tree to breadth-first file
void outputBirthday(Birthdate& bday);

// parses a string for name and birthday
// returns a Person object
Person parsePersonIn(const string& line);

// parses a raw birthday string
// returns a Birthdate object
Birthdate parseBirthdate(const string& raw_birthday);

// returns the index of a target character in the string
int lastIndexIn(const string& str, const char& character);

// !!DANGER!!
// global ofstreams that should only be 
// used in the output functions
ofstream output_postorder;
ofstream output_breadthfirst;

// Entry point for executable
int main()
{
	// Output PartyDB description
	cout << "<< PartyDB by Matthew Tso >>" << endl;
	cout << "Reads name and birthday data from 'input.txt' in\nthe format of `[name] [mm]-[dd]-[yyyy]` per line, \nthen outputs the collected data to two files: \none for post-order traversal and \nthe other for breadth-first traversal.";
	cout << endl << endl;

	BinarySearchTree<Person> people;

	//BinarySearchTree<string> names;
	//BinarySearchTree<Birthdate> birthdays;

	ifstream data;
	string line;

	// Read in the values from the input data file
	// Place them in the people tree
	cout << "Reading input.txt file containing " << endl;
	data.open("..\\input.txt");

	getline(data, line);
	cout << line << endl;

	int iter = 0;
	Person person;
	while (getline(data, line)) {
		person = parsePersonIn(line);
		if (person.getName().length() < 1) { continue; }

		people.insert(person);

		//names.insert(person.getName());
		//birthdays.insert(person.getBirthday());

		//iter++;
		//if (iter > 2000) { break; }
		//cout << "\r                                \r"; // This needs to be longer than the longest name
		//cout << person.getName();
	}
	data.close();
	cout << "\r                                \r";
	cout << "Success." << endl;

	// Print people
	cout << "Outputting postorder to 'output_postorder.txt'" << endl;
	output_postorder.open("..\\output_postorder.txt");
	people.traversePostorder(outputPostorder);
	output_postorder.close();

	// Traverse the tree and output to postorder file
	//cout << "Outputting postorder to 'output_postorder.txt'" << endl; 
	//output_postorder.open("..\\output_postorder.txt");
	//names.traversePostorder(outputName);
	//output_postorder.close();

	// Traverse the tree and output to breadth-first file
	//cout << "Outputting breadth-first to 'output_breadthfirst.txt'" << endl;
	//output_breadthfirst.open("..\\output_breadthfirst.txt");
	//birthdays.traverseBreadth(outputBirthday);
	//output_breadthfirst.close();

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

void outputName(string& name)
{
	output_postorder << name << endl;
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

void outputBirthday(Birthdate& bday)
{
	if (bday.getMonth() < 10) { output_breadthfirst << "0"; }
	output_breadthfirst << bday.getMonth() << "-";
	if (bday.getDay() < 10) { output_breadthfirst << "0"; }
	output_breadthfirst << bday.getDay() << "-";
	output_breadthfirst << bday.getYear() << endl;
}

Person parsePersonIn(const string& line)
{
	int space_index = lastIndexIn(line, ' ');
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

int lastIndexIn(const string& str, const char& character)
{
	int index = -1;
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] == character) {
			index = i;
		}
	}
	return index;
}