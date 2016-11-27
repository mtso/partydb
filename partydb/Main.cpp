
#include <iostream>
#include <fstream>
using namespace std;

#include "BinarySearchTree.h"
#include "Person.h"

void printPeople(Person& person);

void outputPostorder(Person& person);
void outputBreathFirst(Person& person);

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
	people.traverseInorder(outputPostorder);
	output_postorder.close();

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
	output_postorder << person.getName() << " "
		<< bday.getMonth() << "-"
		<< bday.getDay() << "-"
		<< bday.getYear() << endl;
}
void outputBreathFirst(Person& person)
{

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