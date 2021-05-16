#include "GameEngine.h"
//Constructors
GameEngine::GameEngine()
{
}
GameEngine::~GameEngine()
{
}
GameEngine::GameEngine(GameEngine& other)
{
}
void GameEngine::playGame(std::shared_ptr<GameEngineCallback> gec,
 std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, 
 std::shared_ptr<LinkedList> bag, std::shared_ptr<Board> board, 
 std::shared_ptr<bool> gameExited)
{
	
	std::shared_ptr<Player> currentPlayer = player1;
	std::shared_ptr<Player> nonCurrentPlayer = player2;

	while (!*gameExited)
	{
	
		gec->printStartOfTurnDetails(currentPlayer, nonCurrentPlayer, board);
		
		gec->printHandDetails(currentPlayer);

		
		std::string playerAction = getValidatedPlayerAction(gec, currentPlayer, 
		board, bag);
		processPlayerAction(playerAction, currentPlayer, nonCurrentPlayer,
		 board, bag, gec, gameExited);
		
		bool gameEnded = isGameEnded(bag, currentPlayer, nonCurrentPlayer);

	
		if (gameEnded)
		{
			*gameExited = true;
			determineWinningPlayer(player1, player2, gec);
		}

		if (!*gameExited)
		{
			std::shared_ptr<Player> temp = currentPlayer;
			currentPlayer = nonCurrentPlayer;
			nonCurrentPlayer = temp;
		}
	}
}


void GameEngine::processPlayerAction(std::string action, 
 std::shared_ptr<Player> currentPlayer,
 std::shared_ptr<Player> nonCurrentPlayer,
 std::shared_ptr<Board> board, std::shared_ptr<LinkedList> bag,
 std::shared_ptr<GameEngineCallback> gec, std::shared_ptr<bool> gameExited)
{
	
	std::istringstream stream(action);
	std::vector<std::string> tokens((std::istream_iterator<std::string>(stream))
	,std::istream_iterator<std::string>());

	if (tokens[0] == "place")
	{
		std::shared_ptr<Tile> tile = currentPlayer->getTileFromHand(tokens[1],
		true);
		board->placeTile(tile, tokens[3]);

		
		int score = board->calculateScore(tokens[3], tile);

		
		currentPlayer->addScore(score);

	
		if (bag->getSize() > 0)
		{
			currentPlayer->addTileToHand(bag->popHead());
		}

		
		if (currentPlayer->handSize() == 0)
		{
			currentPlayer->addScore(6);
		}
		
	}
	else if (tokens[0] == "replace")
	{
		
		std::shared_ptr<Tile> tile = currentPlayer->getTileFromHand(tokens[1], 
		true);

		
		bag->addBack(tile);

		
		currentPlayer->addTileToHand(bag->popHead());
	
	}
	else if (tokens[0] == "save")
	{
		
		std::string saveGameFile = tokens[1] + ".txt";
		std::ofstream outputGameFile;
		outputGameFile.open(saveGameFile);

		
		std::string gameStatus[TOTAL_GAME_SAVE_DETAILS] = {
			currentPlayer->getName(),
			std::to_string(currentPlayer->getScore()),
			currentPlayer->getHandForDisplay(),
			nonCurrentPlayer->getName(),
			std::to_string(nonCurrentPlayer->getScore()),
			nonCurrentPlayer->getHandForDisplay(),
			board->getCurrentBoardShape(),
			board->getCurrentBoardState(),
			bag->getListForDisplay(),
			currentPlayer->getName()
		};

	
		try
		{
			for (int i = 0; i < TOTAL_GAME_SAVE_DETAILS; i++)
			{
				outputGameFile << gameStatus[i] << std::endl;
			}
			outputGameFile.close();
			gec->printSuccessfulSave();
		}
		catch (...)
		{
			gec->printFailedSave();
		}

	
		std::string action = getValidatedPlayerAction(gec, currentPlayer, 
		board, bag);
		processPlayerAction(action, currentPlayer, nonCurrentPlayer, board, bag,
		gec, gameExited);
	}
	else if (tokens[0] == "quit")
	{
		gec->printGoodbye();
		*gameExited = true;
		// end quit action
	}
}

