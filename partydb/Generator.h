// Generator.h
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

// This contains ad-hoc code that generates
// a giant text file containing name/birthday entries.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ADT\Queue.h"

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

void generateInputFile()
{
	Queue<string> nameQ;
	ifstream names;
	names.open("..\\NAMES.DIC"); // original data file of names
	string name;
	while (getline(names, name)) {
		nameQ.enqueue(name);
	}
	names.close();

	ofstream gen;
	int month;
	int day;
	gen.open("..\\generator.txt");
	gen << nameQ.getLength() << " names and corresponding birthdays." << endl;
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
	gen.close();
}