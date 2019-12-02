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
    QSqlDatabase db; //База данных
    QString currentLink;

    void saveFile(QString tSec, QString tDeal, QString tType, QString tApplication, QString fileName);//Процедура, сохраняющая приложение в БД
    bool removeFile(QString oldLink, QString newLink, QLineEdit *linkEdit);//Процедура, заменяющая старое приложение на новое

private slots:
    void slotSecComboChanged(QString currentText);//Процедура, заменяющая содержимое комбо-бокса, отвечающего за договора при изменении значения комбо-бокса, отвечающего за сектор
    void slotSelectFileButtonClicked();//Процедура, открывающая браузер
    void slotWinScanButtonClicked(); //Процедура, открывающая программу для сканирования нового файла
    void slotSaveButtonClicked(); //Процедура, сохраняющая изменение данных
};

#endif // APPLICATIONUPDATEDIALOG_H
