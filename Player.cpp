#include "Player.h"

Player::Player(){ 
}

// Realisticly the only constructor that should be called, when starting the game, goes through this.
Player::Player(std::string playerName, char playerChar){
    this->playerName = playerName; // Constructor for the class
    this->playerChar = playerChar;
    this->playerScore = 0;
    playMosaic = new PlayMosaic();
    storageMosaic = new StorageMosaic();
    brokenMosaic = new BrokenMosaic();
}

Player::~Player(){
    delete playMosaic;
    delete storageMosaic;  
    delete brokenMosaic;
}

// Simple addition function to the score.
void Player::incrementPlayerScore(int addedScore){
    playerScore = playerScore + addedScore;
}

// If the score goes below this, the score is pushed up to 0
void Player::minimumScore(){
    playerScore = 0;
}

// The next 6 functions access parts of the player object.
std::string Player::getPlayerName(){
    return playerName;
}

char Player::getPlayerChar(){
    return playerChar;
}

int Player::getPlayerScore(){
    return playerScore;
}

PlayMosaic* Player::getPlayMosaic(){
    return playMosaic;
}

StorageMosaic* Player::getStorageMosaic(){
    return storageMosaic;
}

BrokenMosaic* Player::getBrokenMosaic(){
    return brokenMosaic;
}
