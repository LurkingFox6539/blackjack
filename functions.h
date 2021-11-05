#ifndef _DECK_
#define _DECK_


//Make the deck the cards, etc.

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;


struct DefineCard {
	string suit;
	string face;
	int pointsValue; //Face => 10 -- Ace's => 1 or 11
	int cardStatus; // 0 = In play || 1 = In Deck || 2 = In discard
}

Deck[53]; // Deck [52] used for shuffling.


void cardDeck() {
	srand((unsigned)time(0));
	int New_Suit = 0;
	string faces[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	string suits[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };
	string Status[3] = { "In Play", "In Deck", "Discard Pile" };
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
	cout << "Straight deck of cards.." << endl << endl;
	for (int x = 0; x < 52; x++)
	{
		//cout << Deck[x].face << " of " << Deck[x].suit << "   " << Deck[x + 1].face << " of " << Deck[x + 1].suit << "  " << Deck[x + 2].face << " of " << Deck[x + 2].suit << "   " << Deck[x + 3].face << " of " << Deck[x + 3].suit << endl;
		cout << Deck[x].face << " of " << Deck[x].suit << " : Value of " << Deck[x].pointsValue << " : " << Status[Deck[x].cardStatus] << endl;
	}

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

	cout << endl << "Shuffled deck of cards.." << endl << endl;

	for (int x = 0; x < 52; x++)
	{
		//cout << Deck[x].face << " of " << Deck[x].suit << "   " << Deck[x + 1].face << " of " << Deck[x + 1].suit << "   " << Deck[x + 2].face << " of " << Deck[x + 2].suit << "   " << Deck[x + 3].face << " of " << Deck[x + 3].suit << endl;
		cout << Deck[x].face << " of " << Deck[x].suit << " : Value of " << Deck[x].pointsValue << " : " << Status[Deck[x].cardStatus] << endl;
	}

	cout << endl << endl;
	cin >> New_Suit;
}

#endif
