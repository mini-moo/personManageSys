#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtSql>
#include <QSqlError>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //���ñ��룺��QStringת��ΪUTF-8��ʽ�Ա�������ݿ���
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    //�������ݿ�
    QSqlDatabase dbconn = QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName("PersonnMangSys.db");
    if(!dbconn.open())
    {
        qDebug() << QObject::tr("�����ݿ�ʧ��");
    }
    else
    {
        qDebug() << QObject::tr("�����ݿ�ɹ�");
    }

      //�������ݱ�
    QSqlQuery query;
//    query.exec("drop table personMsg");
//    query.prepare("create table personMsg("
//                  "pid integer primary key,"
//                  "passwd varchar(16) not null,"
//                  "permission integer,"
//                  "name varchar(10) not null,sex varchar(8) not null,"
//                  "department varchar(20) not null,position varchar(20),"
//                  "edu_level varchar(20),tel varchar(13),remark varchar(50))");
//    query.exec("insert into personMsg values(110,'123456',1,'����','��','���²�','ְԱ','����','15200352211',' ')");
//    query.exec("insert into personMsg values(111,'123456',0,'����','��','������','ְԱ','˶ʿ','15200352212',' ')");
//    query.exec("insert into personMsg values(112,'123456',0,'����','Ů','������','ְԱ','��ר','15200352213',' ')");
//    query.exec("insert into personMsg values(113,'123456',0,'��¡��','��','��ಿ','����','Сѧ','15200352214',' ')");
//    if(!query.exec())
//        qDebug()<<query.lastError();
//    query.exec("drop table personnel");
//    query.prepare("create table personnel(id integer primary key,"
//                  "pid integer,"
//                  "change varchar(60),"
//                  "description varchar(60))");
//    if(!query.exec())
//        qDebug()<<query.lastError();
//    query.exec("insert into personnel values(1,113,'��ְ','������')");
//    query.exec("insert into personnel values(2,111,'��ְ','ţ�ƣ��������')");
//    query.exec("insert into personnel values(3,112,'��ְ','��Ʒ���������أ��º���̬��')");

//    query.prepare("create table departmentMsg(did integer primary key,"
//                  "name varchar(20),"
//                  "manager varchar(20),"
//                  "intro varchar(100))");
//    if(!query.exec())
//        qDebug() << query.lastError();
//    query.exec("insert into departmentMsg values(104,'���²�','','��������')");
//    query.exec("insert into departmentMsg values(105,'������','','��������')");
//    query.exec("insert into departmentMsg values(106,'������','','��Ϣ�㲥')");
//    query.exec("insert into departmentMsg values(107,'��ಿ','��¡��','�����칫����')");

    //������
    MainWindow w;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    w.setWindowTitle(QObject::tr("��ӭ��"));
    w.show();

    return a.exec();
}
