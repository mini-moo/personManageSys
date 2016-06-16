#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox.h"
#include "QTextCodec.h"
#include <QtSql>
#include "staffmsg.h"
#include "adminopreatwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    this -> close();
}

void MainWindow::on_pushButton_clicked()
{
    StaffMsg *w = new StaffMsg;
    //建立信号与槽的联系
    connect(this,SIGNAL(sendData(QString)),w,SLOT(receiveData(QString)));

    AdminOpreatWindow *m = new AdminOpreatWindow;

    QSqlQuery query;
    int num = 0;
    int n = 0;
    int id = this->ui->lineEdit->text().toInt();
    QString passwd = this->ui->lineEdit_2->text().trimmed();
    query.prepare("select count(*) from personMsg where pid=:id and passwd=:pwd");
    query.bindValue(":id",id);
    query.bindValue(":pwd",passwd);
    if(query.exec())
    {
       query.next();
       num = query.value(0).toInt();
       if(num == 1)
       {
           query.prepare("select permission from personMsg where pid=:id and passwd=:pwd");
           query.bindValue(":id",id);
           query.bindValue(":pwd",passwd);
           if(query.exec())
           {
               query.next();
               n = query.value(0).toInt();
               if(n == 0)
               {
                   //员工登录
                   emit sendData(ui->lineEdit->text());
                   w->setWindowTitle(QObject::tr("员工信息"));
                   w->show();
               }
               else
               {
                   //管理员登录
                   m->setWindowTitle(QObject::tr("操作"));
                   m->show();
               }
           }
       }
       else
       {
           QTextCodec::setCodecForTr( QTextCodec::codecForName("GBK") );
           QMessageBox::warning(this,tr("警告"),tr("用户名或密码错误!"),QMessageBox::Yes);
           this->ui->lineEdit->clear();
           this->ui->lineEdit_2->clear();
           this->ui->lineEdit->setFocus();
       }
    }
}
