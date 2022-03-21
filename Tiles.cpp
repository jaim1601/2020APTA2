#include "Tiles.h"

Tiles::Tiles() {
}

Tiles::~Tiles() {
}

// A random tile is created and returned.
char Tiles::addTile(int i) {
    tile = '0';
    if (i == 1) {
        tile = RED;
    } else if (i == 2) {
        tile = YELLOW;
    } else if (i == 3) {
        tile = DARKBLUE;
    } else if (i == 4) {
        tile = LIGHTBLUE;
    } else if (i == 5) {
        tile = BLACK;
    }

    return tile;
}