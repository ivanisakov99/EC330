//Write a C++ program which receives a file name as command line argument, reads all the lines of text in the input file, 
//and prints out the longest line in the file. 
//If there are multiple lines of the same length, the first longest line should be returned. 
//That is, your program should have one single line of output, which is the longest line in the file. 
//If the input file is empty (does not contain any lines) then your program should not print anything.

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char *argv[]){

    ifstream infile( *(argv + 1) ); //read the file name from the argv
  

    //check the file could be opened successfully if not close the program
    if(infile.bad() || !infile.is_open()){
        cout << "Error: Unable to open file";
        return 0;
    }
  
    string line, longestLine = "";

    //read the file line by line
    while(getline(infile, line, '\n')){

        //if the length of the current read line is more than the earlier update the longestline with the current line
       if(line.length() > longestLine.length()){
           longestLine = line;
       } 
    }
  
    infile.close(); //close the file stream
  

    //print the longest line
    cout << "Longest Line in the file was: " << longestLine <<endl;
  
    return 0;
}