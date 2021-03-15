#include <iostream>
#include <fstream>
#include <cmath>
#include <stack>
#include <utility>
#include <string>
#include <cstring>
#include <stdio.h>
#include <cctype>
#include <algorithm>
#include <iterator>
using namespace std;


//counter for the length of the path
int c = 0;


// function to traverse the maze
bool move(char **maze,stack<pair<int,int>> path){
    int msize = strlen(*maze);
    // initialise x and y to the current position of exploration
    int x = path.top().first;
    int y = path.top().second;
    while(true){
        //cout << "X: " << x << " Y: " << y << endl; 
        // if condition to check if you reached the goal point
        if((x == msize - 1 && y == msize - 1)){
            c++;
            maze[y][x]='*';
            //cout << "The length of the shortest path is: " << c << endl;
            //cout<<"Gotcha!!";
            return true;
        }else{

    // check if possible to move forward and move
    if( x+1 < msize && maze[y][x+1] == '1'){
        c++;
        maze[y][x]='*';
        x++;
        pair<int,int> t(x,y);
        path.push(t);
        if(move(maze,path))
          return true;
        }
      // check if possible to move down and move
    else if(y+1< msize + 1 && maze[y+1][x] == '1'){
        c++;
        maze[y][x]='*';
        y++;
        pair<int,int> t(x,y);
        path.push(t);
        if(move(maze,path))
          return true;
        }
    //// check if possible to move back and move
    else if(x-1 > 0 && maze[y][x-1] == '1'){
        c++;
        maze[y][x]='*';
        x--;
        pair<int,int> t(x,y);
        path.push(t);
        if(move(maze,path))
          return true;
        }
        // check if possible to move up and move
    else if(y-1>0 && maze[y-1][x] == '1'){
        c++;
        maze[y][x]='*';
        y--;
        pair<int,int> t(x,y);
        path.push(t);
        if(move(maze,path))
          return true;
        }
    else {
    cout << c << endl;
    // no move possible so mark it Dead End
    maze[y][x] = 'D';
    c--;
    // pop the top of stack to back track
    path.pop();
    // refresh the values of x and y after pop..
    if(!path.empty()){
       x= path.top().first;
       y= path.top().second;
  
    }else{
        c = 0;
        return false;
    }
    }
        }
    }//while
  
      

}

//maze printing function
void printMaze(char **maze){
    int msize = strlen(*maze);
    for(int i = 0; i < msize; i++){
        for(int j = 0; j < msize;j++){
            cout << maze[i][j] << " ";
        }
        cout << "\n";
    }
}


int main() {
    string line, file = "maze1.txt";
    ifstream input1(file);
    input1.unsetf(std::ios_base::skipws);

    // count the newlines with an algorithm specialized for counting:
    int msize = std::count(std::istream_iterator<char>(input1), std::istream_iterator<char>(), '\n') + 1;
    //cout << size << endl;
    input1.close();
    
    //cout << msize << endl;


    
    char **maze = new char *[msize];
    for(int i = 0; i < msize; i++){
        maze[i] = new char[msize + 1];
    }

    //cout << strlen(*maze) << endl;
    int j = 0;
    ifstream input2(file);
    while(getline(input2, line)){
        int size = line.length();
        char arr[size + 1];
        strcpy(arr, line.c_str());
        for(int i = 0; i < msize + 1; i++){
            maze[j][i] = arr[i];
        }
        
        j++;
    }

    
   //stack path to keep track of traverse
    stack<pair<int,int>> path;
    //initiated path with start point
    pair<int,int> initial(0,0);
    path.push(initial);
    //print the maze at beginning
    printMaze(maze);
    
    if(move(maze, path)){
        cout<<"The path is found\n";
        cout << "The length of the shortest path is: " << c << endl;
    }else{
        
        cout << "The path is not found\n";
    }
    
    //print maze at the end
    printMaze(maze);

    
    input2.close();
    for(int i = 0; i < msize; i++){
        delete[] maze[i];
    }
    delete[] maze;
  
   return 0;
}