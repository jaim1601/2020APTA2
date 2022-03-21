#include "StorageMosaic.h"

// Constructs the storage mosaic as empty
StorageMosaic::StorageMosaic(){
    for (int col = 0; col < PLAYER_MOSAIC_SIZE;col++){
        for(int row = 0; row < PLAYER_MOSAIC_SIZE;row++){
            if(MOSAIC_ARRAY_LIMIT - col <= row){
                mosaic_storage[col][row] = NOTILE;
            }else{
                mosaic_storage[col][row] = EMPTY;
            }
        }
    }
}

StorageMosaic::~StorageMosaic(){

}

// Same as Play Mosaic, prints out one element of the array
char StorageMosaic::getPartMosaic(int colIndex, int rowIndex){
    return mosaic_storage[rowIndex][colIndex];
}

// Prints out a line for output reasons into the utils function.
void StorageMosaic::printlineStorageMosaic(int row){
    for(int col = 0; col < PLAYER_MOSAIC_SIZE; col++){
        std::cout << getPartMosaic(col,row) << " ";
    }
}
// Early implementation of setting parts of the mosaic, works good.
void StorageMosaic::setPartMosaic(int colIndex, int rowIndex, char newTile){
    mosaic_storage[rowIndex][colIndex] = newTile;
}

// This is designed to clear the line once it has filled the line via gameplay
void StorageMosaic::clearLineMosaic(int row){
    for(int col = 0;col < PLAYER_MOSAIC_SIZE;col++){
        if(MOSAIC_ARRAY_LIMIT - col <= row){
            setPartMosaic(col,row,NOTILE);
        }else{
            setPartMosaic(col,row,EMPTY);
        }
    }
}

// This sets the storage mosaic based on the factory and the tile selected and puts it into the mosaic,
// the idea behind returning a integer is that it tells how many tiles are remaning to be put in the broken mosaic
int StorageMosaic::setStorageMosaic(char tileUsed ,int rowIndex,int amountOfTiles){
    if(checkLineChar(rowIndex - 1, tileUsed) == true){
        for(int colIndex = RIGHT_MOST_POSITION; amountOfTiles > 0 && colIndex > (RIGHT_MOST_POSITION - rowIndex);colIndex--){
            if (getPartMosaic(colIndex, rowIndex - 1) != tileUsed){
                setPartMosaic(colIndex, rowIndex - 1, tileUsed);
                amountOfTiles--;
            } 
        }    
    }
    return amountOfTiles;
}

// This checks if the storage mosaic has filled up.
bool StorageMosaic::filledLineCheck(int rowIndex){
    bool characterCheck = false;

    if(getPartMosaic(RIGHT_MOST_POSITION - rowIndex,rowIndex) == RED || 
       getPartMosaic(RIGHT_MOST_POSITION - rowIndex,rowIndex) == YELLOW || 
       getPartMosaic(RIGHT_MOST_POSITION - rowIndex,rowIndex) == DARKBLUE || 
       getPartMosaic(RIGHT_MOST_POSITION - rowIndex,rowIndex) == LIGHTBLUE || 
       getPartMosaic(RIGHT_MOST_POSITION - rowIndex,rowIndex) == BLACK){

        characterCheck = true;
    }

    return characterCheck;
}

//This is a verification check to make sure your not putting alternate colours in a already filled Storage Mosaic
bool StorageMosaic::checkLineChar(int rowIndex, char tileInput){
    bool tileSame = false;

    if (getPartMosaic(RIGHT_MOST_POSITION, rowIndex) == tileInput || getPartMosaic(RIGHT_MOST_POSITION, rowIndex) == NOTILE){
        tileSame = true;
    }
    return tileSame;
}