#pragma once
#ifndef _AITWO_
#define _AITWO_

#include "deck.h"
#include "functions.h"
using namespace std;

int isWin = 0;

void setValue();

// Very simple program allowing the computer to act as the house following the very strict rules set out in blackjack.
// If the house's hand is less than 17 they continue to draw cards. Returns a value depending on the comparison of player and house's hand
int makeDecision() {
	setValue();
	while (players[0].handValue < 17) {
		setValue();
		addCard(players[0].hand);
		system("cls");
		printHand(players[0].hand);
		printHand(players[1].hand);
		setValue();
	}
	system("cls");
	printHand(players[0].hand);
	printHand(players[1].hand);

if (players[1].handValue > 21) {
		cout << "Player's Hand exceeds 21, player goes bust.\n";
		return 0;
	}
	else if (players[0].handValue > players[1].handValue && players[0].handValue < 21) {
		cout << "House has won the game, with a value of " << players[0].handValue << "!\n";
		return 3;
	}
	else if (players[0].handValue > players[1].handValue && players[0].handValue > 21) {
		cout << "House hand exceeds 21, House goes bust. Congrats player.\n";
		isWin = 1;
		return 4;
	}
	else if (players[0].handValue > players[1].handValue && players[0].handValue == 21) {
		cout << "House hit a Black Jack. Player has lost.\n";
		return 5;
	}
	else if (players[1].handValue > players[0].handValue && players[1].handValue == 21) {
		cout << "Player hit a Black Jack. Congrats player.\n";
		isWin = 1;
		return 6;
	}
	else if (players[0].handValue < players[1].handValue) {
		cout << "Player has beat House. Congrats Player.\n";
		isWin = 1;
		return 1;
	}
	else if (players[0].handValue == players[1].handValue) {
		cout << "Player and House are equal. Bets are returned.\n";
		return 2;
	}
}

// Sets the value of the respective hands. It does this by skipping aces and incrementing numAces, adding the value of other cards to the handValue
// and then looping for the number of aces found and adding one or eleven depending on whether or not it would make the hand value go over 21
void setValue(){
	int numAces = 0;
	players[0].handValue = 0;
	players[1].handValue = 0;
	players[2].handValue = 0;

	// Sets value of the House's hand
	for (int i = 0; i < size(players[0].hand); i++) {
		if (players[0].hand.at(i).face == "A") numAces++;
		else players[0].handValue += players[0].hand.at(i).pointsValue;
	}
	for (int i = 0; i < numAces; i++, numAces--) {
		if ((players[0].handValue + 11) > 21) players[0].handValue += 1;
		else players[0].handValue += 11;
	}

	// Sets value of the player's hand
	for (int i = 0; i < size(players[1].hand); i++) {
		if (players[1].hand.at(i).face == "A") numAces++;
		else players[1].handValue += players[1].hand.at(i).pointsValue;
	}
	for (int i = 0; i < numAces; i++, numAces--) {
		if ((players[1].handValue + 11) > 21) players[1].handValue += 1;
		else players[1].handValue += 11;
	}
}

#endif
