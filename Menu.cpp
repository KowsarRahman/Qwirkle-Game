#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "menu.h"


using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv) {

	// Set class variables and constants
	int input;
	isRunning = true;
	menuTitle = "-= QUIRKLE MAIN MENU =-";
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
			cout << "NEW GAME" << endl;
			clearTerminal();
		}
		else if (input == 2) {
			cout << "LOAD GAME" << endl;
			clearTerminal();
		}
		else if (input == 3) {
			cout << "CREDITS" << endl;
			clearTerminal();
		}
	}
	return 0;
}

void clearTerminal() {
	system("clear");
}
