### <ins>Problem: Maze</ins>
Consider a 2D array of 1s and 0s of size NxN. The array is a "maze." You must start from the top left (index (0,0)) and find the length of the shortest path to the bottom right (index (n,n)). You may only travel across elements that have value "1". The top left and bottom right indices are guaranteed to be "1". You may only move horizontally or vertical one index with each step.

For example, for the following input maze, a shortest path is along bolded numbers and has a length of 9:

   **11**001 

   0**1**011 

   0**11**00 

   11**11**0 
   
   110**11**
   
Your program will open an input file, called maze.txt, containing a maze. Your program, when run with no command-line arguments in the same directory as maze.txt, should read the provided maze from the file, determine N, the dimension of the maze, and output the length of the shortest path to the screen. If no path exists, your program should output ‘0’. You may use the provided maze.txt file to test your code.
