#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Messages.h"

using std::string;
using std::cout;
using std::endl;

string creditContents[] = {"Subham Kumar", "Kristian Oqueli Ambrose", "Kowsar Rahman", "Robin Singh Cheema"};
int creditsSize = *(&creditContents + 1) - creditContents;

string programMessages[] = {					// Message IDs
	"0: DEBUG MESSAGE",					// 0
	"Welcome to Quirkle!",					// 1
	"Enter a name for player ",				// 2
	"(Max 10 characters and uppercase characters only!)",	// 3
	"Let's play!",						// 4
	"Enter the filename of the file you wish to load:",	// 5
	"Quirkle game succesfully loaded"			// 6
	"Error: The name you entered contains invalid characters!" // 7
	"FATAL ERROR - An exception has been caught and has caused the program to stop." // 8	
};
int numOfMessages = *(&programMessages + 1) - programMessages;
string msg = "";


Messages::Messages() {
	cout << "A Message class has been created" << endl;
}

Messages::~Messages() {
	cout << "A Menu has been deconstructed" << endl;
}


void Messages::credits() {
	for (int i = 0; i < creditsSize; ++i) {
		cout <<  " -" << creditContents[i] << endl;
	}
}

// The function below gets a message ID (via it's pointer perhaps?) and prints it to the terminal.
// It does not cout directly through here as the message may or may not need a new line, i.e. the message may need to be concatenated.
void Messages::displayMsg(int messageID, std::string customMsg) {
	// First check if a custom message is passed:
	//for (string message : programMessages) {
	if (customMsg.size() > 0) {
		cout << findMsg(messageID) << customMsg << endl;
		}
	else {
		cout << findMsg(messageID) << endl;
	}	
}

string Messages::findMsg(int messageID) {
	for (int i = 0; i < numOfMessages; ++i) {
		if (messageID == i) {
			msg = programMessages[i];
		}
	}
	return msg;
}
