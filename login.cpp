#include "login.h"
#include "ui_login.h"
#include "page2.h"
#include "page4.h"
#include "QMessageBox"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
     ui->pushButton->setStyleSheet("font: 12pt 'MS Shell Dlg 2';color: rgb(255, 255, 255);background-color: rgb(6, 155, 255);");
      ui->pushButton_2->setStyleSheet("font: 12pt 'MS Shell Dlg 2';color: rgb(255, 255, 255);background-color: rgb(6, 155, 255);");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("c:\\info.db");
    database.open();
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_2_clicked()
{
    page2 *w2 = new page2;
    this->close();
    w2->show();
    w2->setWindowTitle("Sign in");
}

void login::on_pushButton_clicked()
{
    QSqlQuery q;
    QString name , pass;
    name = ui->lineEdit->text();
    pass = ui->lineEdit_2->text();
    q.exec("SELECT fullName FROM info WHERE fullName = '"+name+"' AND password = '"+pass+"'");
    if(q.first()){
    page4 *w4 = new page4;
           this->close();
           w4->show();
           w4->setWindowTitle("Complete");
    }
    else
       QMessageBox::warning(this,"invalid","your name or password is incorrect!","Try again");

}

