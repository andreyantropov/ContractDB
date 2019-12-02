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
    QSqlDatabase db; //База данных

    void saveFile(QString tDeal, QString tType, QString tApplication, QString tLink, QString fileName);//Процедура, сохраняющая приложение в БД

private slots:
    void slotSecComboChanged(QString currentText); //Процедура, заменяющая содержимое ComboBox'а appDealSelect при изменении ComboBox'а dealSelect
    void slotSaveButtonClicked(); //Процедура, сохраняющая данные о приложении к договору
    void slotSelectFileButtonClicked(); //Процедура, открывающая окно QFileDialog для выбора приложения к договору
    void slotWinScanButtonClicked(); //Процедура, открывающая программу для сканирования нового файла
};

#endif // APPLICATIONDIALOG_H
