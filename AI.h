/* AI for House
 * Function: add cards to house hand in attempt to beat the player unless it busts, or the players busts, or if the player has a 21. 
 */

//NEITHER OLD NOR NEW AI

#pragma once

#ifndef _AI_
#define _AI_

#include "deck.h";
#include "functions.h"

int makeDecision() {
	int playerValue = 0;
	int houseValue = 0;
	for (int i = 0; i < size(players[1].hand); i++) {
		playerValue += players[1].hand.at(i).pointsValue;
	}
	for (int i = 0; i < size(players[0].hand); i++) {
		houseValue += players[0].hand.at(i).pointsValue;
	}
	while (houseValue < playerValue) {
		for (int i = 0; i < size(players[0].hand); i++) {
			houseValue += players[0].hand.at(i).pointsValue;
		}
		if (playerValue <= 21) {
			addCard(players[0].hand);
			system("cls");
			sleep(0.5);
			printHand(players[0].hand);
			printHand(players[1].hand);
		}
	}
	if (playerValue > 21) {
		cout << "Player's Hand exceeds 21, player goes bust.\n";
		return 0;
	}
	else if (houseValue < playerValue) {
		cout << "Player has beat House. Congrats Player.\n";
		return 1;
	}
	else if (houseValue == playerValue) {
		cout << "Player and House are equal. Bets are returned.\n";
		return 2;
	}
	else if (houseValue > playerValue && houseValue < 21) {
		cout << "House has won the game, with a value of " << houseValue << "!\n";
		return 3;
	}
	else if (houseValue > playerValue && houseValue > 21) {
		cout << "House hand exceeds 21, House goes bust. Congrats player.\n";
		return 4;
	}
	else if (houseValue > playerValue && houseValue == 21) {
		cout << "House hit a Black Jack. Player looses.\n";
		return 5;
	}
	else if (playerValue > houseValue && playerValue == 21) {
		cout << "Player hit a Black Jack. Congrats player.\n";
		return 6;
	}
}

#endif
