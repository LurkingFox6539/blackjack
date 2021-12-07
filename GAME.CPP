/* Black Jack
 * Jacob Hanson
 * Modified: Too many time
 */


#include "DECK.h"
#include "functions.h"
#include "AI.h"
#include "Bet.h"
using namespace std;

bool bankVal = false;
bool betting = false, betting2 = true;
char rechoice, hchoice, bchoice;
int doCont = 0, betIn = 0, newbet = 0;

int main() {

	//Set bank value -- For betting
	//Try catch is a fancy  if else statement
	do {
		try {
			cout << " How much money would you like to start with? : ";
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
			cout << " That number is to big. 1,000,000 is the largest value, please lower your value.\n";
			sleep(2);
			system("cls");
		}
	} while (!bankVal);

	initializeDeck();

	do {
		shuffleDeck();
		system("cls");

		//player needs to bet
		do {
			try {
				cout << " Total Money: " << players[1].monsLeft << endl;
				cout << " How much would you like to bet? : ";
				cin >> betIn;
				if (betIn > players[1].monsLeft) {
					betting = false;
					throw betIn;
				}
				else {
					addBet(betIn, players[1]);
					betting = true;
				}
			}
			catch (int bet) {
				cout << "That bet exceeds your bank value. Please lower your bet!\n";
				sleep(2);
				system("cls");
			}
		} while (!betting);

		//set hands show hands
		setHands();
		showHand();
		sleep(1);

		//players play - hit or stand
		do {
			cout << "\n\tDo you Hit(H) or Stand(S): ";
			cin >> hchoice;
			hchoice = tolower(hchoice);

			if (hchoice == 'h') {
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
					hchoice = 's';
				}
			}
			else if (hchoice == 's') {
				cout << "\tYou stand - no cards dealt.\n";
				doCont = 0;
			}
			else {
				cout << "\tInvalid choice - Choose Hit or Stand.\n";
				hchoice == 'h';
			}
		} while (hchoice == 'h');

		//Only Runs if player doesn't exceed 21
		if (doCont == 0) {

			do {
				
				//raise bets (not actual black jack rules, just for fun)
				cout << "\n Total Money: " << players[1].monsLeft << "\t Bets In: " << players[1].betsIn << endl;

				cout << "\n Would you like to raise your bet (Y/N): ";
				cin >> bchoice;
				bchoice = towlower(bchoice);
				if (bchoice == 'y') {
					cout << "How much would you like to bet: ";
					cin >> newbet;
					addBet(newbet, players[1]);
					betting2;
				}
				else if (bchoice == 'n') {
					betting2 = false;
				}
				else {
					cout << "Invalid Input -- Please type Y or N.\n";
					betting2;
				}

				sleep(1);
				system("cls");
				showHand();

			} while (betting2); 

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
		if (isWin == 1) {
			returnBet(2, players[1]);
		}

		//ask for re-run
		cout << endl;
		cout << "Challenge the House again? (Y/N): ";
		cin >> rechoice;
		rechoice = tolower(rechoice);
		deleteHand(players[1].hand); deleteHand(players[0].hand);
		system("cls");
	} while (rechoice == 'y');

}
