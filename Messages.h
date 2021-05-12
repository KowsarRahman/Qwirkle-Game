#ifndef MAIN_MENU
#define MAIN_MENU

// This header file will contain all of the messages to be output to the terminal.
// Messages will be called through the displayMsg function in Menu.cpp

class Messages {
public:
	// Constuctor/deconstructor
	Messages();
	~Messages();

	// Functions and Methods
	void credits();

	// Variables and Constants
	int displayMsg();
	std::string msg01;


private:
	// Functions and Methods
	void clearTerminal();
	
	// Variables and constants
	bool isRunning;
	std::string menuTitle;
	
};
#endif //MAIN_MENU
