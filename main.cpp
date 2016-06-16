#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtSql>
#include <QSqlError>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置编码：将QString转化为UTF-8格式以便存入数据库中
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    //连接数据库
    QSqlDatabase dbconn = QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName("PersonnMangSys.db");
    if(!dbconn.open())
    {
        qDebug() << QObject::tr("打开数据库失败");
    }
    else
    {
        qDebug() << QObject::tr("打开数据库成功");
    }

      //建立数据表
    QSqlQuery query;
//    query.exec("drop table personMsg");
//    query.prepare("create table personMsg("
//                  "pid integer primary key,"
//                  "passwd varchar(16) not null,"
//                  "permission integer,"
//                  "name varchar(10) not null,sex varchar(8) not null,"
//                  "department varchar(20) not null,position varchar(20),"
//                  "edu_level varchar(20),tel varchar(13),remark varchar(50))");
//    query.exec("insert into personMsg values(110,'123456',1,'张三','男','人事部','职员','本科','15200352211',' ')");
//    query.exec("insert into personMsg values(111,'123456',0,'李四','男','技术部','职员','硕士','15200352212',' ')");
//    query.exec("insert into personMsg values(112,'123456',0,'王五','女','宣传部','职员','大专','15200352213',' ')");
//    query.exec("insert into personMsg values(113,'123456',0,'陈隆阳','男','清洁部','经理','小学','15200352214',' ')");
//    if(!query.exec())
//        qDebug()<<query.lastError();
//    query.exec("drop table personnel");
//    query.prepare("create table personnel(id integer primary key,"
//                  "pid integer,"
//                  "change varchar(60),"
//                  "description varchar(60))");
//    if(!query.exec())
//        qDebug()<<query.lastError();
//    query.exec("insert into personnel values(1,113,'降职','不听话')");
//    query.exec("insert into personnel values(2,111,'升职','牛逼，深得朕心')");
//    query.exec("insert into personnel values(3,112,'降职','产品宣传不过关，事后无态度')");

//    query.prepare("create table departmentMsg(did integer primary key,"
//                  "name varchar(20),"
//                  "manager varchar(20),"
//                  "intro varchar(100))");
//    if(!query.exec())
//        qDebug() << query.lastError();
//    query.exec("insert into departmentMsg values(104,'人事部','','管理人事')");
//    query.exec("insert into departmentMsg values(105,'技术部','','技术至上')");
//    query.exec("insert into departmentMsg values(106,'宣传部','','信息广播')");
//    query.exec("insert into departmentMsg values(107,'清洁部','陈隆阳','美化办公环境')");

    //主界面
    MainWindow w;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    w.setWindowTitle(QObject::tr("欢迎！"));
    w.show();

    return a.exec();
}
