#include <iostream>
#include <string>
using namespace std;

//Helper Function
int steps(int n){   //Implementing a recursive function to calculate the number of different ways
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

//Main Function
int main(int n, char** run){
    int input = stoi(run[1]);  //Reading input and converting it to an integer
    
    cout << steps(input) << endl;   //Printing the output
    
    return 0;
}
