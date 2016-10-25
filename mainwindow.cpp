#include "mainwindow.h"
#include "aboutwindow.h"
#include "ruleswindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "main.h"
#include "language.h"
#include "check_game.h"
#include "tile.h"

extern Tile *tile[8][8];
extern int turn;
extern bool jumps;
extern int count;
extern int exp24[60];
extern bool clicked;
extern bool change_points;
bool without_changing_player = false;

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow (parent),
    ui (new Ui::MainWindow)
    {
        ui->setupUi (this);
        chessBoard (this, tile);
        this->setWindowTitle(QString::fromStdString(language::get_game_name()));
        this->statusBar()->setSizeGripEnabled(false);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        ui->menu_New_game->setTitle(QString::fromStdString(language::get_new_game_menu_name()));
        ui->actionGame_with_computer->setText(QString::fromStdString(language::get_game_with_computer_name()));
        ui->actionGame_with_man->setText(QString::fromStdString(language::get_game_with_man_name()));
        ui->actionEasy->setText(QString::fromStdString(language::get_easy_name()));
        ui->actionHard->setText(QString::fromStdString(language::get_hard_name()));
        ui->menuGame->setTitle(QString::fromStdString(language::get_game_menu_name()));
        ui->menuOptions->setTitle(QString::fromStdString(language::get_options_menu_name()));
        ui->action_About_game->setText(QString::fromStdString(language::get_about_game_name()));
        ui->action_Game_rules->setText(QString::fromStdString(language::get_game_rules_name()));
        ui->action_End_game->setText(QString::fromStdString(language::get_end_game_name()));
        ui->menuComputer_difficulty->setTitle(QString::fromStdString(language::get_game_difficulty_name()));
        ui->actionPlaying_with_the_computer->setText(QString::fromStdString(language::get_play_with_the_computer_name()));
        ui->endButtonMovement->setText(QString::fromStdString(language::get_end_turn_text()));
        ui->player_1_name->setText(QString::fromStdString(language::get_player_text()+" 1"));
        ui->player_2_name->setText(QString::fromStdString(language::get_player_text()+" 2"));
        ui->player_1_points->setText(QString::fromStdString("0"));
        ui->player_2_points->setText(QString::fromStdString("0"));
        hide_end_movement_button();
    }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_End_game_triggered()
{
    this->close();
}

void MainWindow::on_action_About_game_triggered()
{
    AboutWindow *w = new AboutWindow();
    w->show();
}

void MainWindow::on_action_Game_rules_triggered()
{
    RulesWindow *w = new RulesWindow();
    w->show();
}

void MainWindow::on_actionEasy_triggered(bool checked)
{
    if ((settings::get_game_started() == false) || (settings::get_game_with_computer() == false))
    {
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(false);
        return;
    }

    if (checked == true)
    {
        settings::set_computer_difficulty (false);
        ui->actionEasy->setChecked(true);
        ui->actionHard->setChecked(false);
    }
    else
    {
        settings::set_computer_difficulty (true);
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(true);
    }
}

void MainWindow::on_actionHard_triggered(bool checked)
{
    if ((settings::get_game_started() == false) || (settings::get_game_with_computer() == false))
    {
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(false);
        return;
    }

    if (checked == true)
    {
        settings::set_computer_difficulty (true);
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(true);
    }
    else
    {
        settings::set_computer_difficulty (false);
        ui->actionEasy->setChecked(true);
        ui->actionHard->setChecked(false);
    }
}

void MainWindow::on_actionGame_with_man_triggered()
{
    for (int i=0; i<60; i++)
    {
        exp24[i] = 0;
    }

    change_points = false;
    count = 0;
    turn = 1;
    without_changing_player = false;
    settings::set_game_started (true);
    settings::set_game_with_computer (false);
    settings::set_player_1_choosed_white (true);
    settings::set_computer_difficulty (false);
    ui->player_1_name->setText(QString::fromStdString(language::get_player_text()+" 1"));
    ui->player_2_name->setText(QString::fromStdString(language::get_player_text()+" 2"));
    ui->player_1_points->setText(QString::fromStdString("0"));
    ui->player_2_points->setText(QString::fromStdString("0"));
    player_1_name_bold (true);
    player_2_name_bold (false);
    players_set_text (false, false, false);
    show_end_movement_button();
    setPawns (true);
}

