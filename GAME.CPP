/* Black Jack
 * Jacob Hanson
 * Modified: Too many time
 */


#include "DECK.h"
#include "functions.h"
#include "AI.h"
using namespace std;

char choice;

int main() {
	initializeDeck();

	do {
		shuffleDeck();

		//set bets

		//set hands show hands
		setHands();
		sleep(1); printHand(players[0].hand); sleep(1);  printHand(players[1].hand);

		sleep(1);

		//manage bets
		fakeBet();

		system("pause");
		system("cls");

		//reprint hands post card flip
		players[0].hand.at(0).facedown = false;
		printHand(players[0].hand); printHand(players[1].hand); sleep(1);
		cout << makeDecision();


		//allocate money to designated palce


		//ask for re-run
		cout << endl;
		cout << "Challenge the House again? (Y/N): ";
		cin >> choice;

		deleteHand();
		system("cls");
	} while (choice == 'Y');
	
}
