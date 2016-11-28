// BirthdayManager.h
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#include "BirthdayManager.h"

// Static members need to be instantiated at startup.
BinarySearchTree<Person<BY_NAME>> BirthdayManager::tree_by_name;
BinarySearchTree<Person<BY_BIRTHDAY>> BirthdayManager::tree_by_bday;
ofstream BirthdayManager::stream_postorder;
ofstream BirthdayManager::stream_breadthfirst;

void addToNameSortedTree(Person<BY_BIRTHDAY>& person_bday) {
	string name = person_bday.getName().getValue();
	Birthdate birthday = person_bday.getBirthday();
	BirthdayManager::getNameTree().insert(Person<BY_NAME>(name, birthday));
}

BinarySearchTree<Person<BY_NAME>>& BirthdayManager::getNameTree()
{
	return tree_by_name;
}

BinarySearchTree<Person<BY_BIRTHDAY>>& BirthdayManager::getBdayTree()
{
	return tree_by_bday;
}

ofstream& BirthdayManager::getPostorderStream()
{
	return stream_postorder;
}

ofstream& BirthdayManager::getBreadthFirstStream()
{
	return stream_breadthfirst;
}

void BirthdayManager::importDataFrom(const string& filepath, ostream& to_output)
{
	ifstream input_file;
	string line;

	input_file.open(filepath);

	// Read input data line-by-line
	Person<BY_BIRTHDAY> person;
	while (getline(input_file, line)) {
		person = Person<BY_BIRTHDAY>(line);
		if (person.getName().getValue().length() < 1) { continue; }

		tree_by_bday.insert(person);
	}
	input_file.close();

	// Since our BST is not self-balancing,
	// and we have over 20000+ data entries,
	// and the entries are ordered alphabetically by name...
	// We can't just insert the person object that is created
	// by each getline() above.
	// 
	// So,
	// the tree sorted by name needs to be populated 
	// with data from the tree sorted by birthday
	// using in-order traversal, which scrambles the name order;
	// otherwise, it will take a long time....
	tree_by_bday.traverseInorder(addToNameSortedTree);

	to_output << "Successfully read " << tree_by_name.getNodeCount() << " entries." << endl;
}
void BirthdayManager::outputPostorderTo(const string& filepath)
{
	stream_postorder.open(filepath);
	tree_by_bday.traversePostorder(outputPostorder<BY_BIRTHDAY>);
	stream_postorder.close();
}
void BirthdayManager::outputBreadthFirstTo(const string& filepath)
{
	stream_breadthfirst.open(filepath);
	tree_by_name.traverseBreadth(outputBreadthFirst<BY_NAME>);
	stream_breadthfirst.close();
}

bool BirthdayManager::search(const string& name, Person<BY_NAME>& result)
{
	Person<BY_NAME> target(name, Birthdate()) ;
	try {
		result = tree_by_name.getData(target);
		return true;
	}
	catch (BinarySearchTree<Person<BY_NAME>>::NotFoundException error) {
		return false;
	}
}
bool BirthdayManager::update(const string& name, const Birthdate& birthday)
{
	Person<BY_NAME> found_person_by_name;
	Person<BY_BIRTHDAY> found_person_by_birthday;

	try {
		// First search name tree for name
		found_person_by_name = tree_by_name.getData(Person<BY_NAME>(name, Birthdate()));
		// Then search birthday tree using the same name
		// and the birthday value returned from the name tree search
		found_person_by_birthday = tree_by_bday.getData(Person<BY_BIRTHDAY>(name, found_person_by_name.getBirthday()));
	}
	catch (BinarySearchTree<Person<BY_BIRTHDAY>>::NotFoundException) {
		return false;
	}
	catch (BinarySearchTree<Person<BY_NAME>>::NotFoundException) {
		return false;
	}

	bool name_tree_removal_success = false;
	bool bday_tree_removal_success = false;

	name_tree_removal_success = tree_by_name.remove(found_person_by_name);
	if (!name_tree_removal_success) { return false; }

	bday_tree_removal_success = tree_by_bday.remove(found_person_by_birthday);
	if (!bday_tree_removal_success) {
		// If the bday-tree removal wasn't successful,
		// Re-insert the removed entry into the name tree
		tree_by_name.insert(found_person_by_name);
		return false;
	}

	Person<BY_NAME> updated_name_person(name, birthday);
	Person<BY_BIRTHDAY> updated_bday_person(name, birthday);
	tree_by_name.insert(updated_name_person);
	tree_by_bday.insert(updated_bday_person);

	return true;
}
bool BirthdayManager::remove(const string& name)
{
	Person<BY_NAME> found_person_by_name = tree_by_name.getData(Person<BY_NAME>(name, Birthdate()));
	bool name_tree_removal_success = false;
	bool bday_tree_removal_success = false;

	name_tree_removal_success = tree_by_name.remove(found_person_by_name);
	if (!name_tree_removal_success) { return false; }

	bday_tree_removal_success = tree_by_bday.remove(Person<BY_BIRTHDAY>(name, found_person_by_name.getBirthday()));
	if (!bday_tree_removal_success) {
		// If the bday-tree removal wasn't successful,
		// Re-insert the removed entry into the name tree
		tree_by_name.insert(found_person_by_name);
		return false;
	}
	else {
		return true;
	}
}
bool BirthdayManager::insert(const string& raw_input)
{
	try {
		Person<BY_BIRTHDAY> person_by_birthday(raw_input);
		Person<BY_NAME> person_by_name(raw_input);

		tree_by_bday.insert(person_by_birthday);
		tree_by_name.insert(person_by_name);
		return true;
	}
	catch (...) {
		return false;
	}

}