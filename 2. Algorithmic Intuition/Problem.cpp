#include "MaxProduct.h"
#include <iostream>

using namespace std;

int main() {
    cout << "---------------TEST 0-------------" << endl;
    MaxProductClass mProd0;
    string file0 = "input.txt";
    long max = mProd0.MaxProduct(file0);
    
    cout << "The overall max product is: " << max << endl;

    cout << "\n\n---------------TEST 1-------------" << endl;
    MaxProductClass mProd1;
    string file1 = "input1.txt";
    max = mProd1.MaxProduct(file1);
    
    cout << "The overall max product is: " << max << endl;

    cout << "\n\n---------------TEST 2-------------" << endl;
    MaxProductClass mProd2;
    string file2 = "input2.txt";
    max = mProd2.MaxProduct(file2);
    
    cout << "The overall max product is: " << max << endl;

    cout << "\n\n---------------TEST 3-------------" << endl;
    MaxProductClass mProd3;
    string file3 = "input3.txt";
    max = mProd3.MaxProduct(file3);
    
    cout << "The overall max product is: " << max << endl;

    cout << "\n\n---------------TEST 4-------------" << endl;
    MaxProductClass mProd4;
    string file4 = "input4.txt";
    max = mProd4.MaxProduct(file4);
    
    cout << "The overall max product is: " << max << endl;

    cout << "\n\n---------------TEST 5-------------" << endl;
    MaxProductClass mProd5;
    string file5 = "input5.txt";
    max = mProd5.MaxProduct(file5);
    
    cout << "The overall max product is: " << max << endl;

    return 0;
}

