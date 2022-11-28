/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on November 27th 2022 1:00pm
 * Purpose:  Patient details
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;


class Patient {
    
    private:
        string nameF, nameM, nameL, address, city, state, phoneNum, emName, emPhone;
        int zip;

    public:
        //Set
        void setNameF (string nF);
        void setNameM (string nM);
        void setNameL (string nL);
        void setAddress(string ad);
        void setCity (string c);
        void setState (string s);
        void setPhoneNum(string ph);
        void setEmName (string en);
        void setEmPhone (string ep);
        void setZip (int z);
        
        //Get
        string getNameF() const;
        string getNameM() const;
        string getNameL() const;
        string getAddress() const;
        string getCity() const;
        string getState() const;
        string getPhoneNum() const;
        string getEmName() const;
        string getEmPhone() const;
        int getZip() const;
        
};


//Patient Class member functions
void Patient::setNameF(string nF) {
    nameF = nF;
}

void Patient::setNameM(string nM) {
    nameM = nM;
}

void Patient::setNameL(string nL) {
    nameL = nL;
}

void Patient::setAddress(string ad) {
    address = ad;
}

void Patient::setCity (string c) {
    city = c;
}

void Patient::setState (string s) {
    state = s;
}

void Patient::setPhoneNum(string ph) {
    phoneNum = ph;
}

void Patient::setEmName (string en){
    emName = en;
}

void Patient::setEmPhone (string ep){
    emPhone = ep;
}

void Patient::setZip (int z) {
    zip = z;
}

string Patient::getNameF() const{
    return nameF;
}

string Patient::getNameM() const{
    return nameM;
}

string Patient::getNameL() const{
    return nameL;
}

string Patient::getAddress() const{
    return address;
}

string Patient::getCity() const{
    return city;
}

string Patient::getState() const{
    return state;
}

string Patient::getPhoneNum() const{
    return phoneNum;
}

string Patient::getEmName() const{
    return emName;
}

string Patient::getEmPhone() const{
    return emPhone;
}

int Patient::getZip() const{
    return zip;
}

//Procedure class
class Procedure {
    
    private:
        string name, date, namePract;
        int charges;

    public:
        //Set
        void setName (string n);
        void setDate (string d);
        void setNamePract (string nP);
        void setCharges(float c);
        
        //Get
        string getName() const;
        string getDate() const;
        string getNamePract() const;
        float getCharges() const;
};

//Procedure member functions
void Procedure::setName (string n){
    name = n;
}

void Procedure::setDate (string d){
    date = d;
}

void Procedure::setNamePract (string nP){
    namePract = nP;
}

void Procedure::setCharges(float c){
    charges = c;
}

string Procedure::getName() const{
    return name;
}

string Procedure::getDate() const{
    return date;
}

string Procedure::getNamePract() const{
    return namePract;
}

float Procedure::getCharges() const{
    return charges;
}


int main() {
    
    //Declare variables
    Patient* pat;
    pat = new Patient();
    Procedure* proc1;
    proc1 = new Procedure();
    Procedure* proc2;
    proc2 = new Procedure();
    Procedure* proc3;
    proc3 = new Procedure();
    
    //Initialize sample Patient data
    pat->setNameF("Cameron");
    pat->setNameM("Blades");
    pat->setNameL("Hartling");
    pat->setAddress("123 Sesame ST");
    pat->setCity("Hollywood");
    pat->setState("California");
    pat->setZip(92374);
    pat->setPhoneNum("123467890");
    pat->setEmName("Cookie Monster");
    pat->setEmPhone("012346789");
    
    //Initialize Procedure data
    proc1->setName("Physical Exam");
    proc1->setDate("November 27, 2022");
    proc1->setNamePract("Dr. Irvine");
    proc1->setCharges(250.00);
    
    proc2->setName("X-ray");
    proc2->setDate("November 27, 2022");
    proc2->setNamePract("Dr. Jamison");
    proc2->setCharges(500.00);
    
    proc3->setName("Blood test");
    proc3->setDate("November 27, 2022");
    proc3->setNamePract("Dr. Smith");
    proc3->setCharges(200.00);
    
    //Outputs
    
    cout << "The patient's info is: " << endl;
    cout << "Name: " << pat->getNameF() << " " << pat->getNameM() << " " << pat->getNameL() << endl;
    cout << "Address: " << pat->getAddress() << endl;
    cout << "         " << pat->getCity() << ", " << pat->getState() << " " << pat->getZip() << endl;
    cout << "Phone Number: " << pat->getPhoneNum() << endl << endl;
    cout << "Emergency Contact Info:" << endl;
    cout << "Name: " << pat->getEmName() << endl;
    cout << "Phone: " << pat->getEmPhone() << endl << endl << endl;
    
    cout << "Procedure 1" << endl;
    cout << "Procedure Name: " << proc1->getName() << endl;
    cout << "Date: " << proc1->getDate() << endl;
    cout << "Practitioner: " << proc1->getNamePract() << endl;
    cout << "Charge: " << proc1->getCharges() << endl << endl;
    
    cout << "Procedure 2" << endl;
    cout << "Procedure Name: " << proc2->getName() << endl;
    cout << "Date: " << proc2->getDate() << endl;
    cout << "Practitioner: " << proc2->getNamePract() << endl;
    cout << "Charge: " << proc2->getCharges() << endl << endl;
    
    cout << "Procedure 3" << endl;
    cout << "Procedure Name: " << proc3->getName() << endl;
    cout << "Date: " << proc3->getDate() << endl;
    cout << "Practitioner: " << proc3->getNamePract() << endl;
    cout << "Charge: " << proc3->getCharges() << endl << endl;
    
    return 0;
}