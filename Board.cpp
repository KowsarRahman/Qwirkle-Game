#include "Board.h"

Board::Board()
{
	this->board = getBlankBoard();
	this->firstTilePlaced = false;
}

Board::~Board()
{
}

bool Board::placeTile(std::shared_ptr<Tile> tile, std::string position)
{
	int row = getRowNumberByLetter(position.at(0));
	int col = std::stoi(position.substr(1, std::string::npos));

	return placeTile(tile, row, col);
}

bool Board::placeTile(std::shared_ptr<Tile> tile, int row, int column)
{
	if (!this->firstTilePlaced)
	{
		this->firstTilePlaced = true;
	}

	std::shared_ptr<Tile> temp = this->board[row][column];

	this->board[row][column] = tile;

	return true;
}

std::string Board::getBoardForDisplay()
{
	std::string boardString;

	boardString.append("   0");
	for (int i = 1; i < static_cast<int>(this->board.size()); i++)
	{
		(i < 11) ? boardString.append("  ") : boardString.append(" ");
		boardString.append(std::to_string(i));
	}

	boardString.append(" \n");

	boardString.append("  -");
	for (int i = 0; i < static_cast<int>(this->board.size()); i++)
	{
		boardString.append("---");
	}

	boardString.append("\n");

	for (int i = 0; i < static_cast<int>(this->board.size()); i++) {
		boardString.append(getLetterByRowNumber(i));
		boardString.append(" ");
		for (int j = 0; j < static_cast<int>(this->board[i].size()); j++)
		{
			std::shared_ptr<Tile> temp = this->board[i][j];

			if (temp->blankStatus())
			{
				boardString.append("|  ");
			}
			else
			{
				boardString.append("|");
				boardString.append(temp->getTileString());
			}
		}
		boardString.append("|");
		boardString.append("\n");
	}

	return boardString;
}


std::string Board::getLetterByRowNumber(int rowNum)
{
	int rowChar = rowNum + 65;
	char rowLetter = (char)rowChar;
	return std::string(1, rowLetter);
}


int Board::calculateScore(std::string position, std::shared_ptr<Tile> tile)
{
	int score = 0;

	int row = getRowNumberByLetter(position.at(0));
	int col = std::stoi(position.substr(1, std::string::npos));

	int upScore = getScoreForDirection(UP, row, col);
	int downScore = getScoreForDirection(DOWN, row, col);
	int leftScore = getScoreForDirection(LEFT, row, col);
	int rightScore = getScoreForDirection(RIGHT, row, col);


	if ((upScore > 0 || downScore > 0) && (leftScore > 0 && rightScore > 0))
	{
		score = 2;
	}
	else
	{
		score = 1;
	}

	int upDown = upScore + downScore;
	int leftRight = leftScore + rightScore;

	if (upDown == QWIRKLE_PRE_SCORE && leftRight == QWIRKLE_PRE_SCORE)
	{
		std::cout << "DOUBLE QWIRKLE";
		score += (2 * QWIRKLE_SCORE);
	}
	else if (upDown == QWIRKLE_PRE_SCORE || leftRight == QWIRKLE_PRE_SCORE)
	{
		 std::cout << "QWIRKLE";
		score += QWIRKLE_SCORE;
	}

	return upScore + downScore + leftScore + rightScore + score;
}

int Board::getRowNumberByLetter(char rowLetter)
{
	int row = (int)rowLetter;
	row = row - 65;
	return row;
}

bool Board::isTilePlacementValid(std::string position,
 std::shared_ptr<Tile> tile)
{
	bool placementValid;

	int row = getRowNumberByLetter(position.at(0));
	int col = std::stoi(position.substr(1, std::string::npos));

	bool up = checkDirectionPlacement(UP, row, col, tile);
	bool down = checkDirectionPlacement(DOWN, row, col, tile);
	bool left = checkDirectionPlacement(LEFT, row, col, tile);
	bool right = checkDirectionPlacement(RIGHT, row, col, tile);

	if (up && down && left && right)
	{
		placementValid = true;
	}
	else
	{
		placementValid = false;
	}


	if (this->firstTilePlaced && placementValid)
	{
		placementValid = tileTouchesExistingTile(row, col);
	}

	if (placementValid)
	{
		std::shared_ptr<Tile> tile = this->board[row][col];
		if (!tile->blankStatus())
		{
			placementValid = false;
		}
	}

	return placementValid;
}



bool Board::checkDirectionPlacement(int direction, int row, int col,
 std::shared_ptr<Tile> tile)
{
	bool tileValid = true;

	int currentRow = getRowMovementForDirection(direction, row);
	int currentCol = getColMovementForDirection(direction, col);
	if (isPositionInBoard(currentRow, currentCol))
	{

		bool tilesExist = true;
		std::string colours = "";
		std::string shapes = "";

		while (tilesExist)
		{
			if (isPositionInBoard(currentRow, currentCol))
			{
				std::shared_ptr<Tile> temp = this->board[currentRow][currentCol];
				if (temp->blankStatus())
				{
					tilesExist = false;
				}
				else
				{
					colours.append(std::string(1, temp->getColour()));
					shapes.append(std::string(1, temp->getShape()));
				}
				currentRow = getRowMovementForDirection(direction, currentRow);
				currentCol = getColMovementForDirection(direction, currentCol);
			}
			else
			{
				tilesExist = false;
			}
		}

		tileValid = checkMatchingString(colours, shapes, tile, true);

		if (tileValid)
		{
			tileValid = checkMatchingString(shapes, colours, tile, false);
		}
	}

	return tileValid;
}

