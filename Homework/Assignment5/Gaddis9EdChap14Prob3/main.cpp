/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on November 27th 2022 4:00pm
 * Purpose:  Program to determine time off
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

class DayOfYear {
    
    private:
        int day_year;
        int day_month;
        string month_name;
    public:
        DayOfYear(int day);
        DayOfYear(string month, int days);
        void print();
        DayOfYear& operator ++();
        DayOfYear& operator --();
        
};

string month_names (int month_number) {
    string month_names[] = {"January","February","March", "April", "May", "June", "July", "August","September","October","November","December"};
    return month_names[month_number];
}

int month_days(int month_number) {
    int month_days[] {31,28,31,30,31,30,31,31,31,30,31,30,31};
    return month_days[month_number];
}


DayOfYear::DayOfYear(int day) {
    day_year = day;
    day_month = day_year;
    int i = 0;
    while (1)
    {
        if (day_month<= month_days(i))
        {
            month_name = month_names(i);
            break;
        }
        else{
            day_month = day_month - month_days(i++);
            i = i % 12;
        }
    }
}

DayOfYear::DayOfYear(string month, int day) {
    
    for (int i = 0; i<12; i++){
        if(month_names(i) == month) {
            if (day > 0 && day <= month month_days(i)) {
                month_name = month;
                day_month = day;
                day_year = 0;
                for (int j = 0; j<i; j++){
                    day_year += month_days (j);
                    day_year += day;
                }
            }
            
            else {
                cout << "Incorrect date";
                break;
            }
        }
    }
}

void DayOfYear::print()
{
    cout << "Day"<< day_year << "would be" << month_name << " " << day_month << endl;
}

DayOfYear& DayOfYear::operator++()
{
    day_month = day_month + 1;
    day_year = day_year + 1;
    for (int i = 0; i < 12; i++){
        if(month_name == month_names(i)) {
            if(day_month > month_days(i)) {
                day_month = 1;
                month_name = month_names((i+1) % 12);
                if (i== 11)
                    day_year = 1;
            }
            break;
        }
    }
    return *this;
}

DayOfYear& DayOfYear::operator--()
{
    day_month = day_month - 1;
    day_year = day_year - 1;
    for (int i = 0; i < 12; i--){
        if(month_name == month_names(i))
        {
            if(day_month <=0) {
                if (i == 0) {
                    day_month = month_days(11);
                    month_name = month_names(11);
                    int days_year = 365;
                }
                else {
                    day_month = month_days(i -1);
                    month_name = month_names(i -1);
                }
                break;
            }
        }
    }
    return *this;
}


//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize
    DayOfYear dof(2);
    DayOfYear dof2(32);
    DayOfYear dof3(365);
    
    
    cout << endl;
    cout << "Given day and converted day of the month:" << endl;
    dof.print();
    dof2.print();
    dof3.print();
    
    cout << endl << "Given month and converted day of the month:" << endl;
    dof.print("January", 2);
    dof2.print("February",1);
    dof3.print("December",31);
    
    cout << endl;
    
    dof.print();
    dof2.print();
    dof3.print();
    
    cout << endl;
    cout << "After post increment:" << endl;
    dof2.print();
    cout<< endl << "After post decrement:" << endl;
    dof3.print();
    dof= -- dof;
    cout << endl << "After decrement:" << endl;
    dof.print();
    dof.print();

    return 0;
}//End main