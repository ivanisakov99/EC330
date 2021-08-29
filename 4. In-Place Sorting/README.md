# <ins>Problem: In-Place Sorting</ins>

We saw in class different sorting algorithms, and we generally assumed the input to be sorted wasj an array. Here, the provided input is an unordered linked
list of n elements with integer values. We are interested in sorting this list in increasing order (smallest first), in O(n log n) worst case time, while using
constant space (also called in-place sorting). Note that recursion requires additional space on the stack, so should be avoided in this case.

You are provided with the following files: *LNode.h*, *LNode.cpp*, *LSorter.h*, *LSorter.cpp*, and *main.cpp*.

A linked list node, *LNode*, is implemented in *LNode.h* and *LNode.cpp*.
The *LSorter* class with the sortList method are declared in *LSorter.h*. The *sortList* method, which you need to implement, is declared as follows:

    class LSorter { 
      public:
        LNode* sortList(LNode* head); 
    };
    
This method accepts as input the head node of the list to be sorted, and returns the head node of the sorted linked list. Your implementation should be
included in the *LSorter.cpp* file. You may add additional classes and/or methods as you see fit, but everything should be included in this file, and none of
the other files may be modified.

Finally, the provided *main.cpp* file may be used to test your implementation. You may assume that your input consists of non-negative integers with a maximal
value of 1,000,000.

Modify and submit *LSorter.cpp* only. The submitted file should compile and run with the rest of the files. We will run it against large linked list and measure
the run time.

Partial credit will be given for an in-place solution with a runtime that is worse than O(n log n).

### <ins>Expected Outputs:</ins>

    Test Case 0:
    Input: 5 1 7 13 2 9
    Output: 1 2 5 7 9 13

    Test Case 1:
    Input: 5 1 7 13 2 9 9 9 9 
    Output: 1 2 5 7 9 9 9 9 13

    Test Case 2:
    Input: 0
    Output: 0

    Test Case 3:
    Input: -5 1 -7 13 -22 9
    Output: -22 -7 -5 1 9 13
