#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char* argv[]) {

	/* Testing Part A - Inserting to head and tail, and getSize() */
	LinkedList<char> charList;
	cout << "The size of the linked list is " << charList.getSize() << endl;

	/* Insert "EC330!" alternating head and tail */
	charList.InsertToTail('3');
	cout << "Inserted '3' to tail. The size of the linked list is " << charList.getSize() << endl;

	charList.InsertToHead('3');
	cout << "Inserted '3' to head. The size of the linked list is " << charList.getSize() << endl;

	charList.InsertToTail('0');
	cout << "Inserted '0' to tail. The size of the linked list is " << charList.getSize() << endl;

	charList.InsertToHead('C');
	cout << "Inserted 'C' to head. The size of the linked list is " << charList.getSize() << endl;

	charList.InsertToHead('E');
	cout << "Inserted 'E' to head. The size of the linked list is " << charList.getSize() << endl;

	cout << "Content of linked list: ";
	charList.print();

	charList.InsertToTail('!');
	cout << "Inserted '!' to tail. The size of the linked list is " << charList.getSize() << endl;

	cout << "Content of linked list: ";
	charList.print();

	return 0;
}