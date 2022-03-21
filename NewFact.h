#ifndef NEWFACT_H
#define NEWFACT_H

#include "BSTFact.h"
#include "TileBag.h"

#include <iostream>

class NewFact{
public:
    NewFact(TileBag* bag);
    ~NewFact();
    
    // creates all the factories including the centre factory 
    void createFactories(char* seed);
    
    // fills all the factories up for the game to begin
    void fillAllFactories();

    // checks if all the factories are empty or not
    bool isAllFactoriesEmpty();

    // prints out all the factories for the user to see
    void printAllFactories();

    // checks if a tile exists in a specific factory
    bool tilesExist(int factory, char colour);

    // returns the number of tiles that exist within a factory
    int returnTileCount(int factory, char colour);

    // checks if F has been removed or not from the centre factory
    bool isFRemoved();

    // deletes tiles that are not used from a factory and they are pushed into the centre factory
    void deleteTiles(int factory, char colour);

    // this function assists the "deleteTiles" fucntion by deleting the uncalled tiles from the factory
    BSTFact* removeFromFactory(BSTFact* factory, int numb);

    // return centre factory
    BSTFact* getcntrFact();
    //return factory 1
    BSTFact* getFact1();
    //return factory 2
    BSTFact* getFact2();
    //return factory 3
    BSTFact* getFact3();
    //return factory 4
    BSTFact* getFact4();
    //return factory 5
    BSTFact* getFact5();
    //return tilebag
    TileBag* getBag();
private:

    TileBag* bag;

    BSTFact* cntrFactory;
    BSTFact* factory1;
    BSTFact* factory2;
    BSTFact* factory3;
    BSTFact* factory4;
    BSTFact* factory5;

};

#endif // NEWFACT_H