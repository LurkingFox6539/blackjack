/*  Buttons.h
   Mark Wheeler III
   Purpose:
       A modular header file that can be copy-pasted into any program to allow API for creating buttons in the console
       include {
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hStdin, &fdwSaveOldMode);
    clear();
            } in the first part of main to set it up and end the main with {
    SetConsoleMode(hStdin, fdwSaveOldMode);
            }
        Use clear() instead of clear()
*/


#pragma once
#ifndef _BUTTON_
#define _BUTTON_

#include <windows.h>
#include <iostream>
#include <vector>
#include "Bet.h"
using namespace std;

int x, y;
bool loop;
HANDLE hStdin;
DWORD fdwSaveOldMode, fdwMode;
void clear(), listButtons(), makeButton(int, int, int, int, int, bool);

struct Button {
    // Top left and bottom right coordinates for the boundaries of the button
    // element 0 is x and element 1 is y
    int corner[2] = { 0,0 };
    int opCorner[2] = { 0, 0 };
    // Identifier
    int identity = 999999;
    // Switch statement. Add case using button ID
    void run();
    // Is acitvate on double click (default false)
    bool isDouble = false;
};

vector<Button> buttonSet[10];
vector<Button> buttons;
Button buttonHit;

void checkButtons(vector<Button>&, vector<Button> & = buttonSet[0]);

// Each button contains a unique ID, this is used in the switch case to run a block depending on the corresponding ID
void Button::run() {
    switch (buttonHit.identity) {
    case 0:
        if ((tempBet + 10000) <= 1000000) {
            tempBet += 10000;
            loop = false;
            clear();
        }
        else {
            cout << "That number is above 1,000,000; You can't go higher\n";
            loop = false;
            sleep(1);
            clear();
        }
        break;
    case 1:
        if ((tempBet - 10000) >= 0) {
            tempBet -= 10000;
            loop = false;
            clear();
        }
        else {
            cout << "That number is below 0; You can't go lower\n";
            loop = false;
            sleep(1);
            clear();
        }
        break;
    case 2:
        if ((tempBet + 1000) <= 1000000) {
            tempBet += 1000;
            loop = false;
            clear();
        }
        else {
            cout << "That number is above 1,000,000; You can't go higher\n";
            loop = false;
            sleep(1);
            clear();
        }
        break;
    case 3:
        if ((tempBet - 1000) >= 0) {
            tempBet -= 1000;
            loop = false;
            clear();
        }
        else {
            cout << "That number is below 0; You can't go lower\n";
            loop = false;
            sleep(1);
            clear();
        }
        break;
    case 4:
        if ((tempBet + 100) <= 1000000) {
            tempBet += 100;
            loop = false;
            clear();
        }
        else {
            cout << "That number is above 1,000,000; You can't go higher\n";
            loop = false;
            sleep(1);
            clear();
        }
        break;
    case 5:
        if ((tempBet - 100) >= 0) {
            tempBet -= 100;
            loop = false;
            clear();
        }
        else {
            cout << "That number is below 0; You can't go lower\n";
            loop = false;
            sleep(1);
            clear();
        }
        break;
    case 6:
        if ((tempBet + 10) <= 1000000) {
            tempBet += 10;
            loop = false;
            clear();
        }
        else {
            cout << "That number is above 1,000,000; You can't go higher\n";
            loop = false;
            sleep(1);
            clear();
        }
        break;
    case 7:
        if ((tempBet - 10) >= 0) {
            tempBet -= 10;
            loop = false;
            clear();
        }
        else {
            cout << "That number is below 0; You can't go lower\n";
            loop = false;
            sleep(1);
            clear();
        }
        break;
    case 8:
        if ((tempBet + 1) <= 1000000) {
            tempBet += 1;
            loop = false;
            clear();
        }
        else {
            cout << "That number is above 1,000,000; You can't go higher\n";
            loop = false;
            sleep(1);
            clear();
        }
        break;
    case 9:
        if ((tempBet - 1) >= 0) {
            tempBet -= 1;
            loop = false;
            clear();
        }
        else {
            cout << "That number is below 0; You can't go lower\n";
            loop = false;
            sleep(1);
            clear();
        }
        break;
    case 10:
        if (tempBet == 0) {
            cout << "You can't start the game with no money, please select an amount\n";
            loop = false;
            sleep(2);
            clear();
        }
        else {
            players[1].monsLeft = tempBet;
            bankVal = true;
            loop = false;
            clear();
        }
        break;
    case 11:
        if (tempBet == 0) {
            cout << "You can't bet no money, please select an amount\n";
            loop = false;
            sleep(2);
            clear();
        }
        else if (tempBet > players[1].monsLeft) {
            cout << "You can't bet more money than you have, please select a lower amount\n";
            loop = false;
            sleep(2);
            clear();
        }
        else {
            addBet(tempBet, players[1]);
            betting = true;
            loop = false;
            clear();
        }
        break;
    case 12:
        hitLoop = true;
        hchoice = 'h';
        loop = false;
        break;
    case 13:
        newBetLoop = true;
        bchoice = 'y';
        loop = false;
        break;
    case 14:
        if ((players[1].monsLeft - tempBet) < 0) {
            cout << "You can't bet more money than you have, lower your bet\n";
            loop = false;
            sleep(2);
            clear();
        }
        else {
            addBet(tempBet, players[1]);
            addBetLoop = true;
            loop = false;
        }
        break;
    case 15:
        rechoice = 'y';
        reLoop = true;
        loop = false;
        break;
    case 16:
        rechoice = 'n';
        reLoop = true;
        loop = false;
        break;
    case 17:
        newBetLoop = true;
        bchoice = 'n';
        loop = false;
        break;
    case 18:
        hitLoop = true;
        hchoice = 's';
        loop = false;
        break;
    case 999999:
        loop = true;
        break;
    }
    buttonHit.identity = 999999;
}

