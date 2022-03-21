#ifndef BROKENMOSAIC_H
#define BROKENMOSAIC_H

#include <vector>
#include <iostream>

#include "Types.h"

/* This class is used as the 2d vector ADT. The purpose of this class is to store the tiles on the play board (the
** board that the tiles are pushed onto after the inital storage)
*/ 
class BrokenMosaic {
public:

    BrokenMosaic();
    ~BrokenMosaic();

    char returnTile(int tileIndex);
    int returnSize();
    void printBrokenMosaic();
    void excessTilesInput(int amountOfTiles, char tiles);
    void pushFirstPlayer();
    void clear();
    int reduceBrokenScore();

private:
    std::vector<char> brokenMosaic;
};

#endif // BROKENMOSAIC_H