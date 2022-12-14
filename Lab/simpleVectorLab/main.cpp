/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on December 7th 2022 8:00am
 * Purpose: Simple Vector Lab
 */


//header file section
#include <iostream>
//#include
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Global Constants

//Function prototypes
void fillVec(SimpleVector<unsigned char> &);
void prntVec(SimpleVector<unsigned char> &,char);

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    unsigned int size = 200;
    SimpleVector<int> sv(size);

    // //Fill the Vector
    fillVec(sv);

    //Print the Vector
    printVec(sv, 10);

    //Copy the Vector
    SimpleVector<int> copysv(sv);

    //Print the Vector
    printVec(copysv, 10);
    
    
    
    SimpleVector<int> vec(10);

    fillVec(vec);
    cout << "\nVector Now: ";
    prntVec(vec, 12);

    cout << "\nPush Back 10\n";
    vec.push_back(10);
    cout << "Vector Now: ";
    prntVec(vec, 12);

    cout << "\nPush Front 12\n";
    vec.push_front(12);
    cout << "Vector Now: ";
    prntVec(vec, 12);

    cout << "\nPop Back\n";
    cout << "-> Pooped " << vec.pop_back() << endl;
    cout << "\nVector Now: ";
    prntVec(vec, 12);

    cout << "\nPop Front\n";
    cout << "-> Pooped " << vec.pop_front() << endl;
    cout << "\nVector Now: ";
    prntVec(vec, 12);

    return 0;
}

void prntVec(SimpleVector<unsigned char> &sv,char perLine){
    cout<<endl;
    for(unsigned char i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<unsigned char> &sv){
    for(unsigned char i=0;i<sv.size();i++){
        sv[i]=rand()%26+65;
    }
}