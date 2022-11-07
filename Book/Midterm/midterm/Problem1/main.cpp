/*
 * File:     main.cpp
 * Author:   Cameron Hartling
 * Purpose:  Problem 1
 */

 //System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

// Struct for customer data
struct Customer {
    string accNum, name, address;
    float balance;
    float* checks;
    float* deposits;
};
//Problem 1
//Input:  -> None, data on customer bank account
//Output: -> No Return, Print Customer Struct data
int main(int argc, char** argv) {
    cout << endl << "Problem 1" << endl << endl;
    //Initialize variables
    unsigned int i;
    string tempStr;
    int sizeC = 0;
    int sizeD = 0;
    float newBalance;
    Customer* person = new Customer;

    //Ask for information
    //Account Number
    cout << "Input Account Number: ";
        cin >> tempStr;
    while (tempStr.length() != 5) {
        cout << "Please enter a valid account number: " << endl;
        cin >> tempStr;
    }
    person->accNum = tempStr;
    //Name of Customer
    cout << "Input your name: ";
    cin >> person->name;

    //Address of customer
    cout << "Input address: ";
    cin >> person->address;

    //Balance at the beginning of the month
    cout << "What is your balance at the beginning of the month: $";
    cin >> person->balance;

    //Get check values
    cout << "How many checks were written this month: ";
    cin >> sizeC;
    person->checks = new float[sizeC];
    for (i = 0; i < sizeC; i++) {
        cout << "Enter check amount: $";
        cin >> person->checks[i];
    }//end for

    //Deposits
    cout << "How many deposits were made this month: ";
    cin >> sizeD;
    person->deposits = new float[sizeD];
    for (i = 0; i < sizeD; i++) {
        cout << "Enter deposit amount: $";
        cin >> person->deposits[i];
    }//end for

    //Calc new deposit
    newBalance = person->balance;
    // Add deposits
    for (i = 0; i < sizeD; i++) {
        newBalance += person->deposits[i];
    }//end for
    // Subtract checks
    for (i = 0; i < sizeC; i++) {
        newBalance += person->checks[i];
    }//end for
    //Outputs
    cout << "Printing Info for: " << person->name << endl;
    cout << "Account Number:    " << person->accNum << endl;
    cout << "Address:           " << person->address << endl;
    cout << "Beginning balance: " << person->balance << endl << endl;
    cout << "Checks:" << endl;
    for (i = 0; i < sizeC; i++) {
        cout << "$" << person->checks[i] << endl;
    }//end for
    cout << endl << "Deposits:" << endl;
    for (i = 0; i < sizeD; i++) {
        cout << "$" << person->deposits[i] << endl;
    }//end for
    if (newBalance >= 0) {
        cout << "The new balance is: $" << newBalance << endl;
    }//end if
    else {
        cout << "The account has been overdrawn. A $35 fee has been charged. The new balance is: $" << newBalance << endl;
    }//end else


    //Delete Dynamic Structures and Arrays
    delete[] person->checks;
    delete[] person->deposits;
    delete(person);
    return 0;
}