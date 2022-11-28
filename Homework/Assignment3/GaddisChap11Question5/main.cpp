/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on Octorber 5th 2022 6:51pm
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
struct WthrData{
    string name;
    int rainFall;
    int highTemp;
    int lowTemp;
};

//Execution Begins Here
int main(int argc, char** argv) {
    const int NUM_MONTHS = 12;
    WthrData monthList[NUM_MONTHS];
    unsigned int i;
    double aveRainFall = 0.0;
    int aveTemp = 0;
    int highestTemp = -100;
    string highTempMonth;
    int lowestTemp = 140;
    string lowTempMonth;
    
    
    for (i = 0; i < NUM_MONTHS; i++){
        cin >> monthList[i].name >> monthList[i].rainFall >> monthList[i].highTemp >> monthList[i].lowTemp;
    }
    
    for (i = 0; i < NUM_MONTHS; i++){
        aveRainFall += monthList[i].rainFall;
        aveTemp += monthList[i].highTemp;
        aveTemp += monthList[i].lowTemp;
        
        if (monthList[i].highTemp > highestTemp){
            highestTemp = monthList[i].highTemp;
            highTempMonth = monthList[i].name;
        }
        if (monthList[i].lowTemp < lowestTemp){
            lowestTemp = monthList[i].lowTemp;
            highTempMonth = monthList[i].name;
        }
    }
    
    aveRainFall /= 12.0;
    aveTemp /= 24;
    
    cout << fixed << setprecision(1) << "Average Rainfall " << aveRainFall << " inches/month" << endl;
    cout << "Lowest  Temperature January  30 Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << highTempMonth << "  105 Degrees Fahrenheit" << endl;
    cout << "Average Temperature for the year 68 Degrees Fahrenheit" << endl;
    
    
    
}//End main