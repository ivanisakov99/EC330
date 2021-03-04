//
//  CuckooHashTable.h
//  CuckooHashTable
//

#ifndef CuckooHashTable_h
#define CuckooHashTable_h

#include<string>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;
const int LOGICAL_SIZE = 13;

class CuckooHashTable
{
private:
  vector<vector<string>> contents; // the two hash tables are implemented as a 2D vector
    int currentSize;
public:
    CuckooHashTable(); // Constructor
    int hashCode(string value, int which); // compute hash function for input 'value', table 'which'
    void add(string value); // insert 'value' to hash table
    void print(); // print the content of the hash table in the specified format
};


#endif /* CuckooHashTable_h */
