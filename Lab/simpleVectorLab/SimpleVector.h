/* 
 * File:   SimpleVector.h
 * Author: Cameron Hartling
 * Created on June 1st, 2021, 7:50 AM
 * Purpose:  To Test and Modify the Simple Vector
 * Code taken from SimpleVector.h by Dr. Lehr
 */

// SimpleVector class template
#ifndef __SIMPLEVECTOR_H__
#define __SIMPLEVECTOR_H__

#include <iostream>
// #include // Needed for bad_alloc exception
// #include // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector {
    private:
        T *aptr;                 // To point to the allocated array
        int arraySize;           // Number of elements in the array
        void memError();         // Handles memory allocation errors
        void subError();         // Handles subscripts out of range

    public:
        // Default constructor
        SimpleVector() {
            aptr = 0;
            arraySize = 0;
        }

        // Constructor declaration
        SimpleVector(int);

        // Copy constructor declaration
        SimpleVector(const SimpleVector &);

        // Destructor declaration
        ~SimpleVector();

        // Accessor to return the array size
        int size() const {
            return arraySize;
        }

        void push_back(T item);
        void push_front(T item);

        T pop_back();
        T pop_front();

        // Accessor to return a specific element
        T getElementAt(int position);

        // Overloaded [] operator declaration
        T &operator[](const int &);
};
//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it. *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s) {
    arraySize = s;
    // Allocate memory for the array.
    try {
        aptr = new T[s];
    }
    catch (bad_alloc) {
        memError();
    }

    // Initialize the array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    // Copy the array size.
    arraySize = obj.arraySize;

    // Allocate memory for the array.
    aptr = new T[arraySize];
    if (aptr == 0)
        memError();

    // Copy the elements of obj's array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class. *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector() {
    if (arraySize > 0)
        delete[] aptr;
}

template <class T>
void SimpleVector<T>::push_back(T item) {
    
    int newSize = arraySize + 1;

    T *temp = aptr;

    // Allocate memory for the array.
    try {
        aptr = new T[newSize];
    }
    catch (bad_alloc) {
        memError();
    }

    // Initialize the array.
    for (int i = 0; i < arraySize; ++i)
        aptr[i] = temp[i];

    // last new location set to item
    aptr[arraySize] = item;

    delete[] temp;

    arraySize = newSize;
}

template <class T>
void SimpleVector<T>::push_front(T item) {
    int newSize = arraySize + 1;

    T *temp = aptr;

    // Allocate memory for the array.
    try {
        aptr = new T[newSize];
    }
    catch (bad_alloc) {
        memError();
    }

    // Initialize the array.
    for (int i = 0; i < arraySize; ++i)
        aptr[i + 1] = temp[i];

    // assigning item to first location
    aptr[0] = item;

    delete[] temp;

    arraySize = newSize;
}

template <class T>
T SimpleVector<T>::pop_back() {
    T val = getElementAt(arraySize - 1);

    arraySize--;

    T *temp = aptr;

    // Allocate memory for the array.
    try {
        aptr = new T[arraySize];
    }
    catch (bad_alloc) {
        memError();
    }

    // Copying the array.
    for (int i = 0; i < arraySize; ++i)
        aptr[i] = temp[i];

    delete[] temp;

    return val;
}

template <class T>
T SimpleVector<T>::pop_front() {
    T val = getElementAt(0);

    arraySize--;

    T *temp = aptr;

    // Allocate memory for the array.
    try {
        aptr = new T[arraySize];
    }
    catch (bad_alloc) {
        memError();
    }

    // Copying the array.
    for (int i = 0; i < arraySize; ++i)
        aptr[i] = temp[i + 1];

    delete[] temp;

    return val;
}

//*******************************************************
// memError function. Displays an error message and *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError() {
    cout << "ERROR:Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError() {
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript. *
// This function returns the value stored at the sub- *
// script in the array. *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub) {
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element *
// in the array indexed by the subscript. *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub) {
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

#endif