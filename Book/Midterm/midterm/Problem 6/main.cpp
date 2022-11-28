/*
 * File:     main.cpp
 * Author:   Cameron Hartling
 * Purpose:  Problem 6
 */

 //System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


int main(int argc, char** argv) {
    cout << endl << "Problem 6" << endl << endl;

    cout << "Part a" << endl;
    cout << "          Hex       Octal       Binary                  NASA Format" << endl;
    cout << "49.1875:  31.3      61.4        110001.0011             62200006" << endl;
    cout << "49.1875:  3.13      6.046       11.00010011             62300002" << endl;
    cout << "49.1875:  0.3       0.1463      0.0011(repeating)       19999900" << endl;
    cout << "Part b" << endl;

    cout << "Part c" << endl;
    cout << "NASA Format        Decimal" << endl;
    cout << "69999902           3.3" << endl;
    cout << "69999903           6.6" << endl;
    cout << "966667FF           " << endl;
    
    return 0;
}

