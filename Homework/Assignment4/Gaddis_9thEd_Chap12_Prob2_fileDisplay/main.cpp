/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on October 16th, 2022 9:40pm
 * Purpose:  Display 24 lines of a program at a time
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
    unsigned int i;
    
    //Get file Name
    cout << "Enter File name:";
    cin >> fileName;
    inFile.open(fileName, ios::in);
    
    while (inFile){
        for (i = 0; i < 24; i++){
            if (!inFile){
                break;
            }//end if
            getline(inFile, input);
            cout << input << endl;
        }//end for
        cin >> input;
    }//end while
    
    
    //Close files
    inFile.close();
    //Exit stage right!
    return 0;
}// end main