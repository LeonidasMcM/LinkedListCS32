//Here is a C++ class definition for an abstract data type LinkedList of string
//objects.Implement each member function in the class below.Some of the functions we
//may have already done in lecture, that's fine, try to do those first without looking at your
//notes.You may add whatever private data members or private member functions you
//want to this class.




#include <iostream>
#include <string>
using namespace std;

// Convoluted string redefinition
typedef string ItemType;

struct Node {
	ItemType value;
	Node *next;
};
class LinkedList {
private:
	Node * head;
	size_t l_size;
	
public:
	// default constructor
	LinkedList() : head(nullptr), l_size(0) {};

	// copy constructor
	LinkedList(const LinkedList& rhs);

	// Destroys all the dynamically allocated memory
	// in the list.
	~LinkedList();

	// assignment operator
	const LinkedList& operator=(const LinkedList& rhs);

	// Inserts val at the front of the list
	void insertToFront(const ItemType &val);

	// Prints the LinkedList
	void printList() const;

	// Sets item to the value at position i in this
	// LinkedList and return true, returns false if 
	// there is no element i
	bool get(int i, ItemType& item) const;

	// Reverses the LinkedList
	void reverseList();

	// Prints the LinkedList in reverse order
	void printReverse() const;

	// Appends the values of other onto the end of this
	// LinkedList.
	void append(const LinkedList &other);

	// Exchange the contents of this LinkedList with the other
	// one.
	void swap(LinkedList &other);

	// Returns the number of items in the Linked List.
	int size() const;
};