/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on October 16th, 2022 7:00pm
 * Purpose:  Capitalize all first words in sentence from one file and store in another file
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes



//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    string file1;
    string file2;
    char ch1;
    char ch2;
    char ch3;
    fstream inFile;
    
    // Get the input file name
    cout << "Enter the input file name: " << endl;
    cin >> file1;
    inFile.open(file1, ios::in);
    
    // Get the output file name
    cout << "Enter the output file name: " << endl;
    cin >> file2;
    ofstream outFile(file2);
    
    // Check if files are accessible
    if (inFile){
        
        inFile.get(ch1);
        ch2 = '!';
        ch3 = '!';
        
        while (inFile){
            
            if(( ch3 == '.' && ch2 == ' ') || ch2 == '!'){
                outFile.put(toupper(ch1));
            }//end if
            
            else{
                outFile.put(tolower(ch1));
            }//end else
            
            ch3 = ch2;
            ch2 = ch1;
            
            inFile.get(ch1);
            
        }//end while
    }// end if
    
    //Close files
    inFile.close();
    outFile.close();
    //Exit stage right!
    return 0;
}// end main