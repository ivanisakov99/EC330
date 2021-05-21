#include "MaxProduct.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

long MaxProductClass::MaxProduct(string filename){
    // Opening the file
    ifstream inFile(filename);

    // If file not found, displaying error and returning 0
    if(!inFile){
        cout << "Input file is not found!" << endl;
        return 0;
    }

    // Initialising max and overallmax to -999999 and first, second and third to 1
    long max, overallmax, first, second, third;
    long input;

    max = overallmax = LONG_MIN;
    first = second = third = 1;

    // Looping as long as an integer is read successfully from file
    while(inFile >> input){
        // Checking if input is -999999, thus the end of the line
        if(input == -999999){
            // Checking the last three entries
            for(int i = 0; i < 3; i++){
                if(first * second * third > max){
                    max = first * second * third;
                }
                first = second;
                second = third;
                third = 1;
            }

            // If max is still LONG_MIN, it means there were no inputs prior to that
            // -999999, so we print a blank line
            if(max == LONG_MIN){
                cout << endl;
            }
            else{
                // Otherwise printing max
                cout << max << endl;
            }

            // Now if max is bigger than overallmax, setting overallmax as max
            if(max > overallmax){
                overallmax = max;
            }

            // Resetting max
            max = LONG_MIN;
        }
        else{
            // Otherwise (if input is not -999999), checking if max is still LONG_MIN
            // or product of second, third and input is bigger than current max
            if(max == LONG_MIN || (second * third * input) > max){
                // Setting product of second, third and input as new max
                max = second * third * input;
            }

            // Setting second as first, third as second and input as new third.
            first = second;
            second = third;
            third = input;
        }
    }

    

    // Closing the file
    inFile.close();

    // If overallmax is still LONG_MIN, it means there are no valid inputs on
    // the file to find the products of, in which case we return 0
    if(overallmax == LONG_MIN){
        return 0;
    }

    // Else returning overallmax
    return overallmax;
}