#include "tile.h"
#include "validation.h"
#include "mainwindow.h"
#include "main.h"
#include "check_game.h"

extern MainWindow *w;
validation *valid = new validation ();

extern int turn;
extern QWidget *myWidget;
extern Tile *click1;
extern Tile *tile[8][8];
int jump_from_field[2] = { 0, 0 };
bool jumps = false;
bool clicked = false;
int count = 0;

void validate (Tile *temp, int c);
void disOrange ();
void disBlue ();

void Tile::mousePressEvent (QMouseEvent *event)
{
    clicked = true;
    validate (this, ++count);
}

void Tile::display (char elem)
{
    this->set_pieceName (elem);

    if (this->get_pieceColor() && this->get_piece())
    {
        this->setPixmap (QPixmap (":/Images/pawn_white.svg"));
    }
    else if (this->get_piece())
    {
        this->setPixmap (QPixmap (":/Images/pawn_black.svg"));
    }
    else
    {
        this->clear();
    }
}

void validate (Tile *temp, int c)
{
    int retValue = 0;
    int i = 0;

    if (c == 1)
    {
        if (temp->get_piece() && (temp->get_pieceColor() == turn))
        {
            retValue = valid->chooser (temp);

            if (retValue)
            {
                click1 = new Tile();
                temp->setStyleSheet ("QLabel {background-color: green;}");
                click1 = temp;
                jump_from_field[0] = temp->get_row();
                jump_from_field[1] = temp->get_col();
            }
            else
            {
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    else
    {
        if (temp->get_tileNum() == click1->get_tileNum())
        {
            click1->tileDisplay ();
            disOrange ();
            max = 0;
            count = 0;
        }

        for (i=0; i<max; i++)
        {            
            if (temp->get_tileNum() == exp24[i])
            {        
                click1->set_piece (0);
                temp->set_piece (1);

                temp->set_pieceColor (click1->get_pieceColor());
                temp->set_pieceName (click1->get_pieceName());

                click1->display (click1->get_pieceName());
                temp->display (click1->get_pieceName());

                click1->tileDisplay ();
                temp->tileDisplay ();

                retValue = valid->check (click1);

                disOrange ();

                max = 0;

                if (abs (temp->get_row() - jump_from_field[0]) == 1)
                {
                    jump_from_field[0] = 0;
                    jump_from_field[1] = 0;

                    end_turn();
                }
                else
                {
                    jump_from_field[0] = temp->get_row();
                    jump_from_field[1] = temp->get_col();
                    jumps = true;
                }

                count = 0;
            }
            else
            {
                count = 1;
            }
        }
    }
}

void Tile::tileDisplay ()
{
    if (this->get_tileColor())
    {
        this->setStyleSheet ("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
    }
    else
    {
        this->setStyleSheet ("QLabel {background-color: rgb(211, 211, 158);}:hover{background-color: rgb(170,95,127);}");
    }
}

void disOrange ()
{
    int i = 0;

    for (i=0; i<max; i++)
    {
        tile[exp24[i]/8][exp24[i]%8]->tileDisplay ();
    }
}

void disBlue ()
{
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            tile[i][j]->tileDisplay();
        }
    }
}
