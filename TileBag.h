#ifndef TILEBAG_H
#define TILEBAG_H

#include <bits/stdc++.h>

#include "Types.h"
#include "Tiles.h"

class Node {
public:
    char colour;
    Node* next;
};


/* This class is used as the Linked List ADT. It will store the tiles in the tilebag. From the tilebag, the tiles
** will then be pushed onto the factories from which players can retrive them for their board
*/
class TileBag {
public:
    
    // Constructor/Copy Constructor/Deconstructor.
    TileBag();
    ~TileBag();

    // Returns size of the tilebag
    int bagSize();

    // Get first tile from Tilebag Linked List
    char get_front();

    // Add to the back of the Tilebag Linked List
    void add_back(char tile);

    // Remove first element from Tilebag Linked List
    void remove_front();

    // Bag is filled with 100 tiles (the number of tiles in a normal game of azul)
    void fill_bag(char* input_seed);

    // Print the Tilebag for save function
    char* printBag();

    // Return size of BoxLid array
    int boxSize();

    // Add unused tiles into the boxlid
    void addToBoxLid(char tile);

    // Add tiles from boxlid into the bag
    void refillBag();

    // Shuffles tiles in boxlid
    // Chauhan, S (2019), Shuffle an Array using STL in C++ (Version 1.0) [Source Code]. https://www.geeksforgeeks.org/shuffle-an-array-using-stl-in-c/#:~:text=STL%20contains%20two%20methods%20which,shuffle()%20and%20random_shuffle().&text=This%20method%20rearranges%20the%20elements,some%20other%20randomly%20picked%20element.
    void shuffle(int n);

private:
    Node* head;
    int seed;
    int length;
    char BoxLid[MAX_TILES_IN_TILEBAG];
};

#endif // TILEBAG_H