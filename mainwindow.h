#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

namespace Ui
{
    class MainWindow;
}

class MainWindow: public QMainWindow
{
private:
    Ui::MainWindow *ui;
    Q_OBJECT
private slots:
    void on_action_End_game_triggered();
    void on_action_About_game_triggered();
    void on_action_Game_rules_triggered();
    void on_actionEasy_triggered(bool checked);
    void on_actionHard_triggered(bool checked);
    void on_actionGame_with_man_triggered();
    void on_actionGame_with_computer_triggered();
    void on_actionPlaying_with_the_computer_triggered (bool checked);
    void on_endButtonMovement_clicked();
public:
    explicit MainWindow(QWidget *parent = 0);
    void change_player_bold();
    void show_end_movement_button();
    void hide_end_movement_button();
    void player_1_name_bold (bool bold);
    void player_2_name_bold (bool bold);
    void set_player_1_points (std::string points);
    void set_player_2_points (std::string points);
    void set_play_with_computer_button (bool choise);
    std::string get_player_1_points ();
    std::string get_player_2_points ();
    void players_set_text (bool winner, bool winner1, bool winner2);
    ~MainWindow();
};

#endif
