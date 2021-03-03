#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char* argv[]) {

	/* Testing Part A: Deleting node */
	LinkedList<double> doubleList;

	doubleList.InsertToHead(5467.8);
	doubleList.InsertToHead(1000);
	doubleList.InsertToHead(999999);
	doubleList.InsertToHead(36);
	doubleList.InsertToHead(0.067);
	cout << "Inserted 0.067, 36, 999999, 1000, 5467.8 to list" << endl;

	/* Delete nodes */
	doubleList.deleteNode(1000);
	cout << "Deleted 1000 from list." << endl;
	cout << "Content of linked list: ";
	doubleList.print();

	doubleList.deleteNode(36);
	cout << "Deleted 36 from list." << endl;
	cout << "Content of linked list: ";
	doubleList.print();

	doubleList.deleteNode(5467.8);
	cout << "Deleted 5467.8 from list." << endl;
	cout << "Content of linked list: ";
	doubleList.print();

	 doubleList.deleteNode(999999);
	cout << "Deleted 999999  from list." << endl;
	cout << "Content of linked list: ";
	doubleList.print();;

	doubleList.deleteNode(0.067);
	cout << "Deleted 0.067 from list." << endl;
	cout << "Content of linked list: ";
	doubleList.print();

	return 0;
}