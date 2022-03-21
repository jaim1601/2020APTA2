#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "PlayMosaic.h"
#include "StorageMosaic.h"
#include "BrokenMosaic.h"


class Player{
public:
    Player();
    Player(std::string playerName, char playerChar);
    ~Player();

    void incrementPlayerScore(int addedScore);
    void minimumScore();

    std::string getPlayerName();
    char getPlayerChar();
    int getPlayerScore();
    PlayMosaic* getPlayMosaic();
    StorageMosaic* getStorageMosaic();
    BrokenMosaic* getBrokenMosaic();

private:
    std::string playerName; 
    char playerChar;
    int playerScore;
    PlayMosaic* playMosaic;
    StorageMosaic* storageMosaic;
    BrokenMosaic* brokenMosaic;
};

#endif // PLAYER_H