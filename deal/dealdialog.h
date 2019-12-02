#ifndef DEALDIALOG_H
#define DEALDIALOG_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
#include <QTextCodec>

#include "MyDirFunctions.h"
#include "alert.h"
#include "mycombobox.h"
#include "mydateedit.h"

namespace Ui {
class DealDialog;
}

class DealDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DealDialog(QWidget *parent = 0);
    ~DealDialog();
    
private:
    Ui::DealDialog *ui;
    QSqlDatabase db; //���� ������

private slots:
    void slotSaveButtonClicked(); //���������, ����������� ������ � �������� ��� ������� �� ������ "���������"
};

#endif // DEALDIALOG_H
