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

int main() {
	initializeDeck();

	do {
		shuffleDeck();


		//Set bank value
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
		
		system("cls");

		//set bets

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
				cout << "\tHit - heres a card.\n";
				addCard(players[1].hand);
				sleep(1);
				system("cls");
				showHand();
			}
			else if (pchoice == 's') {
				cout << "\tYou stand - no cards dealt.\n";
			}
			else {
				cout << "\tInvalid choice - Choose Hit or Stand.\n";
				pchoice == 'h';
			}
		} while (pchoice == 'h');
	
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

		//allocate money to designated palce

		//ask for re-run
		cout << endl;
		cout << "Challenge the House again? (Y/N): ";
		cin >> choice;
		choice = tolower(choice);
		deleteHand(players[0].hand); deleteHand(players[1].hand);
		system("cls");
	} while (choice == 'y' );
	
}
