#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char* argv[]) {
    cout << "---------------TEST 0-------------" << endl;
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




    cout << "\n\n---------------TEST 1-------------" << endl;
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




    cout << "\n\n---------------TEST 2-------------" << endl;
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




    cout << "\n\n---------------TEST 3-------------" << endl;
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




    cout << "\n\n---------------TEST 4-------------" << endl;
    /* Testing Part A: Deleting from empty lits & deleting nodes that don't exist */
	LinkedList<double> doubleList2;

	/* Attempt to delete from head and tail of empty list */
	doubleList2.deleteFromHead();
	cout << "Attempted to delete from head" << endl;
	doubleList2.deleteFromTail();
	cout << "Attempted to delete from tail" << endl;

	/* Attempt to delete from empty list */
	doubleList2.deleteNode(0);
	cout << "Attempted to delete value 0 from empty list " << endl;

	/* Attempt to delete something not in the list */
	cout << "Inserted 3 to head" << endl;
	doubleList2.InsertToHead(3);
	doubleList2.deleteNode(1);
	cout << "Attempted to delete 1 from list" << endl;
	cout << "Content of linked list: ";
	doubleList2.print();




    cout << "\n\n---------------TEST 5-------------" << endl;
    /* Testing Part B - Stacks */
    cout << "Char Stack:" << endl;
    StackFromList<char> charStack;

    cout << "The stack is ";
    if (!charStack.isEmpty())
        cout << "not ";
    cout << "empty" << endl;

    cout << "Pushing to the stack: g n e u b" << endl;

    charStack.push('g');
    charStack.push('n');
    charStack.push('e');
    charStack.push('u');
    charStack.push('b');

    cout << "The top of the stack was " << charStack.pop() << endl;
    cout << "The top of the stack was " << charStack.pop() << endl;

    cout << "Pushing to the stack: ! " << endl;

    charStack.push('!');

    cout << "The stack is ";
    if (!charStack.isEmpty())
        cout << "not ";
    cout << "empty" << endl;

    cout << "The top of the stack was " << charStack.pop() << endl;
    cout << "The top of the stack was " << charStack.pop() << endl;
    cout << "The top of the stack was " << charStack.pop() << endl;
    cout << "The top of the stack was " << charStack.pop() << endl;

    cout << "The stack is ";
    if (!charStack.isEmpty())
        cout << "not ";
    cout << "empty" << endl << endl;

    cout << "String Stack: " << endl;
    StackFromList<string> stringStack;

    cout << "Pushing to the stack: \"oh\" \"what\" \"a\" \"beautiful\" \"morning\" " << endl;
    stringStack.push("oh");
    stringStack.push("what");
    stringStack.push("a");
    stringStack.push("beautiful");
    stringStack.push("morning");

    cout << "The top of the stack was " << stringStack.pop() << endl;
    cout << "The top of the stack was " << stringStack.pop() << endl;
    cout << "The top of the stack was " << stringStack.pop() << endl;
    cout << "The top of the stack was " << stringStack.pop() << endl;

    cout << "The stack is ";
    if (!stringStack.isEmpty())
        cout << "not ";
    cout << "empty" << endl;

    cout << "The top of the stack was " << stringStack.pop() << endl;

    cout << "The stack is ";
    if (!stringStack.isEmpty())
        cout << "not ";
    cout << "empty" << endl;




    cout << "\n\n---------------TEST 6-------------" << endl;
    /* Testing Part C - Queues */
    cout << "Int Queue:" << endl;
    QueueFromList<int> intQueue;

    cout << "The queue is ";
    if (!intQueue.isEmpty())
        cout << "not ";
    cout << "empty" << endl;

    cout << "Enqueueing to the queue: 5 4 3 2 1" << endl;

    intQueue.enqueue(5);
    intQueue.enqueue(4);
    intQueue.enqueue(3);
    intQueue.enqueue(2);
    intQueue.enqueue(1);

    cout << "The head of the queue was " << intQueue.dequeue() << endl;
    cout << "The head of the queue was " << intQueue.dequeue() << endl;

    cout << "Enqueueing to the queue: 0 -1 " << endl;

    intQueue.enqueue(0);
    intQueue.enqueue(-1);

    cout << "The queue is ";
    if (!intQueue.isEmpty())
        cout << "not ";
    cout << "empty" << endl;

    cout << "The head of the queue was " << intQueue.dequeue() << endl;
    cout << "The head of the queue was " << intQueue.dequeue() << endl;
    cout << "The head of the queue was " << intQueue.dequeue() << endl;
    cout << "The head of the queue was " << intQueue.dequeue() << endl;
    cout << "The head of the queue was " << intQueue.dequeue() << endl;

    cout << "The queue is ";
    if (!intQueue.isEmpty())
        cout << "not ";
    cout << "empty" << endl << endl;

    cout << "String Queue: " << endl;
    QueueFromList<string> stringQueue;

    cout << "Enqueueing to the queue: \"and\" \"now,\" \"the\" \"end\" \"is\" \"near\" " << endl;
    stringQueue.enqueue("and");
    stringQueue.enqueue("now,");
    stringQueue.enqueue("the");
    stringQueue.enqueue("end");
    stringQueue.enqueue("is");
    stringQueue.enqueue("near");

    cout << "The head of the queue was " << stringQueue.dequeue() << endl;
    cout << "The head of the queue was " << stringQueue.dequeue() << endl;
    cout << "The head of the queue was " << stringQueue.dequeue() << endl;
    cout << "The head of the queue was " << stringQueue.dequeue() << endl;

    cout << "The queue is ";
    if (!stringQueue.isEmpty())
        cout << "not ";
    cout << "empty" << endl;

    cout << "The head of the queue was " << stringQueue.dequeue() << endl;
    cout << "The head of the queue was " << stringQueue.dequeue() << endl;

    cout << "The queue is ";
    if (!stringQueue.isEmpty())
        cout << "not ";
    cout << "empty" << endl;




    cout << "\n\n---------------TEST 7-------------" << endl;
    /* Valgrind test, memory should all be freed */

    /* Checking destructor */
    LinkedList<int> intList2;
    intList2.InsertToHead(1);
    intList2.InsertToHead(2);
    intList2.InsertToHead(3);
    intList2.InsertToHead(4);
    intList2.InsertToHead(5);
    intList2.InsertToHead(6);
    intList2.InsertToHead(7);

    /* Checking delete methods */
    intList2.deleteFromHead();
    intList2.deleteFromTail();
    intList2.deleteNode(5);
    intList2.deleteNode(6);

    return 0;
}