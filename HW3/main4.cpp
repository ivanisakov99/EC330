#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char* argv[]) {


	/* Testing Part A: Deleting from empty lits & deleting nodes that don't exist */
	LinkedList<double> doubleList;

	/* Attempt to delete from head and tail of empty list */
	doubleList.deleteFromHead();
	cout << "Attempted to delete from head" << endl;
	doubleList.deleteFromTail();
	cout << "Attempted to delete from tail" << endl;

	/* Attempt to delete from empty list */
	doubleList.deleteNode(0);
	cout << "Attempted to delete value 0 from empty list " << endl;

	/* Attempt to delete something not in the list */
	cout << "Inserted 3 to head" << endl;
	doubleList.InsertToHead(3);
	doubleList.deleteNode(1);
	cout << "Attempted to delete 1 from list" << endl;
	cout << "Content of linked list: ";
	doubleList.print();

	return 0;
}