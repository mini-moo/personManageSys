#ifndef CHANGEPERSON_H
#define CHANGEPERSON_H

#include <QDialog>

namespace Ui {
    class ChangePerson;
}

class ChangePerson : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePerson(QWidget *parent = 0);
    ~ChangePerson();

private:
    Ui::ChangePerson *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
};

#endif // CHANGEPERSON_H
