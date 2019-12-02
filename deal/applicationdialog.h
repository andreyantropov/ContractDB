#ifndef APPLICATIONDIALOG_H
#define APPLICATIONDIALOG_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
#include <QProcess>
#include <QTextCodec>
#include <QDebug>
#include <QRegExp>

#include "MyDirFunctions.h"
#include "alert.h"
#include "mycombobox.h"

namespace Ui {
class ApplicationDialog;
}

class ApplicationDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ApplicationDialog(QWidget *parent = 0);
    ~ApplicationDialog();
    
private:
    Ui::ApplicationDialog *ui;
    QSqlDatabase db; //���� ������

    void saveFile(QString tDeal, QString tType, QString tApplication, QString tLink, QString fileName);//���������, ����������� ���������� � ��

private slots:
    void slotSecComboChanged(QString currentText); //���������, ���������� ���������� ComboBox'� appDealSelect ��� ��������� ComboBox'� dealSelect
    void slotSaveButtonClicked(); //���������, ����������� ������ � ���������� � ��������
    void slotSelectFileButtonClicked(); //���������, ����������� ���� QFileDialog ��� ������ ���������� � ��������
    void slotWinScanButtonClicked(); //���������, ����������� ��������� ��� ������������ ������ �����
};

#endif // APPLICATIONDIALOG_H
