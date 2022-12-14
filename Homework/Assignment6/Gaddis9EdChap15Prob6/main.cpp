/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on December 4th 2022 5:00pm
 * Purpose: Use a class to have graded essay
 */

#include <iostream>
using namespace std;

// Essay class
class Essay{
    private:
        int gram;
        int spell;
        int length;
        int cont;
    public:
        Essay(){
            gram = 0;
            spell = 0;
            length = 0;
            cont = 0;
        }
        
        Essay(int g, int s, int l, int c){
            gram = g;
            spell = s;
            length = l;
            cont = c;
        }
        
        void setGram(int g){
            gram = g;
        }
        
        void setSpell(int s){
            spell = s;
        }
        
        void setLength(int l){
            length = l;
        }
        
        void setCont(int c){
            cont = c;
        }
        
        int getGram(){
            return gram;
        }
        
        int getSpell(){
            return spell;
        }
        
        int getLength(){
            return length;
        }
        
        int getCont(){
            return cont;
        }
};


int main(int argc, char** argv) {
    //Initialize
    int g, s, l, c;
    
    //Get user input
    cout << "Enter scores for essay grade" << endl;
    cout << "Grammar: ";
    cin >> g;
    cout << "Spelling: ";
    cin >> s;
    cout << "Correct length: ";
    cin >> l;
    cout << "Content: ";
    cin >> c;
    
    Essay ess(g,s,l,c);
    
    
    return 0;
}

