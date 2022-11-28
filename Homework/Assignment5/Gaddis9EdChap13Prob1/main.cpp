/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on November 24th 2022 4:00pm
 * Purpose: 
 */

//#include "stdafx.h"
//header file section
#include <iostream>
//#include
using namespace std;

//Date class
class Date {
    
    private:
        int month;
        int day;
        int year;
        
    public:
        void setDate(int, int, int);
        void dateFormat1();
        void dateFormat2();
        void dateFormat3();
        string getMonth(int);
        Date(int, int, int);
        
};


//Default constructor with three parameters
Date::Date(int m, int d, int y) {

    month = m;
    day = d;
    year = y;

}


//Function to set the date variables
void Date::setDate(int m, int d, int y) {
    
    month = m;
    day = d;
    year = y;
    
}//end setDate


//Function to print date in 3/15/10 format
void Date::dateFormat1() {
    
    cout << "The date you have entered in format 1 is : " << month << "/" << day << "/" << year << endl;
    
}//end of dateFormat1


//Function to print date in March 15, 2010 format
void Date::dateFormat2() {
    
    string strMonth;
    //To convert the month to string format
    strMonth = getMonth(month);
    cout << "The date you have entered in format 2 is : " << strMonth << " " << day << ", " << year << endl;
    
}//end of dateFormat2


//Function to print date in 15 March 2010 format
void Date::dateFormat3() {
    
    string strMonth;
    //To convert the month to string format
    strMonth = getMonth(month);
    cout << "The date you have entered in format 3 is : " << day << " " << strMonth << " " << year << endl;
    
}//end of dateFormat1


//Function to convert the given number of month to month name
string Date::getMonth(int m) {
    
    string month;
    
    //Convert number of month to name of month
    if (m == 1)
        month = "January";
    else if (m == 2)
        month = "February";
    else if (m == 3)
        month = "March";
    else if (m == 4)
        month = "April";
    else if (m == 5)
        month = "May";
    else if (m == 6)
        month = "June";
    else if (m == 7)
        month = "July";
    else if (m == 8)
        month = "August";
    else if (m == 9)
        month = "September";
    else if (m == 10)
        month = "October";
    else if (m == 11)
        month = "November";
    else if (m == 12)
        month = "December";
    else
        month = "Invalid Month";
    
    return month;
}

//Function main
int main(int argc, char** argv) {
    
    int monthIn, dayIn, yearIn;
    
    //Invoking default constructor
    Date inputDate(1, 1, 2000);
    
    //Read data from the user
    cout << "Enter date to display in different formats." << endl;
    cout << "Enter the month of the date : ";
    cin >> monthIn;
    cout << "Enter the day of the date : ";
    cin >> dayIn;
    cout << "Enter the year of the date : ";
    cin >> yearIn;
    cout << endl;
    
    //Validate date entered
    if (monthIn<1 || monthIn>12 || dayIn<1 || dayIn>31 || yearIn<0 || yearIn>2022) {
    
        //default date stored by the constructor
        cout << endl << "The date you entered is invalid." << endl;
        
    }
    else {

        //To set the data input by the user and display
        inputDate.setDate(monthIn, dayIn, yearIn);
        inputDate.dateFormat1();
        inputDate.dateFormat2();
        inputDate.dateFormat3();

    }

    
    return 0;
}//end of main