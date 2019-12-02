#ifndef DEALUPDATEDIALOG_H
#define DEALUPDATEDIALOG_H

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
class DealUpdateDialog;
}

class DealUpdateDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DealUpdateDialog(QString currentSec, QString currentDeal, QString currentOrg, QString currentTheme, QString currentItem, QString currentDate, QString currentDealLink, QWidget *parent = 0);
    ~DealUpdateDialog();
    
private:
    Ui::DealUpdateDialog *ui;
    QSqlDatabase db; //База данных
    QString currentLink;

private slots:
    void slotSaveButtonClicked(); //Процедура, сохраняющая изменение данных
};

#endif // DEALUPDATEDIALOG_H
