/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on December 9th 2022 9:00am
 * Purpose: Implement the MilTime class
 */

#include "MilTime.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    //Declare variables
    int hours,sec;
    Miltime t1(0,0);
    
    // Get hour and seconds from user
    cout << "Enter the time in Military Hours:";
    cin >> hours;
    cout << "Enter the Military seconds:";
    cin >> sec;
    
    try {
        //Call the function to setTime
        t1.setTime(hours,sec);

        //Display the Time
        cout << "Military Format:" << endl;

        if(t1.getHr() / 12 == 1) {
            if (t1.getMin() == 0) {
            cout << "0 Minutes";
            }
            
            else
            cout << t1.getMin() << "Minutes";
        }
        else {
            if(t1.getMin() == 0) {
                cout << "";
            }
            
            else
                cout << "";
        }
    }
    
    //catch the exception
    catch(Miltime::BadHour) {
        cout << "Error! Bad hours(Enter only 0-2359) " << endl;
    }
    catch(Miltime::BadSeconds) {
        cout << "Error Bad Seconds (Enter only 0-:59) " << endl;
    }
    
    return 0;
}