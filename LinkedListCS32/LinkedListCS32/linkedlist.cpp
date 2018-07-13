#include "linkedlist.h"





LinkedList::LinkedList(const LinkedList & rhs)
{
	LinkedList copy;
	ItemType val;
	int increment=0;
	for (int i = rhs.size(); i >0; i--) {
		rhs.get(i, val);
		copy.insertToFront(val);
		increment++;
	}
	copy.swap(*this);

}

LinkedList::~LinkedList()
{
	while ( this->head != nullptr) {
		Node* copy = this->head->next;
		delete this->head;
		this->head = copy;
	}
}

const LinkedList & LinkedList::operator=(const LinkedList & rhs)
{
	LinkedList copy;
	ItemType val;
	int increment = 0;
	for (int i = rhs.size(); i >0; i--) {
		rhs.get(i, val);
		copy.insertToFront(val);
		increment++;
	}
	copy.swap(*this);
	return *this;
}

void LinkedList::insertToFront(const ItemType & val)
{
	if (this->head == nullptr) {
		Node* newhead = new Node;
		newhead->value = val;
		newhead->next = this->head;
		this->head = newhead;
		this->head->next = nullptr;
		l_size++;
	}

	else {
		Node* newhead = new Node;
		newhead->value = val;
		newhead->next = this->head;
		this->head = newhead;


		l_size++;
	}

	//// Creating a copy of the old head
	//Node copy = *this->head;

	////Creating a new head with the proper values
	//Node* newhead = new Node;
	//newhead->value = val;
	//*newhead->next = copy;

	////Setting the head equal to the New head
	//this->head = newhead;

	

}

void LinkedList::printList() const
{
	ItemType s = "";
	for (int i = 0; i <= this->size()-1; i++) {
		this->get(i, s);
		cout << s << " ";
	}
	cout << "\n";
}

bool LinkedList::get(int i, ItemType & item) const
{
	Node* traverse = this->head;
	/*cout << traverse->value << "\n";
	item = traverse->value;
	cout << item << "\n";*/
	i++;
	for (int j = 1; j <= i; j++) {
		
		if (j == i) {
			item = traverse->value;
			//cout << "TEST " << item << "\n";
			return true;
		}
		traverse = traverse->next;

}
	return false;

}

void LinkedList::reverseList()
{
	LinkedList reverseclone;
	Node *temp=this->head;
	int originalsize = this->size();
	while (temp != nullptr) {
		reverseclone.insertToFront(temp->value);
		/*cout << "TEST " << temp->value << "\n";*/
		temp = temp->next;
	}
	reverseclone.printList();

	this->swap(reverseclone);
	


	

}

void LinkedList::printReverse() const
{
	
	ItemType s="";
	for (int i = this->size()-1; i >= 0; i--) {
		this->get(i, s);
		cout << s << " ";
	}
	cout << "\n";
}

void LinkedList::append(const LinkedList & other)
{
	Node* traverse = this->head;
	// Traversing to the end of this
	while (traverse->next != nullptr) {
		traverse = traverse->next;
	}

	// Appending from the head of other
	Node* traverseother = other.head;
	while (traverseother != nullptr) {
		Node *append = new Node;
		append->value = traverseother->value;
		traverse->next = append;
		traverse = traverse->next;
		traverseother = traverseother->next;
	}
	traverse->next = nullptr;
	this->l_size = this->l_size+other.size();


}

void LinkedList::swap(LinkedList & other)
{
	Node  *temp;
	size_t tempsize;

	//Swaps the head pointers
	temp = this->head;
	this->head = other.head;
	other.head = temp;

	//Swaps the sizes
	tempsize = this->size();
	this->l_size = other.l_size;
	other.l_size = tempsize;


}

int LinkedList::size() const
{
	return int(l_size);
}
