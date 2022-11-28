/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on November 27th 2022 5:00pm
 * Purpose:  Dollar integer to english
 */

#include <iostream>
#include <string>
#include<math.h>
using namespace std;

class Numbers{
    private:
        int number;
        string lessThan20[20] = {"Zero","One","Two","Three","Four","Five","Six","Seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
        
    public:
        Numbers (int x) {
        number = x;
        }
        
        void print();
};

void Numbers::print(){
    
    unsigned char n1000s,n100s,n10s,n1s;
    n1000s = number / 1000;   //1000s place
    n100s = number % 1000 / 100;//100s place
    n10s = number % 100 / 10;   //10s place
    n1s = number % 10;        //1s place
    
    //Output 1000's
    if (n1000s > 0){
        cout << (n1000s==9?"Nine ": n1000s==8?"Eight ": n1000s==7?"Seven ": n1000s==6?"Six ": n1000s==5?"Five ": n1000s==4?"Four ": n1000s==3?"Three ": n1000s==2?"Two ": n1000s==1?"One ");
        cout << "Hundred";
    }
    
    //Output 100's
    if (n100s > 0){
        cout << (n100s==9?"Nine ": n100s==8?"Eight ": n100s==7?"Seven ": n100s==6?"Six ": n100s==5?"Five ": n100s==4?"Four ": n100s==3?"Three ": n100s==2?"Two ": n100s==1?"One ");
        cout << "Hundred";
    }
    
    //Output under 100's
    if (n10s < 20){
        if(n10s==1){
            if(n1s==9)cout << lessThan20[20];
            else if(n1s==8)cout << lessThan20[19];
            else if(n1s==7)cout << lessThan20[18];
            else if(n1s==6)cout << lessThan20[17];
            else if(n1s==5)cout << lessThan20[16];
            else if(n1s==4)cout << lessThan20[15];
            else if(n1s==3)cout << lessThan20[14];
            else if(n1s==2)cout << lessThan20[13];
            else if(n1s==1)cout << lessThan20[12];
            else if(n1s==0)cout << lessThan20[11];
        }
        else if(n10s==0){
            if(n1s==9)cout << lessThan20[9];
            else if(n1s==8)cout << lessThan20[8];
            else if(n1s==7)cout << lessThan20[7];
            else if(n1s==6)cout << lessThan20[6];
            else if(n1s==5)cout << lessThan20[5];
            else if(n1s==4)cout << lessThan20[4];
            else if(n1s==3)cout << lessThan20[3];
            else if(n1s==2)cout << lessThan20[2];
            else if(n1s==1)cout << lessThan20[1];
            else if(n1s==0)cout << lessThan20[0];
        }
        
    }
    else{
        if(n10s==9)cout<<"Ninety ";
        else if(n10s==8)cout<<"Eighty ";
        else if(n10s==7)cout<<"Seventy ";
        else if(n10s==6)cout<<"Sixty ";
        else if(n10s==5)cout<<"Fifty ";
        else if(n10s==4)cout<<"Fourty ";
        else if(n10s==3)cout<<"Thirty ";
        else if(n10s==2)cout<<"Twenty ";
        
        if(n1s==9)cout<<"Nine ";
        else if(n1s==8)cout<<"Eight ";
        else if(n1s==7)cout<<"Seven ";
        else if(n1s==6)cout<<"Six ";
        else if(n1s==5)cout<<"Five ";
        else if(n1s==4)cout<<"Four ";
        else if(n1s==3)cout<<"Three ";
        else if(n1s==2)cout<<"Two ";
        else if(n1s==1)cout<<"One ";
    }
    
}



//Execution Begins Here
int main(int argc, char** argv) {
    //Declare
    int num;
    
    //Initialize
    cout << "Enter a dollar amount: ";
    cin >> num;
    Numbers number(num);
    
    //Output
    cout << endl << num << "is: $";
    number->print();
    
    return 0;
}//End main