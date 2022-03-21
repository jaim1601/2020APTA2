#ifndef TILES_H
#define TILES_H

#include <random>

#include "Types.h"

/* This class is used to create the tiles. The tiles will be randomly generated here and be called by the Tilebag
** class to fill itself.
*/
class Tiles {
public:
    Tiles();
    ~Tiles();

    // A random tile is created and returned.
    char addTile(int i);

private:
    char tile;

};

#endif // TILES_H