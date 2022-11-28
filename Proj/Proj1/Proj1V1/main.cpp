/*
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on October 28th, 2022 7:00am
 * Purpose:  Have running Blackjack game
 * Version: 1
 */

 //System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void CreateDeck(string* deck);
void Shuffle(string* deck);
int CardVal(string card);
void Blackjack();


//Execution Begins Here
int main(int argc, char** argv) {
	
	//Initialize Variables
	char choice = 'y';
	string init = " ";
	char name[100];
	char* initial;
	int wins;

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

	while (choice == 'y') {
		
		cout << "Enter y to play a hand of Blackjack(enter anything else to stop): ";
		cin >> choice;
		cout << endl << endl;

		if (choice == 'y') Blackjack();
	}

	cout << endl << "Thank you for playing!" << endl;

	return 0;
}


// Function to create a deck
void CreateDeck(string* deck) {
	
	// Initialize variables
	unsigned int i;
	unsigned int j;
	int count = 0;

	string n[13] = {"Ace","King","Queen","Jack","Ten","Nine","Eight","Seven","Six","Five","Four","Three","Two"};
	string s[4] = {"Spades","Clubs","Diamonds","Hearts"};

	//Populate deck
	//Number
	for (i = 0; i < 13; i++) {
		
		//Suit
		for (j = 0; j < 4; j++) {
			
			deck[count] = n[i] + " " + s[j];
			count++;

		}

	}

}


// Function to shuffle array of cards
void Shuffle(string* deck) {
	
	// set rand seed
	srand(static_cast<unsigned int>(time(0)));

	// Initialize variables
	unsigned int i;
	string swap;
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


// Function for card value
int CardVal(string card) {
	
	//Initialize
	unsigned int i;
	string num[13] = {"Ace","King","Queen","Jack","Ten","Nine","Eight","Seven","Six","Five","Four","Three","Two"};
	int values[13] = {1,10,10,10,10,9,8,7,6,5,4,3,2};


	for (i = 0; i < 13; i++) {

		if (card.substr(0,2) == num[i].substr(0,2)) return values[i];

	}

	return 0;
}



// Blackjack gameplay
void Blackjack() {
	
	//Initialize variables
	int size = 52;
	unsigned int i;
	int user = 0;
	int countD1 = 0; //Deck counter
	int countD2 = 0; //Dealer hand counter
	int countP = 0; //Player had counter
	int dealerTot = 0;
	int playerTot = 0;
	string* deck = new string[size];
	string* dealer = new string[size];
	string* player = new string[size];
	
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
	dealerTot += CardVal(dealer[0]);
	dealerTot += CardVal(dealer[1]);
	playerTot += CardVal(player[0]);
	playerTot += CardVal(player[1]);

	// Check to see if dealer has a Blackjack
	if (dealerTot == 21) {

		cout << "The dealer has a Blackjack and has won!" << endl << endl;

	}
	else {
		
		//Ask user if they want to hold or get another card
		while (user == 0 && playerTot < 21) {
			
			cout << "Your hand is:" << endl;
			for (i = 0; i < countP; i++) {

				cout << player[i] << "  ";

			}

			cout << endl << endl << "Your total is: " << playerTot << endl << endl;
			cout << "Do you want another card(0 yes, 1 no)?";
			cin >> user;
			cout << endl << endl;

			//Add new card if chosen
			if (user == 0) {

				player[countP] = deck[countD1];
				cout << "New card: " << player[countP];
				playerTot += CardVal(player[countP]);
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

		}

		//below 21
		else {
			
			//Add new cards to the dealer untill they win or go over
			cout << "The Dealers hand is:" << endl;
			for (i = 0; i < countD2; i++) {

				cout << dealer[i] << "  ";

			}
			cout << endl << "The Dealers total is: " << dealerTot << endl;
			
			while (playerTot >= dealerTot && dealerTot <= 21) {

				dealer[countD2] = deck[countD1];
				cout << "New card: " << dealer[countD2] << endl;
				dealerTot += CardVal(dealer[countD2]);
				countD1++, countD2++;
				cout << "New total: " << dealerTot << endl;

			}

			if (dealerTot > 21) {

				cout << "You have won! The dealer went over 21." << endl;

			}
			else {

				cout << "The dealer has won with a total of: " << dealerTot << endl;

			}

		}

	}

}