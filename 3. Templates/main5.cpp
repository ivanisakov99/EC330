#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char* argv[]) {

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

    return 0;
}