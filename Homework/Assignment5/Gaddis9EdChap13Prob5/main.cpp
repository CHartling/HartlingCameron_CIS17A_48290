/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on November 27th 2022 4:00pm
 * Purpose:  
 */

//System Libraries
#include <iostream>
using namespace std;

class RetailItems{
    private:
        string description;
        int unitsOnHand;
        double price;
        
    public:
        void setDescription(string d){
            description = d;
        }
        
        void setUnitsOnHand(int u){
            unitsOnHand = u;
        }
        
        void setPrice(double p){
            price = p;
        }
        
        string getDescription() const{
            return description;
        }
        
        int getUnitsOnHand() const{
            return unitsOnHand;
        }
        
        double getPrice() const{
            return price;
        }
        
};

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Initialize RetailItems variables
    RetailItems* item1;
    item1 = new RetailItems();
    RetailItems* item2;
    item2 = new RetailItems();
    RetailItems* item3;
    item3 = new RetailItems();
    
    //Adding data
    item1->setDescription("Jacket");
    item1->setUnitsOnHand(12);
    item1->setPrice(59.95);
    
    item2->setDescription("Designer Jacket");
    item2->setUnitsOnHand(40);
    item2->setPrice(34.95);
    
    item3->setDescription("Shirt");
    item3->setUnitsOnHand(20);
    item3->setPrice(24.95);
    
    //Output
    cout << "Items in stock" << endl;
    cout << item1->getDescription() << " Units on hand: " << item1->getUnitsOnHand() << " Price: " << item1->getPrice() << endl;
    cout << item2->getDescription() << " Units on hand: " << item2->getUnitsOnHand() << " Price: " << item2->getPrice() << endl;
    cout << item3->getDescription() << " Units on hand: " << item3->getUnitsOnHand() << " Price: " << item3->getPrice() << endl;
    
    return 0;
}//End main