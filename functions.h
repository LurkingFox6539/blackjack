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
		if (thisHand.at(i).facedown && !flipCards) cout << "\t|" << "Facedown |  ";
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
		if (thisHand.at(i).facedown && !flipCards) cout << underline"\t| Facedown|" << unUnderline"  ";
		else cout << underline"\t|     " << setw(2) << thisHand[i].face << ' ' << thisHand[i].suit << "|" << unUnderline"  ";
	}
	cout << endl;
}

#endif
