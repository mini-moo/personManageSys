#include "staffmsgopr.h"
#include "ui_staffmsgopr.h"
#include <QSqlQuery>
#include <QComboBox>
#include <QMessageBox>

StaffMsgOpr::StaffMsgOpr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffMsgOpr)
{
    ui->setupUi(this);
}

StaffMsgOpr::~StaffMsgOpr()
{
    delete ui;
}

//�˳�
void StaffMsgOpr::on_pushButton_4_clicked()
{
    this->close();
}

//��ѯ
void StaffMsgOpr::on_pushButton_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QSqlQuery query;
    QString pid = "";
    QString passwd = "";
    int permission;
    QString name = "";
    QString sex = "";
    QString department = "";
    QString position = "";
    QString edu_level = "";
    QString tel = "";
    QString remark = "";
    QString limit = "";
    query.prepare("select * from personMsg where pid=:id");
    query.bindValue(":id",id);
    if(query.exec())
    {
        query.next();
        pid = query.value(0).toString();
        passwd = query.value(1).toString();
        permission = query.value(2).toInt();
        if(permission == 1)//permissionΪint����ת��ΪQString����
            limit = "����Ա";
        else
            limit = "Ա��";
        name = query.value(3).toString();
        sex = query.value(4).toString();
        department = query.value(5).toString();
        position = query.value(6).toString();
        edu_level = query.value(7).toString();
        tel = query.value(8).toString();
        remark= query.value(9).toString();

        ui->lineEdit_2->setText(pid);
        ui->lineEdit_3->setText(passwd);
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(limit));
        ui->lineEdit_4->setText(name);
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(sex));
        ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(department));
        ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText(position));
        ui->comboBox_5->setCurrentIndex(ui->comboBox_5->findText(edu_level));
        ui->lineEdit_5->setText(tel);
        ui->plainTextEdit->setPlainText(remark);
    }
}

//�޸�
void StaffMsgOpr::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QString pid = "";
    QString passwd = "";
    QString permission = "";
    QString name = "";
    QString sex = "";
    QString department = "";
    QString position = "";
    QString edu_level = "";
    QString tel = "";
    QString remark = "";
    int limit;
    pid = ui->lineEdit->text();
    if(pid != NULL)
    {
        QMessageBox::StandardButton rb=QMessageBox::warning(NULL,QObject::tr("����"),QObject::tr("�޸Ľ����ڸ�����Ϣ��ȷ���޸ģ�"),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
        if(rb == QMessageBox::Yes)
        {
            //ɾ���޸�ǰ������
            query.prepare("delete from personMsg where pid=:pid");
            query.bindValue(":pid",pid);
            query.exec();

            //ui->lineEdit_2->setText(pid);
            passwd=ui->lineEdit_3->text();
            permission=ui->comboBox->itemText(ui->comboBox->currentIndex());
            if(permission == "1")
                limit = 1;
            else
                limit = 0;
            name=ui->lineEdit_4->text();
            sex=ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());
            department=ui->comboBox_3->itemText(ui->comboBox_3->currentIndex());
            position=ui->comboBox_4->itemText(ui->comboBox_4->currentIndex());
            edu_level=ui->comboBox_5->itemText(ui->comboBox_5->currentIndex());
            tel=ui->lineEdit_5->text();
            remark=ui->plainTextEdit->toPlainText();

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
                QMessageBox::warning(NULL,QObject::tr("�ɹ�"),QObject::tr("�޸ĳɹ�"));
            else
                 QMessageBox::warning(NULL,QObject::tr("����������"),QObject::tr("Ա�����ظ�������Ƿ��ַ���ǿ�Ԫ��Ϊ��"));
        }
    }
}

//ɾ��
void StaffMsgOpr::on_pushButton_3_clicked()
{
    QSqlQuery query;
    QString pid = ui->lineEdit->text();
    if(pid!=NULL)
    {
        QMessageBox::StandardButton rb=QMessageBox::warning(NULL,QObject::tr("����"),QObject::tr("ɾ�������ڸ�����Ϣ��ȷ��ɾ����"),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
        if(rb == QMessageBox::Yes)
        {
            query.prepare("delete from personMsg where pid=:pid");
            query.bindValue(":pid",pid);
            if(query.exec())
                QMessageBox::warning(NULL,QObject::tr("�ɹ�"),QObject::tr("ɾ���ɹ�"));
        }
    }
}
