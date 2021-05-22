#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <cctype>
#include <vector>
#include "StringMatching.h"

using namespace std;

int main(int argc, char** argv){
    string file = "TinyData.txt";
    cout << "---------------" << file << "---------------" << endl;
    cout << "---------------Part A---------------" << endl;
    fourA(file);
    cout << "\n---------------Part B---------------" << endl;
    fourB(file);
    cout << "\n\n---------------Part C---------------\n\n" << endl;
    fourC(file);
    
    file = "SmallData.txt";
    cout << "\n\n---------------" << file << "---------------" << endl;
    cout << "---------------Part A---------------" << endl;
    fourA(file);
    cout << "\n---------------Part B---------------" << endl;
    fourB(file);
    cout << "\n\n---------------Part C---------------\n\n" << endl;
    fourC(file);

    file = "BigData.txt";
    cout << "\n\n---------------" << file << "---------------" << endl;
    cout << "---------------Part A---------------" << endl;
    fourA(file);
    cout << "\n---------------Part B---------------" << endl;
    fourB(file);
    cout << "\n\n---------------Part C---------------\n\n" << endl;
    fourC(file);

	return 0;
}