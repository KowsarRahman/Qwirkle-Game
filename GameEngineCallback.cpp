#include "GameEngineCallback.h"

GameEngineCallback::GameEngineCallback()
{
}
GameEngineCallback::~GameEngineCallback()
{
}
GameEngineCallback::GameEngineCallback(GameEngineCallback& other)
{
}

void GameEngineCallback::printStartOfTurnDetails(std::shared_ptr<Player> player1,
 std::shared_ptr<Player> player2, std::shared_ptr<Board> board)
{
	
	std::cout << "\n" <<player1->getName() << ", it's your turn" << "\n";
	std::cout << "Score for " << player1->getName() << ": " <<
	player1->getScore() << "\n";
	std::cout << "Score for " << player2->getName() << ": " <<
	player2->getScore() << "\n";
	std::cout << board->getBoardForDisplay() << "\n";
}



void GameEngineCallback::printInvalidInput()
{
	std::cout << "Invalid Input" << "\n";
}

void GameEngineCallback::printHandDetails(std::shared_ptr<Player> player1)
{
	std::cout << "Your hand is" << "\n";
	std::cout << player1->getHandForDisplay();
	std::cout << "\n\n";

}

void GameEngineCallback::printQwirkle()
{
	std::cout << "\n" << "QWIRKLE!!!" << "\n";
}

void GameEngineCallback::printGoodbye()
{
	std::cout << "\n" << "Goodbye" << "\n";
}

void GameEngineCallback::printGameOver(std::shared_ptr<Player> player1,
 std::shared_ptr<Player> player2, std::shared_ptr<Player> winningPlayer,
 bool tie)
{
	std::cout << "\n" << "Game over" << "\n";
	std::cout << "Score for " << player1->getName() << ": " << 
	player1->getScore() << "\n";
	std::cout << "Score for " << player2->getName() << ": " <<
	player2->getScore() << "\n";
	if (tie)
	{
		std::cout << "It's a tie!" << "\n";
	}
	else
	{
		std::cout << "Player " << winningPlayer->getName() << " won!" << "\n";
	}
	std::cout << "Goodbye" << "\n";
}

void GameEngineCallback::printDoubleQwirkle()
{
	std::cout << "\n" << "DOUBLE QWIRKLE!!!" << "\n";
}

void GameEngineCallback::printGetInput()
{
	std::cout << INPUT_PROMPT;
}

void GameEngineCallback::printFailedSave()
{
	std::cout << "\n" << "An error occured, could not save the game." << "\n";
}

void GameEngineCallback::printEmptyBag()
{
	std::cout << "\n" << "Empty bag. No tiles left to swap." << "\n";
}

void GameEngineCallback::printSuccessfulSave()
{
	std::cout << "\n" << "Game successfully saved" << "\n";
}
