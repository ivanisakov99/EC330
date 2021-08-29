#ifndef CuckooHashTable_h
#define CuckooHashTable_h

#include<string>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

// Number of hash tables
#define NUM_OF_TABLES 2

// Size of the hash tables
#define LOGICAL_SIZE 13

// Hash function 1
#define h1 13

// Hash function 2
#define h2 11

class CuckooHashTable{
  private:
    // The two hash tables are implemented as a 2D vector
    vector< vector<string> > contents;
    
    // The current number of elements in the hash tables
    int num_of_elements;

  public:
    // Constructor
    CuckooHashTable();
    
    // Compute the hash function for input 'value' and table 'which'
    int hashFunction(string value, int which); 
    
    // Insert 'value' into the hash tables
    void add(string value); 
    
    // Print the content of the hash tables in the specified format
    void print(); 
};

#endif
