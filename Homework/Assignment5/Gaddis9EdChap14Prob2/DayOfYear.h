/* 
 * File: DayOfYear.h
 * Author: Cameron Hartling
 * Created on November 27, 2022, 7:28 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
// Header files section
#include <iostream>
using namespace std;

// DayOfYear class
class DayOfYear
{
    
    private:
        int day;
        string months[12];
        int endOfMonth[13];
        static string dayMonth;
        static int restDays;
    
    public:
        DayOfYear(int d);
        void print();
        void setEndOfMonths();
        void setMonthNames();
}; // end if DayOfYear class

#endif