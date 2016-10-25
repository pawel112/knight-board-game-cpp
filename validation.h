#ifndef VALIDATION_H
#define VALIDATION_H

#include "tile.h"

extern Tile *tile[8][8];
extern int exp24[60];
extern int max;
extern int wR;
extern int wC;

class validation
{
private:
    int flag;
    int retVal;
public:
    void orange ();
    int chooser (Tile *temp);
    int validatePawn (Tile *temp);
    int check (Tile *temp);
};

#endif
