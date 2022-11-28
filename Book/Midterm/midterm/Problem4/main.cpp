/*
 * File:     main.cpp
 * Author:   Cameron Hartling
 * Purpose:  Problem 4
 */

 //System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


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
int main(int argc, char** argv) {
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
    return 0;
}

