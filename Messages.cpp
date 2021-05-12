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
void displayMsg(int messageID, string customMsg) {
	// First check if a custom message is passed:
	if (messageID == 0) {
		// Output message with ID 0
	}
	else {
		// TODO return (print) the message of the id passed through here.
		
	}
}
