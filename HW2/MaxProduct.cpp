//MaxProduct.cpp file
#include <iostream>
#include <string>
#include <fstream>
#include "MaxProduct.h"
//using namespace std;

long MaxProductClass::MaxProduct(string filename){

    //opening file

    ifstream inFile(filename);

    //if file not found, displaying error and returning 0

    if(!inFile){

        cout << "Input file is not found!" << endl;

        return 0;

    }

    //initializing max and overallmax to -999999, first, second and third to 1

    long max = -999999, overallmax = -999999, first = 1, second = 1, third = 1, input;

    //looping as long as an integer is read successfully from file

    while(inFile >> input){

        //checking if input is -999999

        if(input == -999999){

            //if max is still -999999, it means there were no inputs prior to that
            //-999999, so we print a blank line (or replace with whatever you like)

            if(max == -999999){

                cout << endl;

            }
            else{

                //otherwise printing max
                cout << max << endl;

            }

            //now if max is bigger than overallmax, setting max as overallmax

            if(max > overallmax){

                overallmax = max;

            }

            //resetting first, second, third and max

            first = second = third = 1;

            max = -999999;

        }
        else{

            //otherwise (if input is not -999999), checking if max is still -999999
            //or product of second, third and input is bigger than current max

            if(max == -999999 || (second * third * input) > max){

                //setting product of second, third and input as new max

                max = second * third * input;

            }

            //setting second as first, third as second and input as new third.

            first = second;

            second = third;

            third = input;

        }

    }

    //closing file

    inFile.close();

    //if overallmax is still -999999, it means there are no valid inputs on
    //the file to find the products of, in which case we return 0

    if(overallmax == -999999){

        return 0;

    }

    //else returning overallmax

    return overallmax;

}