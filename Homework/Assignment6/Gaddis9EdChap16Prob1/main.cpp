/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on December 9th 2022 9:00am
 * Purpose: Use a class to hold and change date formats, include exception classes
 */

#include <iostream>
using namespace std;

//Date Class
class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        //Constructor
        Date() {
            day=0;
            month=0;
            year=0;
        }
        
        // Invalid Day Exception class
        class InvalidDay{};
        
        //Invalid Month Exception class
        class InvalidMonth{};
        
        //setter functions
        void setDay(int );
        void setMonth(int);
        void setYear(int);
        
        //getter Functions
        int getDay();
        int getMonth();
        int getYear();
        
        //Display functions
        void printFormat1();
        void printFormat2();
        void printFormat3();
};

void Date::setDay(int d) {
    //Input validation
    if(d < 1 || d > 31) {
        throw InvalidDay();
    }
    else
        day = d;
}

void Date::setMonth(int m) {
    //Input validation
    if(m < 1 || m > 12) {
        throw InvalidMonth();
    }
    else
        month = m;
}

void Date::setYear(int y) {
    year = y;
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

void Date::printFormat1() {
    
}

void Date::printFormat2() {
    switch(month) {
        case 1: cout<<"January";
        break;
        case 2:cout<<"February";
        break;
        case 3:cout<<"march";
        break;
        case 4:cout<<"April";
        break;
        case 5:cout<<"May";
        break;
        case 6:cout<<"June";
        break;
        case 7:cout<<"July";
        break;
        case 8:cout<<"August";
        break;
        case 9:cout<<"September";
        break;
        case 10:cout<<"October";
        break;
        case 11:cout<<"November";
        break;
        case 12:cout<<"December";
        break;
    }
}

void Date::printFormat3() {
    switch(month) {
        case 1: cout<<"January";
        break;
        case 2:cout<<"February";
        break;
        case 3:cout<<"march";
        break;
        case 4:cout<<"April";
        break;
        case 5:cout<<"May";
        break;
        case 6:cout<<"June";
        break;
        case 7:cout<<"July";
        break;
        case 8:cout<<"August";
        break;
        case 9:cout<<"September";
        break;
        case 10:cout<<"October";
        break;
        case 11:cout<<"November";
        break;
        case 12:cout<<"December";
        break;
    }
}




int main(int argc, char** argv) {
    //create Date object
    Date d1;
    
    //Declare the variables
    int day,month,year;
    
    //Get date from user
    cout << "Enter the Day: ";
    cin >> day;
    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the year: ";
    cin >> year;
    
    
    // try block
    try {
        //call the setter methods
        d1.setDay(day);
        d1.setMonth(month);
        d1.setYear(year);
        //call the display methods
        d1.printFormat1();
        d1.printFormat2();
        d1.printFormat3();
    }
    // multiple catch blocks
    catch(Date::InvalidDay) {
        cout<<"Error! Please enter only days " << "numbers between (1-30/31) days";
    }

    catch(Date::InvalidMonth) {
        cout << "Error! Please enter only" << " month numbers between (1-12)" << endl;
    }

    
    
    return 0;
}

