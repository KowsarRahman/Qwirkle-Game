#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Messages.h"

#define GROUP_MEMBERS  4
#define STUDENT_COMPONENTS  3

using std::string;
using std::cout;
using std::endl;

string creditContents[GROUP_MEMBERS][STUDENT_COMPONENTS] = {	{"Subham Kumar", "s3810497", "s3810497@student.rmit.edu.au"}, 
				{"Kristian Oqueli Ambrose", "s3839785", "s3839785@student.rmit.edu.au"}, 
				{"Kowsar Rahman", "s3825159", "s3825159@student.rmit.edu.au"},
				{"Robin Singh Cheema", "s3815323", "s3815323@student.rmit.edu.au"}};

string programMessages[] = {					// Message IDs
	"0: DEBUG MESSAGE",					// 0
	"Welcome to Quirkle!",					// 1
	"Enter a name for player ",				// 2
	"(Max 10 characters and uppercase characters only!)",	// 3
	"Let's play!",						// 4
	"Enter the filename of the file you wish to load:",	// 5
	"Quirkle game succesfully loaded",			// 6
	"Error: The name you entered contains invalid characters!", // 7
	"FATAL ERROR - An exception has been caught and has caused the program to stop.", // 8	
	"--------------------------------"			// 9
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
	displayMsg(9, "");
	for (int i = 0; i < GROUP_MEMBERS; ++i) {
		for (int j = 0; j < STUDENT_COMPONENTS; ++j) {
			cout <<  "  " << creditContents[i][j] << endl;
		}
		cout << endl;
	}
	displayMsg(9, "");
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
