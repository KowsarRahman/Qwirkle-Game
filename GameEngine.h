#ifndef ASSIGN2_GAMEENGINE_H
#define ASSIGN2_GAMEENGINE_H

#include "GameEngineCallback.h"
#include "Player.h"
#include "LinkedList.h"
#include "Board.h"

#include <iostream>
#include <fstream>
#include <memory>

#define TOTAL_GAME_SAVE_DETAILS 10

class GameEngine {
public:
    GameEngine();

    ~GameEngine();

    GameEngine(GameEngine& other);

    
    std::string getValidatedPlayerAction(std::shared_ptr<GameEngineCallback>gec,
     std::shared_ptr<Player> currentPlayer,
     std::shared_ptr<Board> board,
     std::shared_ptr<LinkedList> bag);

    void playGame(std::shared_ptr<GameEngineCallback> gec,
     std::shared_ptr<Player> player1, std::shared_ptr<Player> player2,
     std::shared_ptr<LinkedList> bag, std::shared_ptr<Board> board,
     std::shared_ptr<bool>gameExited);

    void determineWinningPlayer(std::shared_ptr<Player> player1, 
     std::shared_ptr<Player> player2, std::shared_ptr<GameEngineCallback> gec);

    void processPlayerAction(std::string action, 
     std::shared_ptr<Player> currentPlayer, 
     std::shared_ptr<Player> nonCurrentPlayer, std::shared_ptr<Board> board, 
     std::shared_ptr<LinkedList> bag, std::shared_ptr<GameEngineCallback> gec, 
     std::shared_ptr<bool> gameExited);

    bool isValidLocation(std::string location, std::shared_ptr<Board> board);

    bool isGameEnded(std::shared_ptr<LinkedList> bag,
     std::shared_ptr<Player> currentPlayer, 
     std::shared_ptr<Player> nonCurrentPlayer);

    bool isValidTile(std::string tile);

    

private:
    Colour getTileColour(std::string tileString);
    
    Shape getTileShape(std::string tileString);

};

#endif // ASSIGN2_GAMEENGINE_H
