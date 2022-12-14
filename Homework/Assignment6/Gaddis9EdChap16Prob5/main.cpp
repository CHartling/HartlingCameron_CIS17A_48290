/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on December 9th 2022 11:00am
 * Purpose: Template for running total
 */

#include <iostream>
using namespace std;

template <class T>
T Total(T numVal){
    //Declare variables
    unsigned int i;
    T val;
    T total;
    
    cout << "Enter values: " << endl;
    
    for(i = 0; i < numVal; i++){
        cin >> val;
        total += val;
    }
    
    return total;
}


int main(int argc, char** argv) {
    //Declare variables
    int numVals;
    int totalVal;
    
    cout << "Enter the number of values to be added: ";
    cin >> numVals;
    cout << endl << endl;
    
    totalVal = Total(numVals);
    cout << "The sum of the values is: " << totalVal;
    
    
    return 0;
}

