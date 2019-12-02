#ifndef APPLICATIONUPDATEDIALOG_H
#define APPLICATIONUPDATEDIALOG_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
#include <QProcess>
#include <QTextCodec>
#include <QDebug>

#include "MyDirFunctions.h"
#include "alert.h"
#include "mycombobox.h"

namespace Ui {
class ApplicationUpdateDialog;
}

class ApplicationUpdateDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ApplicationUpdateDialog(QString currentSec, QString currentDeal, QString currentType, QString currentApplication, QString currentApplicationLink, QWidget *parent = 0);
    ~ApplicationUpdateDialog();
    
private:
    Ui::ApplicationUpdateDialog *ui;
    QSqlDatabase db; //���� ������
    QString currentLink;

    void saveFile(QString tSec, QString tDeal, QString tType, QString tApplication, QString fileName);//���������, ����������� ���������� � ��
    bool removeFile(QString oldLink, QString newLink, QLineEdit *linkEdit);//���������, ���������� ������ ���������� �� �����

private slots:
    void slotSecComboChanged(QString currentText);//���������, ���������� ���������� �����-�����, ����������� �� �������� ��� ��������� �������� �����-�����, ����������� �� ������
    void slotSelectFileButtonClicked();//���������, ����������� �������
    void slotWinScanButtonClicked(); //���������, ����������� ��������� ��� ������������ ������ �����
    void slotSaveButtonClicked(); //���������, ����������� ��������� ������
};

#endif // APPLICATIONUPDATEDIALOG_H
