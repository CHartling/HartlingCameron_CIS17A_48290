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
int main(int argc, char** argv) {
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
    
    return 0;
}

