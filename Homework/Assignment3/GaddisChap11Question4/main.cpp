/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on Octorber 5th 2022 9:55am
 * Purpose:  Drink Machine Simulator
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct item{
    string name;
    float cost;
    int num;
};

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int nums = 5;
    struct item drink[nums];
    int profit = 0;
    
    //Initialize Variables
    drink[0].name = "Cola";
    drink[1].name = "Root Beer";
    drink[2].name = "Lemon-Lime";
    drink[3].name = "Grape Soda";
    drink[4].name = "Cream Soda";
    
    drink[0].cost = 75;
    drink[1].cost = 75;
    drink[2].cost = 75;
    drink[3].cost = 80;
    drink[4].cost = 80;
    
    drink[0].num = 20;
    drink[1].num = 20;
    drink[2].num = 20;
    drink[3].num = 20;
    drink[4].num = 20;
    
    int exit = 1;
    while(exit > 0){
        int i;
        for(i = 0; i < 5; i++){
            string hold = drink[i].name;
            int length = hold.length();
            int actLength = 11 - length;
            cout << drink[i].name;
            for(int startLength = 0; actLength > startLength; actLength--){
                cout << " "; //Makes the spacing correct
            }
            cout << drink[i].cost <<"  " << drink[i].num << endl;
        }
        cout << "Quit\n";
        
        string choiceValue;
        int choiceNum;
        int choiceCheck = 0;
        while(choiceCheck == 0){
            getline(cin, choiceValue);
            if(choiceValue == drink[0].name){
                if(drink[0].num != 0){
                    choiceNum = 0;
                    choiceCheck = 1;
                    drink[0].num--;
                }
                else
                    cout <<"SOLD OUT\n";
            }
            else if(choiceValue == drink[1].name){
                if(drink[0].num != 0){
                    choiceNum = 1;
                    choiceCheck = 1;
                    drink[1].num--;
                }
                else
                    cout <<"SOLD OUT\n";
            }
            else if(choiceValue == drink[2].name){
                if(drink[0].num != 0){
                    choiceNum = 2;
                    choiceCheck = 1;
                    drink[2].num--;
                }
                else
                    cout <<"SOLD OUT\n";
                
            }
            else if(choiceValue == drink[3].name){
                if(drink[0].num != 0){
                    choiceNum = 3;
                    choiceCheck = 1;
                    drink[3].num--;
                }
                else
                    cout <<"SOLD OUT\n";
            }
            else if(choiceValue == drink[4].name){
                if(drink[0].num != 0){
                    choiceNum = 4;
                    choiceCheck = 1;
                    drink[4].num--;
                }
                else
                    cout <<"SOLD OUT\n";
            }
            else if(choiceValue == "Quit"){
                cout << profit << endl;
                return 0;
            }
            else{
                cout <<"Try again\n";
                choiceCheck = 0;
            }
        }
        
        float money;
        float change;
        int noMoney = 0;

        while(noMoney == 0){
            cin >> money;
            cin.ignore();
            if ((money < 0) or (money > 100)){
                cout << "Try Again :(";
            }
            else{
                noMoney = 1;
            }
        }

        switch(choiceNum){
            case 0:
                change = money - drink[0].cost;
                break;
            case 1:
                change = money - drink[1].cost;
                break;
            case 2:
                change = money - drink[2].cost;
                break;
            case 3:
                change = money - drink[3].cost;
                break;
            case 4:
                change = money - drink[4].cost;
        }
        cout << change << endl;
        profit = profit + (money-change);
    } 
}//End main