#pragma once
#ifndef _AI_
#define _AI_

#include "deck.h"
#include "functions.h"
using namespace std;

void setValue();

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
	else if (players[0].handValue < players[1].handValue) {
		cout << "Player has beat House. Congrats Player.\n";
		return 1;
	}
	else if (players[0].handValue == players[1].handValue) {
		cout << "Player and House are equal. Bets are returned.\n";
		return 2;
	}
	else if (players[0].handValue > players[1].handValue && players[0].handValue < 21) {
		cout << "House has won the game, with a value of " << players[0].handValue << "!\n";
		return 3;
	}
	else if (players[0].handValue > players[1].handValue && players[0].handValue > 21) {
		cout << "House hand exceeds 21, House goes bust. Congrats player.\n";
		return 4;
	}
	else if (players[0].handValue > players[1].handValue && players[0].handValue == 21) {
		cout << "House hit a Black Jack. Player looses.\n";
		return 5;
	}
	else if (players[1].handValue > players[0].handValue && players[1].handValue == 21) {
		cout << "Player hit a Black Jack. Congrats player.\n";
		return 6;
	}
}

void setValue(){
	players[0].handValue = 0;
	players[1].handValue = 0;
	players[2].handValue = 0;

	for (int i = 0; i < size(players[1].hand); i++) {
		if (players[1].hand.at(i).face == "A") {
			int aVal = ace.value(players[1]);
			players[1].handValue += aVal;
		}
		else {
			players[1].handValue += players[1].hand.at(i).pointsValue;
		}
	}
	for (int i = 0; i < size(players[0].hand); i++) {
		if (players[0].hand.at(i).face == "A") {
			int aVal = ace.value(players[0]);
			players[0].handValue += aVal;
		}
		else {
			players[0].handValue += players[0].hand.at(i).pointsValue;
		}
	}
}

#endif
