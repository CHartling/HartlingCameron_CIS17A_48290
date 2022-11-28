/*
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on October 28th, 2022 7:00am
 * Purpose:  Have running Blackjack game that saves user data
 * Version: 2
 */

 //System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions


// Structures
struct Card{
    
    string name;
    int value;
    
};

//Function Prototypes
void CreateDeck(Card* deck);
void Shuffle(Card* deck);
int Blackjack();
void Record(string name, int wins);

//Execution Begins Here
int main(int argc, char** argv) {
	
	//Initialize Variables
	int choice = 0;
	string init = " ";
	char name[100];
	char* initial;
	int wins = 0;
        enum Choices {Play, Save};
        

	// Explain the rules of Blakcjack
	cout << "The rules of Blackjack:" << endl;
	cout << "The dealer and the player will get two cards in the beginning." << endl;
	cout << "The goal of the game is to get closest to 21 without going over." << endl;
	cout << "Face cards are worth 10 points, Ace is worth 11, and the rest are face value." << endl;
	cout << "After the deal the player goes first determining if they want another card or not." << endl;
	cout << "The player can get any number of additional cards as long as the total does not go over 21." << endl;
	cout << "After the player stops the dealer tries to match or beat the players score." << endl;
	cout << "The dealer wins if points are tied." << endl << endl;

	//Ask user for name
	cout << "Please enter your first name then your last name: " << endl;
	cin.get(name, 100);

	//Get users initials
	init += name[0];
	initial = strchr(name, ' ');
	init += name[(initial - name) + 1];

	//Welcome message
	cout << "Welcome " << init << "!" << endl;
	cout << "I hope you have a great time playing Blackjack" << endl;

	while (choice == 0 || choice == 1) {
		
		cout << endl << endl << "Enter 0 to play a hand of Blackjack or 1 to save data(enter anything else to stop): ";
		cin >> choice;
		cout << endl << endl;

		switch(choice){
                    
                    case Play : wins += Blackjack();
                        break;
                    case Save : Record(init, wins);
                        break;
                    
                }
                
	}

	cout << endl << "Thank you for playing!" << endl;

	return 0;
}


// Function that saves user data
void Record(string name, int wins){
    
    // Initialize
    char choice;
    string oldName;
    int oldWins;
    fstream saveWins("save.dat", ios::in | ios::out | ios::binary);
    
    // Output previous data
    saveWins.seekg(0L,ios::beg);
    saveWins.read(reinterpret_cast<char *>(&oldName), sizeof(oldName));
    saveWins.seekg(5L,ios::beg);
    saveWins.read(reinterpret_cast<char *>(&oldWins), sizeof(oldWins));
    
    // Ask if user wants to replace data
    cout << "Enter 0 to replace data:" << endl;
    cin >> choice;
    
    if (choice == 0){
        
        saveWins.seekg(0L,ios::beg);
        saveWins.write(reinterpret_cast<char *>(&name), sizeof(name));
        saveWins.seekg(5L,ios::beg);
        saveWins.write(reinterpret_cast<char *>(&wins), sizeof(wins));
        
    }
    
}


// Function to create a deck
void CreateDeck(Card* deck) {
	
	// Initialize variables
	unsigned int i;
	unsigned int j;
	int count = 0;

	string n[13] = {"Ace","King","Queen","Jack","Ten","Nine","Eight","Seven","Six","Five","Four","Three","Two"};
        int values[13] = {11,10,10,10,10,9,8,7,6,5,4,3,2};
	string s[4] = {"Spades","Clubs","Diamonds","Hearts"};

	//Populate deck
	//Number
	for (i = 0; i < 13; i++) {
                
		//Suit
		for (j = 0; j < 4; j++) {
			
			deck[count].name = n[i] + " " + s[j];
                        deck[count].value = values[i];
			count++;

		}

	}

}


// Function to shuffle array of cards
void Shuffle(Card* deck) {
	
	// set rand seed
	srand(static_cast<unsigned int>(time(0)));

	// Initialize variables
	unsigned int i;
	Card swap;
	int rNum;

	//Populate deck
	CreateDeck(deck);

	//Randomly shuffle the deck
	for (i = 0; i < 52; i++) {
		
		rNum = rand() % 51;
		swap = deck[i];
		deck[i] = deck[rNum];
		deck[rNum] = swap;

	}

}




// Blackjack gameplay
int Blackjack() {
	
	//Initialize variables
	int size = 52;
	unsigned int i;
	int user = 0;
	int countD1 = 0; //Deck counter
	int countD2 = 0; //Dealer hand counter
	int countP = 0; //Player had counter
	int dealerTot = 0;
	int playerTot = 0;
	Card* deck = new Card[size];
	Card* dealer = new Card[size];
	Card* player = new Card[size];
	
	//Get a shuffled deck
	Shuffle(deck);

	//Deal the first two cards
	dealer[countD2] = deck[countD1];
	countD1++,countD2++;
	dealer[countD2] = deck[countD1];
	countD1++,countD2++;
	player[countP] = deck[countD1];
	countD1++,countP++;
	player[countP] = deck[countD1];
	countD1++,countP++;

	// Check values of hand
	dealerTot += dealer[0].value;
	dealerTot += dealer[1].value;
	playerTot += player[0].value;
	playerTot += player[1].value;

	// Check to see if dealer has a Blackjack
	if (dealerTot == 21) {

		cout << "The dealer has a Blackjack and has won!" << endl << endl;

	}
	else {
		
		//Ask user if they want to hold or get another card
		while (user == 0 && playerTot < 21) {
			
			cout << "Your hand is:" << endl;
			for (i = 0; i < countP; i++) {

				cout << player[i].value << "  ";

			}

			cout << endl << endl << "Your total is: " << playerTot << endl << endl;
			cout << "Do you want another card(0 yes, 1 no)?";
			cin >> user;
			cout << endl << endl;

			//Add new card if chosen
			if (user == 0) {

				player[countP] = deck[countD1];
				cout << "New card: " << player[countP].value << endl;
				playerTot += player[countP].value;
				countD1++, countP++;

			}

		}

		//If over 21
		if (playerTot > 21) {

			cout << "You went over 21 and lost the game" << endl;

		}

		//exactly 21
		else if (playerTot == 21) {

			cout << "You got Blackjack and won the game!" << endl;
                        return 1;

		}

		//below 21
		else {
			
			//Add new cards to the dealer untill they win or go over
			cout << "The Dealers hand is:" << endl;
			for (i = 0; i < countD2; i++) {

				cout << dealer[i].value << "  ";

			}
			cout << endl << "The Dealers total is: " << dealerTot << endl;
			
			while (playerTot >= dealerTot && dealerTot <= 21) {

				dealer[countD2] = deck[countD1];
				cout << "New card: " << dealer[countD2].value << endl;
				dealerTot += dealer[countD2].value;
				countD1++, countD2++;
				cout << "New total: " << dealerTot << endl;

			}

			if (dealerTot > 21) {

				cout << "You have won! The dealer went over 21." << endl;
                                return 1;

			}
			else {

				cout << "The dealer has won with a total of: " << dealerTot << endl;

			}

		}

	}
        
        // Clear memory
        delete[] deck;
        delete[] player;
        delete[] dealer;
        
        return 0;
}