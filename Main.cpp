#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Messages.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

void clearTerminal();
bool allowClear = true;	// This variable allows the clearing of the terminal for the User Interface.	

int main(int argc, char** argv) {

	// Set class variables and constants
	int input;
	bool isRunning = true;
	string menuTitle = "-= QUIRKLE MAIN MENU =-";
	string menuOptions[] = { "1. New game", "2. Load Game", "3. Credits", "4. Quit", "0. DEBUG" };
	int menuSize = *(&menuOptions + 1) - menuOptions;

	Messages* messages = new Messages();

	// Initialise the program
// This is a skeleton of the main menu for Robin to Implement.

	messages->displayMsg(1, "");

	// To make the menu always appear, a loop is used.
	while (isRunning) {
		// Output menu
	cout << endl << menuTitle << endl;
		for (int i = 0; i < menuSize; ++i) {
		       cout << menuOptions[i] << endl;	
		}

		// Ask for user input
		cout << "Enter an option:" << endl;
		cin >> input;

		// TODO add a check if a number that is < 1 or > 4 is entered and ask the user to enter a valid option.
		if (input == 4) {
			// Terminate
			isRunning = false;
			cout << "Terminating program...";
		}
		else if (input == 1) {
			clearTerminal();
			cout << "NEW GAME" << endl;
			// TODO Call the new game function/method from here
			
			messages->displayMsg(2, "1");
			//TODO input player 1

			messages->displayMsg(2, "2");
			//TODO input player 2
			//
			// Start Quirkle game...
		}
		else if (input == 2) {
			clearTerminal();
			cout << "LOAD GAME" << endl;
			messages->displayMsg(5, "");
			
			// TODO Call the load game function/method from here
		}
		else if (input == 3) {
			clearTerminal();
			cout << "CREDITS" << endl;
			// TODO Call the credits function/method from here
			messages->credits();
		}
		// DEBUG OPTION, REMOVE IN FINAL SUBMISSION
		else if (input == 0) {
			clearTerminal();
			cout << "DEBUG OPTION" << endl;
			//menu->displayMessage(1); // message with id 1 is a debug message
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
