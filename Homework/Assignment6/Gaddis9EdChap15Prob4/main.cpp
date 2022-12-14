/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on December 4th 2022 5:00pm
 * Purpose: Implement the MilTime class
 */

#include "MilTime.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    //Declare variables
    int mh;
    int ms;
    
    // Get user input
    cout <<"Enter the hours in military format: ";
    cin >> mh;
    cout << "Enter the seconds: ";
    cin >> ms;
    
    Miltime mt(mh, ms);
    cout << endl << "Time in military format: ";
    cout << mt.getHr() << ":" <<mt.getSec() << endl;
    cout << "Time in standard format: ";
    
    if(mt.getStandHr() <=12)
        cout << setw(2) << mt.getStandHr();
    else
        cout << setw(2) << mt.getStandHr() - 12;
    
    cout <<":" << mt.getMin() << ":" << mt.getSec();
    
    if(mt.getStandHr() < 12)
        cout << "AM"<< endl;
    else
        cout<<"PM" << endl;
    
    
    return 0;
}