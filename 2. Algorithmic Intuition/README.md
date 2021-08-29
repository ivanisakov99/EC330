# <ins>Problem: Max Product</ins>

Write and briefly explain the following C++ function:

    long MaxProduct (string file);

that accepts an input file containing sequences of integers. Each sequence starts on a new line, may continue on several subsequent lines, contains at most 100
numbers, and ends with the number -999999 (which is not part of the sequence).

The function outputs to the screen the maximum continuous sub-sequence product of up to 3 numbers for each sequence, one output per line. It returns the maximum of
all the outputs.

      Sample input:
         1 2 3 -999999
         -5 -2 2 -30 -999999 
         6 9 -10 1 -999999 
         -8 -999999

      Sample output: 
         6
         120
         54
         -8
         The overall max product is: 120
         
The MaxProduct method is a member function of the MaxProductClass class, which should be implemented in MaxProduct.cpp and declared in MaxProduct.h. Try to make
your function as efficient as you can.

### <ins>Expected Outputs:</ins>

      Test Case 0:
      6
      120
      54
      -8
      The overall max product is: 120

      Test Case 1:
      2040
      238
      720
      2720
      72
      The overall max product is: 2720

      Test Case 2:
      264355
      514368
      528660
      108864
      196224
      The overall max product is: 528660  

      Test Case 3:
      -9
      8
      3
      8
      4
      7
      5  
      6
      8
      9
      The overall max product is: 9

      Test Case 4:
      -1000000
      -2000000
      -3000000
      The overall max product is: -1000000

      Test Case 5:
      See output5.txt
