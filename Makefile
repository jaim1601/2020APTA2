.default: all

all: azul

clean:
	rm -f azul *.o

azul: main.o utils.o Player.o PlayMosaic.o StorageMosaic.o BrokenMosaic.o TileBag.o Tiles.o BSTGame.o BST_Node.o BSTFact.o NewFact.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^