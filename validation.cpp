#include <iostream>

#include "validation.h"
#include "settings.h"
#include "tile.h"

extern int jump_from_field[2];
extern bool jumps;
extern Tile *tile[8][8];

int validation::chooser (Tile *temp)
{
    disBlue();
    flag = validatePawn (temp);
    orange();
    return flag;
}

int validation::validatePawn (Tile *temp)
{
    int row = 0;
    int col = 0;

    row = temp->get_row();
    col = temp->get_col();
    retVal = 0;

    if (settings::get_game_started() == false)
    {
        return retVal;
    }

    if (jumps == true)
    {
        //jumps
        if (row+2 <= 7 && col+2 <= 7 && tile[row+1][col+1]->get_piece() && !tile[row+2][col+2]->get_piece() && temp->get_row() == jump_from_field[0] && temp->get_col() == jump_from_field[1])
        {
            exp24[max++] = tile[row+2][col+2]->get_tileNum();
            retVal = 1;
        }

        if (row+2 <= 7 && col-2 >= 0 && tile[row+1][col-1]->get_piece() && !tile[row+2][col-2]->get_piece() && temp->get_row() == jump_from_field[0] && temp->get_col() == jump_from_field[1])
        {
            exp24[max++] = tile[row+2][col-2]->get_tileNum();
            retVal = 1;
        }

        if (row-2 >= 0 && col-2 >= 0 && tile[row-1][col-1]->get_piece() && !tile[row-2][col-2]->get_piece() && temp->get_row() == jump_from_field[0] && temp->get_col() == jump_from_field[1])
        {
            exp24[max++] = tile[row-2][col-2]->get_tileNum();
            retVal = 1;
        }

        if (row-2 >= 0 && col+2 <= 7 && tile[row-1][col+1]->get_piece() && !tile[row-2][col+2]->get_piece() && temp->get_row() == jump_from_field[0] && temp->get_col() == jump_from_field[1])
        {
            exp24[max++] = tile[row-2][col+2]->get_tileNum();
            retVal = 1;
        }
    }
    else
    {
        if (row-1 >= 0 && col-1 >= 0 && !tile[row-1][col-1]->get_piece())
        {
            exp24[max++] = tile[row-1][col-1]->get_tileNum();
            retVal = 1;
        }

        if (row+1 <= 7 && col+1 <= 7 && !tile[row+1][col+1]->get_piece())
        {
            exp24[max++] = tile[row+1][col+1]->get_tileNum();
            retVal = 1;
        }

        if (row-1 >= 0 && col+1 <= 7 && !tile[row-1][col+1]->get_piece())
        {
            exp24[max++] = tile[row-1][col+1]->get_tileNum();
            retVal = 1;
        }

        if (row+1 <= 7 && col-1 >= 0 && !tile[row+1][col-1]->get_piece())
        {
            exp24[max++] = tile[row+1][col-1]->get_tileNum();
            retVal = 1;
        }

        //jumps
        if (row+2 <= 7 && col+2 <= 7 && tile[row+1][col+1]->get_piece() && !tile[row+2][col+2]->get_piece())
        {
            exp24[max++] = tile[row+2][col+2]->get_tileNum();
            retVal = 1;
        }

        if (row+2 <= 7 && col-2 >= 0 && tile[row+1][col-1]->get_piece() && !tile[row+2][col-2]->get_piece())
        {
            exp24[max++] = tile[row+2][col-2]->get_tileNum();
            retVal = 1;
        }

        if (row-2 >= 0 && col-2 >= 0 && tile[row-1][col-1]->get_piece() && !tile[row-2][col-2]->get_piece())
        {
            exp24[max++] = tile[row-2][col-2]->get_tileNum();
            retVal = 1;
        }

        if (row-2 >= 0 && col+2 <= 7 && tile[row-1][col+1]->get_piece() && !tile[row-2][col+2]->get_piece())
        {
            exp24[max++] = tile[row-2][col+2]->get_tileNum();
            retVal = 1;
        }
    }

    return retVal;
}

int validation::check (Tile *temp)
{
    return 0;
}

void validation::orange()
{
    for (int i=0; i<max; i++)
    {
        if (exp24[i] != 0)
        {
            tile[exp24[i]/8][exp24[i]%8]->setStyleSheet ("QLabel {background-color: orange;}");
        }
    }
}
