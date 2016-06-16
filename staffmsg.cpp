#include "staffmsg.h"
#include "ui_staffmsg.h"
#include <QSqlQuery>

StaffMsg::StaffMsg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffMsg)
{
    ui->setupUi(this);
}

void StaffMsg::receiveData(QString data)
{
    id = data;
    QSqlQuery query;
    QString pid = "";
    //QString passwd = "";
    QString permission = "";
    QString name = "";
    QString sex = "";
    QString department = "";
    QString position = "";
    QString edu_level = "";
    QString tel = "";
    QString remark = "";
    query.prepare("select * from personMsg where pid=:id ");
    query.bindValue(":id",id.toInt());
    if(query.exec())
    {
        query.next();
        pid = query.value(0).toString();
        //passwd = query.value(1).toString();
        permission = query.value(2).toString();
        name = query.value(3).toString();
        sex = query.value(4).toString();
        department = query.value(5).toString();
        position = query.value(6).toString();
        edu_level = query.value(7).toString();
        tel = query.value(8).toString();
        remark= query.value(9).toString();

        ui->lineEdit->setText(pid);
        ui->lineEdit_2->setText(name);
        ui->lineEdit_3->setText(permission);
        ui->lineEdit_4->setText(sex);
        ui->lineEdit_5->setText(department);
        ui->lineEdit_6->setText(position);
        ui->lineEdit_7->setText(edu_level);
        ui->lineEdit_8->setText(tel);
        ui->plainTextEdit->setPlainText(remark);
    }
}

StaffMsg::~StaffMsg()
{
    delete ui;
}
