#pragma once

#ifndef _AI_
#define _AI_

#include "deck.h";
#include "functions.h"

int makeDecision() {
	int playerValue = 0;
	int houseValue = 0;
	for (int i = 0; i < size(playerHand); i++) {
		playerValue += playerHand.at(i).pointsValue;
	}
	for (int i = 0; i < size(houseHand); i++) {
		houseValue += houseHand.at(i).pointsValue;
	}
	while (houseValue < playerValue) {
		for (int i = 0; i < size(houseHand); i++) {
			houseValue += houseHand.at(i).pointsValue;
		}
		if (playerValue <= 21) {
			addCard(houseHand);
			system("cls");
			printHand(houseHand);
			printHand(playerHand);
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
