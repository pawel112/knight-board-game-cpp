#include <QApplication>
#include <ctime>

#include "mainwindow.h"
#include "tile.h"
#include "main.h"
#include "chooselanguage.h"
#include "language.h"
#include "ai.h"

int turn = 1;
int max = 0;
int wR = 0;
int wC = 0;
int bR = 0;
int bC = 0;
int exp24[60];
Tile *click1;
MainWindow *w = NULL;
extern bool jumps;
extern int count;
bool change_points = NULL;
choose_movement *cm = new choose_movement();

Tile *tile[8][8] = { { NULL } };

void Border::outline (QWidget *baseWidget, int xPos, int yPos, int Pos)
{
    QLabel *outLabel = new QLabel (baseWidget);

    if (!Pos)
    {
        outLabel->setGeometry (xPos-100, yPos-80, 552, 20);        //Horizontal Borders
    }
    else
    {
        outLabel->setGeometry (xPos-100, yPos-80, 20, 512);        //Vertical Borders
    }
    outLabel->setStyleSheet ("QLabel { background-color :rgb(170, 170, 127); color : black; }");
}

void chessBoard (QWidget *baseWidget, Tile *tile[8][8])
{
    int i = 0;
    int j = 0;
    int k = 0;
    int hor = 0;
    int ver = 0;
    Border *border[4] = { NULL };

    //borderDisplay
    {
        border[0]->outline (baseWidget, 250, 115, 0);
        border[1]->outline (baseWidget, 250, 647, 0);
        border[2]->outline (baseWidget, 250, 135, 1);
        border[2]->outline (baseWidget, 782, 135, 1);
    }

    //Create 64 tiles (allocating memories to the objects of Tile class)
    //cleaning
    ver = 55;
    for (i=0; i<8; i++)
    {
        hor = 170;
        for (j=0; j<8; j++)
        {
            tile[i][j] = new Tile (baseWidget);
            tile[i][j]->set_tileColor ((i+j)%2);
            tile[i][j]->set_piece (0);
            tile[i][j]->set_row (i);
            tile[i][j]->set_col (j);
            tile[i][j]->set_tileNum (k++);
            tile[i][j]->tileDisplay ();
            tile[i][j]->setGeometry (hor, ver, 64, 64);
            hor += 64;
        }
        ver += 64;
    }

    setPawns(true);

    wR = 7;
    wC = 4;
    bR = 0;
    bC = 4;
}

void setPawns (bool standart)
{
    jumps = false;

    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            tile[i][j]->set_tileColor ((i+j)%2);
            tile[i][j]->setStyleSheet ("QLabel {background-color: green;}");
            tile[i][j]->set_piece (0);
            tile[i][j]->set_row (i);
            tile[i][j]->set_col (j);
            tile[i][j]->set_pieceColor (0);
            tile[i][j]->display ('n');
            tile[i][j]->tileDisplay ();

        }
    }

    if (standart == true)
    {
        //white pawns
        for (int j=0; j<8; j++)
        {
            if (j%2 == 1)
            {
                tile[0][j]->set_piece (1);
                tile[0][j]->set_pieceColor (0);
                tile[0][j]->display ('P');
            }
        }
        for (int j=0; j<8; j++)
        {
            if (j%2 == 0)
            {
                tile[1][j]->set_piece (1);
                tile[1][j]->set_pieceColor (0);
                tile[1][j]->display ('P');
            }
        }

        //black pawns
        for (int j=0; j<8; j++)
        {
            if (j%2 == 0)
            {
                tile[7][j]->set_piece (1);
                tile[7][j]->set_pieceColor (1);
                tile[7][j]->display ('P');
            }
        }
        for (int j=0; j<8; j++)
        {
            if (j%2 == 1)
            {
                tile[6][j]->set_piece (1);
                tile[6][j]->set_pieceColor (1);
                tile[6][j]->display ('P');
            }
        }
    }
    else
    {
        //black pawns
        for (int j=0; j<8; j++)
        {
            if (j%2 == 1)
            {
                tile[0][j]->set_piece (1);
                tile[0][j]->set_pieceColor (1);
                tile[0][j]->display ('P');
            }
        }
        for (int j=0; j<8; j++)
        {
            if (j%2 == 0)
            {
                tile[1][j]->set_piece (1);
                tile[1][j]->set_pieceColor (1);
                tile[1][j]->display ('P');
            }
        }

        //white pawns
        for (int j=0; j<8; j++)
        {
            if (j%2 == 0)
            {
                tile[7][j]->set_piece (1);
                tile[7][j]->set_pieceColor (0);
                tile[7][j]->display ('P');
            }
        }
        for (int j=0; j<8; j++)
        {
            if (j%2 == 1)
            {
                tile[6][j]->set_piece (1);
                tile[6][j]->set_pieceColor (0);
                tile[6][j]->display ('P');
            }
        }
    }
}

int main (int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a (argc, argv);

    ChooseLanguage w;
    w.show();

    return a.exec ();
}
