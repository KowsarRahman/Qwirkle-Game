#ifndef ASSIGN2_MAINMENU_H
#define ASSIGN2_MAINMENU_H

#include "LinkedList.h"
#include "GameEngine.h"
#include "Player.h"
#include "Board.h"
#include "GameEngineCallback.h"

#include <vector>
#include <memory>

#define INITIAL_TILES 6

/* 
 * GameLauncher class - responsible for the menu and also starting game,
 * this is one of two classes that print to the console (other is GEC)
 */
class MainMenu {
public:
	MainMenu();

	MainMenu(MainMenu& other);

	~MainMenu();

	void runGame();

	void printMenu();

	void showDetails();

	// Methods to get game ready, anything made here is passed to game engine
	void startNewGame(std::shared_ptr<bool> gameExited);

	void loadGame(std::vector<std::string> data,
	 std::shared_ptr<bool> gameExited);

private:
	std::shared_ptr<Player> getPlayer(std::shared_ptr<bool> gameExited);

	std::shared_ptr<LinkedList> getBag(std::string bag);

	std::shared_ptr<LinkedList> getBag();

	std::vector<std::string> convertTileStringToVector(std::string tiles,
	 std::string delimiters);
};

#endif // ASSIGN2_MAINMENU_H
