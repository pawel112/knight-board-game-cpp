#ifndef MAIN_H
#define MAIN_H

#include "tile.h"

class Border
{
public:
    Border ();
    void outline (QWidget *baseWidget, int xPos, int yPos, int Pos);
};

void chessBoard (QWidget *baseWidget, Tile *tile[8][8]);
void setPawns (bool standart);
int main (int argc, char *argv[]);

#endif
