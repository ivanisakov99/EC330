#include <iostream>
#include<cmath>
#include<stack>
#include<utility>


using namespace std;


// function to traverse the maze
bool move(char maze[10][16],stack<pair<int,int>> path){
    // initiate x and y to the current position of exploration
    int x =path.top().first;
    int y=path.top().second;
    while(true){
        // if condition to check if you reached the goal point
        if((x == 13 && y ==8)){
            maze[y][x]='*';
            //cout<<"Gotcha!!";
            return true;
        }

    // check if possible to move forward and move
    if( x+1 <14 && maze[y][x+1] == ' '){
        maze[y][x]='*';
        x++;
        pair<int,int> t(x,y);
        path.push(t);
        if(move(maze,path))
          return true;
        }
      // check if possible to move down and move
    else if(y+1<9 && maze[y+1][x] == ' '){
        maze[y][x]='*';
        y++;
        pair<int,int> t(x,y);
        path.push(t);
        if(move(maze,path))
          return true;
        }
    //// check if possible to move back and move
    else if(x-1 >0 && maze[y][x-1] == ' '){
        maze[y][x]='*';
        x--;
        pair<int,int> t(x,y);
        path.push(t);
        if(move(maze,path))
          return true;
        }
        // check if possible to move up and move
    else if(y-1>0 && maze[y-1][x] == ' '){
        maze[y][x]='*';
        y--;
        pair<int,int> t(x,y);
        path.push(t);
        if(move(maze,path))
          return true;
        }
    // no move possible so mark it Dead End
    maze[y][x] = 'D';
    // pop the top of stack to back track
    path.pop();
    // refresh the values of x and y after pop..
    if(! path.empty()){
       x= path.top().first;
       y= path.top().second;
  
    }else{
        return false;
    }
  
    }//while
  
      

}
//maze printing function
void printMaze(char maze[10][16]){
    for(int i=0;i<10;i++){
        for(int j=0;j<16;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {

    char maze[10][16]= {"ooooooooooooooo",
                        "o o o ooo o  oo",
                        "o             o",
                        "o o ooooooo o o",
                        "o o   o   o   o",
                        "o ooo  oo  oooo",
                        "o    o o      o",
                        "oo o o o ooo oo",
                        "oo   o   o   oo",
                        "ooooooooooooooo"};
   //stack path to keep track of traverse
    stack<pair<int,int>> path;
    //initiated path with start point
    pair<int,int> initial(1,1);
    path.push(initial);
    //print the maze at beginning
    printMaze(maze);
    if(move(maze,path)){
        cout<<"The path is found\n";
    }
    //print maze at the end
    printMaze(maze);


    
  
   return 0;
}