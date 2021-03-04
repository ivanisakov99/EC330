#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char* argv[]) {

	/* Testing Part A: Deleting from head and tail */
	LinkedList<float> floatList;
	float data;

	floatList.InsertToHead(1.01);
	floatList.InsertToHead(2.02);
	floatList.InsertToHead(3.03);
	floatList.InsertToHead(4.04);
	floatList.InsertToHead(5.05);
	cout << "Inserted 5.05, 4.04, 3.03, 2.02, 1.01 to list " << endl;

	data = floatList.deleteFromHead();
	cout << "Deleted " << data << " from head." << endl;
	cout << "Content of linked list: ";
	floatList.print();

	data = floatList.deleteFromTail();
	cout << "Deleted " << data << " from tail." << endl;
	cout << "Content of linked list: ";
	floatList.print();

	data = floatList.deleteFromTail();
	cout << "Deleted " << data << " from tail." << endl;
	cout << "Content of linked list: ";
	floatList.print();

	data = floatList.deleteFromHead();
	cout << "Deleted " << data << " from head." << endl;
	cout << "Content of linked list: ";
	floatList.print();

	floatList.InsertToHead(6.06);
	cout << "Inserted 6.06 to head." << endl;
	cout << "Content of linked list: ";
	floatList.print();

	data = floatList.deleteFromHead();
	cout << "Deleted " << data << " from head." << endl;
	cout << "Content of linked list: ";
	floatList.print();

	data = floatList.deleteFromTail();
	cout << "Deleted " << data << " from tail." << endl;
	cout << "Content of linked list: ";
	floatList.print();

	return 0;
}