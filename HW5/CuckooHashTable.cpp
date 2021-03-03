#include "CuckooHashTable.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

// upper bound on number of elements in our set
#define hashN 11

// choices for position
#define ver 2


string dis;
  
// Array to store possible positions for a key 
int pos[ver]; 

CuckooHashTable::CuckooHashTable() 
{ 
    string number = "";
    vector<string> row;
    for(int i = 0; i < ver; i++){
        contents.push_back (row);
        for(int j = 0; j < LOGICAL_SIZE; j++){
            contents[i].push_back (number);
        }
    }
    currentSize = 0;
} 



int CuckooHashTable::hashCode(string value, int which){
    
    int key = stoi(value);
    switch (which) 
    { 
        
        case 1: return key % LOGICAL_SIZE; 
        case 2: return hashN - (key % hashN); 
        
    } 
}


void CuckooHashTable::add(string value){
    string temp;
    dis = value;
    int count = 0;
    int tid = 0;
    while(count <= 2*LOGICAL_SIZE){
        
        if(count == 2*LOGICAL_SIZE){
            cout << "Error: Insert causes infinite loop" << endl;
            exit(EXIT_FAILURE);
        }
        
        for (int i = 0; i < ver; i++) 
        { 
            pos[i] = hashCode(dis, i+1); 

            if (contents[i][pos[i]] == dis){
                return; 
            }
        } 
        
        if (contents[tid][pos[tid]] != "") 
        { 
            temp = dis;
            dis = contents[tid][pos[tid]]; 
            contents[tid][pos[tid]] = temp;
            tid = (tid + 1) % ver;
            count++;
        } 
        else {
            contents[tid][pos[tid]] = dis;
            currentSize++;
            return;
        }
    }
    
   
}



void CuckooHashTable::print() 
{ 
    int n = 1;
  
    for (int i=0; i< ver; i++){
        printf("Table %d:\n", n); 
        for (int j = 0; j < LOGICAL_SIZE; j++){
           if(contents[i][j] == ""){
               cout << "-" << endl;
           }else
           {
               cout << contents[i][j] << endl;
           }
           
        }
        n++;
    }
    
} 
