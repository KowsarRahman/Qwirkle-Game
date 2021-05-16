#include "MainMenu.h"

MainMenu::MainMenu()
{
}
MainMenu::~MainMenu()
{
}
MainMenu::MainMenu(MainMenu& other)
{
}

void MainMenu::printMenu()
{
	std::cout << "Menu" << "\n";
	std::cout << "----" << "\n";
	std::cout << "1. New Game" << "\n";
	std::cout << "2. Load Game" << "\n";
	std::cout << "3. Credits (Show student information)" << "\n";
	std::cout << "4. Quit" << "\n\n";
}

void MainMenu::runGame()
{

	std::cout << "Welcome to Qwirkle!" << "\n";
	std::cout << "-------------------" << "\n";
	std::string userInput = "";
	std::shared_ptr<bool> gameExited = std::make_shared<bool>();
	*gameExited = false;

	do
	{
		printMenu();
		std::cout << INPUT_PROMPT;

		std::getline(std::cin, userInput);
		if (std::cin.eof()) {
			userInput = "4";
		}

		//selection options
		if (userInput == "1")
		{
			startNewGame(gameExited);
		}
		else if (userInput == "2")
		{
			// Take in user input
			std::cout << "Enter the filename from which load a game" << "\n";
			std::string fileName = "";
			std::cout << INPUT_PROMPT;
			std::getline(std::cin, fileName);


			std::ifstream myfile;
			myfile.open(fileName);

			std::string currentLine;
			std::vector<std::string> tokens;

			// Checks if the file is there
			if (!myfile.is_open())
			{
				std::cout << "Cannot find the file." << "\n \n";
			}
			else {

				while (getline(myfile, currentLine))
				{
					tokens.push_back(currentLine);
				}
				myfile.close();
				
				try 
				{
					loadGame(tokens, gameExited);
				} 
				catch (...)
				{
					std::cout << "Incorrect format for game." << "\n \n";
				}
			}
		}
		else if (userInput == "3") {
			showDetails();
		}
		else if (userInput == "4")
		{
			std::cout << "Goodbye" << "\n";
		}
		else
		{
			std::cout << "Invalid Input" << "\n\n";
		}

	} while ((userInput != "4") && !*gameExited);
}

void MainMenu::showDetails(){
	std::cout << "-----------------------------------" << "\n";
			std::cout << "Name: Robin Singh Cheema" << "\n";
			std::cout << "Student ID: s3815323" << "\n";
			std::cout << "Email: s3815323@student.rmit.edu.au" << "\n";
			std::cout << "-----------------------------------" << "\n";
			std::cout << "Name: Kowsar Rahman" << "\n";
			std::cout << "Student ID: s3825159" << "\n";
			std::cout << "Email: s3825159@student.rmit.edu.au" << "\n";
			std::cout << "-----------------------------------" << "\n";
			std::cout << "Name: Subham Kumar" << "\n";
			std::cout << "Student ID: s3810497" << "\n";
			std::cout << "Email: s3810497@student.rmit.edu.au" << "\n";
			std::cout << "-----------------------------------" << "\n";
			std::cout << "Name: Kristian Oqueli Ambrose" << "\n";
			std::cout << "Student ID: s3839785" << "\n";
			std::cout << "s3839785@student.rmit.edu.au" << "\n";
			std::cout << "-----------------------------------" << "\n\n";
}

void MainMenu::startNewGame(std::shared_ptr<bool> gameExited)
{
	std::shared_ptr<Player> player1 = nullptr;
	std::shared_ptr<Player> player2 = nullptr;
	std::string player2Name;

	std::cout << "Starting a New Game" << "\n";
	std::cout << "Enter a name for player 1 (uppercase characters only)" 
	<< "\n";
	player1 = getPlayer(gameExited);

	if (!*gameExited)
	{
		std::cout << "Enter a name for player 2 (uppercase characters only)" 
		<< "\n";
		player2 = getPlayer(gameExited);
	}

	if (!*gameExited) 
	{
		// names cannot be duplicates
		while (player1->getName() == player2->getName())
		{
			std::cout << "Invalid Input" << "\n";
			player2 = getPlayer(gameExited);
		}

		std::cout << "Lets Play!" << "\n";

		std::shared_ptr<LinkedList> bag = getBag();

		// Deal 6 tiles to each player
		for (int i = 0; i < INITIAL_TILES; i++)
		{
			std::shared_ptr<Tile> tile = bag->popHead();
			std::shared_ptr<Tile> tile2 = bag->popHead();

			player1->addTileToHand(tile);
			player2->addTileToHand(tile2);
		}

		std::shared_ptr<GameEngine> engine = std::make_shared<GameEngine>();
		std::shared_ptr<GameEngineCallback> gec 
		= std::make_shared<GameEngineCallback>();
		std::shared_ptr<Board> board = std::make_shared<Board>();
		engine->playGame(gec, player1, player2, bag, board, gameExited);
	}
}

