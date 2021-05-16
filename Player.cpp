#include "Player.h"

Player::Player(std::string name)
{
	std::regex playerNameRegex (PLAYER_NAME_REGEX);

	
	if (!std::regex_match(name, playerNameRegex))
	{
		throw "Invalid player name";
	}

	this->name = name;
	this->hand = std::make_shared<LinkedList>();
	this->score = 0;
}

Player::Player(std::string name, int score, std::shared_ptr<LinkedList> hand)
{
	std::regex playerNameRegex (PLAYER_NAME_REGEX);

	
	if (!std::regex_match(name, playerNameRegex))
	{
		throw "Invalid player name";
	}

	this->name = name;
	this->hand = hand;
	this->score = score;
}

Player::~Player()
{
}



int Player::getScore()
{
	return this->score;
}



std::string Player::getName()
{
	return this->name;
}



std::shared_ptr<Tile> Player::getTileFromHand(std::string tileS,
 bool deleteTile)
{
	Colour tileColour = tileS.at(0);
	Shape tileShape = std::stoi(tileS.substr(1, std::string::npos));

	int index = this->hand->findIndex(tileColour, tileShape);
	std::shared_ptr<Tile> tile = this->hand->getByIndex(index);
	if (deleteTile)
	{
		this->hand->softDeleteByIndex(index);
	}
	return tile;
}

void Player::addTileToHand(std::shared_ptr<Tile> tile)
{
	this->hand->addBack(tile);
}

std::string Player::getHandForDisplay()
{
	return this->hand->getListForDisplay();
}





void Player::addScore(int scoreN)
{
	this->score = this->score + scoreN;
}

int Player::handSize()
{
	return this->hand->getSize();
}

bool Player::ifTileExists(std::string tile)
{
	int tileIndex = this->hand->findIndex(getTileColour(tile),
	 getTileShape(tile));
	bool exists;
	(tileIndex == -1) ? exists = false : exists = true;
	return exists;
}

Shape Player::getTileShape(std::string tileString)
{
	Shape tileShape = std::stoi(tileString.substr(1, std::string::npos));
	return tileShape;
}

Colour Player::getTileColour(std::string tileString)
{
	Colour tileColour = tileString.at(0);
	return tileColour;
}
