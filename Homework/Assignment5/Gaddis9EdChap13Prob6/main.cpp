/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on November 27th 2022 4:00pm
 * Purpose:  Inventory class
 */

//System Libraries
#include <iostream>
using namespace std;


class Inventory {
    private:
        int itemNumber;
        int quantity;
        float cost;
        float totalCost;
    public:
        Inventory();
        Inventory(int n, int q, double c);
        
        void setItemNumber (int item_num) {
            itemNumber = item_num;
        }
        
        void setQuantity (int qun) {
            quantity = qun;
        }
        
        void setCost(double cs) {
            cost = cs;
        }
        
        void setTotalCost () {
            totalCost=cost*quantity;
        }
        
        int getItemNumber() const {
            return itemNumber;
        }
        
        int getQuantity() const {
            return quantity;
        }
        
        float getCost() const {
            return cost;
        }
        
        float getTotalCost() const {
            return totalCost;
        }
};

Inventory::Inventory(){
    itemNumber = 0;
    quantity = 0;
    cost = 0.0;
    totalCost = 0;
}
Inventory::Inventory(int n, int q, double c){
    setItemNumber(n);
    setQuantity(q);
    setCost (c);
    setTotalCost();
}


//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare
    int itemNum, qty;
    double cs;
    
    //Initialize
    Inventory* inv;
    inv = new Inventory();
    
    cout << "Enter item number : ";
    cin>> itemNum;
    cout << "Enter item quantity : ";
    cin>> qty;
    cout << "Enter item cost : ";
    cin>> cs;
    
    if(item_no < 0 || qty < 0 || cs < 0)
        cout <<"\nYou have entered invalid values....\n";
    else
    {
        inv->setItemNumber(itemNum);
        inv->setQuantity(qty);
        inv->setCost(cs);
        
        cout << endl << "The Details of the item you have entered: " << endl;
        cout << "Item Number :" << inv->getItemNumber() << endl;
        cout << "Item Quantity:" << inv->getQuantity() << endl;
        cout << "Cost:" << inv->getCost() << endl;
        cout << "Total Cost :" << inv->getTotalCost() << endl;
    }
    return 0;

}//End main