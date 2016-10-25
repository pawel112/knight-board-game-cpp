#ifndef CHOOSELANGUAGE_H
#define CHOOSELANGUAGE_H

#include <QDialog>

namespace Ui {
class ChooseLanguage;
}

class ChooseLanguage: public QDialog
{
private:
    Ui::ChooseLanguage *ui;
    Q_OBJECT
private slots:
    void on_en_button_clicked();
    void on_pl_button_clicked();
public:
    explicit ChooseLanguage(QWidget *parent = 0);
    ~ChooseLanguage();
};

#endif
