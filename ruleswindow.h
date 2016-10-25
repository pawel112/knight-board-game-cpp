#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QDialog>

namespace Ui
{
    class RulesWindow;
}

class RulesWindow: public QDialog
{
private:
    Q_OBJECT
    Ui::RulesWindow *ui;
private slots:
        void on_pushButton_clicked();
public:
    explicit RulesWindow(QWidget *parent = 0);
    ~RulesWindow();
};

#endif
