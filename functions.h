#pragma once

#ifndef _FUNCTIONS_
#define _FUNCTIONS

#define underline "\033[4m"
#define unUnderline "\033[0m"

#include "deck.h"
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;

// Input number of seconds to sleep for
void sleep(int a) {
	this_thread::sleep_for(chrono::seconds(a));
}

//	Prints the cards in the hand you input. Input playerHand or houseHand
//	Allows input to have all cards in the hand flipped face up (default false)
void printHand(vector<DefineCard> thisHand, bool flipcards = false) {
	for (int i = 0; i < size(thisHand); i++) {
		cout << underline"\t           " << unUnderline"  ";
	}
	cout << endl;
	for (int i = 0; i < size(thisHand); i++) {
		if (thisHand.at(i).facedown && !flipcards) cout << "\t|" << "Facedown |  ";
		else cout << "\t|" << setw(2) << thisHand[i].face << ' ' << thisHand[i].suit << "     |  ";
	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int i = 0; i < size(thisHand); i++) {
			cout << "\t|         |  ";
		}
		cout << endl;
	}
	for (int i = 0; i < size(thisHand); i++) {
		if (thisHand.at(i).facedown && !flipcards) cout << underline"\t| Facedown|" << unUnderline"  ";
		else cout << underline"\t|     " << setw(2) << thisHand[i].face << ' ' << thisHand[i].suit << "|" << unUnderline"  ";
	}
	cout << endl;
}

//	Prints a card meant to look like the deck, used for drawing
void printDeck() {
	cout << underline"\t           " << unUnderline"      " << underline"         "<< unUnderline"\n"
		<< "\t| Deck    |\t " << underline"| STAND |" << unUnderline" \n\t|         |\n\t|         |\n\t|         |\n\t|         |\n\t"
		<< underline"|    Deck |" << unUnderline"\n";
}

// Adds two cards to each player's hand for the beginning of the game
void setHands() {
	addCard(players[0].hand, true);
	addCard(players[1].hand);
	addCard(players[0].hand);
	addCard(players[1].hand);
}

// Prints the main UI for the game
void showHand() {
	cout << "\t\t   House - " << players[0].handValue << endl;
	sleep(0.5); printHand(players[0].hand); sleep(0.5);  printHand(players[1].hand);
	cout << "\n\t\t   Player - " << players[1].handValue << endl;
}

#endif
