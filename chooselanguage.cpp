#include "chooselanguage.h"
#include "ui_chooselanguage.h"
#include "mainwindow.h"
#include "language.h"
#include "main.h"

extern MainWindow *w;

ChooseLanguage::ChooseLanguage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseLanguage)
    {
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        ui->setupUi(this);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        this->setWindowTitle(QString::fromStdString(language::get_game_name()));
    }

ChooseLanguage::~ChooseLanguage()
{
    delete ui;
}

void ChooseLanguage::on_en_button_clicked()
{
    //choose English language
    language::set_en();
    w = new MainWindow();
    w->show();
    this->close();
}

void ChooseLanguage::on_pl_button_clicked()
{
    //choose Polish language
    language::set_pl();
    w = new MainWindow();
    w->show();
    this->close();
}
