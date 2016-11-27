// Main.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#include <iostream>
#include <fstream>
using namespace std;

#include "BinarySearchTree.h"
#include "Person.h"
#include "ADT\Queue.h"

// outputs tree to postorder file
template <int S>
void outputPostorder(Person<S>& person);

// outputs tree to breadthfirst file
template <int S>
void outputBreadthFirst(Person<S>& person);


// !!DANGER!!
// global ofstreams that should only be 
// used in the output functions
ofstream output_postorder;
ofstream output_breadthfirst;

// !!DANGER!!
// global variable name-sorted tree should only be used for traversal 
BinarySearchTree<Person<BY_NAME>> people_name;

void addToNameSortedTree(Person<BY_BIRTHDAY>& person_bday) {
	people_name.insert(Person<BY_NAME>(person_bday.getName().getValue(), person_bday.getBirthday()));
}

// Entry point for executable
int main()
{
	// Output PartyDB description
	cout << "<< PartyDB by Matthew Tso >>" << endl;
	cout << "Reads name and birthday data from 'input.txt' in\nthe format of `[name] [mm]-[dd]-[yyyy]` per line, \nthen outputs the collected data to two files: \none for post-order traversal and \nthe other for breadth-first traversal.";
	cout << endl << endl;

	BinarySearchTree<Person<BY_BIRTHDAY>> people_bday;

	ifstream data;
	string line;

	// Read in the values from the input data file
	// Place them in the people tree
	cout << "Reading input.txt file containing " << endl;
	data.open("..\\input.txt");

	getline(data, line);
	cout << line << endl;

	int iter = 0;
	Person<BY_BIRTHDAY> person;
	while (getline(data, line)) {
		person = Person<BY_BIRTHDAY>(line);
		if (person.getName().getValue().length() < 1) { continue; }

		people_bday.insert(person);

		//cout << "\r                                \r"; // This needs to be longer than the longest name
		//cout << person.getName().getValue();
	}
	data.close();
	cout << "\r                                \r";
	cout << "Success." << endl;

	// Since our BST is not self-balancing,
	// and we have over 20000+ data entries,
	// we need to populate the tree sorted by name
	// using data from the tree sorted by birthday;
	// otherwise, it will take a long time....
	people_bday.traverseInorder(addToNameSortedTree);

	// Traverse the bday tree and output to post-order file
	cout << "Outputting postorder to 'output_postorder.txt'" << endl;
	output_postorder.open("..\\output_postorder.txt");
	people_bday.traversePostorder(outputPostorder<BY_BIRTHDAY>);
	output_postorder.close();

	// Traverse the name tree and output to breadth-first file
	cout << "Outputting breadth-first to 'output_breadthfirst.txt'" << endl;
	output_breadthfirst.open("..\\output_breadthfirst.txt");
	people_name.traverseBreadth(outputBreadthFirst<BY_NAME>);
	output_breadthfirst.close();

	system("pause");
	return 0;
}

template <int S>
void outputPostorder(Person<S>& person)
{
	Birthdate bday = person.getBirthday();
	output_postorder << person.getName().getValue() << " ";

	if (bday.getMonth() < 10) { output_postorder << "0"; }
	output_postorder << bday.getMonth() << "-";
	if (bday.getDay() < 10) { output_postorder << "0"; }
	output_postorder << bday.getDay() << "-";
	output_postorder << bday.getYear() << endl;
}

template <int S>
void outputBreadthFirst(Person<S>& person)
{
	Birthdate bday = person.getBirthday();
	output_breadthfirst << person.getName().getValue() << " ";

	if (bday.getMonth() < 10) { output_breadthfirst << "0"; }
	output_breadthfirst << bday.getMonth() << "-";
	if (bday.getDay() < 10) { output_breadthfirst << "0"; }
	output_breadthfirst << bday.getDay() << "-";
	output_breadthfirst << bday.getYear() << endl;
}
