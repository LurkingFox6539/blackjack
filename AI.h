#pragma once

#ifndef _AI_
#define _AI_

#include "deck.h"
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
			printHand(players[0].hand);
			printHand(players[1].hand);
		}
	}
	if (playerValue > 21) return 0;
	else if (houseValue < playerValue) return 1;
	else if (houseValue == playerValue) return 2;
	else if (houseValue > playerValue && houseValue < 21) return 3;
	else if (houseValue > playerValue && houseValue > 21) return 4;
	else if (houseValue > playerValue && houseValue == 21) return 5;
}

#endif
