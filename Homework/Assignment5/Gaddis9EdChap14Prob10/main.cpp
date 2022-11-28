/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on November 27th 2022 4:00pm
 * Purpose:  Sales records for a corporation
 */

//System Libraries
#include <iostream>
using namespace std;

class DivSales
{
    private:
        int quarterSales[4];
        static double totalSales;
    public:
        void add(int, int, int, int);
        int sales(int);
        static double getValue() {
            return totalSales;
        }
};


void DivSales::add(int s1, int s2, int s3, int s4) {
    quarterSales[0] = s1;
    quarterSales[1] = s2;
    quarterSales[2] = s3;
    quarterSales[3] = s4;
    totalSales = totalSales + s1 + s2 + s3 + s4;
}

int DivSales:: sales(int n) {
    int value = quarterSales[n];
    return value;
}

//error method
void error() {
    cout << "You have entered a negative value.";
}

double DivSales::totalSales = 0.00;

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare variables
    DivSales ds[6];
    int i, j;
    
    for (i = 0; i<6; i++)
    {
        int s1, s2, s3, s4;
        //Get sales data from the user
        cout << "\nEnter Sales of Division: " << i + 1 << endl;
        cout << "Enter Q1 Sales: ";
        cin >> s1;
        while(s1 < 0){
            error();
            cout << "Enter Q1 Sales: ";
            cin >> s1;
        }
        cout << "Enter Q2 Sales: ";
        cin >> s2;
        while(s2 < 0){
            error();
            cout << "Enter Q2 Sales: ";
            cin >> s2;
        }
        cout << "Enter Q3 Sales: ";
        cin >> s3;
        while(s3 < 0){
            error();
            cout << "Enter Q3 Sales: ";
            cin >> s3;
        }
        cout << "Enter Q4 Sales: ";
        cin >> s4;
        while(s4 < 0){
            error();
            cout << "Enter Q4 Sales: ";
            cin >> s4;
        }
        ds[i].add(s1, s2, s3, s4);
    }
    
    cout << "-----------------------------------\n";
    cout << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4"
    << endl;
    cout << "-----------------------------------\n";
    for (i = 0; i<6; i++) {
        cout << "Div " << i + 1<<"|";
        for (j = 0; j<4; j++)
        cout << "\t" << ds[i].sales(j);
        cout << endl;
    }
    
    cout << "-----------------------------------\n";
    cout << "\n Total All Division Sales for the Year: " << ds[0].getValue()<< endl;

    return 0;
}//End main