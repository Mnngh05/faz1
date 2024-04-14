#include "page1.h"
#include "ui_page1.h"
#include "page2.h"


page1::page1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::page1)
{
    setWindowTitle("Welcome");
    ui->setupUi(this);
    ui->imageLabel->setStyleSheet("image: url(:/new/prefix1/pc3.jpg);");
    ui->pushButton->setStyleSheet("background-color: rgb(80, 177, 188);");
}

page1::~page1()
{
    delete ui;
}


void page1::on_pushButton_clicked()
{
    page2 *w2 = new page2;
    w2->show();
    w2->setWindowTitle("Sign in");
    this->close();
}

