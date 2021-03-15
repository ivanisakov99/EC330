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
#include <queue>

using namespace std;

//Create a class to store the coordinates of the Maze
class Coordinates
{
    public:
    int x;
    int y;
};
 
//Create a class for the queue used in BFS
class Queue
{
    public:
    Coordinates points;
    int path_distance;
};
 
 
//Using BFS to find the shortest path from the starting point to the end point
int BFS(char **maze, Coordinates start, Coordinates end)
{
    int msize = strlen(*maze) - 1;
    
    //Check that the path is actually reachable
    if (maze[start.x][start.y] == '0' || maze[end.x][end.y] == '0'){
        return 0;
    }
    
    //Mark the points that have been visited
    bool visited[msize][msize];
    memset(visited, false, sizeof visited);
    visited[start.x][start.y] = true;
 
    //Create a queue for BFS
    queue<Queue> queue;
    
    //Starting distance is 0
    Queue Q = {start, 0};
    queue.push(Q);
 
    
    while (!queue.empty())
    {
        Queue current = queue.front();
        Coordinates points = current.points;
 
        //Check if we have reached the end
        if (points.x == end.x && points.y == end.y){
            return current.path_distance + 1;
        }
 
        //If we haven't reached the end, pop the coordinates from the queue
        queue.pop();

        //Indeces of the nearby points
        int Row[] = {-1, 0, 0, 1};
        int Column[] = {0, -1, 1, 0};
 
        for (int i = 0; i < 4; i++)
        {
            int Next_x = points.x + Row[i];
            int Next_y = points.y + Column[i];
             
            //Check if the nearby points are 1's and are not visited
            if((Next_x >= 0) && (Next_x < msize) && (Next_y >= 0) && (Next_y < msize) && maze[Next_x][Next_y] == '1' && !visited[Next_x][Next_y])
            {
                //If the next points are 1's and not visited, mark them as visited and enqueue them
                visited[Next_x][Next_y] = true;
                Queue Next_Point = { {Next_x, Next_y}, current.path_distance + 1 };
                queue.push(Next_Point);
            }
        }
    }
 
    //Return 0 if end point can't be reached
    return 0;
}




 
//Driver program to test above function
int main()
{
    string line, file = "maze.txt";
    
    //Load the file
    ifstream input1(file);
    input1.unsetf(std::ios_base::skipws);

    //Count the number of new line characters to find out the length of the 2D array
    int msize = count(istream_iterator<char>(input1), istream_iterator<char>(), '\n') + 1;
    input1.close();
    
    //Create a 2D char array the same size as the maze
    char **maze = new char *[msize];
    for(int i = 0; i < msize; i++){
        maze[i] = new char[msize + 1];
    }

    //Fill the created char array with the elements of the maze
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
    //Starting and ending coordinates of the path in the maze
    Coordinates start = {0, 0};
    Coordinates end = {msize - 1, msize - 1};
 
    //Searching for the shortest path
    cout << BFS(maze, start, end) << endl;

    //deleting the 2D char array from the heap
    for(int i = 0; i < msize; i++){
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}