// Clear screen and set correct input modes for console
void clear() {
    system("cls");
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE;
    SetConsoleMode(hStdin, fdwMode);
}

// Lists all buttons
void listButtons() {
    for (int i = 0; i < buttons.size(); i++) {
        cout << "\nButton " << i << ": " << buttons.at(i).corner[0] << ", " << buttons.at(i).corner[1] << " | " << buttons.at(i).opCorner[0] << ", " << buttons.at(i).opCorner[1] << endl;
    }
}

// Checks for a button being clicked, put inside loop. Can check up to 2 button sets, second default is the null set buttonSet[0]
void checkButtons(vector<Button>& buttonCheck, vector<Button>& buttonCheck2) {
    DWORD cNumRead;
    INPUT_RECORD record[128];

    ReadConsoleInput(hStdin, record, 128, &cNumRead);

    // Loops for how many inputs it read
    for (DWORD i = 0; i < cNumRead; i++)
    {
        // Skips input if it wasn't a mouse event
        if (MOUSE_EVENT) {
            MOUSE_EVENT_RECORD mer = record[i].Event.MouseEvent;
            // Checks for a double click
            if (mer.dwEventFlags == DOUBLE_CLICK) {
                x = mer.dwMousePosition.X, y = mer.dwMousePosition.Y;
                // Loops for a number of times equal to the size of the vector and checks if the X/Y coords are within the button's parameters
                for (int j = 0; j < buttonCheck.size(); j++) {
                    if ((x >= buttonCheck.at(j).corner[0] && x <= buttonCheck.at(j).opCorner[0]) &&
                        (y >= buttonCheck.at(j).corner[1] && y <= buttonCheck.at(j).opCorner[1]) &&
                        buttonCheck.at(j).isDouble) {
                        buttonHit.identity = buttonCheck.at(j).identity;
                    }
                }
                // Loops for a number of times equal to the size of the vector and checks if the X/Y coords are within the button's parameters
                for (int j = 0; j < buttonCheck2.size(); j++) {
                    if ((x >= buttonCheck2.at(j).corner[0] && x <= buttonCheck2.at(j).opCorner[0]) &&
                        (y >= buttonCheck2.at(j).corner[1] && y <= buttonCheck2.at(j).opCorner[1]) &&
                        buttonCheck2.at(j).isDouble) {
                        buttonHit.identity = buttonCheck2.at(j).identity;
                    }
                }
            }
            // Otherwise checks for the mouse button being lifted from either a left or right click
            else if (mer.dwEventFlags == 0 && mer.dwButtonState != FROM_LEFT_1ST_BUTTON_PRESSED && mer.dwButtonState != RIGHTMOST_BUTTON_PRESSED) {
                x = mer.dwMousePosition.X, y = mer.dwMousePosition.Y;
                // Loops for a number of times equal to the size of the vector and checks if the X/Y coords are within the button's parameters
                for (int j = 0; j < buttonCheck.size(); j++) {
                    if ((x >= buttonCheck.at(j).corner[0] && x <= buttonCheck.at(j).opCorner[0]) &&
                        (y >= buttonCheck.at(j).corner[1] && y <= buttonCheck.at(j).opCorner[1]) &&
                        !buttonCheck.at(j).isDouble) {
                        buttonHit.identity = buttonCheck.at(j).identity;
                    }
                }
                // Loops for a number of times equal to the size of the vector and checks if the X/Y coords are within the button's parameters
                for (int j = 0; j < buttonCheck2.size(); j++) {
                    if ((x >= buttonCheck2.at(j).corner[0] && x <= buttonCheck2.at(j).opCorner[0]) &&
                        (y >= buttonCheck2.at(j).corner[1] && y <= buttonCheck2.at(j).opCorner[1]) &&
                        !buttonCheck2.at(j).isDouble) {
                        buttonHit.identity = buttonCheck2.at(j).identity;
                    }
                }
            }
        }
        // Breaks if it was an input besides a mouse input
        else break;
    }
}

// Makes a new button using top left corner x/y and bottom right corner x/y, an integer ID, and whether to force a double click
void makeButton(int x1, int y1, int x2, int y2, int id, bool doubleClick = false) {
    Button temp;
    temp.corner[0] = x1, temp.corner[1] = y1;
    temp.opCorner[0] = x2, temp.opCorner[1] = y2;
    temp.isDouble = doubleClick;
    temp.identity = id;
    buttons.push_back(temp);
}

#endif
