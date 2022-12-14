/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on December 9th 2022 10:00am
 * Purpose: Template for absolute value
 */

#include <iostream>
using namespace std;

template <class T>
T abs(T arg1){
    if (arg1 < 0){
        return -arg1;
    }
    else
        return arg1;
}



int main(int argc, char** argv) {
    // Initialize variables
    float test1 = -2.55;
    int test2 = 2;
    
    //Output
    cout << "The first value is: " << test1 << " absolute value: " << abs(test1) << endl;
    cout << "The second value is: " << test2 << " absolute value: " << abs(test2) << endl;
    
    
    return 0;
}