std::shared_ptr<Player> MainMenu::getPlayer(std::shared_ptr<bool> gameExited)
{
	std::string playerName = "";
	bool playerCreated = false;
	std::shared_ptr<Player> player;

	do
	{
		std::cout << INPUT_PROMPT;
		std::getline(std::cin, playerName);
		if (std::cin.eof()) 
		{
			*gameExited = true;
			std::cout << "\nGoodbye" << std::endl;
		}
		else {
			try
			{
				player = std::make_shared<Player>(playerName);
				playerCreated = true;
			}
			catch (const char* msg)
			{
				playerCreated = false;
				std::cout << msg << std::endl;
			}
		}
		
	} while (!playerCreated && !*gameExited);

	return player;
}

std::shared_ptr<LinkedList> MainMenu::getBag()
{
	// get fresh bag of 2 of each token
	std::string bagTiles = 
	"R1,R2,R3,R4,R5,R6,O1,O2,O3,O4,O5,O6,Y1,Y2,Y3,Y4,Y5,Y6,G1,G2,G3,G4,G5,G6,"
	"B1,B2,B3,B4,B5,B6,P1,P2,P3,P4,P5,P6,R1,R2,R3,R4,R5,R6,O1,O2,O3,O4,O5,O6,"
	"Y1,Y2,Y3,Y4,Y5,Y6,G1,G2,G3,G4,G5,G6,B1,B2,B3,B4,B5,B6,P1,P2,P3,P4,P5,P6";
	std::shared_ptr<LinkedList> bag = std::make_shared<LinkedList>();
	bag->initiliseList(convertTileStringToVector(bagTiles, ","));
	bag->shuffleLinkedList();
	return bag;
}

std::shared_ptr<LinkedList> MainMenu::getBag(std::string bagTiles)
{
	std::shared_ptr<LinkedList> bag = std::make_shared<LinkedList>();
	bag->initiliseList(convertTileStringToVector(bagTiles, ","));
	bag->shuffleLinkedList();
	return bag;
}

std::vector<std::string> MainMenu::convertTileStringToVector
 (std::string tiles, std::string delimiters)
{
    std::stringstream ss(tiles);
    std::vector<std::string> tiles2;
    std::string line;
    while (getline(ss, line))
    {
        std::size_t prev = 0, pos;
        while ((pos = line.find_first_of(delimiters, prev))
		 != std::string::npos)
        {
            if (pos > prev)
                tiles2.push_back(line.substr(prev, pos - prev));
            prev = pos + 1;
        }
        if (prev < line.length())
            tiles2.push_back(line.substr(prev, std::string::npos));
    }

    return tiles2;
}

// Writing data from the loaded save file
void MainMenu::loadGame(std::vector<std::string> data,
 std::shared_ptr<bool> gameExited) 
{
    std::shared_ptr<Player> player1 = nullptr;
    std::shared_ptr<Player> player2 = nullptr;

    int score1 = stoi(data[1]);
    int score2 = stoi(data[4]);

    std::shared_ptr<LinkedList> tileHand1 = std::make_shared<LinkedList>();
    tileHand1->initiliseList(convertTileStringToVector(data[2], ","));

    std::shared_ptr<LinkedList> tileHand2 = std::make_shared<LinkedList>();
    tileHand2->initiliseList(convertTileStringToVector(data[5], ","));

    // Creating players based on who was the current player so they go first
    if (data[0].compare(data[9]) == 0)
    {
        player1 = std::make_shared<Player>(data[0], score1, tileHand1);
        player2 = std::make_shared<Player>(data[3], score2, tileHand2);
    }
    else {
        player1 = std::make_shared<Player>(data[3], score2, tileHand2);
        player2 = std::make_shared<Player>(data[0], score1, tileHand1);
    }

    std::shared_ptr<LinkedList> bag = getBag(data[8]);

    
    std::shared_ptr<Board> board = std::make_shared<Board>();

    
    std::vector<std::string> boardState = convertTileStringToVector(data[7],
	 " @,");

    int tileCounter = 0;
    int boardPosition = 1;
    // Places the loaded board tiles on board
    for (boardPosition = 1; (int)boardState.size() > 
	 boardPosition; boardPosition++)
    {
        std::shared_ptr<Tile> tile = std::make_shared<Tile>
		(boardState[tileCounter][0], boardState[tileCounter][1] - 48);
        board->placeTile(tile, boardState[boardPosition]);
        boardPosition += 1;
        tileCounter += 2;
    }

    std::cout << "Qwirkle game successfully loaded" << "\n";

    std::shared_ptr<GameEngine> engine = std::make_shared<GameEngine>();
    std::shared_ptr<GameEngineCallback> gec = 
	std::make_shared<GameEngineCallback>();
	engine->playGame(gec, player1, player2, bag, board, gameExited);

}
