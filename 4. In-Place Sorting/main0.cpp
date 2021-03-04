//
//  main.cpp
//
//  Copyright © Tali Moreshet. All rights reserved.
//

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char* argv[]) {

    /*** For part (a): Testing of linked list: ***/
    cout << "*** Int linked list: ***" << endl;
    LinkedList<int> intList;
    int intElement;
    
    cout << "Inserting to linked list: 1 2 3 4 5" << endl;
    intList.InsertToTail(1);
    intList.InsertToTail(2);
    intList.InsertToTail(3);
    intList.InsertToTail(4);
    intList.InsertToTail(5);
    
    cout << "The size of the linked list is " << intList.getSize() << endl;
    cout << "Content of linked list: ";
    intList.print();
    
    intElement = intList.deleteFromHead();
    
    cout << "Deleted " << intElement << " from head. The size of the linked list is " << intList.getSize() << endl;
    cout << "Content of linked list: ";
    intList.print();
    
    intElement = intList.deleteFromTail();
    cout << "Deleted " << intElement << " from tail. The size of the linked list is " << intList.getSize() << endl;
    cout << "Content of linked list: ";
    intList.print();

    intList.deleteNode(3);
    cout << "Deleted node containing 3. The size of the linked list is " << intList.getSize() << endl;
    cout << "Content of linked list: ";
    intList.print();
    
    intList.InsertToHead(0);
    cout << "Inserted 0 to head. The size of the linked list is " << intList.getSize() << endl;
    cout << "Content of linked list: ";
    intList.print();
    
    intList.deleteNode(4);
    cout << "Deleted node containing 4. The size of the linked list is " << intList.getSize() << endl;
    cout << "Content of linked list: ";
    intList.print();

    intList.deleteNode(0);
    cout << "Deleted node containing 0. The size of the linked list is " << intList.getSize() << endl;
    cout << "Content of linked list: ";
    intList.print();
    
    intElement = intList.deleteFromTail();
    cout << "Deleted " << intElement << " from tail. The size of the linked list is " << intList.getSize() << endl;
    cout << "Content of linked list: ";
    intList.print();
    
    
    /*** For part (a): Testing of linked list - part 2: ***/
    cout << endl << endl << "*** String linked list: ***" << endl;
    LinkedList<string> stringList;
    string strElement;
    
    cout << "Inserting to linked list: one two three four" << endl;
    stringList.InsertToTail("one");
    stringList.InsertToTail("two");
    stringList.InsertToTail("three");
    stringList.InsertToTail("four");
    
    cout << "The size of the linked list is " << stringList.getSize() << endl;
    cout << "Content of linked list: ";
    stringList.print();
    
    strElement = stringList.deleteFromHead();
    cout << "Deleted " << strElement << " from head. The size of the linked list is " << stringList.getSize() << endl;
    cout << "Content of linked list: ";
    stringList.print();
    
    strElement = stringList.deleteFromTail();
    cout << "Deleted " << strElement << " from tail. The size of the linked list is " << stringList.getSize() << endl;
    cout << "Content of linked list: ";
    stringList.print();
    
    stringList.deleteNode("three");
    cout << "Deleted node containing three. The size of the linked list is " << stringList.getSize() << endl;
    cout << "Content of linked list: ";
    stringList.print();
    
    stringList.InsertToHead("zero");
    cout << "Inserted to node zero to head. The size of the linked list is " << stringList.getSize() << endl;
    cout << "Content of linked list: ";
    stringList.print();
    
    stringList.deleteNode("two");
    cout << "Deleted node containing two. The size of the linked list is " << stringList.getSize() << endl;
    cout << "Content of linked list: ";
    stringList.print();
    
    strElement = stringList.deleteFromHead();
    cout << "Deleted " << strElement << " from head. The size of the linked list is " << stringList.getSize() << endl;
    cout << "Content of linked list: ";
    stringList.print();
    
    
    /*** For part (b): Testing of stack: ***/
    cout << endl << endl << "*** Int stack: ***" << endl;
    StackFromList<int> intStack;
    
    cout << "Pushing to the stack: 1 2 3 4" << endl;
    
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.push(4);
    
    cout << "The top of the stack was " << intStack.pop() << endl;
    cout << "The top of the stack was " << intStack.pop() << endl;
    
    cout << "Pushing to the stack: 5 6" << endl;

    intStack.push(5);
    intStack.push(6);
    
    cout << "The stack is ";
    if (!intStack.isEmpty())
        cout << "not ";
    cout << "empty" << endl;
    
    cout << "The top of the stack was " << intStack.pop() << endl;
    cout << "The top of the stack was " << intStack.pop() << endl;
    cout << "The top of the stack was " << intStack.pop() << endl;
    cout << "The top of the stack was " << intStack.pop() << endl;
    
    cout << "The stack is ";
    if (!intStack.isEmpty())
        cout << "not ";
    cout << "empty" << endl;
    
    
    /*** For part (c): Testing of queue: ***/
    cout << endl << endl << "*** Char queue: ***" << endl;
    QueueFromList<char> charQueue;
    
    cout << "Enqueueing to the queue: a b c d" << endl;
    
    charQueue.enqueue('a');
    charQueue.enqueue('b');
    charQueue.enqueue('c');
    charQueue.enqueue('d');
    
    cout << "The head of the queue was " << charQueue.dequeue() << endl;
    cout << "The head of the queue was " << charQueue.dequeue() << endl;
    
    cout << "Enqueueing to the queue: e" << endl;
    
    charQueue.enqueue('e');
    
    cout << "The queue is ";
    if (!charQueue.isEmpty())
        cout << "not ";
    cout << "empty" << endl;
    
    cout << "The head of the queue was " << charQueue.dequeue() << endl;
    cout << "The head of the queue was " << charQueue.dequeue() << endl;
    cout << "The head of the queue was " << charQueue.dequeue() << endl;
    
    cout << "The queue is ";
    if (!charQueue.isEmpty())
        cout << "not ";
    cout << "empty" << endl;

    return 0;
}