/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on November 27th 2022 4:00pm
 * Purpose:  Dimensions fo a yard
 */

//System Libraries
#include <iostream>
using namespace std;

class Yard
{
    private:
        int length, width;
    public:
        Yard(){
            length = 0; width = 0;
        }
        
        void setLength(int len) {
            length = len;
        }
        
        void setWidth(int w) {
            width = w;
        }
        
        int getArea(){
            return (length * width);
        }
};



int main(int argc, char** argv) {
    
    //Declare Variables
    int len, wid;
    
    //Initialize Yard
    Yard* lawn;
    lawn = new Yard();
    
    
    cout <<"Enter the length and width of each yard." << endl;
    cout << "Length: ";
    cin >> len;
    lawn->setLength(len);
    cout<< "width: ";
    cin >> wid;
    lawn->setWidth(wid);
    
    cout << "The area of the yard is: " << lawn->getArea() << endl;
    
    return 0;
}

