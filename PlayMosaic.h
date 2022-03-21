#ifndef PLAYMOSAIC_H
#define PLAYMOSAIC_H

#include <iostream>

#include "Types.h"

/* This class is used as the 2d array ADT. The purpose of this class is to store the tiles on the play board (the
** board that the tiles are pushed onto after the inital storage)
*/ 
class PlayMosaic {
public:

    PlayMosaic();
    ~PlayMosaic();

    char getPartMosaic(int colIndex, int rowIndex);
    void printlinePlayMosaic(int row);
    void setPartMosaic(int colIndex, int rowIndex, char newTile);
    int mosaicInput(int rowIndex, char newTile);
    bool verifyFilledPlayMosaic(int rowIndex,char charVerify);
    int findNearbyTiles(int colIndex,int rowIndex);
    bool isCharacterHere(int colIndex,int rowIndex);
    
private:
    char mosaic_board[PLAYER_MOSAIC_SIZE][PLAYER_MOSAIC_SIZE];
};

#endif // PLAYMOSAIC_H