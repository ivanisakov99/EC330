#include "CuckooHashTable.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

// string dis;
  


CuckooHashTable::CuckooHashTable(){ 
    string entry = "";
    vector<string> row;

    // Initialise as empty
    for(int i = 0; i < NUM_OF_TABLES; i++){
        contents.push_back (row);
        for(int j = 0; j < LOGICAL_SIZE; j++){
            contents[i].push_back (entry);
        }
    }

    // Set the number of elements to nill
    num_of_elements = 0;
} 

int CuckooHashTable::hashFunction(string value, int which){
    switch (which){ 
        // h1(x) = x mod 13
        case 1: return stoi(value) % h1; 

        // h2(x) = 11 - (x mod 11)
        case 2: return h2 - (stoi(value) % h2); 
    } 

    return 0;
}

void CuckooHashTable::add(string value){
    string temp;
    string displacement_value = value;
    int count = 0;
    int tid = 0;

    // Array of possible positions for a key 
    int pos[NUM_OF_TABLES]; 

    // while(count <= 2*LOGICAL_SIZE){
    while(true){
        
        // The value that is being rehashed is the same value that is being added,
        // which means that there is an infinite loop present
        if(displacement_value == value && count > 0){
            cout << "Infinite loop detected when " << value << " is inserted" << endl;
            return;
        }
        
        // Calculate the keys to each table
        for (int i = 0; i < NUM_OF_TABLES; i++){ 
            pos[i] = hashFunction(displacement_value, i + 1); 

            // Duplicate element
            if (contents[i][pos[i]] == displacement_value){
                return; 
            }
        } 
        
        // Displace the current entry by the new value and rehash
        if(contents[tid][pos[tid]] != ""){ 
            temp = displacement_value;
            displacement_value = contents[tid][pos[tid]]; 
            contents[tid][pos[tid]] = temp;
            // tid++;
            (++tid >= NUM_OF_TABLES) ? tid = 0 : tid;
            count++;
        } 
        // Successfully add the new value
        else{
            contents[tid][pos[tid]] = displacement_value;
            num_of_elements++;
            return;
        }
    }
}

void CuckooHashTable::print(){ 
    for (int i = 0; i < NUM_OF_TABLES; i++){
        printf("Table %d:\n", i + 1); 
        for (int j = 0; j < LOGICAL_SIZE; j++){
            if(contents[i][j] == ""){
                cout << "-" << endl;
            }
            else{
               cout << contents[i][j] << endl;
            }
        }
    }
} 
