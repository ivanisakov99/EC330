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

### <ins>Expected Outputs:</ins>

    ---------------TEST 0-------------
    *** Int linked list: ***
    Inserting to linked list: 1 2 3 4 5
    The size of the linked list is 5
    Content of linked list: 1 2 3 4 5
    Deleted 1 from head. The size of the linked list is 4
    Content of linked list: 2 3 4 5
    Deleted 5 from tail. The size of the linked list is 3
    Content of linked list: 2 3 4
    Deleted node containing 3. The size of the linked list is 2
    Content of linked list: 2 4
    Inserted 0 to head. The size of the linked list is 3
    Content of linked list: 0 2 4
    Deleted node containing 4. The size of the linked list is 2
    Content of linked list: 0 2
    Deleted node containing 0. The size of the linked list is 1
    Content of linked list: 2 
    Deleted 2 from tail. The size of the linked list is 0
    Content of linked list: Linked list is empty


    *** String linked list: ***
    Inserting to linked list: one two three four
    The size of the linked list is 4
    Content of linked list: one two three four
    Deleted one from head. The size of the linked list is 3
    Content of linked list: two three four
    Deleted four from tail. The size of the linked list is 2
    Content of linked list: two three
    Deleted node containing three. The size of the linked list is 1
    Content of linked list: two 
    Inserted to node zero to head. The size of the linked list is 2
    Content of linked list: zero two
    Deleted node containing two. The size of the linked list is 1
    Content of linked list: zero 
    Deleted zero from head. The size of the linked list is 0
    Content of linked list: Linked list is empty


    *** Int stack: ***
    Pushing to the stack: 1 2 3 4
    The top of the stack was 4
    The top of the stack was 3
    Pushing to the stack: 5 6
    The stack is not empty
    The top of the stack was 6
    The top of the stack was 5
    The top of the stack was 2
    The top of the stack was 1
    The stack is empty


    *** Char queue: ***
    Enqueueing to the queue: a b c d
    The head of the queue was a
    The head of the queue was b
    Enqueueing to the queue: e
    The queue is not empty
    The head of the queue was c
    The head of the queue was d
    The head of the queue was e
    The queue is empty


    ---------------TEST 1-------------
    The size of the linked list is 0
    Inserted '3' to tail. The size of the linked list is 1
    Inserted '3' to head. The size of the linked list is 2
    Inserted '0' to tail. The size of the linked list is 3
    Inserted 'C' to head. The size of the linked list is 4
    Inserted 'E' to head. The size of the linked list is 5
    Content of linked list: E C 3 3 0
    Inserted '!' to tail. The size of the linked list is 6
    Content of linked list: E C 3 3 0 !


    ---------------TEST 2-------------
    Inserted 5.05, 4.04, 3.03, 2.02, 1.01 to list 
    Deleted 5.05 from head.
    Content of linked list: 4.04 3.03 2.02 1.01
    Deleted 1.01 from tail.
    Content of linked list: 4.04 3.03 2.02
    Deleted 2.02 from tail.
    Content of linked list: 4.04 3.03
    Deleted 4.04 from head.
    Content of linked list: 3.03 
    Inserted 6.06 to head.
    Content of linked list: 6.06 3.03
    Deleted 6.06 from head.
    Content of linked list: 3.03 
    Deleted 3.03 from tail.
    Content of linked list: Linked list is empty

    ---------------TEST 3-------------
    Inserted 0.067, 36, 999999, 1000, 5467.8 to list
    Deleted 1000 from list.
    Content of linked list: 0.067 36 999999 5467.8
    Deleted 36 from list.
    Content of linked list: 0.067 999999 5467.8
    Deleted 5467.8 from list.
    Content of linked list: 0.067 999999
    Deleted 999999  from list.
    Content of linked list: 0.067 
    Deleted 0.067 from list.
    Content of linked list: Linked list is empty

    ---------------TEST 4-------------
    Attempted to delete from head
    Attempted to delete from tail
    Attempted to delete value 0 from empty list 
    Inserted 3 to head
    Attempted to delete 1 from list
    Content of linked list: 3 

    ---------------TEST 5-------------
    Char Stack:
    The stack is empty
    Pushing to the stack: g n e u b
    The top of the stack was b
    The top of the stack was u
    Pushing to the stack: ! 
    The stack is not empty
    The top of the stack was !
    The top of the stack was e
    The top of the stack was n
    The top of the stack was g
    The stack is empty

    String Stack: 
    Pushing to the stack: "oh" "what" "a" "beautiful" "morning" 
    The top of the stack was morning
    The top of the stack was beautiful
    The top of the stack was a
    The top of the stack was what
    The stack is not empty
    The top of the stack was oh
    The stack is empty


    ---------------TEST 6-------------
    Int Queue:
    The queue is empty
    Enqueueing to the queue: 5 4 3 2 1
    The head of the queue was 5
    The head of the queue was 4
    Enqueueing to the queue: 0 -1 
    The queue is not empty
    The head of the queue was 3
    The head of the queue was 2
    The head of the queue was 1
    The head of the queue was 0
    The head of the queue was -1
    The queue is empty

    String Queue: 
    Enqueueing to the queue: "and" "now," "the" "end" "is" "near" 
    The head of the queue was and
    The head of the queue was now,
    The head of the queue was the
    The head of the queue was end
    The queue is not empty
    The head of the queue was is
    The head of the queue was near
    The queue is empty
