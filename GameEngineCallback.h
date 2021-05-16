#ifndef ASSIGN2_GAMEENGINECALLBACK_H
#define ASSIGN2_GAMEENGINECALLBACK_H

#include "Player.h"
#include "Board.h"

#include <iostream>
#include <memory>

#define INPUT_PROMPT "> "

class GameEngineCallback {
public:
    GameEngineCallback();

    ~GameEngineCallback();

    GameEngineCallback(GameEngineCallback &other);

    void printDoubleQwirkle();

    void printStartOfTurnDetails(std::shared_ptr<Player> player1, 
     std::shared_ptr<Player> player2, std::shared_ptr<Board> board);

    void printHandDetails(std::shared_ptr<Player> player1);

    void printQwirkle();

    void printGoodbye();

    void printInvalidInput();

    void printGameOver(std::shared_ptr<Player> player1,
     std::shared_ptr<Player> player2, std::shared_ptr<Player> winningPlayer,
     bool tie);

    void printSuccessfulSave();

    void printFailedSave();

    void printGetInput();

    void printEmptyBag();

};

#endif // ASSIGN2_GAMEENGINECALLBACK_H
