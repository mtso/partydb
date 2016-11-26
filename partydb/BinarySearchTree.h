// BST.h
// Lab 4: partydb
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

template <typename Data>
class BinarySearchTree
{
private:

public:

	bool isEmpty() const;

	int getHeight() const;

	int getNodeCount() const;

	Data getRootData() const;

	void setRootData(const Data& new_data);

	void insert(const Data& new_data);

	void remove(const Data& target);

	void clear();

	bool contains(const Data& target);

	Data getData(const Data& target);

};