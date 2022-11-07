/*
 * File: Proj1.cpp
 * Author: Cameron Hartling
 * Created on October 28th, 2022 7:00am
 * Purpose:  Blakcjack Pseudo Code
 * Version: 0
 */

 //System Libraries

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

// Function Prototypes
// void CreateDeck(string* deck);
// void Shuffle(string* deck);
// int CardVal(string card);
// void Blackjack();


//Main function

	//Initialize Variables

	// Explain the rules of Blakcjack

	//Ask user for name

	//Get users initials

	//Welcome message
        
        //While loop for asking user to play blackjack
	
            // Ask user if they want to play
        
            // If yes call Blackjack function
        
        // Thank you message for playing


// Function to create a deck
// void CreateDeck(string* deck)
	
	// Initialize variables
        
        // Two string arrays containing card names and suits

	//Populate deck
	// For loop for the card names
		
		// For loop for suit
			
                        // Add card name and suit together and put in deck[]



// Function to shuffle array of cards
// void Shuffle(string* deck)
	
	// set rand seed

	// Initialize variables

	//Populate deck by calling CreateDeck()

	//Randomly shuffle the deck using for loop and swapping random places


// Function for card value
// int CardVal(string card)
	
	//Initialize
        
        // string array for card name
        // int array for values of card names

        // For loop that goes through and checks for equivalent card name in array and string parameter
                
                // return value in the same position as the int array



// Blackjack gameplay
// void Blackjack()
	
	//Initialize variables
        
        // Create dynamic arrays for deck, dealer, and player
	
	//Get a shuffled deck by calling Shuffle(deck)

	//Deal the first two cards by moving cards from deck to dealer and player

	// Add values of the cards to dealerTot and playerTot

	// Check to see if dealer has a Blackjack
        
        // else
		
                // While loop for getting more cards for user
        
                    //Ask user if they want to hold or get another card
			
        
			// Print out users hand, player[]

                        // Print out the total hand value
			
                        // Ask if they want another card

			//Add new card if chosen
        
        
		//If over 21 print losing statement

		//If exactly 21 print winning statement

		//else
			
			// Print dealers hand and total
        
                        //Add new cards to the dealer untill they win or go over
			
                        // If dealerTot is over 21 print winning statement for player
        
                        // else print losing statement for player