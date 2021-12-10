/* Black Jack
 * Jacob Hanson
 * Modified: Too many time
 * Mark Wheeler III - December 8 2021:
 *		Changing all inputs to buttons inputs to prevent invalid input
 */

#include "AI.h"
#include "Bet.h"
#include "buttons.h"
using namespace std;

int doCont = 0;
void initializeButtons();

int main() {
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hStdin, &fdwSaveOldMode);
	clear();

	initializeButtons();

	//Set bank value -- For betting
	//Try catch is a fancy  if else statement
	do {
		cout << " How much money would you like to start with? (Max 1,000,000) : \n\t + 10,000 - \t + 1,000 - \t + 100 - \t + 10 - \t + 1 - \n Current amount: "
			<< tempBet << "\n\t SET MONEY \n";
		loop = true;
		do {
			checkButtons(buttonSet[1], buttonSet[2]);
			buttonHit.run();
		} while (loop);
	} while (!bankVal);
	bankVal = false;
	tempBet = 0;

	// Initializes the value of cards, faces, etc.
	initializeDeck();

	// Main loop
	do {
		shuffleDeck();
		tempBet = 0;
		clear();

		//player needs to bet
		do {
			cout << "How much would you like to bet? : \n\t + 10,000 - \t + 1,000 - \t + 100 - \t + 10 - \t + 1 - \n Current money: " << players[1].monsLeft
				<< " Current bet : " << tempBet << "\n\t PLACE BET \n";
			loop = true;
			do {
				checkButtons(buttonSet[1], buttonSet[3]);
				buttonHit.run();
			} while (loop);
		} while (!betting);
		betting = false;

		setHands();		// Adds starting cards to both hands
		setValue();		// Sets the value of the players' hands
		showHand();		// Prints the hands
		sleep(1);		// Pauses for a second

		//players play - hit or stand
		do {
			do {
				cout << "\n\tSelect the deck to draw a card or double tap STAND to stand\n";
				printDeck();
				do {
					checkButtons(buttonSet[4]);
					buttonHit.run();
				} while (loop);
			} while (!hitLoop);
			hitLoop = false;

			if (hchoice == 'h') {
				cout << "\tHit - heres a card.\n";
				addCard(players[1].hand);
				sleep(1);
				clear();
				setValue();
				showHand();

				//checking for handvalue s.t. if handValue > 21 = you lose;
				setValue();
				if (players[1].handValue > 21) {
					cout << "\tThe players hand exceeds 21 - You go bust\n";
					hchoice = 's';
					doCont = 1;
				}
			}
			else {
				sleep(1);
				clear();
				setValue();
				showHand();
				doCont = 0;
			}
		} while (hchoice == 'h');

		//Only Runs if player doesn't exceed 21
		if (doCont == 0) {

			do {
				cout << "\tYou stand - no cards dealt.\n";

				//raise bets (not actual black jack rules, just for fun)
				cout << "\n Total Money: " << players[1].monsLeft << "\t Bets In: " << players[1].betsIn << endl;

				do {
					cout << "\n Would you like to raise your bet?\n\tYes\tNo\n";
					do {
						checkButtons(buttonSet[5]);
						buttonHit.run();
					} while (loop);
				} while (!newBetLoop);
				newBetLoop = false;
				
				if (bchoice == 'y') {
					clear();
					tempBet = 0;
					do {
						setValue();
						showHand();
						cout << "\tYou stand - no cards dealt.\n";
						cout << "\n Total Money: " << players[1].monsLeft << "\t Bets In: " << players[1].betsIn << endl << endl;
						cout << "How much would you like to bet?\n\t + 10,000 - \t + 1,000 - \t + 100 - \t + 10 - \t + 1 - \n\n Current money: "
							<< players[1].monsLeft - tempBet << "\tCurrent bet : " << players[1].betsIn + tempBet << "\n\t PLACE BET \n";
						do {
							checkButtons(buttonSet[6], buttonSet[7]);
							buttonHit.run();
						} while (loop);
					} while (!addBetLoop);
					addBetLoop = false;
					tempBet = 0;
				}
				else {
					betting2 = false;
				}

				sleep(1);
				clear();
				setValue();
				showHand();

			} while (betting2);


			//reprint hands post card flip
			players[0].hand.at(0).facedown = false;
			clear();
			setValue();
			showHand();
			cout << endl;
			makeDecision();
			cout << endl;

			//allocate money to designated place
			if (isWin == 1) {
				returnBet(2, players[1]);
			}
			else {
				players[1].betsIn = 0;
			}

			cout << " Total Money: " << players[1].monsLeft << endl;
		}
		do {
			//ask for re-run
			cout << "\n Challenge the House again?\n\tYes\tNo\n";
			do {
				checkButtons(buttonSet[8]);
				buttonHit.run();
			} while (loop);
		} while (!reLoop);		
		deleteHand(players[1].hand); deleteHand(players[0].hand);
		doCont = 1;
		clear();
	} while (rechoice == 'y');

	SetConsoleMode(hStdin, fdwSaveOldMode);
}

