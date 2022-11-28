/* 
 * File:   main.cpp
 * Author: Cameron Hartling
 * Created on September 11, 2020, 11:00 AM
 * Purpose:  
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> // I/O Manipulators
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants and Conversion
const char  PERCENT=100;//Percent Conversion
const float TRILLIN=1e12f;//Trillion
const float BILLION=1e9f;//Billion

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    double divSales;
    
    //Initialize all known variables
    divSales = 3.46;
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    
    //Display the Inputs/Outputs
    cout << setw(8) << fixed << setprecision(2) << divSales << endl;

    //Clean up the code, close files, de-allocate memory, etc....
    //Exit stage right
    return 0;
}