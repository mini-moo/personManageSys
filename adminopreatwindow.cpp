#include "adminopreatwindow.h"
#include "ui_adminopreatwindow.h"
#include <QtSql>
#include <QTextCodec>
#include "addstaff.h"
#include "staffmsgopr.h"
#include "changeperson.h"

AdminOpreatWindow::AdminOpreatWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminOpreatWindow)
{
    ui->setupUi(this);
}

AdminOpreatWindow::~AdminOpreatWindow()
{
    delete ui;
}

void AdminOpreatWindow::on_pushButton_clicked()
{
    addStaff *w = new addStaff;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    w->setWindowTitle(QObject::tr("添加"));
    w->show();
}

void AdminOpreatWindow::on_pushButton_4_clicked()
{
    this->close();
}

void AdminOpreatWindow::on_pushButton_3_clicked()
{
    StaffMsgOpr *w = new StaffMsgOpr;
    w->show();
    this->close();
}

void AdminOpreatWindow::on_pushButton_2_clicked()
{
    ChangePerson *w = new ChangePerson;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    w->setWindowTitle(QObject::tr("人事变动"));
    w->show();
    this->close();
}
