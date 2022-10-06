/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on October 5th, 2022 8:30am
 * Purpose:  Store data on a company's division
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct Division{
    string name;
    double FQuartSale;
    double SQuartSale;
    double TQuartSale;
    double FoQuartSale;
    double TotalAnnSale;
    double AveQuartSale;
};
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Division east;
    Division west;
    Division north;
    Division south;
    unsigned int i;
    
    //Initialize Variables
    east.name = "East Division";
    west.name = "West Division";
    north.name = "North Division";
    south.name = "South Division";
    
    // North Division
    cout << "North\n";
    cout << "Enter first-quarter sales:\n";
    cin >> north.FQuartSale;
    cout << "Enter second-quarter sales:\n";
    cin >> north.SQuartSale;
    cout << "Enter third-quarter sales:\n";
    cin >> north.TQuartSale;
    cout << "Enter fourth-quarter sales:\n";
    cin >> north.FoQuartSale;
    
    //Calc
    north.TotalAnnSale = north.FQuartSale + north.SQuartSale + north.TQuartSale + north.FoQuartSale;
    north.AveQuartSale = north.TotalAnnSale / 4;
    
    //Final Output
    cout << fixed << setprecision(2) << "Total Annual sales:$" << north.TotalAnnSale << endl << "Average Quarterly Sales:$" << north.AveQuartSale << endl;
    
    // West Division
    cout << "West\n";
    cout << "Enter first-quarter sales:\n";
    cin >> west.FQuartSale;
    cout << "Enter second-quarter sales:\n";
    cin >> west.SQuartSale;
    cout << "Enter third-quarter sales:\n";
    cin >> west.TQuartSale;
    cout << "Enter fourth-quarter sales:\n";
    cin >> west.FoQuartSale;
    
    //Calc
    west.TotalAnnSale = west.FQuartSale + west.SQuartSale + west.TQuartSale + west.FoQuartSale;
    west.AveQuartSale = west.TotalAnnSale / 4;
    
    //Final Output
    cout << fixed << setprecision(2) << "Total Annual sales:$" << west.TotalAnnSale << endl << "Average Quarterly Sales:$" << west.AveQuartSale << endl;
    
    // East Division
    cout << "East\n";
    cout << "Enter first-quarter sales:\n";
    cin >> east.FQuartSale;
    cout << "Enter second-quarter sales:\n";
    cin >> east.SQuartSale;
    cout << "Enter third-quarter sales:\n";
    cin >> east.TQuartSale;
    cout << "Enter fourth-quarter sales:\n";
    cin >> east.FoQuartSale;
    
    //Calc
    east.TotalAnnSale = east.FQuartSale + east.SQuartSale + east.TQuartSale + east.FoQuartSale;
    east.AveQuartSale = east.TotalAnnSale / 4;
    
    //Final Output
    cout << fixed << setprecision(2) << "Total Annual sales:$" << east.TotalAnnSale << endl << "Average Quarterly Sales:$" << east.AveQuartSale << endl;
    
    // South Division
    cout << "South\n";
    cout << "Enter first-quarter sales:\n";
    cin >> south.FQuartSale;
    cout << "Enter second-quarter sales:\n";
    cin >> south.SQuartSale;
    cout << "Enter third-quarter sales:\n";
    cin >> south.TQuartSale;
    cout << "Enter fourth-quarter sales:\n";
    cin >> south.FoQuartSale;
    
    //Calc
    south.TotalAnnSale = south.FQuartSale + south.SQuartSale + south.TQuartSale + south.FoQuartSale;
    south.AveQuartSale = south.TotalAnnSale / 4;
    
    //Final Output
    cout << "Total Annual sales:$" << south.TotalAnnSale << endl << "Average Quarterly Sales:$" << south.AveQuartSale;
    
    //Exit stage right!
    return 0;
}