/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on December 4th 2022 4:00pm
 * Purpose: Program that stores employee data
 */


#include <iostream>
#include <string>
using namespace std;
class Employee {
    private:
        string EmpName;
        int EmpNumber;
        string Hiredate;
    public: 
        Employee () {
            EmpName = " ";
            EmpNumber = 0;
            Hiredate= " ";
        }
        Employee (string name, int number,string date) {
            EmpName = name;
            EmpNumber = number;
            Hiredate= date;
        }
        void Employee::setEmpName (string str);
        void Employee::setEmpNumber(int num);
        void Employee::setHireDate(string date);
        string Employee::getEmpName();
        int Employee::getEmpNumber();
        string Employee::getHireDate();
};

void Employee::setEmpName (string str) {
    EmpName = str;
}

void Employee::setEmpNumber(int num) {
    EmpNumber = num;
}

void Employee::setHireDate(string date) {
    Hiredate = date;
}

string Employee::getEmpName() {
    return EmpName;
}

int Employee::getEmpNumber() {
    return EmpNumber;
}

string Employee::getHireDate() {
    return Hiredate;
}

class ProductionWorker:public Employee {
    private: 
        int shift;
        double hrPay;
    public: 
        ProductionWorker()
        {
            shift = 0;
            hrPay = 0;
        }
        void setShift(int sh);
        void setHrPay(double pay);
        int getShift();
        double getHrPay();
};

void ProductionWorker::setShift(int sh) {
    shift = sh;
}

void ProductionWorker::setHrPay(double pay) {
    hrPay = pay;
}

int ProductionWorker::getShift() {
    return shift;
}

double ProductionWorker::getHrPay() {
    return hrPay;
}

int main(int argc, char** argv) {
    int shift;
    double pay;
    
    cout<<"Enter shift(1 = Day, 2 = Night): ";
    cin>> shift;
    cout<< "Enter hourly pay: ";
    cin>> pay;
    
    ProductionWorker emp(shift,pay);
    emp->setEmpName("Winston");
    emp.setEmpNumber(562);
    emp.setHireDate(" June:11");
    cout << "Employee Details: " << endl << endl;
    cout << "Employee Name: " << emp.getEmpName() << endl;
    cout << "Employee Number: " << emp.getEmpNumber() << endl;
    cout << "Employee Hire Date: " << emp.getHireDate() << endl;
    cout << "Employee Shift: " << emp.getShift() << endl;
    cout << "EmployeeHourlyPay: " << emp.getHrPay() << endl;
    
    
    return 0;
}