void MainWindow::on_actionGame_with_computer_triggered()
{
    for (int i=0; i<60; i++)
    {
        exp24[i] = 0;
    }

    change_points = false;
    count = 0;
    turn = 1;
    without_changing_player = false;
    settings::set_game_started (true);
    settings::set_game_with_computer (true);
    settings::set_player_1_choosed_white (true);
    settings::set_computer_difficulty (true);
    ui->player_1_name->setText(QString::fromStdString(language::get_player_text()+" 1"));
    ui->player_2_name->setText(QString::fromStdString(language::get_player_text()+" 2"));
    ui->player_1_points->setText(QString::fromStdString("0"));
    ui->player_2_points->setText(QString::fromStdString("0"));
    player_1_name_bold (true);
    player_2_name_bold (false);
    players_set_text (false, false, false);
    show_end_movement_button();
    on_actionHard_triggered (true);
    setPawns (true);
}

void MainWindow::on_actionPlaying_with_the_computer_triggered (bool checked)
{
    if (checked == false)
    {
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(false);
    }
    else
    {
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(true);
    }

    settings::set_game_with_computer (checked);
}

void MainWindow::on_endButtonMovement_clicked()
{
    if (settings::get_game_started() == false)
    {
        return;
    }

    disBlue();
    if (clicked == true)
    {
        clicked = false;
    }
    end_turn();
}

void MainWindow::change_player_bold()
{
    if (turn == 1)
    {
        player_1_name_bold (true);
        player_2_name_bold (false);
    }
    else
    {
        player_1_name_bold (false);
        player_2_name_bold (true);
    }
}

void MainWindow::show_end_movement_button()
{
   ui->endButtonMovement->show();
}

void MainWindow::hide_end_movement_button()
{
    ui->endButtonMovement->hide();
}

void MainWindow::player_1_name_bold (bool bold)
{
    if (bold == true)
    {
        ui->player_1_name->setStyleSheet(" font-weight: bold; ");
    }
    else
    {
        ui->player_1_name->setStyleSheet(" font-weight: none; ");
    }
}

void MainWindow::player_2_name_bold (bool bold)
{
    if (bold == true)
    {
        ui->player_2_name->setStyleSheet(" font-weight: bold; ");
    }
    else
    {
        ui->player_2_name->setStyleSheet(" font-weight: none; ");
    }
}

void MainWindow::players_set_text (bool winner, bool winner1, bool winner2)
{
    if (winner == true)
    {
        if ((winner1 == true) && (winner2 == false))
        {
            ui->player_1_name->setText(QString::fromStdString(language::get_winner_text()));
            player_1_name_bold (true);
            player_2_name_bold (false);
        }
        else if ((winner1 == false) && (winner2 == true))
        {
            ui->player_2_name->setText(QString::fromStdString(language::get_winner_text()));
            player_1_name_bold (false);
            player_2_name_bold (true);
        }
        else if ((winner1 == true) && (winner2 == true))
        {
            ui->player_1_name->setText(QString::fromStdString(language::get_draw_text()));
            ui->player_2_name->setText(QString::fromStdString(language::get_draw_text()));
            player_1_name_bold (true);
            player_2_name_bold (true);
        }
    }
    else
    {
        ui->player_1_name->setText(QString::fromStdString(language::get_player_text()+" 1"));
        ui->player_2_name->setText(QString::fromStdString(language::get_player_text()+" 2"));
    }
}

void MainWindow::set_player_1_points (std::string points)
{
    ui->player_1_points->setText(QString::fromStdString(points));
}

void MainWindow::set_player_2_points (std::string points)
{
    ui->player_2_points->setText(QString::fromStdString(points));
}

void MainWindow::set_play_with_computer_button (bool choise)
{
    ui->actionPlaying_with_the_computer->setChecked(choise);
}

std::string MainWindow::get_player_1_points ()
{
    return ui->player_1_points->text().toStdString();
}

std::string MainWindow::get_player_2_points ()
{
    return ui->player_2_points->text().toStdString();
}
