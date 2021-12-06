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
	string face = "\1";
	int cardStatus = 0;
	int pointsValue = 0;
	bool facedown = false;
};

struct Player {
	vector<DefineCard> hand;
	int handValue = 0;
	int monsLeft = 0;
	int betsIn = 0;
};

Player players[3];

struct AceValue {
	int value(Player player = players[2]) {
		if ((player.handValue + 11) > 21) return 1;
		else if ((player.handValue + 11) <= 21) return 11;
		else return 1;
	}
};

DefineCard Deck[53];
AceValue ace;


//	Adds a card to the inputted hand (playerHand or houseHand)
//	Allows input for whether the card should be facedown down or not (default false)
void addCard(vector<DefineCard>& hand, bool facedown = false) {
	int i = 0;
	while (Deck[0 + i].cardStatus != 1) {
		i++;
	}
	Deck[0 + i].facedown = facedown;
	hand.push_back(Deck[0 + i]);
	Deck[0 + i].cardStatus = 0;
}

//	Input the hand to remove the card from, followed by the card's position starting from 0
void removeCard(vector<DefineCard>& hand, int cardPos) {
	hand.erase(hand.begin() + cardPos);
}

//delete hand
void deleteHand(vector<DefineCard>& hand) {
	hand.erase(hand.begin(), hand.end());
}

//	Initializes all the cards in the deck to their base values
void initializeDeck() {
	int New_Suit = 0;
	string faces[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	string Status[3] = { "In Play", "In Deck", "Discard Pile" };
	char suits[4] = { '\x04', '\x05', '\x03', '\x06' };
	int CardValue[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
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
