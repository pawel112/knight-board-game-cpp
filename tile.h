#ifndef TILE_H
#define TILE_H

#include <QLabel>

class Tile: public QLabel
{
private:
    int tileColor;
    int piece;
    int pieceColor;
    int row;
    int col;
    int tileNum;
    char pieceName;
public:
    Tile (QWidget* pParent=0, Qt::WindowFlags f=0): QLabel(pParent, f) {}
    Tile (const QString& text, QWidget* pParent=0, Qt::WindowFlags f=0): QLabel(text, pParent, f) {}

    int get_tileColor() { return tileColor; }
    int get_piece() { return piece; }
    int get_pieceColor() { return pieceColor; }
    int get_row() { return row; }
    int get_col() { return col; }
    int get_tileNum() { return tileNum; }
    char get_pieceName() { return pieceName; }

    void set_tileColor (int tileColor) { this->tileColor = tileColor; }
    void set_piece (int piece) { this->piece = piece; }
    void set_pieceColor (int pieceColor) { this->pieceColor = pieceColor; }
    void set_row (int row) { this->row = row; }
    void set_col (int col) { this->col = col; }
    void set_tileNum (int tileNum) { this->tileNum = tileNum; }
    void set_pieceName (char pieceName) { this->pieceName = pieceName; }

    void mousePressEvent (QMouseEvent *event);
    void display (char elem);
    void tileDisplay ();
};

void disOrange ();
void disBlue ();

#endif
