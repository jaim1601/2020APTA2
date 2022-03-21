#include "PlayMosaic.h"

// Constructs the class and the array.
PlayMosaic::PlayMosaic(){
    for (int col = 0; col < PLAYER_MOSAIC_SIZE;col++){
        for(int row = 0; row < PLAYER_MOSAIC_SIZE;row++){
            this->mosaic_board[col][row] = NOTILE;
        }
    }
}

PlayMosaic::~PlayMosaic(){

}

// Used to get a section of the array and return it, mostly used for printing to output.
char PlayMosaic::getPartMosaic(int colIndex, int rowIndex){
    return mosaic_board[rowIndex][colIndex];
}

// The purpose of this Function is to print it line by line, the only reason is that printing the whole board out isn't exactly feasable to the assignment specs and doing it
// as a line makes it a lot more visually appealing and is easily done in the utils function
void PlayMosaic::printlinePlayMosaic(int row){
    for(int col = 0; col < PLAYER_MOSAIC_SIZE; col++){
        std::cout << " " << getPartMosaic(col,row);
    }
}

// Early implementation of setting parts of the mosaic, works good.
void PlayMosaic::setPartMosaic(int colIndex, int rowIndex, char newTile){
    mosaic_board[rowIndex][colIndex] = newTile;
}

// Undergoes the algorithm to determine where to place the mosaic once storage mosaic has been filled. Utilised mod since it's worked out well for placing the tiles
int PlayMosaic::mosaicInput(int rowIndex, char newTile){
    int colIndex = 0;
    if(newTile == DARKBLUE){
        colIndex = rowIndex % PLAYER_MOSAIC_SIZE;
        setPartMosaic(colIndex, rowIndex, newTile);
    }else if(newTile == YELLOW){
        colIndex = (rowIndex + 1) % PLAYER_MOSAIC_SIZE;
        setPartMosaic(colIndex, rowIndex, newTile);
    }else if(newTile == RED){
        colIndex = (rowIndex + 2) % PLAYER_MOSAIC_SIZE;
        setPartMosaic(colIndex, rowIndex, newTile);
    }else if(newTile == BLACK){
        colIndex = (rowIndex + 3) % PLAYER_MOSAIC_SIZE;
        setPartMosaic(colIndex, rowIndex, newTile);
    }else if(newTile == LIGHTBLUE){
        colIndex = (rowIndex + 4) % PLAYER_MOSAIC_SIZE;
        setPartMosaic(colIndex, rowIndex, newTile);
    }else{
        // std::cout << "Error" << std::endl;
    }
    return colIndex;
}

// This function verifies if the Play Mosaic has the tile in question found in the row, returns false if the character is not found
bool PlayMosaic::verifyFilledPlayMosaic(int rowIndex,char charVerify){
    bool isCharacterThere = false;
    for(int colIndex = 0;colIndex < PLAYER_MOSAIC_SIZE;colIndex++){
        if(getPartMosaic(colIndex,rowIndex) == charVerify){
            isCharacterThere = true;
        }
    }
    return isCharacterThere;
}

// This function is definitely not the cleanest but it was the one that worked, this method by far was the most difficult for me(Daniel) to crack
// figuring out how to find the part that is being scored, then figuring out a way to scan the nearby tiles was by far the biggest part of this thing
// that I struggled with. I'll be honest, I'm not that happy with the implementation but it was the one that I got it to the end with.
int PlayMosaic::findNearbyTiles(int colIndex,int rowIndex){
    int scoreCalculation = 0;

    bool rowPresent = false;
    bool colPresent = false;
    bool stopChecking = false;

    int rowIndexUp = rowIndex - 1;
    int rowIndexDown = rowIndex + 1;
    int colIndexRight = colIndex + 1;
    int colIndexLeft = colIndex - 1;

    for(;colIndexRight <= MOSAIC_ARRAY_LIMIT;colIndexRight++){
        if(isCharacterHere(colIndexRight,rowIndex) == true && stopChecking == false){
            scoreCalculation++;
            colPresent = true;
        }else{stopChecking = true;}
    }
    stopChecking = false;
    for(;colIndexLeft >= 0;colIndexLeft--){
        if(isCharacterHere(colIndexLeft,rowIndex) == true && stopChecking == false){
            scoreCalculation++;
            colPresent = true;
        }else{stopChecking = true;}
    }
    stopChecking = false;
    for(;rowIndexDown <= MOSAIC_ARRAY_LIMIT;rowIndexDown++){
        if(isCharacterHere(colIndex,rowIndexDown) == true && stopChecking == false){
            scoreCalculation++;
            rowPresent = true;
        }else{stopChecking = true;}
    }
    stopChecking = false;
    for(;rowIndexUp >= 0;rowIndexUp--){
        if(isCharacterHere(colIndex,rowIndexUp) == true && stopChecking == false){
            scoreCalculation++;
            rowPresent = true;
        }else{stopChecking = true;}
    }

    if(rowPresent == true){
        scoreCalculation++;
    }
    if(colPresent == true){
        scoreCalculation++;
    }

    if(scoreCalculation == 0){
        scoreCalculation = 1;
    }

    return scoreCalculation;
}

// Simple check to see if there is a tile there or not, used for the above function to calc score.
bool PlayMosaic::isCharacterHere(int colIndex,int rowIndex){
    bool isaTileHere = false;
    if(getPartMosaic(colIndex,rowIndex) != NOTILE){
        isaTileHere = true;
    }
    return isaTileHere;
}