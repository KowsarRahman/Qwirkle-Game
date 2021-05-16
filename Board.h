#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include "Tile.h"

#include <string>
#include <iostream>
#include <vector>

#define UP 0
#define DOWN 1
#define	LEFT 2
#define	RIGHT 3
#define QWIRKLE_PRE_SCORE 5
#define QWIRKLE_SCORE 6
#define BOARD_SIZE 26
#define BOARD_LOWER_BOUND 0
#define BOARD_UPPER_BOUND 25
#define BOARD_STATE_DELIMITER ", "
#define BOARD_STATE_SPACER "@"

typedef std::vector<std::vector<std::shared_ptr<Tile>>> GameBoard;

class Board {
public:
	Board();

	~Board();
	// Place a tile in the specified location (row, column)
	// return is placement was successful

	bool placeTile(std::shared_ptr<Tile> tile, std::string position);

	std::string getBoardForDisplay();

	std::string getCurrentBoardState();

	bool placeTile(std::shared_ptr<Tile> tile, int row, int column);

	std::string getLetterByRowNumber(int rowNum);

	int getRowNumberByLetter(char rowLetter);

	int calculateScore(std::string position, std::shared_ptr<Tile> tile);

	bool isPositionInBoard(int row, int col);

	std::string getCurrentBoardShape();

	bool isTilePlacementValid(std::string position, std::shared_ptr<Tile> tile);

private:
	GameBoard board;

	bool firstTilePlaced;

	bool checkMatchingString(std::string str, std::string str2, 
	 std::shared_ptr<Tile> tile, bool colour);

	GameBoard getBlankBoard();

	bool checkDirectionPlacement(int direction, int row, int col,
	 std::shared_ptr<Tile> tile);

	int getScoreForDirection(int direction, int row, int col);

	int getRowMovementForDirection(int direction, int row);

	bool tileTouchesExistingTile(int row, int col);

	bool checkIfTileExists(int direction, int row, int col);

	int getColMovementForDirection(int direction, int col);
};

#endif // ASSIGN2_BOARD_H
