#include <iostream>
#include <queue>

#include "ai.h"
#include "main.h"
#include "settings.h"
#include "check_game.h"

extern Tile *tile[8][8];
extern int jump_from_field[2];
extern choose_movement *cm;
extern bool jumps;

movement::movement ()
{
    this->movement_from[0] = 0;
    this->movement_from[1] = 0;
    this->movement_to[0] = 0;
    this->movement_to[1] = 0;
    this->movement_throw1[0] = 0;
    this->movement_throw1[1] = 0;
    this->movement_throw2[0] = 0;
    this->movement_throw2[1] = 0;
    this->movement_weight = 0;
}

movement::movement (int movement_weight, int movement_from1, int movement_from2, int movement_to1, int movement_to2, int movement_throw11, int movement_throw12, int movement_throw21, int movement_throw22)
{
    this->movement_from[0] = movement_from1;
    this->movement_from[1] = movement_from2;
    this->movement_to[0] = movement_to1;
    this->movement_to[1] = movement_to2;
    this->movement_throw1[0] = movement_throw11;
    this->movement_throw1[1] = movement_throw12;
    this->movement_throw2[0] = movement_throw21;
    this->movement_throw2[1] = movement_throw22;
    this->movement_weight = movement_weight;
}

movement::movement (const movement &old_movement)
{
    movement_from[0] = old_movement.movement_from[0];
    movement_from[1] = old_movement.movement_from[1];
    movement_to[0] = old_movement.movement_to[0];
    movement_to[1] = old_movement.movement_to[1];
    movement_throw1[0] = old_movement.movement_throw1[0];
    movement_throw1[1] = old_movement.movement_throw1[1];
    movement_throw2[0] = old_movement.movement_throw2[0];
    movement_throw2[1] = old_movement.movement_throw2[1];
    movement_weight = old_movement.movement_weight;
}

choose_movement::choose_movement()
{
    clear_queue();
}

void choose_movement::do_movement (movement choosed_movement)
{
    tile[choosed_movement.get_movement_to1()][choosed_movement.get_movement_to2()]->set_piece (1);
    tile[choosed_movement.get_movement_to1()][choosed_movement.get_movement_to2()]->set_pieceColor (0);
    tile[choosed_movement.get_movement_to1()][choosed_movement.get_movement_to2()]->display ('P');

    tile[choosed_movement.get_movement_from1()][choosed_movement.get_movement_from2()]->set_piece (0);
    tile[choosed_movement.get_movement_from1()][choosed_movement.get_movement_from2()]->set_pieceColor (0);
    tile[choosed_movement.get_movement_from1()][choosed_movement.get_movement_from2()]->display ('n');

    tile[choosed_movement.get_movement_from1()][choosed_movement.get_movement_from2()]->setStyleSheet ("QLabel {background-color: blue;}");
    tile[choosed_movement.get_movement_to1()][choosed_movement.get_movement_to2()]->setStyleSheet ("QLabel {background-color: blue;}");

    if (!((choosed_movement.get_movement_throw11() == 0) && (choosed_movement.get_movement_throw12() == 0)))
    {
        tile[choosed_movement.get_movement_throw11()][choosed_movement.get_movement_throw12()]->setStyleSheet ("QLabel {background-color: blue;}");
    }

    if (!((choosed_movement.get_movement_throw21() == 0) && (choosed_movement.get_movement_throw22() == 0)))
    {
        tile[choosed_movement.get_movement_throw21()][choosed_movement.get_movement_throw22()]->setStyleSheet ("QLabel {background-color: blue;}");
    }
}

void choose_movement::add_movement (movement new_movement)
{
    this->movements.push (new_movement);
}

void choose_movement::clear_queue ()
{
    while (this->movements.empty() == false)
    {
        this->movements.top();
        this->movements.pop();
    }

    while (this->result.empty() == false)
    {
        this->result.top();
        this->result.pop();
    }
}

