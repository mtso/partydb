
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

int main()
{
	ifstream data;
	data.open("..\\input.txt");
	string line;

	while (getline(data, line)) {
		cout << line << endl;
	}

	data.close();
	


	system("pause");
	return 0;
}