#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char* argv[]) {

    /* Valgrind test, memory should all be freed */

    /* Checking destructor */
    LinkedList<int> intList;
    intList.InsertToHead(1);
    intList.InsertToHead(2);
    intList.InsertToHead(3);
    intList.InsertToHead(4);
    intList.InsertToHead(5);
    intList.InsertToHead(6);
    intList.InsertToHead(7);

    /* Checking delete methods */
    intList.deleteFromHead();
    intList.deleteFromTail();
    intList.deleteNode(5);
    intList.deleteNode(6);

    return 0;
}