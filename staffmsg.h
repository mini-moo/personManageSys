#ifndef STAFFMSG_H
#define STAFFMSG_H

#include <QDialog>

namespace Ui {
    class StaffMsg;
}

class StaffMsg : public QDialog
{
    Q_OBJECT

public:
    explicit StaffMsg(QWidget *parent = 0);
    ~StaffMsg();

private slots:
    void receiveData(QString data);

private:
    Ui::StaffMsg *ui;
    QString id;
};

#endif // STAFFMSG_H
