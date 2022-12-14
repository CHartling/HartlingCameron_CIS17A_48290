/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on December 9th 2022 10:00am
 * Purpose: Template for min and max of two values
 */

#include <iostream>
using namespace std;

template <class T>
T min(T arg1, T arg2) {
    if (arg1 < arg2)
        return arg1;
    else
        return arg2;
}

template <class T>
T max(T arg1, T arg2)
{
    if (arg1 > arg2)
        return arg1;
    else
        return arg2;
}


int main(int argc, char** argv) {
    //Declare variables
    int int1, int2;
    float float1, float2;
    
    //For int values
    cout << "Testing integer values...."<< endl;
    
    //Get user input
    cout << "Enter the first integer value: ";
    cin >> int1;
    cout << "Enter the second integer value: ";
    cin >> int2;
    
    //Output Results
    cout << "Minium of " << int1 << "and " << int2 << " is " << min(int1,int2) << endl;
    cout << "Maximum of " << int1 << "and " << int2 << " is " << max(int1,int2) << endl;
    
    //For float values
    cout << "Testing float values...."<< endl;
    
    //Get user input
    cout << "Enter the first float value: ";
    cin >> float1;
    cout << "Enter the second float value: ";
    cin >> float2;
    
    //Output results
    cout << "Minium of " << float1 << "and " << float2 << " is " << min(float1,float2) << endl;
    cout << "Maximum of " << float1 << "and " << float2 << " is " << max(float1,float2) << endl;
    
    
    
    return 0;
}

