# <ins>Problem: Templates</ins>

You are provided with a partial implementation of a templated singly-linked list in LinkedList.h, with some missing functionality. It contains a templated Node
class and a templated LinkedList class. **Do not modify the class definitions**.

The linked list class contains the following methods:
• LinkedList – Constructor of a linked list with a head pointing to null (implemented).
• ~LinkedList – Destructor of a linked list.
• deleteFromHead – Removes and returns content of the first node of the list. (If the
list is empty, does nothing.)
• deleteFromTail – Removes and returns content of last node of the list. (If the list
is empty, does nothing.)
• deleteNode – Removes node with provided data from the list.
• InsertToHead – Inserts node with provided data at the head (implemented).
• InsertToTail – Inserts node with provided data at the tail.
• getSize – Returns the number of nodes in the linked list.
• print - Prints the linked list (implemented).

Notice that while the declaration and implementation of classes are typically split between .cpp and .h files, some compilers cannot handle templates in separate
files, which is why we include both the declaration and implementation in a single .h file.

The *main.cpp* file consists of sample test code for each of the tasks below. Your code, which should be added to the provided *LinkedList.h* will be compiled and run
with variations of this file.

1. Complete the implementation of the templated singly-linked list provided in the header file.
2. Implement *StackFromList*, a templated stack class backed by the above singly- linked list. The stack should have a private linked list member, and utilize the
linked list methods to implement its functionality. The stack should include a constructor, a destructor, a push, a pop, and an *isEmpty* method (which returns a
bool).
3. Implement, *QueueFromList*, a templated queue class backed by the above singly- linked list. The queue should have a private linked list member, and utilize the
linked list methods to implement its functionality. The queue should include a constructor, a destructor, an enqueue (insert to head), a deque (remove from tail),
and an *isEmpty* method (which returns a bool).
 