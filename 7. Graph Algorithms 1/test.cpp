#include <iostream>
#include <fstream>
#include<cmath>
#include<stack>
#include<utility>


using namespace std;

int c = 0;
// function to traverse the maze
bool move(char **maze,stack<pair<int,int>> path){
    // initiate x and y to the current position of exploration
    int x =path.top().first;
    int y=path.top().second;
    while(true){
        // if condition to check if you reached the goal point
        if((x == 4 && y ==4)){
            c++;
            maze[y][x]='*';
            //cout<<"Gotcha!!";
            return true;
        }

    // check if possible to move forward and move
    if( x+1 < 6 && maze[y][x+1] == '1'){
        c++;
        maze[y][x]='*';
        x++;
        pair<int,int> t(x,y);
        path.push(t);
        if(move(maze,path))
          return true;
        }
      // check if possible to move down and move
    else if(y+1< 6 && maze[y+1][x] == '1'){
        c++;
        maze[y][x]='*';
        y++;
        pair<int,int> t(x,y);
        path.push(t);
        if(move(maze,path))
          return true;
        }
    //// check if possible to move back and move
    else if(x-1 >0 && maze[y][x-1] == '1'){
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
    // no move possible so mark it Dead End
    maze[y][x] = 'D';
    c--;
    // pop the top of stack to back track
    path.pop();
    // refresh the values of x and y after pop..
    if(! path.empty()){
       x= path.top().first;
       y= path.top().second;
  
    }else{
        c = 0;
        return false;
    }
  
    }//while
  
      

}
//maze printing function
void printMaze(char **maze){
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    string line, file = "maze.txt";
    /*
    char maze[5][6]= {  "11001",
                        "01011",
                        "01100",
                        "11110",
                        "11010"};
    */
   ifstream input1(file);
    input1.unsetf(std::ios_base::skipws);

    //count the length of the 2D array (+ 1 for the length of the char array)
    int msize = count(istream_iterator<char>(input1), istream_iterator<char>(), '\n');
    input1.close();


   //int msize = 5;



   
   char **maze = new char *[msize];
    for(int i = 0; i < msize + 1; i++){
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
    if(move(maze,path)){
        cout<<c << endl;
    }else{
        cout << c << endl;
    }
    //print maze at the end
    printMaze(maze);


  
   return 0;
}