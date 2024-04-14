#include "page1.h"
#include "page4.h"
#include "ui_page4.h"
#include <QComboBox>
#include "QMessageBox"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

page4::page4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page4)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("c:\\info.db");
    database.open();

    ui->setupUi(this);
    ui->spinBox->setMaximum(2018);
    ui->spinBox->setMinimum(1920);

    QStringList expertise = (QStringList()
                        <<"Backend"
                        <<"Frontend"
                        <<"Fullstack"
                        <<"Security"
                         <<"Windowx"
                         <<"SEO"
                         <<"Database"
                         <<"Mobile");
    ui->expertisecomboBox->addItems(expertise);

}

page4::~page4()
{
    delete ui;
}

void page4::on_pushButton_clicked()
{
    QSqlQuery q;
    QString name, year, exper, loc;
    name = ui->lineEdit_2->text();
    year = ui->spinBox->text();
    exper = ui->expertisecomboBox->currentText();
    loc = ui->lineEdit->text();
    q.exec("SELECT fullName FROM info WHERE fullName = '"+name+"'");
    if (q.first()){
    q.exec("UPDATE info SET location = '"+loc+"',expertise = '"+exper+"',birth = '"+year+"' WHERE fullName = '"+name+"'");
    QMessageBox::information(this,"Successful","Information completion was successful");
    }
    else {
        QMessageBox::warning(this,"wrong name","please enter the correct name","try agin");
    }
}


void page4::on_signOutPushButton_clicked()
{
    page1 *w1 = new page1;
    w1->show();
    w1->setWindowTitle("Welcome");
    this->close();
}

