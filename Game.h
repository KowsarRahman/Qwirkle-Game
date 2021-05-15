#ifndef GAME_ENGINE
#define GAME_ENGINE

using "LinkedList.h"
using "Tile.h"

public:
	void gameInit(std::string p1Name, std::string p2Name);
	void initTileBag();

private:
	void gameBoard(Tile tile, int posX, int posY);

#endif //GAME_ENGINE
