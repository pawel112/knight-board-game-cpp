#include <iostream>

#include "check_game.h"
#include "tile.h"
#include "mainwindow.h"
#include "main.h"
#include "settings.h"
#include "ai.h"

#include <QDebug>

extern MainWindow *w;
extern Tile *tile[8][8];
extern int turn;
extern bool jumps;
extern int jump_from_field[2];
extern int max;
extern int count;
extern bool without_changing_player;
extern bool change_points;
extern choose_movement *cm;

int end_game()
{
    bool white_pawns_wins = false;
    bool black_pawns_wins = false;

    //check black
    if ((tile[0][1]->get_piece() == 1) && (tile[0][1]->get_pieceColor() == 1) && (tile[0][3]->get_piece() == 1) && (tile[0][3]->get_pieceColor() == 1) && (tile[0][5]->get_piece() == 1) && (tile[0][5]->get_pieceColor() == 1) && (tile[0][7]->get_piece() == 1) && (tile[0][7]->get_pieceColor() == 1) && (tile[1][0]->get_piece() == 1) && (tile[1][0]->get_pieceColor() == 1) && (tile[1][2]->get_piece() == 1) && (tile[1][2]->get_pieceColor() == 1) && (tile[1][4]->get_piece() == 1) && (tile[1][4]->get_pieceColor() == 1) && (tile[1][6]->get_piece() == 1) && (tile[1][6]->get_pieceColor() == 1))
    {
        black_pawns_wins = true;
    }

    //check white
    if ((tile[6][1]->get_piece() == 1) && (tile[6][1]->get_pieceColor() == 0) && (tile[6][3]->get_piece() == 1) && (tile[6][3]->get_pieceColor() == 0) && (tile[6][5]->get_piece() == 1) && (tile[6][5]->get_pieceColor() == 0) && (tile[6][7]->get_piece() == 1) && (tile[6][7]->get_pieceColor() == 0) && (tile[7][0]->get_piece() == 1) && (tile[7][0]->get_pieceColor() == 0) && (tile[7][2]->get_piece() == 1) && (tile[7][2]->get_pieceColor() == 0) && (tile[7][4]->get_piece() == 1) && (tile[7][4]->get_pieceColor() == 0) && (tile[7][6]->get_piece() == 1) && (tile[7][6]->get_pieceColor() == 0))
    {
        white_pawns_wins = true;
    }

    if ((white_pawns_wins == true) && (black_pawns_wins == true))
    {
        return 3;
    }

    if ((white_pawns_wins == true) && (black_pawns_wins == false))
    {
        return 2;
    }

    if ((white_pawns_wins == false) && (black_pawns_wins == true))
    {
        return 1;
    }

    if ((white_pawns_wins == false) && (black_pawns_wins == false))
    {
        return 0;
    }
    return 0;
}

void end_turn()
{
    cm->clear_queue();
    if (!((jump_from_field[0] == 0) && (jump_from_field[1] == 0)))
    {
        tile[jump_from_field[0]][jump_from_field[1]]->setStyleSheet ("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
    }

    disOrange ();
    max = 0;
    count = 0;

    if (without_changing_player == false)
    {
        turn = (turn+1)%2;
    }

    if (end_game() == 0)
    {
        w->change_player_bold();
    }
    else if ((end_game() == 1) && (settings::get_game_with_computer() == false))
    {
        //turn without change
        //don't change the players bold
        if (change_points == true)
        {
            w->set_player_2_points (std::to_string(stoi(w->get_player_2_points())+1));
        }
        else
        {
            change_points = true;
        }

        without_changing_player = true;
        w->player_1_name_bold (false);
        w->player_2_name_bold (true);
        w->players_set_text (true, true, false);
    }
    else if (end_game() == 2)
    {
        //turn without change
        //don't change the players bold
        w->set_player_1_points (std::to_string(stoi(w->get_player_1_points())+1));
        without_changing_player = true;
        w->player_1_name_bold (true);
        w->player_2_name_bold (false);
        w->players_set_text (true, false, true);
    }
    else
    {
        if (settings::get_game_with_computer() == true)
        {
            disBlue();
        }

        settings::set_game_started(false);
        w->hide_end_movement_button();

        if (stoi(w->get_player_1_points()) < stoi(w->get_player_2_points()))
        {
            w->player_1_name_bold (true);
            w->player_2_name_bold (false);
        }
        else if (stoi(w->get_player_1_points()) > stoi(w->get_player_2_points()))
        {
            w->player_1_name_bold (false);
            w->player_2_name_bold (true);
        }
        else
        {
            w->player_1_name_bold (true);
            w->player_2_name_bold (true);
            w->players_set_text (true, true, true);
        }

        w->hide_end_movement_button();

        jump_from_field[0] = 0;
        jump_from_field[1] = 0;
        jumps = false;

        if ((end_game() == 1) && (settings::get_game_with_computer() == true))
        {
            if (stoi(w->get_player_1_points()) > stoi(w->get_player_2_points()))
            {
                w->set_player_1_points (std::to_string(stoi(w->get_player_1_points())+5*(rand()%5+1)));
            }
            else if (stoi(w->get_player_1_points()) < stoi(w->get_player_2_points()))
            {
                w->set_player_2_points (std::to_string(stoi(w->get_player_2_points())+5*(rand()%5+1)));
            }
            setPawns(false);
        }
        return;
    }

    jump_from_field[0] = 0;
    jump_from_field[1] = 0;
    jumps = false;
    w->show_end_movement_button();

    if ((turn == 0) && (settings::get_game_with_computer() == true))
    {
        cm->finds_movements(tile);
        movement temp_movement = cm->return_movement();
        if (temp_movement.get_movement_weight() != 0)
        {
            cm->do_movement (temp_movement);
        }
        end_turn();
    }
}
