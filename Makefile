.default: all

all: qwirkle

clean:
	rm -rf qwirkle *.o *.dSYM

qwirkle: Board.o GameEngine.o GameEngineCallback.o MainMenu.o LinkedList.o Node.o Player.o qwirkle.o Tile.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
