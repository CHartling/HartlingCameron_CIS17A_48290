/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on November 27th 2022 4:00pm
 * Purpose:  Determine what day of the year it is
 */

//Libraries
#include "DayOfYear.h"
#include <iostream>
using namespace std;



//Execution Begins Here
int main(int argc, char** argv) {
    
    // variables declaration
    int dayNumber;
    // prompt the user for the day-number in a year
    cout << "Enter a day-number between 1 and 365: ";
    cin >> dayNumber;
    // verify whether the day-number is valid
    while (dayNumber < 1 || dayNumber > 365)
    {
    cout << "It is invalid entry. Enter any number between 1 and 365: ";
    cin >> dayNumber;
    } // end while
    //Create an object for DayOfYear class by calling its parameterized constructor.
    // create an object for DayOfYear class
    DayOfYear d(dayNumber);
    //Set the ending days of the months by calling setEndOfMonths function.
    // call the setEndOfMonths function
    d.setEndOfMonths();
    //Set the month names of the year by calling setEndOfMonths function.
    // call the setEndOfMonths function
    d.setMonthNames();
    //Display the result by calling print function.
    // call the print() function
    d.print();

    return 0;
    
    
}//End main