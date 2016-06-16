#ifndef ADMINOPREATWINDOW_H
#define ADMINOPREATWINDOW_H

#include <QDialog>

namespace Ui {
    class AdminOpreatWindow;
}

class AdminOpreatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminOpreatWindow(QWidget *parent = 0);
    ~AdminOpreatWindow();

private:
    Ui::AdminOpreatWindow *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
};

#endif // ADMINOPREATWINDOW_H
