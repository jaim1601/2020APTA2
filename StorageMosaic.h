#ifndef STORAGEMOSAIC_H
#define STORAGEMOSAIC_H

#include <iostream>

#include "Types.h"

// This Class is used as another 2D Array to contain all of the Mosaic pieces waiting to be placed on the board
class StorageMosaic {
public:
    StorageMosaic();
    ~StorageMosaic();

    char getPartMosaic(int rowIndex, int colIndex);
    void printlineStorageMosaic(int row);
    void clearLineMosaic(int row);
    void setPartMosaic(int rowIndex, int colIndex, char newTile);
    int setStorageMosaic(char tileUsed, int rowIndex,int amountOfTiles);
    bool filledLineCheck(int rowIndex);
    bool checkLineChar(int rowIndex, char tileInput);
    
private:
    char mosaic_storage[PLAYER_MOSAIC_SIZE][PLAYER_MOSAIC_SIZE];
};

#endif // STORAGEMOSAIC_H