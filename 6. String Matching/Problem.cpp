#include "Problem.h"

/*****************************************  Main  *****************************************/

int main(int argc, char** argv){
    /* Timing and IO setup */
    chrono::time_point<chrono::steady_clock> start, stop; 
    chrono::duration<double> difference_in_time;
    double delta_time; // Holds the final run time 
    
    string file = "TinyData.txt";

    cout << "---------------TEST " << file << " -------------" << endl;
    cout << "\n\n---------------Part A---------------\n\n" << endl;
    start = chrono::steady_clock::now(); 
    fourA(file);
    cout << "\n\n---------------Part B---------------\n\n" << endl;
    fourB(file);
    cout << "\n\n---------------Part C---------------\n\n" << endl;
    fourC(file);
    
    stop = chrono::steady_clock::now(); 
    difference_in_time = stop - start;
    delta_time = double(difference_in_time.count()); 
    cout << file << " time: " << delta_time << endl;
    
    file = "SmallData.txt";
    cout << "\n\n---------------TEST " << file << " -------------" << endl;
    cout << "\n\n---------------Part A---------------\n\n" << endl;
    start = chrono::steady_clock::now(); 
    fourA(file);
    cout << "\n\n---------------Part B---------------\n\n" << endl;
    fourB(file);
    cout << "\n\n---------------Part C---------------\n\n" << endl;
    fourC(file);

    stop = chrono::steady_clock::now(); 
    difference_in_time = stop - start;
    delta_time = double(difference_in_time.count()); 
    cout << file << " time: " << delta_time << endl;

    file = "BigData.txt";
    cout << "\n\n---------------TEST " << file << " -------------" << endl;
    cout << "\n\n---------------Part A---------------\n\n" << endl;
    start = chrono::steady_clock::now(); 
    fourA(file);
    cout << "\n\n---------------Part B---------------\n\n" << endl;
    fourB(file);
    cout << "\n\n---------------Part C---------------\n\n" << endl;
    fourC(file);

    stop = chrono::steady_clock::now(); 
    difference_in_time = stop - start;
    delta_time = double(difference_in_time.count()); 
    cout << file << " time: " << delta_time << endl;

	return 0;
}