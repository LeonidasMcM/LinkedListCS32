#include"linkedlist.h"
#include<cassert>

int main() {

	LinkedList e1;
	e1.insertToFront("bell");
	e1.insertToFront("biv");
	e1.insertToFront("devoe");

	e1.printList();

	LinkedList e2;
	e2.insertToFront("Andre");
	e2.insertToFront("Big Boi");
	e1.append(e2); // adds contents of e2 to the end of e1
	
	/*cout << "post append size: " << e1.size() << "\n";
	cout << "initial size 2nd: " << e2.size() << "\n";
*/

	string s;
	/*e1.get(4, s);
	cout << "TEST: "<<s <<"\n";*/
	assert(e1.size() == 5);
	assert(e1.get(3, s));
	assert(s == "Big Boi");

	assert(e2.size() == 2 && e2.get(1, s) && s == "Andre");

	return 0;
}