void choose_movement::finds_movements(Tile *tile[8][8])
{
    if (settings::get_game_started() == false)
    {
        return;
    }

    for (int i=0; i<8; i++)
    //I omits the last row on the chessboard, because computer shouldn't choose movements involving backflow movements
    {
        for (int j=0; j<7; j++)
        {
            if (i%2==0)
            {
                if ((j%2==0) || (!tile[i][j]->get_piece()) || (tile[i][j]->get_pieceColor() != 0))
                {
                    continue;
                }
            }
            else
            {
                if ((j%2==1) || (!tile[i][j]->get_piece()) || (tile[i][j]->get_pieceColor() != 0))
                {
                    continue;
                }
            }

            if ((i == 6) && (tile[i][j]->get_pieceColor() == 0))
            {
                continue;
            }

            //1. weight 1
            //up, left
            if (tile[i][j]->get_row()-1 >= 0 && tile[i][j]->get_col()-1 >= 0 && !tile[tile[i][j]->get_row()-1][tile[i][j]->get_col()-1]->get_piece())
            {
                cm->add_movement(movement(-1, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()-1, tile[i][j]->get_col()-1));
            }

            //up, right
            if (tile[i][j]->get_row()-1 >= 0 && tile[i][j]->get_col()+1 <= 7 && !tile[tile[i][j]->get_row()-1][tile[i][j]->get_col()+1]->get_piece())
            {
                cm->add_movement(movement(-1, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()-1, tile[i][j]->get_col()+1));
            }

            //down, left
            if (tile[i][j]->get_row()+1 <= 7 && tile[i][j]->get_col()-1 >= 0 && !tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()-1]->get_piece())
            {
                cm->add_movement(movement(1, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+1, tile[i][j]->get_col()-1));
            }

            //down, right
            if (tile[i][j]->get_row()+1 <= 7 && tile[i][j]->get_col()+1 <= 7 && !tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()+1]->get_piece())
            {
                cm->add_movement(movement(1, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+1, tile[i][j]->get_col()+1));
            }


            //2. jumps - weight 2
            //down right x2
            if (tile[i][j]->get_row()+2 <= 7 && tile[i][j]->get_col()+2 <= 7 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()+2]->get_piece())
            {
                cm->add_movement(movement(2, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+2, tile[i][j]->get_col()+2));
            }

            //down left x2
            if (tile[i][j]->get_row()+2 <= 7 && tile[i][j]->get_col()-2 >= 0 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()-2]->get_piece())
            {
                cm->add_movement(movement(2, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+2, tile[i][j]->get_col()-2));
            }

            //up right x2
            if (tile[i][j]->get_row()-2 >= 0 && tile[i][j]->get_col()+2 <= 7 && tile[tile[i][j]->get_row()-1][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()-2][tile[i][j]->get_col()+2]->get_piece())
            {
                cm->add_movement(movement(-2, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()-2, tile[i][j]->get_col()+2));
            }

            //up left x2
            if (tile[i][j]->get_row()-2 >= 0 && tile[i][j]->get_col()-2 >= 0 && tile[tile[i][j]->get_row()-1][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()-2][tile[i][j]->get_col()-2]->get_piece())
            {
                cm->add_movement(movement(-2, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()-2, tile[i][j]->get_col()-2));
            }


            //3. jumps - weight 4 (skipping movements weights below zero)
            //down right x4
            if (tile[i][j]->get_row()+4 <= 7 && tile[i][j]->get_col()+4 <= 7 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()+2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()+3]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()+4]->get_piece())
            {
                cm->add_movement(movement(4, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+4, tile[i][j]->get_col()+4, tile[i][j]->get_row()+2, tile[i][j]->get_col()+2));
            }

            //down left x4
            if (tile[i][j]->get_row()+4 <= 7 && tile[i][j]->get_col()-4 >= 0 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()-2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()-3]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()-4]->get_piece())
            {
                cm->add_movement(movement(4, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+4, tile[i][j]->get_col()-4, tile[i][j]->get_row()+2, tile[i][j]->get_col()-2));
            }

            //down right x2, down left x2
            if (tile[i][j]->get_row()+4 <= 7 && tile[i][j]->get_col()+2 <= 7 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()+2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()]->get_piece())
            {
                cm->add_movement(movement(4, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+4, tile[i][j]->get_col(), tile[i][j]->get_row()+2, tile[i][j]->get_col()+2));
            }

            //down left x2, down right x2
            if (tile[i][j]->get_row()+4 <= 7 && tile[i][j]->get_col()-2 >= 0 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()-2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()]->get_piece())
            {
                cm->add_movement(movement(4, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+4, tile[i][j]->get_col(), tile[i][j]->get_row()+2, tile[i][j]->get_col()-2));
            }


            //4. jumps - weight 6 (skipping movements weights below zero)
            //down right x6
            if (tile[i][j]->get_row()+6 <= 7 && tile[i][j]->get_col()+6 <= 7 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()+2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()+3]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()+4]->get_piece() && tile[tile[i][j]->get_row()+5][tile[i][j]->get_col()+5]->get_piece() && !tile[tile[i][j]->get_row()+6][tile[i][j]->get_col()+6]->get_piece())
            {
                cm->add_movement(movement(6, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+6, tile[i][j]->get_col()+6, tile[i][j]->get_row()+2, tile[i][j]->get_col()+2, tile[i][j]->get_row()+4, tile[i][j]->get_col()+4));
            }

            //down left x6
            if (tile[i][j]->get_row()+6 <= 7 && tile[i][j]->get_col()-6 >= 0 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()-2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()-3]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()-4]->get_piece() && tile[tile[i][j]->get_row()+5][tile[i][j]->get_col()-5]->get_piece() && !tile[tile[i][j]->get_row()+6][tile[i][j]->get_col()-6]->get_piece())
            {
                cm->add_movement(movement(6, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+6, tile[i][j]->get_col()-6, tile[i][j]->get_row()+2, tile[i][j]->get_col()-2, tile[i][j]->get_row()+4, tile[i][j]->get_col()-4));
            }

            //down right x4, down left x2
            if (tile[i][j]->get_row()+6 <= 7 && tile[i][j]->get_col()+4 <= 7 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()+2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()+3]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()+4]->get_piece() && tile[tile[i][j]->get_row()+5][tile[i][j]->get_col()+3]->get_piece() && !tile[tile[i][j]->get_row()+6][tile[i][j]->get_col()+2]->get_piece())
            {
                cm->add_movement(movement(6, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+6, tile[i][j]->get_col()+2, tile[i][j]->get_row()+2, tile[i][j]->get_col()+2, tile[i][j]->get_row()+4, tile[i][j]->get_col()+4));
            }

            //down left x4, down right x2
            if (tile[i][j]->get_row()+6 <= 7 && tile[i][j]->get_col()-6 >= 0 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()-2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()-3]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()-4]->get_piece() && tile[tile[i][j]->get_row()+5][tile[i][j]->get_col()-5]->get_piece() && !tile[tile[i][j]->get_row()+6][tile[i][j]->get_col()-6]->get_piece())
            {
                cm->add_movement(movement(6, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+6, tile[i][j]->get_col()-6, tile[i][j]->get_row()+2, tile[i][j]->get_col()-2, tile[i][j]->get_row()+4, tile[i][j]->get_col()-4));
            }

            //down right x2, down left x4
            if (tile[i][j]->get_row()+6 <= 7 && tile[i][j]->get_col()+2 <= 7 && tile[i][j]->get_col()-2 >= 0 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()+2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()]->get_piece() && tile[tile[i][j]->get_row()+5][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+6][tile[i][j]->get_col()-2]->get_piece())
            {
                cm->add_movement(movement(6, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+6, tile[i][j]->get_col()-2, tile[i][j]->get_row()+2, tile[i][j]->get_col()+2, tile[i][j]->get_row()+4, tile[i][j]->get_col()));
            }

            //down left x2, down right x4
            if (tile[i][j]->get_row()+6 <= 7 && tile[i][j]->get_col()+2 <= 7 && tile[i][j]->get_col()-2 >= 0 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()-2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()]->get_piece() && tile[tile[i][j]->get_row()+5][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+6][tile[i][j]->get_col()+2]->get_piece())
            {
                cm->add_movement(movement(6, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+6, tile[i][j]->get_col()+2, tile[i][j]->get_row()+2, tile[i][j]->get_col()-2, tile[i][j]->get_row()+4, tile[i][j]->get_col()));
            }

            //down right x2, down left x2, down right x2
            if (tile[i][j]->get_row()+6 <= 7 && tile[i][j]->get_col()+2 <= 7 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()+2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()]->get_piece() && tile[tile[i][j]->get_row()+5][tile[i][j]->get_col()+1]->get_piece() && !tile[tile[i][j]->get_row()+6][tile[i][j]->get_col()+2]->get_piece())
            {
                cm->add_movement(movement(6, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+6, tile[i][j]->get_col()+2, tile[i][j]->get_row()+2, tile[i][j]->get_col()+2, tile[i][j]->get_row()+4, tile[i][j]->get_col()));
            }

            //down left x2, down right x2, down left x2
            if (tile[i][j]->get_row()+6 <= 7 && tile[i][j]->get_col()-2 >= 0 && tile[tile[i][j]->get_row()+1][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+2][tile[i][j]->get_col()-2]->get_piece() && tile[tile[i][j]->get_row()+3][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+4][tile[i][j]->get_col()]->get_piece() && tile[tile[i][j]->get_row()+5][tile[i][j]->get_col()-1]->get_piece() && !tile[tile[i][j]->get_row()+6][tile[i][j]->get_col()-2]->get_piece())
            {
                cm->add_movement(movement(6, tile[i][j]->get_row(), tile[i][j]->get_col(), tile[i][j]->get_row()+6, tile[i][j]->get_col()-2, tile[i][j]->get_row()+2, tile[i][j]->get_col()-2, tile[i][j]->get_row()+4, tile[i][j]->get_col()));
            }
        }
    }
}

movement choose_movement::return_movement ()
{
    if (this->movements.size() == 0)
    {
        clear_queue();
        return movement();
    }
    else if (this->movements.size() == 1)
    {
        movement return_movement = this->movements.top();
        clear_queue();
        return return_movement;
    }
    else if (settings::get_computer_difficulty()==true)
    {
        movement temp = movements.top();
        int weight = temp.get_movement_weight();

        while (this->movements.empty() == false)
        {
            movement new_movement = this->movements.top();
            this->movements.pop();

            if (new_movement.get_movement_weight() == weight)
            {
                this->result.push(new_movement);
            }
            else
            {
                break;
            }
        }

        int result_size = (int)this->result.size();
        int choosed_movement = rand()%result_size;

        for (int i=0; i<choosed_movement-1; i++)
        {
            this->result.top();
            this->result.pop();
        }
        movement return_movement = this->result.top();
        clear_queue();
        return return_movement;
    }
    else
    {
        int movements_size = (int)this->movements.size();
        int choosed_movement = rand()%movements_size;
        movement return_movement = this->movements.top();

        for (int i=0; i<choosed_movement; i++)
        {
            return_movement = this->movements.top();
            this->movements.pop();
        }

        clear_queue();
        return return_movement;
    }
}
