#include "CuckooHashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char** argv){

	ifstream input("input.txt");
	CuckooHashTable cht;
	string number = "";

  	string line;
  	while (getline(input, line)) {

    	cht.add(line);
  	}
	cht.print();

	return 0;
}
