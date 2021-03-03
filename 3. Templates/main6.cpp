#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char* argv[]) {

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

    return 0;
}