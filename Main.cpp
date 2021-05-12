#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

//#include "Menu.h"


using std::string;
using std::cin;
using std::cout;
using std::endl;

void clearTerminal();

int main(int argc, char** argv) {

	// Set class variables and constants
	int input;
	bool allowClear = true; // This variable allows the clearing of the terminal for the User Interface.
	bool isRunning = true;
	string menuTitle = "-= QUIRKLE MAIN MENU =-";
	string menuOptions[] = { "1. New game", "2. Load Game", "3. Credits", "4. Quit" };
	int menuSize = *(&menuOptions + 1) - menuOptions;

	// Initialise the program
// This is a skeleton of the main menu for Robin to Implement.

	// To make the menu always appear, a loop is used.

	while (isRunning) {
		// Output menu
		cout << menuTitle << endl;
		for (int i = 0; i < menuSize; ++i) {
		       cout << menuOptions[i] << endl;	
		}

		// Ask for user input
		cout << "Enter an option:" << endl;
		cin >> input;

		if (input == 4) {
			// Terminate
			isRunning = false;
			clearTerminal();
		}
		else if (input == 1) {
			clearTerminal();
			cout << "NEW GAME" << endl;
			}
		else if (input == 2) {
			clearTerminal();
			cout << "LOAD GAME" << endl;
		}
		else if (input == 3) {
			clearTerminal();
			cout << "CREDITS" << endl;
		}
	}
	return 0;
}

void clearTerminal() {
	// May need an exception here as this may not work in Windows.
	// If it does not work in Windows, replace "clear" with "cls".
	if (allowClear) {
		system("clear");
	}
}
