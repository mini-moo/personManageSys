#include "changeperson.h"
#include "ui_changeperson.h"
#include <QtSql>
#include <QComboBox>
#include <QDebug>
#include <QMessageBox>

ChangePerson::ChangePerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePerson)
{
    ui->setupUi(this);
}

ChangePerson::~ChangePerson()
{
    delete ui;
}

void ChangePerson::on_pushButton_3_clicked()
{
    this->close();
}

//查找
void ChangePerson::on_pushButton_clicked()
{
     int uid = ui->lineEdit->text().toInt();
     QSqlQuery query;
     QString id;
     QString pid;
     QString change;
     QString description;
     query.prepare("select * from personnel where id=:uid");
     query.bindValue(":uid",uid);
     if(query.exec())
     {
         query.next();
         id = query.value(0).toString();
         pid = query.value(1).toString();
         change = query.value(2).toString();
         description = query.value(3).toString();

         ui->lineEdit_3->setText(id);
         ui->lineEdit_2->setText(pid);
         ui->comboBox->setCurrentIndex(ui->comboBox->findText(change));
         ui->plainTextEdit->setPlainText(description);
     }
}

//添加变更
void ChangePerson::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QSqlQuery queryChange;

    int pid = ui->lineEdit_2->text().toInt();
    QString passwd = "";
    int permission;
    QString name = "";
    QString sex = "";
    QString department = "";
    QString position = "";
    QString edu_level = "";
    QString tel = "";
    QString remark = "";

    int num = 0;
    int id = ui->lineEdit_3->text().toInt();
    QString change = ui->comboBox->itemText(ui->comboBox->currentIndex());
    QString description = ui->plainTextEdit->toPlainText();
    //修改personMsg中的数据
    if(change == "升职为经理")
    {
        queryChange.prepare("select * from personMsg where pid=:pid");
        queryChange.bindValue(":pid",pid);
        if(queryChange.exec())
        {
            queryChange.next();
            passwd = queryChange.value(1).toString();
            permission = queryChange.value(2).toInt();
            name = queryChange.value(3).toString();
            sex = queryChange.value(4).toString();
            department = queryChange.value(5).toString();
            //position = query.value(6).toString();
            position = "经理";
            edu_level = queryChange.value(7).toString();
            tel = queryChange.value(8).toString();
            remark= queryChange.value(9).toString();
            queryChange.prepare("delete from personMsg where pid=:pid");
            queryChange.bindValue(":pid",pid);
            queryChange.exec();

            queryChange.prepare("insert into personMsg values(:pid,:passwd,:permission,:name,:sex,:department,:position,:edu_level,:tel,:remark)");
            queryChange.bindValue(":pid",pid);
            queryChange.bindValue(":passwd",passwd);
            queryChange.bindValue(":permission",permission);
            queryChange.bindValue(":name",name);
            queryChange.bindValue(":sex",sex);
            queryChange.bindValue(":department",department);
            queryChange.bindValue(":position",position);
            queryChange.bindValue(":edu_level",edu_level);
            queryChange.bindValue(":tel",tel);
            queryChange.bindValue(":remark",remark);
            queryChange.exec();
        }
    }
    else if(change == "降职为职员")
    {
        queryChange.prepare("select * from personMsg where pid=:pid");
        queryChange.bindValue(":pid",pid);
        if(queryChange.exec())
        {
            queryChange.next();
            passwd = queryChange.value(1).toString();
            permission = queryChange.value(2).toInt();
            name = queryChange.value(3).toString();
            sex = queryChange.value(4).toString();
            department = queryChange.value(5).toString();
            //position = query.value(6).toString();
            position = "职员";
            edu_level = queryChange.value(7).toString();
            tel = queryChange.value(8).toString();
            remark= queryChange.value(9).toString();
            queryChange.prepare("delete from personMsg where pid=:pid");
            queryChange.bindValue(":pid",pid);
            queryChange.exec();

            queryChange.prepare("insert into personMsg values(:pid,:passwd,:permission,:name,:sex,:department,:position,:edu_level,:tel,:remark)");
            queryChange.bindValue(":pid",pid);
            queryChange.bindValue(":passwd",passwd);
            queryChange.bindValue(":permission",permission);
            queryChange.bindValue(":name",name);
            queryChange.bindValue(":sex",sex);
            queryChange.bindValue(":department",department);
            queryChange.bindValue(":position",position);
            queryChange.bindValue(":edu_level",edu_level);
            queryChange.bindValue(":tel",tel);
            queryChange.bindValue(":remark",remark);
            queryChange.exec();
        }
    }
    else if(change == "解雇")
    {
        queryChange.prepare("select * from personMsg where pid=:pid");
        queryChange.bindValue(":pid",pid);
        if(queryChange.exec())
        {
            queryChange.next();
            passwd = queryChange.value(1).toString();
            permission = queryChange.value(2).toInt();
            name = queryChange.value(3).toString();
            sex = queryChange.value(4).toString();
            department = queryChange.value(5).toString();
            //position = query.value(6).toString();
            position = "离职";
            edu_level = queryChange.value(7).toString();
            tel = queryChange.value(8).toString();
            remark= queryChange.value(9).toString();
            queryChange.prepare("delete from personMsg where pid=:pid");
            queryChange.bindValue(":pid",pid);
            queryChange.exec();

            queryChange.prepare("insert into personMsg values(:pid,:passwd,:permission,:name,:sex,:department,:position,:edu_level,:tel,:remark)");
            queryChange.bindValue(":pid",pid);
            queryChange.bindValue(":passwd",passwd);
            queryChange.bindValue(":permission",permission);
            queryChange.bindValue(":name",name);
            queryChange.bindValue(":sex",sex);
            queryChange.bindValue(":department",department);
            queryChange.bindValue(":position",position);
            queryChange.bindValue(":edu_level",edu_level);
            queryChange.bindValue(":tel",tel);
            queryChange.bindValue(":remark",remark);
            queryChange.exec();
        }
    }
    query.prepare("select count(*) from personnel where id=:id");
    query.bindValue(":id",id);
    if(query.exec())
    {
        query.next();
        num = query.value(0).toInt();
        if(num == 1)
            QMessageBox::warning(NULL,QObject::tr("请重新输入"),QObject::tr("记录号已存在！"));
        else
        {
            query.prepare("insert into personnel values(:id,:pid,:change,:description)");
            query.bindValue(":id",id);
            query.bindValue(":pid",pid);
            query.bindValue(":change",change);
            query.bindValue(":description",description);
            if(query.exec())
            {
                QMessageBox::information(NULL,QObject::tr("成功"),QObject::tr("变更成功"));
            }
        }
    }
}
