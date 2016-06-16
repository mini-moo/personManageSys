#ifndef STAFFMSGOPR_H
#define STAFFMSGOPR_H

#include <QDialog>

namespace Ui {
    class StaffMsgOpr;
}

class StaffMsgOpr : public QDialog
{
    Q_OBJECT

public:
    explicit StaffMsgOpr(QWidget *parent = 0);
    ~StaffMsgOpr();

private:
    Ui::StaffMsgOpr *ui;

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
};

#endif // STAFFMSGOPR_H
