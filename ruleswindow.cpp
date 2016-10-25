#include "ruleswindow.h"
#include "ui_ruleswindow.h"
#include "language.h"

RulesWindow::RulesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RulesWindow)
    {
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        ui->setupUi(this);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        this->setWindowTitle(QString::fromStdString(language::get_game_rules_name()));
        ui->textBrowser->setText(QString::fromStdString(language::get_game_rules_text()));
        ui->pushButton->setText(QString::fromStdString(language::get_close_text()));
    }

RulesWindow::~RulesWindow()
{
    delete ui;
}

void RulesWindow::on_pushButton_clicked()
{
    this->close();
}
