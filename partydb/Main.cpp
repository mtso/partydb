// Main.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#include <iostream>
#include <fstream>
using namespace std;

#include "BirthdayManager.h"

int firstOccurrenceOf(const char& character, const string& in_string)
{
	for (int i = 0; i < (int)in_string.length(); i++) {
		if (in_string[i] == character) {
			return i;
		}
	}
	return -1;
}

Birthdate parseBirthdate(const string& raw_birthday)
{
	string month_str = raw_birthday.substr(0, 2);
	string day_str = raw_birthday.substr(3, 2);
	string year_str = raw_birthday.substr(6, 4);

	int month, day, year;
	try {
		month = stoi(month_str);
		day = stoi(day_str);
		year = stoi(year_str);
	}
	catch (std::invalid_argument error) {
		return Birthdate();
	}
	return Birthdate(month, day, year);
}


// Entry point for executable
int main()
{
	// Output PartyDB description
	cout << "<< PartyDB by Matthew Tso >>" << endl;
	//cout << "Reads name and birthday data from 'input.txt' in\nthe format of `[name] [mm]-[dd]-[yyyy]` per line, \nthen outputs the collected data to two files: \none for post-order traversal and \nthe other for breadth-first traversal.";
	//cout << endl << endl;

	BirthdayManager manager;
	manager.importDataFrom("..\\input.txt", cout);

	string input;
	string command;
	string argument;
	int argument_length;
	int space_index;
	bool should_continue = true;
	bool should_output = false;

	Person<BY_NAME> result_by_name;
	Person<BY_BIRTHDAY> result_by_birthday;
	do {
		cout << "> ";
		getline(cin, input);

		space_index = firstOccurrenceOf(' ', input);
		argument_length = input.length() - space_index - 1;

		command = input.substr(0, space_index);
		argument = input.substr(space_index + 1, argument_length);

		if (command == "search" || command == "find") {

			if (manager.search(argument, result_by_name)) {
				cout << result_by_name.getName() << "'s birthday is: " << result_by_name.getBirthday() << endl;
			}
			else {
				cout << "Could not find an entry that matches the name: " << argument << endl;
			}
		}
		else if (command == "update") {
			Person<BY_NAME> new_person;
			try {
				new_person = Person<BY_NAME>(argument);\

				if (manager.update(new_person.getName().getValue(), new_person.getBirthday())) {
					cout << "Updated successfully" << endl;
				}
				else {
					cout << "Could not find an entry that matched: " << argument << endl;
				}
			}
			catch (...) {
				cout << "Data does not match the format `[name] [mm]-[dd]-[yyyy]`: " << argument << endl;
			}
			
			
		}
		else if (toupper(command[0]) == 'Q') {
			should_continue = false;

			cout << "Would you like to output the tree data? (Y/n)\n> ";
			getline(cin, input);
			if (toupper(input[0]) == 'Y') { should_output = true; }
		}

	} while (should_continue);

	if (should_output) {
		manager.outputPostorderTo("..\\output_postorder.txt");
		manager.outputBreadthFirstTo("..\\output_breadthfirst.txt");
	}

	system("pause");
	return 0;
}