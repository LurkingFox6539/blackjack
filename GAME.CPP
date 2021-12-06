/* Black Jack
 * Jacob Hanson
 * Modified: Too many time
 */

#include "DECK.h"
#include "functions.h"
#include "AI.h"
using namespace std;

bool bankVal = false;
char choice, pchoice;
int doCont = 0;

int main() {

	//Set bank value -- For betting
	//Try catch is a fancy  if else statement
	do {
		try {
			cout << "How much money would you like to start with? : ";
			cin >> players[1].monsLeft;

			if (players[1].monsLeft > 1000000) {
				bankVal = false;
				throw players[1].monsLeft;
			}
			else {
				bankVal = true;
			}
		}
		catch (int bank) {
			cout << "That number is to big. 1,000,000 is the largest value, please lower your value.\n";
			sleep(2);
			system("cls");
		}
	} while (!bankVal);

	initializeDeck();

	do {
		shuffleDeck();
		system("cls");

		//set hands show hands
		setHands();
		showHand();
		sleep(1);

		//players play - hit or stand
		do {
			cout << "\n\tDo you Hit(H) or Stand(S): ";
			cin >> pchoice;
			pchoice = tolower(pchoice);

			if (pchoice == 'h') {
				cout << "\tHit - heres a card.\n" << players[1].handValue;
				addCard(players[1].hand);
				sleep(1);
				system("cls");
				showHand();

				//checking for handvalue s.t. if handValue > 21 = you lose;
				setValue();
				if (players[1].handValue > 21) {
					cout << "The players hand exceeds 21 - You go bust\n";
					doCont = 1;
					pchoice = 's';
				}
			}
			else if (pchoice == 's') {
				cout << "\tYou stand - no cards dealt.\n";
			}
			else {
				cout << "\tInvalid choice - Choose Hit or Stand.\n";
				pchoice == 'h';
			}
		} while (pchoice == 'h');

		//Only Runs if player doesn't exceed 21
		if (doCont == 0) {
			//manage bets
			cout << "\n Heres how much money you have: " << players[1].monsLeft << endl;
			fakeBet();

			system("pause");
			system("cls");

			//reprint hands post card flip
			players[0].hand.at(0).facedown = false;
			showHand();
			cout << makeDecision();
			cout << endl;
			for (int i = 0; i < size(players[1].hand); i++) {
				cout << players[1].hand.at(i).pointsValue << endl;
			}
		}

		//allocate money to designated palce

		//ask for re-run
		cout << endl;
		cout << "Challenge the House again? (Y/N): ";
		cin >> choice;
		choice = tolower(choice);
		deleteHand(players[1].hand); deleteHand(players[0].hand);
		system("cls");
	} while (choice == 'y');

}
