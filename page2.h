#ifndef PAGE2_H
#define PAGE2_H

#include <QMainWindow>

namespace Ui {
class page2;
}

class page2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit page2(QWidget *parent = nullptr);
    ~page2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_logpushButton_clicked();

    //void on_pushButton_3_clicked();

    //void on_pushButton_4_clicked();


    void on_enterNumLineEdit_textEdited(const QString &arg1);

private:
    Ui::page2 *ui;
};

#endif // PAGE2_H
