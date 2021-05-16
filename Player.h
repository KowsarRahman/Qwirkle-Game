#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H


#include "Tile.h"
#include "LinkedList.h"



#include <regex>
#include <memory>
#include <string>


#define PLAYER_NAME_REGEX "^[A-Z]+$"

class Player {
public:
	Player(std::string name);

	Player(std::string name, int score, std::shared_ptr<LinkedList> hand);

	~Player();

	int getScore();
    int handSize();

	std::string getName();
    std::string getHandForDisplay();
	
    

	
	void addTileToHand(std::shared_ptr<Tile> tile);
	void addScore(int score);
	bool ifTileExists(std::string tile);
	std::shared_ptr<Tile> getTileFromHand(std::string tile, bool deleteTile);
	
	

private:
    
	Colour getTileColour(std::string tileString);
	Shape getTileShape(std::string tileString);	
	

	std::shared_ptr<LinkedList> hand;
	std::string name;
	int score;
	
    	
};

#endif // ASSIGN2_PLAYER_H