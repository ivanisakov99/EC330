#include <iostream>
#include <string>
using namespace std;

// Implementing a recursive function to calculate the number of different ways
int steps(int n){
    if(n <= 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    else{
        return steps(n - 3) + steps(n - 2) + steps(n - 1);
    }

}

// Main Function
int main(int n, char** run){
    // Reading input and converting it to an integer
    int input = stoi(run[1]);
    
    // Printing the output
    cout << steps(input) << endl;
    
    return 0;
}