#include "Problem.h"
 
//Driver program to test above function
int main()
{
    string line, file = "maze_all_1.txt";
    
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