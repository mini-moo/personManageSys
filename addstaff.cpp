#include "addstaff.h"
#include "ui_addstaff.h"
#include <QtSql>
#include <QComboBox>
#include <QDebug>
#include <QMessageBox>

addStaff::addStaff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStaff)
{
    ui->setupUi(this);
}

addStaff::~addStaff()
{
    delete ui;
}

void addStaff::on_pushButton_2_clicked()
{
    this -> close();
}

void addStaff::on_pushButton_clicked()
{
    int limit;
    int pid = ui->lineEdit->text().toInt();
    QString passwd = ui->lineEdit_2->text();
    QString permission = ui->comboBox->itemText(ui->comboBox->currentIndex());
    if(permission == "管理员")
        limit = 1;
    else
        limit = 0;
    QString name = ui->lineEdit_3->text();
    QString sex = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());
    QString department = ui->comboBox_3->itemText(ui->comboBox_3->currentIndex());
    QString position = ui->comboBox_5->itemText(ui->comboBox_5->currentIndex());
    QString edu_level = ui->comboBox_4->itemText(ui->comboBox_4->currentIndex());
    QString tel = ui->lineEdit_4->text();
    QString remark = ui->plainTextEdit->toPlainText();
    QSqlQuery query;
    query.prepare("insert into personMsg values(:pid,:passwd,:permission,:name,:sex,:department,:position,:edu_level,:tel,:remark)");
    query.bindValue(":pid",pid);
    query.bindValue(":passwd",passwd);
    query.bindValue(":permission",limit);
    query.bindValue(":name",name);
    query.bindValue(":sex",sex);
    query.bindValue(":department",department);
    query.bindValue(":position",position);
    query.bindValue(":edu_level",edu_level);
    query.bindValue(":tel",tel);
    query.bindValue(":remark",remark);
    if(query.exec())
        QMessageBox::information(NULL, QObject::tr("成功"), QObject::tr("新建成功"));
    else
        QMessageBox::information(NULL, QObject::tr("失败"), QObject::tr("新建失败"));
}
