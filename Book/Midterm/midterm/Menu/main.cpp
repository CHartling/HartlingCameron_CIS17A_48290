/*
 * File:     main.cpp
 * Author:   Cameron Hartling
 * Purpose:  Menu using Functions, for the midterm
 */

 //System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"
//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;


    //Loop and Display menu
    do {
        menu();
        cin >> choice;

        //Process/Map inputs to outputs
        switch (choice) {
        case '1': {prob1(); break; }
        case '2': {prob2(); break; }
        case '3': {prob3(); break; }
        case '4': {prob4(); break; }
        case '5': {prob5(); break; }
        case '6': {prob6(); break; }
        case '7': {prob7(); break; }
        default: cout << "Exiting Menu" << endl;
        }
    } while (choice >= '1' && choice <= '7');

    //Exit stage right!
    return 0;
}//end main


//Menu
//Input:  -> None
//Output: -> No Return, Print menu
void menu() {
    //Display menu
    cout << endl << "Choose from the following Menu" << endl;
    cout << "Type 1 for Problem 1" << endl;
    cout << "Type 2 for Problem 2" << endl;
    cout << "Type 3 for Problem 3" << endl;
    cout << "Type 4 for Problem 4" << endl;
    cout << "Type 5 for Problem 5" << endl;
    cout << "Type 6 for Problem 6" << endl;
    cout << "Type 7 for Problem 7" << endl << endl;
}//end menu


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
void prob1() {
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
}//end prob1



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
void prob2() {
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
}//end prob2



//Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
void prob3() {
    cout << endl << "Problem 3" << endl;
    cout << "This is included in another program." << endl;
}//end pro3



//problem 4 functions
void encrypt() {
    //initialize variables
    unsigned int i;
    int size = 4;
    int* code = new int[size];
    string input;
    int temp;

    //get non-crypted data
    cout << "enter non-crypted data: ";
    cin >> input;

    //convert string into char array
    for (i = 0; i < size; i++) {
        code[i] = input[i] - '0';
    }//end for

    //encode the char array
    for (i = 0; i < size; i++) {
        code[i] = (code[i] + 6) % 8;
    }//end for
    //swap
    temp = code[0];
    code[0] = code[2];
    code[2] = temp;
    temp = code[1];
    code[1] = code[3];
    code[3] = temp;

    //output
    cout << "the encrypted code is " << code[0] << code[1] << code[2] << code[3] << endl << endl;

    //delete array
    delete [] code;
}//end encrypt

void decrypt() {
    //Initialize variables
    unsigned int i;
    int size = 4;
    int* code2 = new int[size];
    string input2;
    int temp;

    //Get encrypted data
    cout << "Enter non-crypted data: ";
    cin >> input2;

    cout << input2 << endl;

    //Convert string into char array
    for (i = 0; i < size; i++) {
        code2[i] = input2[i] - '0';
    }//end for
    
    //Decrypt the code
    //Swap
    temp = code2[0];
    code2[0] = code2[2];
    code2[2] = temp;
    temp = code2[1];
    code2[1] = code2[3];
    code2[3] = temp;

    for (i = 0; i < size; i++) {
        if (code2[i] == 6)code2[i] = 0;
        else if (code2[i] == 7)code2[i] = 1;
        else if (code2[i] == 0)code2[i] = 2;
        else if (code2[i] == 1)code2[i] = 3;
        else if (code2[i] == 2)code2[i] = 4;
        else if (code2[i] == 3)code2[i] = 5;
        else if (code2[i] == 4)code2[i] = 6;
        else if (code2[i] == 5)code2[i] = 7;
    }//end for



    ////Output
    cout << "The decrypted code is " << code2[0] << code2[1] << code2[2] << code2[3] << endl << endl;

    ////Delete array
    delete[] code2;
}//end decrypt

//Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
void prob4() {
    cout << endl << "Problem 4" << endl << endl;
    //Initialize variables
    int num = 1;

    //Ask for decrypt or encrypt
    while (num == 1 || num == 2) {
        cout << "Enter 1 for encryption or enter 2 for decryption: ";
        cin >> num;
        if (num == 1)encrypt();
        if (num == 2)decrypt();
    }//end while
}//end prob4



//Problem 5
//Input:  -> None
//Output: -> No Return, Output answers to questions
void prob5() {
    cout << endl << "Problem 5" << endl << endl;
    cout << "a. The largest n for the function n! that can be calculated for a byte variable is 5" << endl;
    cout << "b. The largest n for the function n! that can be calculated for a" << endl;
    cout << "short int:                    7" << endl;
    cout << "signed short int:             8" << endl;
    cout << "unsigned short int:           7" << endl;
    cout << "int:                          12" << endl;
    cout << "signed int:                   12" << endl;
    cout << "unsigned int:                 12" << endl;
    cout << "long int:                     20" << endl;
    cout << "signed long int:              20" << endl;
    cout << "unsigned long int:            20" << endl;
    cout << "long long int:                20" << endl;
    cout << "signed long long int:         20" << endl;
    cout << "unsigned long long int:       20" << endl;
    cout << "float:                        12" << endl;
    cout << "signed float:                 12" << endl;
    cout << "unsigned float:               12" << endl;
    cout << "double:                       20" << endl;
    cout << "signed double:                20" << endl;
    cout << "unsigned double:              20" << endl;
}//end prob5



//Problem 6
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
void prob6() {
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

}//end prob6



//Structs for Problem 7
struct Prime {
    unsigned short prime;
    unsigned short power;
};
struct Primes {
    unsigned char nPrimes;
    Prime* prime;
};
//Functions for Problem 7
Primes* factor(int num) {
    //Initialize
    Primes* prm = new Primes;
    prm->nPrimes = '0';
    int size = 10;
    prm->prime = new Prime[size];
    Prime test{2, 0};
    unsigned int i;
    
    //Populate with prime numbers
    prm->prime[0] = test;
    test = { 3, 0 };
    prm->prime[1] = test;
    test = { 5, 0 };
    prm->prime[2] = test;
    test = { 7, 0 };
    prm->prime[3] = test;
    test = { 11, 0 };
    prm->prime[4] = test;
    test = { 13, 0 };
    prm->prime[5] = test;
    test = { 17, 0 };
    prm->prime[6] = test;
    test = { 19, 0 };
    prm->prime[7] = test;
    test = { 23, 0 };
    prm->prime[8] = test;
    test = { 29, 0 };
    prm->prime[9] = test;

    for (i = 0; i < size; i++) {
        while ((num % (prm->prime[i]).prime) == 0) {
            num /= (prm->prime[i]).prime;
            (prm->prime[i]).power += 1;
        }//end while
    }//end for

    return prm;
}//end factor
void prntPrm(Primes* prm) {
    unsigned int i;

    cout << "Prime:        Power:" << endl;
    for (i = 0; i < 10; i++) {
        if ((prm->prime[i]).power != 0) {
            cout << (prm->prime[i]).prime << "         " << (prm->prime[i]).power << endl;
        }//end if
    }//end for

}//end prntPrm
//Problem 7
//Input:  -> None, Get integer from user
//Output: -> No Return
void prob7() {
    cout << endl << "Problem 7" << endl << endl;
    // Initialize variables
    int num;
    Primes* prm = new Primes;

    //Get num from user
    cout << "Pleas enter an integer: ";
    cin >> num;

    //Get prime numbers
    prm = factor(num);

    //Output
    cout << "The number: " << num << "and its primes: " << endl;
    prntPrm(prm);
    //Delete Dynamic Structures and Arrays
    delete(prm);
}//end prob7