#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
	int input;
	string menuOptions[] = { "1. New game", "2. Load Game", "3. Credits", "4. Quit" };
	int menuSize = *(&menuOptions + 1) - menuOptions;

	// Initialise the program
	// This is a skeleton of the main menu for Robin to Implement
	
	// output menu:
	cout << "Main menu" << endl;
	for (int i = 0; i < menuSize; ++i) {
	       cout << menuOptions[i] << endl;	
	}
	
	// Ask for user input
	cout << "Enter an option:" << endl;

	input = 0; // It is currently hard-coded to terminate the program. Make the "input" variable use a cin from the keyboard
	if (input == 4) {
		// Terminate
		return 0;
	}
	else if (input == 1) {
		cout << "NEW GAME" << endl;
	}
	else if (input == 2) {
		cout << "LOAD GAME" << endl;
	}
	else if (input == 3) {
		cout << "CREDITS" << endl;
	}
	return 0;
}
