/* 
 * File:   main.cpp
 * Author: Cameron Hartling
 * Created on October 5th, 2022 12:27pm
 * Purpose:  Budget Allocation and tracking
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct Budget {
    double housng, utill, houshldExp, trnsprt, food, med, insrnc, entrtnmnt, clthng, misc;
    
};//end Budget

Budget spent(){
    Budget monthlyBudget;
    
    cout << "Enter housing cost for the month:$" << endl;
    cin >> monthlyBudget.housng;
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> monthlyBudget.utill;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> monthlyBudget.houshldExp;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> monthlyBudget.trnsprt;
    cout << "Enter food cost for the month:$" << endl;
    cin >> monthlyBudget.food;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> monthlyBudget.med;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> monthlyBudget.insrnc;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> monthlyBudget.entrtnmnt;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> monthlyBudget.clthng;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> monthlyBudget.misc;
    
    return monthlyBudget;
}// end spent

void overUnder(Budget totalBudget, Budget monthlyBudget){
    double total = 0.00;
    
    if (totalBudget.housng < monthlyBudget.housng)
        cout << "Housing Over" << endl;
    else if (totalBudget.housng > monthlyBudget.housng)
        cout << "Housing Under" << endl;
    else
        cout << "Housing Even" << endl;
    
    if (totalBudget.utill < monthlyBudget.utill)
        cout << "Utilities Over" << endl;
    else if (totalBudget.utill > monthlyBudget.utill)
        cout << "Utilities Under" << endl;
    else
        cout << "Utilities Even" << endl;
    
    if (totalBudget.houshldExp < monthlyBudget.houshldExp)
        cout << "Household Expenses Over" << endl;
    else if (totalBudget.houshldExp > monthlyBudget.houshldExp)
        cout << "Household Expenses Under" << endl;
    else
        cout << "Household Expenses Even" << endl;
    
    if (totalBudget.trnsprt < monthlyBudget.trnsprt)
        cout << "Transportation Over" << endl;
    else if (totalBudget.trnsprt > monthlyBudget.trnsprt)
        cout << "Transportation Under" << endl;
    else
        cout << "Transportation Even" << endl;
    
    if (totalBudget.food < monthlyBudget.food)
        cout << "Food Over" << endl;
    else if (totalBudget.food > monthlyBudget.food)
        cout << "Food Under" << endl;
    else
        cout << "Food Even" << endl;
    
    if (totalBudget.med < monthlyBudget.med)
        cout << "Medical Over" << endl;
    else if (totalBudget.med > monthlyBudget.med)
        cout << "Medical Under" << endl;
    else
        cout << "Medical Even" << endl;
    
    if (totalBudget.insrnc < monthlyBudget.insrnc)
        cout << "Insurance Over" << endl;
    else if (totalBudget.insrnc > monthlyBudget.insrnc)
        cout << "Insurance Under" << endl;
    else
        cout << "Insurance Even" << endl;
    
    if (totalBudget.entrtnmnt < monthlyBudget.entrtnmnt)
        cout << "Entertainment Over" << endl;
    else if (totalBudget.entrtnmnt > monthlyBudget.entrtnmnt)
        cout << "Entertainment Under" << endl;
    else
        cout << "Entertainment Even" << endl;
    
    if (totalBudget.clthng < monthlyBudget.clthng)
        cout << "Clothing Over" << endl;
    else if (totalBudget.clthng > monthlyBudget.clthng)
        cout << "Clothing Under" << endl;
    else
        cout << "Clothing Even" << endl;
    
    if (totalBudget.misc < monthlyBudget.misc)
        cout << "Miscellaneous Over" << endl;
    else if (totalBudget.misc > monthlyBudget.misc)
        cout << "Miscellaneous Under" << endl;
    else
        cout << "Miscellaneous Even" << endl;
    
    
    total = (totalBudget.housng - monthlyBudget.housng) + (totalBudget.clthng - monthlyBudget.clthng) + (totalBudget.entrtnmnt - monthlyBudget.entrtnmnt) + (totalBudget.food - monthlyBudget.food) + (totalBudget.houshldExp - monthlyBudget.houshldExp) + (totalBudget.insrnc - monthlyBudget.insrnc) + (totalBudget.med - monthlyBudget.med) + (totalBudget.misc - monthlyBudget.misc) + (totalBudget.trnsprt - monthlyBudget.trnsprt) + (totalBudget.utill - monthlyBudget.utill);
    if (total < 0.0)
        cout << fixed << setprecision(2) << "You were $" << (-1 * total) << " over budget";
    else if(total > 0.0)
        cout << fixed << setprecision(2) << "You were $" << total << " under budget";
    else
        cout << "You were at the budget";
    
}// end overUnder

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    Budget totalBudget;
    Budget monthlyBudget;
    
    //Initialize Variables
    totalBudget = {500.00,150.00,65.00,50.00,250.00,30.00,100.00,150.00,75.00,50.00};
    
    //Send to functions
    monthlyBudget = spent();
    overUnder(totalBudget, monthlyBudget);
    
    
    //Exit stage right!
    return 0;
}