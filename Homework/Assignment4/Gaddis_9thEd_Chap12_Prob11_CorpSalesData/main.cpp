/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on October 16th, 2022 9:00pm
 * Purpose:  Store Corporate Sales Data
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct corp{
    string division;
    double quart1, quart2, quart3, quart4;
};

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    corp east, west, north, south;
    fstream outFile;
    outFile.open("out.txt", ios::out);
    
    //East
    east.division = "East";
    cout << "East Division";
    cout << "\nEnter quarter 1 sales: $";
    cin >> east.quart1;
    cout << "\nEnter quarter 2 sales: $";
    cin >> east.quart2;
    cout << "\nEnter quarter 3 sales: $";
    cin >> east.quart3;
    cout << "\nEnter quarter 4 sales: $";
    cin >> east.quart4;
    
    outFile << east.division << endl;
    outFile << east.quart1 << endl;
    outFile << east.quart2 << endl;
    outFile << east.quart3 << endl;
    outFile << east.quart4 << endl << endl;
    
    //West
    west.division = "West";
    cout << "\nWest Division";
    cout << "\nEnter quarter 1 sales: $";
    cin >> west.quart1;
    cout << "\nEnter quarter 2 sales: $";
    cin >> west.quart2;
    cout << "\nEnter quarter 3 sales: $";
    cin >> west.quart3;
    cout << "\nEnter quarter 4 sales: $";
    cin >> west.quart4;
    
    outFile << west.division << endl;
    outFile << west.quart1 << endl;
    outFile << west.quart2 << endl;
    outFile << west.quart3 << endl;
    outFile << west.quart4 << endl << endl;
    
    //North
    north.division = "North";
    cout << "\nNorth Division";
    cout << "\nEnter quarter 1 sales: $";
    cin >> north.quart1;
    cout << "\nEnter quarter 2 sales: $";
    cin >> north.quart2;
    cout << "\nEnter quarter 3 sales: $";
    cin >> north.quart3;
    cout << "\nEnter quarter 4 sales: $";
    cin >> north.quart4;
    
    outFile << north.division << endl;
    outFile << north.quart1 << endl;
    outFile << north.quart2 << endl;
    outFile << north.quart3 << endl;
    outFile << north.quart4 << endl << endl;
    
    //South
    south.division = "South";
    cout << "\nSouth Division";
    cout << "\nEnter quarter 1 sales: $";
    cin >> south.quart1;
    cout << "\nEnter quarter 2 sales: $";
    cin >> south.quart2;
    cout << "\nEnter quarter 3 sales: $";
    cin >> south.quart3;
    cout << "\nEnter quarter 4 sales: $";
    cin >> south.quart4;
    
    outFile << south.division << endl;
    outFile << south.quart1 << endl;
    outFile << south.quart2 << endl;
    outFile << south.quart3 << endl;
    outFile << south.quart4 << endl << endl;
    
    //Close files
    outFile.close();
    
    //Exit stage right!
    return 0;
}// end main