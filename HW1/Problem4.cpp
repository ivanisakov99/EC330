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
