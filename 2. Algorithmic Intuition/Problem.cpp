#include "MaxProduct.h"
#include <iostream>

using namespace std;

int main() {
    MaxProductClass mProd;
    string file = "input.txt";
    long max = mProd.MaxProduct(file);
    
    cout << "The overall max product is: " << max << endl;
    
    return 0;
}

