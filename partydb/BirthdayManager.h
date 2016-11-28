// BirthdayManager.h
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_BIRTHDAYMANAGER_H
#define PARTYDB_BIRTHDAYMANAGER_H

#include <fstream>
using namespace std;

#include "BinarySearchTree.h"
#include "Person.h"

template <int S>
void outputPostorder(Person<S>& person)
{
	BirthdayManager::getPostorderStream() << person.getName().getValue() << " ";

	Birthdate bday = person.getBirthday();	
	if (bday.getMonth() < 10) { BirthdayManager::getPostorderStream() << "0"; }
	BirthdayManager::getPostorderStream() << bday.getMonth() << "-";
	if (bday.getDay() < 10) { BirthdayManager::getPostorderStream() << "0"; }
	BirthdayManager::getPostorderStream() << bday.getDay() << "-";
	BirthdayManager::getPostorderStream() << bday.getYear() << endl;
}

template <int S>
void outputBreadthFirst(Person<S>& person)
{
	BirthdayManager::getBreadthFirstStream() << person.getName().getValue() << " ";

	Birthdate bday = person.getBirthday();
	if (bday.getMonth() < 10) { BirthdayManager::getBreadthFirstStream() << "0"; }
	BirthdayManager::getBreadthFirstStream() << bday.getMonth() << "-";
	if (bday.getDay() < 10) { BirthdayManager::getBreadthFirstStream() << "0"; }
	BirthdayManager::getBreadthFirstStream() << bday.getDay() << "-";
	BirthdayManager::getBreadthFirstStream() << bday.getYear() << endl;
}

class BirthdayManager
{
private:
	// managed trees and output streams are static in order to be placed in traversal functions
	static BinarySearchTree<Person<BY_BIRTHDAY>> tree_by_bday;
	static BinarySearchTree<Person<BY_NAME>> tree_by_name;
	static ofstream stream_postorder;
	static ofstream stream_breadthfirst;

public:
	void importDataFrom(const string& filepath, ostream& to_output);
	void outputPostorderTo(const string& filepath);
	void outputBreadthFirstTo(const string& filepath);

	bool search(const string& name, Person<BY_NAME>& result);
	bool update(const string& name, const Birthdate& birthday);
	bool remove(const string& name);
	bool insert(const string& raw_input);

	static BinarySearchTree<Person<BY_NAME>>& getNameTree();
	static BinarySearchTree<Person<BY_BIRTHDAY>>& getBdayTree();
	static ofstream& getPostorderStream();
	static ofstream& getBreadthFirstStream();
};

#endif