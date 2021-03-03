/*	Input:  input.txt file, containing sequences of numbers. 
**             Each sequence starts on a new line, may continue of several subsequent lines, 
**             contains at most 100 numbers, and ends with the number -999999 
**             (which is not part of the sequence).
**	Output:  outputs to the screen the maximum sub-sequence product of up to 3 numbers for each sequence, 
**             one output per line, followed by the maximum of all the outputs.
*/

#include <iostream>
#include "MaxProduct.h"

using namespace std;

int main() {
    MaxProductClass mProd;

    long max = mProd.MaxProduct("input.txt");
    
    cout << "The overall max product is: " << max << endl;
    
    return 0;
}

