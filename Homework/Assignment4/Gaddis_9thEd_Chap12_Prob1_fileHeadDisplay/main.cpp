/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on October 16th, 2022 9:20pm
 * Purpose:  Display the first 10 lines of a program
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes



//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    string fileName;
    string input;
    fstream inFile;
    int count = 0;
    
    //Get file Name
    cout << "Enter File name:";
    cin >> fileName;
    inFile.open(fileName, ios::in);
    
    do{
        count++;
        getline(inFile, input);
        cout << input << endl;
        
        if (!inFile){
            cout << "Entire file has been displayed.";
            break;
        }
    }while(inFile && count < 10);
    
    
    //Close files
    inFile.close();
    //Exit stage right!
    return 0;
}// end main