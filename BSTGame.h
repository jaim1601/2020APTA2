#ifndef BSTGAME_H
#define BSTGAME_H


#include "Player.h"
#include "Types.h"
#include "utils.h"
#include "BSTFact.h"
#include "NewFact.h"

/* This file is an exact copy of the orignal game file however it has been implemented so that a BST is used for 
** the factories rather than a vector
*/

Player* setupPlayer(Player* player, char playerChar);
void playtheGame(char* seed);
void playerTurn(Player* player,NewFact* fact);
void mosaicPrint(Player* player);
void brokenPrint(Player* player);
void factoriesPrint(NewFact* fact);
void playerInput(Player* player,NewFact* fact);
void gameplayFunctions(Player* player,NewFact* fact, int factorySelect, char tileSelect, int mosaicLineSelect);
void endRoundCheck(Player* player,NewFact* fact,char* gameCheck);
void scoreCheck(Player* player,int colIndex,int rowIndex);
void gameEnd(Player* player1,Player* player2,NewFact* fact);
void addToTileBag(int count,TileBag* bag, char tile, char* gameCheck);
void addToTileBagBroken(Player* player, TileBag* bag, char* gameCheck);
void isBagEmpty(NewFact* fact, TileBag* bag);


#endif // BSTGAME_H