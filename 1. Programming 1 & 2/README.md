### <ins>Problem 1: Programming I</ins>

Write a C++ program which receives a file name as command line argument, reads all the lines of text in the input file, and prints out the longest line in the file. If there are multiple lines of the same length, the first longest line should be returned. That is, your program should have one single line of output, which is the longest line in the file. If the input file is empty (does not contain any lines) then your program should not print anything.

For example, suppose that you compile your program to the executable Problem4, your program should be run from the command line as follows:

    > Problem4 TextFile.txt
  
For the provided sample input file, TextFile.txt, your program should print the following output:

    > It then reads all the lines of text in the input file, and prints out the longest line in the file.


### <ins>Problem 2: Programming II</ins>

A child is jumping up a flight of stairs. The child can jump either 1, 2, or 3 steps at a time. Implement the following recursive C++ function, that returns the
number of different ways that the child can jump up a flight of n stairs:

    int steps (n);
  
Your main function should receive an integer as a command-line argument, call the steps function with the provided integer as input, and print out the output returned by the function.

For example, suppose that you compile your program to the executable Problem5, for the integer 20, your program should be run as follows:

    > Problem5 20

You MUST use only recursion for this problem. You may not use iteration (no for, while, or do-while loops).
