#pragma once

#ifndef _BETS_
#define _BETS_

#include "AI.h"
char rechoice, hchoice, bchoice;
int betIn = 0, newbet = 0, tempBet = 0;
bool bankVal = false, betting = false, betting2 = true, hitLoop = false, newBetLoop = false, addBetLoop = false, reLoop = false;

//	Adds a set amount to the target's bet and removes the same amount from their current money
void addBet(int add, Player& player) {
	player.betsIn += add;
	player.monsLeft -= add;
}

//	Removes a player's bet and returns it to their money pile
void removeBet(int remove, Player& player) {
	player.betsIn -= remove;
	player.monsLeft += remove;
}

//	Returns a player's bet at a certain ratio and sets their current bet to 0
void returnBet(int ratio, Player& player) {
	player.monsLeft += player.betsIn * ratio;
	player.betsIn = 0;
}

//	Doubles down the player's bet and removes the same amount from their money pile
void doubleBet(Player& player) {
	player.betsIn += player.betsIn;
	player.monsLeft -= player.betsIn / 2;
}

#endif
