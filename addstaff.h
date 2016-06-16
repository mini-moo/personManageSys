#ifndef ADDSTAFF_H
#define ADDSTAFF_H

#include <QDialog>

namespace Ui {
    class addStaff;
}

class addStaff : public QDialog
{
    Q_OBJECT

public:
    explicit addStaff(QWidget *parent = 0);
    ~addStaff();

private:
    Ui::addStaff *ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // ADDSTAFF_H
