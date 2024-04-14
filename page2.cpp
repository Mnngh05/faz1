#include "page2.h"
#include "ui_page2.h"
#include "QMessageBox"
#include "page3.h"
#include "login.h"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

int r;

page2::page2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page2)
{
    ui->setupUi(this);
    ui->passlineEdit->setEchoMode(QLineEdit::Password);
    ui->logpushButton->setStyleSheet("font: 12pt 'MS Shell Dlg 2';color: rgb(255, 255, 255);background-color: rgb(6, 155, 255);");
    ui->pushButton_2->setEnabled(false);
    r = rand()%9000 +1000;
    ui->randlineEdit->setText(QString::number(r));
    ui->randlineEdit->setEnabled(false);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("c:\\info.db");
    database.open();
}


page2::~page2()
{
    delete ui;
}

void page2::on_pushButton_clicked()
{
     r = rand()%9000 +1000;
     ui->randlineEdit->setText(QString::number(r));
     ui->randlineEdit->setEnabled(false);
}




void page2::on_enterNumLineEdit_textEdited(const QString &arg1)
{
     ui->pushButton_2->setEnabled(true);
     ui->pushButton_2->setStyleSheet("font: 12pt 'MS Shell Dlg 2';color: rgb(255, 255, 255);background-color: rgb(6, 155, 255);");
}

void page2::on_pushButton_2_clicked()
{
    QSqlQuery q;
    QString name , pass;
    name = ui->namelineEdit->text();
    pass = ui->passlineEdit->text();
    q.exec("SELECT fullName FROM info WHERE fullName = '"+name+"'");

    if(ui->randlineEdit->text() != ui->enterNumLineEdit->text()) {
            QMessageBox::warning(this,"Incorrect", "Please enter the correct number","Try again");
        }
    else if(q.first()){
        QMessageBox::warning(this,"Invalid", "Please enter another name or fill the password section");
    }
    else if( ui->randlineEdit->text() == ui->enterNumLineEdit->text())
    {
        q.exec("INSERT INTO info(fullName , password)VALUES('"+name+"' , '"+pass+"')");
        page3 *w3 = new page3;

        this->close();
        w3->show();
        w3->setWindowTitle("Code");
    }

    else
        QMessageBox::warning(this,"Invalid", "Please enter valid information");

}


void page2::on_logpushButton_clicked()
{
    login *w5 = new login;
    w5->show();
    w5->setWindowTitle("Login");
    this->close();
}


/*void page2::on_pushButton_3_clicked()
{
    QSqlQuery q;
    q.exec("SELECT * FROM info");
    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(q);
    ui->tableView->setModel(m);
}


void page2::on_pushButton_4_clicked()
{
    QString d;
    d = ui->delnamelineEdit->text();
    QSqlQuery q;
    q.exec("DELETE FROM info WHERE fullName ='"+d+"' ");
}
*/











