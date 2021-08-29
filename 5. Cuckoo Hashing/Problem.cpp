#include "CuckooHashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char** argv){
	cout << "---------------TEST 0-------------" << endl;
	ifstream input0("input0.txt");
	CuckooHashTable cht0;
	string number = "";

  	string line;
  	while (getline(input0, line)) {
    	cht0.add(line);
  	}
	cht0.print();

	input0.close();

	cout << "\n\n---------------TEST 1-------------" << endl;
	ifstream input1("input1.txt");
	CuckooHashTable cht1;
	number = "";

  	while (getline(input1, line)) {
    	cht1.add(line);
  	}
	cht1.print();

	input1.close();

	cout << "\n\n---------------TEST 2-------------" << endl;
	ifstream input2("input2.txt");
	CuckooHashTable cht2;
	number = "";

  	while (getline(input2, line)) {
    	cht2.add(line);
  	}
	cht2.print();

	input2.close();

	cout << "\n\n---------------TEST 3-------------" << endl;
	ifstream input3("input3.txt");
	CuckooHashTable cht3;
	number = "";

  	while (getline(input3, line)) {
    	cht3.add(line);
  	}

	input3.close();

	cout << "\n\n---------------TEST 4-------------" << endl;
	ifstream input4("input4.txt");
	CuckooHashTable cht4;
	number = "";

  	while (getline(input4, line)) {
    	cht4.add(line);
  	}
	cht4.print();

	input4.close();


	return 0;
}