bool Board::checkMatchingString(std::string str, std::string str2,
 std::shared_ptr<Tile> tile, bool colour)
{
	bool tileValid = true;
	if (str.size() > 1)
	{
		if (str.at(0) == str.at(1))
		{
			if (colour)
			{
				if (tile->getColour() != str.at(0))
				{
					tileValid = false;
				}
				if (str2.find(std::string(1, tile->getShape()))
				!= std::string::npos)
				{
					tileValid = false;
				}
			}
			else
			{
				if (tile->getShape() != str.at(0))
				{
					tileValid = false;
				}
				if (str2.find(std::string(1, tile->getColour()))
				!= std::string::npos)
				{
					tileValid = false;
				}
			}
		}
	}
	else if (str.size() == 1)
	{
		if (colour)
		{
			if (!(tile->getColour() == str.at(0)) && 
			!(tile->getShape() == str2.at(0)))
			{
				tileValid = false;
			}
			if (tile->getColour() == str.at(0) && 
			tile->getShape() == str2.at(0))
			{
				tileValid = false;
			}
		}
		else
		{
			tileValid = true;
		}
	}

	return tileValid;
}

GameBoard Board::getBlankBoard()
{
	std::vector<std::vector<std::shared_ptr<Tile>>> board;

	for (int i = 0; i < BOARD_SIZE; i++) {
		
		std::vector<std::shared_ptr<Tile>> colVec;

		for (int j = 0; j < BOARD_SIZE; j++) {
			colVec.push_back(std::make_shared<Tile>());
		}
		board.push_back(colVec);
	}

	return board;
}

int Board::getScoreForDirection(int direction, int row, int col)
{
	int score = 0;

	int currentRow = getRowMovementForDirection(direction, row);
	int currentCol = getColMovementForDirection(direction, col);
	if (isPositionInBoard(currentRow, currentCol))
	{
		bool tilesExist = true;
		std::string colours = "";

		while (tilesExist)
		{
			if (isPositionInBoard(currentRow, currentCol))
			{
				std::shared_ptr<Tile> temp = this->board[currentRow][currentCol];
				if (temp->blankStatus())
				{
					tilesExist = false;
				}
				else
				{
					colours.append(std::string(1, temp->getColour()));
				}
				currentRow = getRowMovementForDirection(direction, currentRow);
				currentCol = getColMovementForDirection(direction, currentCol);
			}
			else
			{
				tilesExist = false;
			}
		}
		score = colours.size();
	}

	return score;
}


int Board::getColMovementForDirection(int direction, int col)
{
	int newCol = col;

	if (direction == LEFT)
	{
		newCol--;
	}
	else if (direction == RIGHT)
	{
		newCol++;
	}

	return newCol;
}

bool Board::tileTouchesExistingTile(int row, int col)
{
	bool validTile = true;
	bool up = checkIfTileExists(UP, row, col);
	bool down = checkIfTileExists(DOWN, row, col);
	bool left = checkIfTileExists(LEFT, row, col);
	bool right = checkIfTileExists(RIGHT, row, col);

	if (!up && !down && !left && !right)
	{
		validTile = false;
	}
	return validTile;
}

bool Board::checkIfTileExists(int direction, int row, int col)
{
	int tileExists;

	int newRow = getRowMovementForDirection(direction, row);
	int newCol = getColMovementForDirection(direction, col);

	if (isPositionInBoard(newRow, newCol))
	{
		std::shared_ptr<Tile> tile = this->board[newRow][newCol];

		tileExists = (tile->blankStatus()) ? false : true;
	}
	else
	{
		tileExists = false;
	}
	return tileExists;
}
int Board::getRowMovementForDirection(int direction, int row)
{
	int newRow = row;

	if (direction == UP)
	{
		newRow--;
	}
	else if (direction == DOWN)
	{
		newRow++;
	}

	return newRow;
}


bool Board::isPositionInBoard(int currentRow, int currentCol)
{
	bool inBoard;

	if (currentRow >= BOARD_LOWER_BOUND && currentCol >= BOARD_LOWER_BOUND
		&& currentRow <= BOARD_UPPER_BOUND && currentCol <= BOARD_UPPER_BOUND)
	{
		inBoard = true;
	}
	else
	{
		inBoard = false;
	}

	return inBoard;
}

std::string Board::getCurrentBoardShape()
{
	std::string boardShape;
	boardShape.append(std::to_string(BOARD_SIZE));
	boardShape.append(",");
	boardShape.append(std::to_string(BOARD_SIZE));
	return boardShape;
}

std::string Board::getCurrentBoardState()
{
	std::string boardState;

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// get current tile
			std::shared_ptr<Tile> currentTile = this->board[i][j];

			if (!currentTile->blankStatus())
			{
				boardState.append(currentTile->getTileString());
				boardState.append(BOARD_STATE_SPACER);
				boardState.append(getLetterByRowNumber(i) + std::to_string(j));
				boardState.append(BOARD_STATE_DELIMITER);
			}
		}
	}
	return boardState.substr(0, boardState.length() - 2);
}


