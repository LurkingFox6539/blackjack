/*	modified November 8 2021, Mark Wheeler III
*		changed card strings to their numbers and letter instead of words
*		changed strings for suits to symbols for the suits
*		removed outputs and added the playerHand vector
*		also split the deck initializing and shuffling and added 
*		facedown bool to card struct
*/

#ifndef _DECK_
#define _DECK_


//Make the deck the cards, etc.

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <ctime>
using namespace std;


struct DefineCard {
	char suit = '\0';
	string face = "\0";
	int cardStatus = 0;
	int pointsValue = 0;
	bool facedown = false;
}

Deck[53];
vector<DefineCard> houseHand;
vector<DefineCard> playerHand;

//	Adds a card to the inputted hand (playerHand or houseHand)
void addCard(vector<DefineCard>& hand) {
	int i = 0;
	while (Deck[0 + i].cardStatus != 1) {
		i++;
	}
	hand.push_back(Deck[0 + i]);
	Deck[0 + i].cardStatus = 0;
}

//	Initializes all the cards in the deck to their base values
void initializeDeck() {
	int New_Suit = 0;
	string faces[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	string Status[3] = { "In Play", "In Deck", "Discard Pile" };
	char suits[4] = { '\x04', '\x05', '\x03', '\x06' };
	int CardValue[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	for (int x = 0; x < 52; x++)
	{

		Deck[x].face = faces[x % 13];
		Deck[x].suit = suits[New_Suit];
		Deck[x].pointsValue = CardValue[x % 13];
		Deck[x].cardStatus = 1;
		if ((x + 1) % 13 == 0)
			New_Suit++;
	}
}

//	Shuffles the deck
void shuffleDeck() {
	srand((unsigned)time(0));
	for (int x = 0; x < 600; x++)
	{
		int a = rand() % 52;
		int b = rand() % 52;

		Deck[52].face = Deck[a].face;
		Deck[52].suit = Deck[a].suit;
		Deck[52].pointsValue = Deck[a].pointsValue;
		Deck[52].cardStatus = Deck[a].cardStatus;

		Deck[a].face = Deck[b].face;
		Deck[a].suit = Deck[b].suit;
		Deck[a].pointsValue = Deck[b].pointsValue;
		Deck[a].cardStatus = Deck[b].cardStatus;

		Deck[b].face = Deck[52].face;
		Deck[b].suit = Deck[52].suit;
		Deck[b].pointsValue = Deck[52].pointsValue;
		Deck[b].cardStatus = Deck[52].cardStatus;
	}
}

#endif
