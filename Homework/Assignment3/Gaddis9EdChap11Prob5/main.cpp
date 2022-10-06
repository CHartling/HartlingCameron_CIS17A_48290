/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on Octorber 5th 2022 9:55am
 * Purpose:  Store data on month's weather
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    enum Months {January,Feburary,March,April,May,June,July,August,September,October,November,December};
    const int NUM_MONTHS = 12;
    float rainFall[NUM_MONTHS],highTemp[NUM_MONTHS],lowTemp[NUM_MONTHS];
    float aveRainFall,aveTemp,highTemps,lowTemps;
    Months month;
    //Initialize Variables
    highTemps =- 1000;
    lowTemps = 1000;
    aveRainFall = aveTemp = 0;
    //Process or map Inputs to Outputs
    for (month = January; month <= December; month = static_cast<Months>(month + 1)){
        while(cin >> rainFall[month]){
            //Rainfall
            cout << "Enter the total rainfall for the month:" << endl;
            aveRainFall += rainFall[month];
            
            //High Temp
            cout << "Enter the high temp:" << endl;
            cin >> highTemp[month];
            aveTemp += highTemp[month];
            if (highTemp[month] > highTemps)
                highTemps = highTemp[month];
            
            //Low Temp
            cout << "Enter the low temp:" << endl;
            cin >> lowTemp[month];
            aveTemp += lowTemp[month];
            if (lowTemp[month] < lowTemps)
                lowTemps = lowTemp[month];
        }
    }
    //Calculate Averages
    aveRainFall = (aveRainFall * 2) / month;
    aveTemp = aveTemp / month;
    //Display Outputs
    cout << "Average monthly rainfall:" << fixed << setprecision(2) << aveRainFall << endl;
    cout << "High Temp:" << fixed << setprecision(0) << highTemps << endl;
    cout << "Low Temp:" << fixed << setprecision(0) << lowTemps << endl;
    cout << "Average Temp:" << fixed << setprecision(1) << aveTemp;
    //Exit stage right!
    return 0;
}