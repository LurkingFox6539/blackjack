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
void printHand(vector<DefineCard> thisHand) {
	for (int i = 0; i < size(thisHand); i++) {
		cout << underline"           " << unUnderline"  ";
	}
	cout << endl;
	for (int i = 0; i < size(thisHand); i++) {
		if (thisHand.at(i).facedown == false) cout << "|" << setw(2) << thisHand[i].face << ' ' << thisHand[i].suit << "     |  ";
		else cout << "|" << "Facedown |  ";
	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int i = 0; i < size(thisHand); i++) {
			cout << "|         |  ";
		}
		cout << endl;
	}
	for (int i = 0; i < size(thisHand); i++) {
		if (thisHand.at(i).facedown == false) cout << underline"|     " << setw(2) << thisHand[i].face << ' ' << thisHand[i].suit << "|" << unUnderline"  ";
		else cout << underline"| Facedown|" << unUnderline"  ";
	}
	cout << endl;
}

#endif
