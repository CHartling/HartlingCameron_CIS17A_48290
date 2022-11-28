#include "DayOfYear.h"
#include <iostream>
using namespace std;

//Initialize the static variables.
// definition of static variables
string DayOfYear::dayMonth = "";
int DayOfYear::restDays = 0;


// constructor definition
DayOfYear::DayOfYear(int d) {
    day = d;
}

// setEndOfMonths function definition
void DayOfYear::setEndOfMonths() {
    endOfMonth[0] = 0;
    endOfMonth[1] = 31;
    endOfMonth[2] = 59;
    endOfMonth[3] = 90;
    endOfMonth[4] = 120;
    endOfMonth[5] = 151;
    endOfMonth[6] = 181;
    endOfMonth[7] = 212;
    endOfMonth[8] = 243;
    endOfMonth[9] = 273;
    endOfMonth[10] = 304;
    endOfMonth[11] = 334;
    endOfMonth[12] = 365;
}

// setMonthNames function definition
void DayOfYear::setMonthNames() {
    months[0] = "January";
    months[1] = "February";
    months[2] = "March";
    months[3] = "April";
    months[4] = "May";
    months[5] = "June";
    months[6] = "July";
    months[7] = "August";
    months[8] = "September";
    months[9] = "October";
    months[10] = "November";
    months[11] = "December";
}

// print function definition
void DayOfYear::print() {
    
    int month = 0;
    while (endOfMonth[month] < day){
        month++;
    }
    
    dayMonth += months[month - 1];
    restDays += day - endOfMonth[month - 1];
    cout << endl << "The corresponding day is: " << dayMonth << " " << restDays << endl;
}