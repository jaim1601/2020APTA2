#include "BrokenMosaic.h"

// This constructor is kept empty as it starts empty
BrokenMosaic::BrokenMosaic(){

}

BrokenMosaic::~BrokenMosaic(){

}

// Returns a char, used for refilling the tilebag
char BrokenMosaic::returnTile(int tileIndex){
    char tileReturned = NOTILE;
    if(tileIndex < returnSize()){
        tileReturned = brokenMosaic.at(tileIndex);
    }

    return tileReturned;
}

// Returns a int, used in finding the size for the for loop in pushing the tiles back to the tilebag. Also makes it a int
int BrokenMosaic::returnSize(){
    int brokenSize = 0;
    brokenSize = brokenMosaic.size();

    return brokenSize;
}

// Prints Broken Mosaic Vector
void BrokenMosaic::printBrokenMosaic(){
    for(unsigned int i=0; i<brokenMosaic.size(); ++i){
        std::cout << brokenMosaic.at(i) << ' ';
    }
    std::cout << std::endl;
}

// Pushes excess correct tiles into the broken mosaic
void BrokenMosaic::excessTilesInput(int amountOfTiles, char tiles){
    for(int tileCount = 0;tileCount < amountOfTiles;tileCount++){
        brokenMosaic.push_back(tiles);
    }
}

// Pushes F token to the brokenMosaic
void BrokenMosaic::pushFirstPlayer(){
    brokenMosaic.push_back(FIRSTPLAYER);
}

// Clears the Broken Mosaic after a turn
void BrokenMosaic::clear(){
    brokenMosaic.clear();
}

// Compares the size of the broken mosaic to get a negative score for the player.
int BrokenMosaic::reduceBrokenScore(){
    int scoreReduction = 0;
    if(brokenMosaic.size() <= ONE_POINT_REDUCTION_CAP){
        scoreReduction = -brokenMosaic.size();
    }else if(brokenMosaic.size() <= TWO_POINT_REDUCTION_CAP){
        scoreReduction = -(2 * brokenMosaic.size()) + ONE_POINT_REDUCTION_CAP; 
    }else if(brokenMosaic.size() <= THREE_POINT_REDUCTION_CAP){
        scoreReduction = -(3 * brokenMosaic.size()) + THREE_POINT_REDUCTION_CAP;
    }else{
        scoreReduction = MAX_AMOUNT_OF_POINTS_LOST;
    }
    return scoreReduction;  
}