// Make all of the buttons and assign them to appropriate groups
void initializeButtons() {
	// Buttons
	makeButton(8, 1, 10, 1, 0);						// +10,000
	makeButton(17, 1, 19, 1, 1);					// -10,000
	makeButton(24, 1, 26, 1, 2);					// +1,000
	makeButton(32, 1, 34, 1, 3);					// -1,000
	makeButton(40, 1, 42, 1, 4);					// +100
	makeButton(46, 1, 48, 1, 5);					// -100
	makeButton(56, 1, 58, 1, 6);					// +10
	makeButton(61, 1, 63, 1, 7);					// -10
	makeButton(72, 1, 74, 1, 8);					// +1
	makeButton(76, 1, 78, 1, 9);					// -1
	makeButton(9, 3, 17, 3, 10);					// Set original money
	makeButton(9, 3, 17, 3, 11);					// Set original bet
	makeButton(8, 22, 10, 22, 0);					// +10,000 two
	makeButton(17, 22, 19, 22, 1);					// -10,000 two
	makeButton(24, 22, 26, 22, 2);					// +1,000 two
	makeButton(32, 22, 34, 22, 3);					// -1,000 two
	makeButton(40, 22, 42, 22, 4);					// +100 two
	makeButton(46, 22, 48, 22, 5);					// -100 two
	makeButton(56, 22, 58, 22, 6);					// +10 two
	makeButton(61, 22, 63, 22, 7);					// -10 two
	makeButton(72, 22, 74, 22, 8);					// +1 two
	makeButton(76, 22, 78, 22, 9);					// -1 two
	makeButton(7, 19, 19, 26, 12);					// Deck for drawing
	makeButton(7, 22, 11, 22, 13);					// Yes new bet
	makeButton(8, 25, 18, 25, 14);
	makeButton(7, 20, 11, 20, 15);					// Challenge house yes
	makeButton(15, 20, 18, 20, 16);					// Challenge house no
	makeButton(15, 22, 18, 22, 17);					// No new bet
	makeButton(24, 19, 34, 21, 18, true);			// Big button for stand

	// Making sets of buttons (buttonSet[0] is null)
	for (int i = 12; i < 22; i++) buttonSet[6].push_back(buttons.at(i));	// Set of the second 10 buttons
	for (int i = 0; i < 10; i++) buttonSet[1].push_back(buttons.at(i));		// Set of the first 10 buttons
	buttonSet[2].push_back(buttons.at(10));									// Set money button set
	buttonSet[3].push_back(buttons.at(11));									// Set bet button set
	buttonSet[4].push_back(buttons.at(22));									// Set stand and hit buttons
	buttonSet[4].push_back(buttons.at(28));									// ""
	buttonSet[5].push_back(buttons.at(23));									// Set yes and no new bet buttons
	buttonSet[5].push_back(buttons.at(27));									// ""
	buttonSet[7].push_back(buttons.at(24));									// Set new bet
	buttonSet[8].push_back(buttons.at(25));									// Set challenge house again yes/no
	buttonSet[8].push_back(buttons.at(26));									// ""
}