std::string GameEngine::getValidatedPlayerAction(
 std::shared_ptr<GameEngineCallback> gec,
 std::shared_ptr<Player> currentPlayer, 
 std::shared_ptr<Board> board, std::shared_ptr<LinkedList> bag)
{
	bool inputCorrect = false;
	std::string playerAction;

	while (!inputCorrect)
	{
		gec->printGetInput();
		std::getline(std::cin, playerAction); 
		
		if(std:: cin.eof()){
		playerAction = "quit";
		}
		inputCorrect = true;

		
		std::istringstream stream(playerAction);

		std::vector<std::string> tokens((
		 std::istream_iterator<std::string>(stream)),
		 std::istream_iterator<std::string>());

	
		int tokensSize = tokens.size();
		if (tokensSize > 0)
		{	
			if (tokens[0] == "place")
			{
				if (tokensSize == 4)
				{
			
					if (!isValidTile(tokens[1]) || !isValidLocation(tokens[3],
					 board))
					{
						gec->printInvalidInput();
						inputCorrect = false;
					}
					else
					{
						if (!currentPlayer->ifTileExists(tokens[1]) ||
						 !board->isTilePlacementValid(tokens[3],
						  currentPlayer->getTileFromHand(tokens[1], false)))
						{
							gec->printInvalidInput();
							inputCorrect = false;
						}
					}
				}
				else
				{
					gec->printInvalidInput();
					inputCorrect = false;
				}
			}
			else if (tokens[0] == "replace")
			{
				if (tokensSize == 2)
				{
					if (!isValidTile(tokens[1]))
					{
						gec->printInvalidInput();
						inputCorrect = false;
					}
					else
					{
						if (!currentPlayer->ifTileExists(tokens[1]))
						{
							gec->printInvalidInput();
							inputCorrect = false;
						}
						if (bag->getSize() == 0)
						{
							gec->printEmptyBag();
							inputCorrect = false;
						}
					}
				}
				else
				{
					gec->printInvalidInput();
					inputCorrect = false;
				}
			}
			else if (tokens[0] == "save")
			{
				if (tokensSize != 2)
				{
					gec->printInvalidInput();
					inputCorrect = false;
				}
			}
			else if (tokens[0] == "quit" ||std:: cin.eof() )
			{
				
				if (tokensSize != 1)
				{
					gec->printInvalidInput();
					inputCorrect = false;
				}
			}
			else
			{
				gec->printInvalidInput();
				inputCorrect = false;
			}
		}
		else
		{
			gec->printInvalidInput();
			inputCorrect = false;
		}
	}

	return playerAction;
}



bool GameEngine::isValidLocation(std::string location,
std::shared_ptr<Board> board)
{
	bool returnVal = false;
	
	try
	{
		int row = board->getRowNumberByLetter(location.at(0));
		int col = std::stoi(location.substr(1, std::string::npos));
		returnVal = board->isPositionInBoard(row, col);
	}
	catch (const std::exception&)
	{
		returnVal = false;
	}
	return returnVal;
}

bool GameEngine::isValidTile(std::string tile)
{
	std::regex regex_expr("([ROYGBP]){1}([123456]){1}");
	return std::regex_match(tile, regex_expr);
}

bool GameEngine::isGameEnded(std::shared_ptr<LinkedList> bag,
std::shared_ptr<Player> currentPlayer, std::shared_ptr<Player> nonCurrentPlayer)
{
	bool gameEnded = false;

	if (bag->getSize() == 0 && (currentPlayer->handSize() == 0 ||
	nonCurrentPlayer->handSize() == 0))
	{
		gameEnded = true;
	}

	return gameEnded;
}



Colour GameEngine::getTileColour(std::string tileString)
{
	Colour tileColour = tileString.at(0);
	return tileColour;
}

Shape GameEngine::getTileShape(std::string tileString)
{
	Shape tileShape = std::stoi(tileString.substr(1, std::string::npos));
	return tileShape;
}

void GameEngine::determineWinningPlayer(std::shared_ptr<Player> player1,
 std::shared_ptr<Player> player2,  std::shared_ptr<GameEngineCallback> gec) 
{
	int player1Score = player1->getScore();
	int player2Score = player2->getScore();

	if (player1Score > player2Score)
	{
		gec->printGameOver(player1, player2, player1, false);
	}
	else if (player1Score < player2Score)
	{
		gec->printGameOver(player1, player2, player2, false);
	}
	else {
		gec->printGameOver(player1, player2, nullptr, true);
	}
}
