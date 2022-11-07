/*
 * File:     main.cpp
 * Author:   Cameron Hartling
 * Purpose:  Problem 2
 */

 //System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

//Problem 2 Roman Numeral conversion
//Author: Dr. Mark E. Lehr
//Modified to fit problem 2 usage by: Cameron Hartling
string RtoAConv(unsigned short n2Cnvrt) {
    string numberE = "";
    
    if (n2Cnvrt >= 1 && n2Cnvrt <= 3000) {
        //Process or map Inputs to Outputs
            //Determine 1000's, 100's, 10's, 1's
        unsigned char n1000s, n100s, n10s, n1s;
        n1000s = n2Cnvrt / 1000;   //Shift 3 places to the left
        n100s = n2Cnvrt % 1000 / 100;//Remainder of division of 1000 then shift 2 left
        n10s = n2Cnvrt % 100 / 10;   //Remainder of division of 100 then shift 1 left
        n1s = n2Cnvrt % 10;        //Remainder of division by 10

        //Output the number of 1000's in Roman Numerals
        if (n1000s == 3)numberE = numberE + "Three Thousand ";
        if (n1000s == 2)numberE = numberE + "Two Thousand ";
        if (n1000s == 1)numberE = numberE + "One Thousand ";
        

        //Output the number of 100's
        if (n100s == 9)numberE = numberE + "Nine Hundred ";
        else if (n100s == 8)numberE = numberE + "Eight Hundred ";
        else if (n100s == 7)numberE = numberE + "Seven Hundred ";
        else if (n100s == 6)numberE = numberE + "Six Hundred ";
        else if (n100s == 5)numberE = numberE + "Five Hundred ";
        else if (n100s == 4)numberE = numberE + "Four Hundred ";
        else if (n100s == 3)numberE = numberE + "Three Hundred ";
        else if (n100s == 2)numberE = numberE + "Two Hundred ";
        else if (n100s == 1)numberE = numberE + "One Hundred ";
        

        //Output the number of 10's
        if (n10s == 9)numberE = numberE + "Ninty ";
        else if (n10s == 8)numberE = numberE + "Eighty ";
        else if (n10s == 7)numberE = numberE + "Seventy ";
        else if (n10s == 6)numberE = numberE + "Sixty ";
        else if (n10s == 5)numberE = numberE + "Fifty ";
        else if (n10s == 4)numberE = numberE + "Fourty ";
        else if (n10s == 3)numberE = numberE + "Thirty ";
        else if (n10s == 2)numberE = numberE + "Twenty ";
        

        //Output the number of 1's
        if (n10s == 1) {
            if (n1s == 9)numberE = numberE + "Nineteen";
            if (n1s == 8)numberE = numberE + "Eighteen";
            if (n1s == 7)numberE = numberE + "Seventeen";
            if (n1s == 6)numberE = numberE + "Sixteen";
            if (n1s == 5)numberE = numberE + "Fifteen";
            if (n1s == 4)numberE = numberE + "Fourteen";
            if (n1s == 3)numberE = numberE + "Thirteen";
            if (n1s == 2)numberE = numberE + "Twelve";
            if (n1s == 1)numberE = numberE + "Eleven";
        }
        else {
            if (n1s == 9)numberE = numberE + "Nine";
            if (n1s == 8)numberE = numberE + "Eight";
            if (n1s == 7)numberE = numberE + "Seven";
            if (n1s == 6)numberE = numberE + "Six";
            if (n1s == 5)numberE = numberE + "Five";
            if (n1s == 4)numberE = numberE + "Four";
            if (n1s == 3)numberE = numberE + "Three";
            if (n1s == 2)numberE = numberE + "Two";
            if (n1s == 1)numberE = numberE + "One";
        }
    }

    return numberE;
}//end RtoAConv
//Proble 2 Structures
struct Emp {
    string comp, address, name, amountE;
    short amountN, hours, payR;
};
//Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units

int main(int argc, char** argv) {
    cout << endl << "Problem 2" << endl << endl;
    // Initialize variables
    unsigned int i;
    int size;
    int pay = 0;
    string comp, addr, nm;

    //Get number of employees
    cout << "Enter the number of employees: ";
    cin >> size;
    Emp* payList = new Emp[size];

    //Get company name and address
    cout << "Enter company name: ";
    cin >> comp;
    cout << "Enter company address: ";
    cin >> addr;

    //Add company info to each employee
    for (i = 0; i < size; i++) {
        payList[i].comp = comp;
        payList[i].address = addr;
    }//end for

    //Get the name and pay of each employee
    for (i = 0; i < size; i++) {
        cout << "Enter the employees name: ";
        cin >> nm;
        payList[i].name = nm;
        cout << "Enter the employees hours: ";
        cin >> payList[i].hours;
        while (payList[i].hours <= 0) {
            cout << "Enter the employees hours: ";
            cin >> payList[i].hours;
        }//end while
        cout << "Enter the employees pay rate: ";
        cin >> payList[i].payR;
        while (payList[i].payR <= 0) {
            cout << "Enter the employees hours: ";
            cin >> payList[i].payR;
        }//end while

        //Calc Pay in numeric and english
        payList[i].amountN = payList[i].hours * payList[i].payR;
        payList[i].amountE = RtoAConv(payList[i].amountN);
    }//end while

    //Outputs
    cout << endl << endl << "-------Paychecks--------" << endl << endl;
    for (i = 0; i < size; i++) {
        cout << payList[i].comp << endl;
        cout << payList[i].address << endl;
        cout << "Name: " << payList[i].name << "     Amount: $" << payList[i].amountN << endl;
        cout << "Amount: " << payList[i].amountE << endl;
        cout << "Signature: " << endl << endl;
    }//end for

    //Delete dynamic arrays
    delete[] payList;
    return 0;
}

