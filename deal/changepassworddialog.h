#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H

#include <QDialog>
#include <QTextCodec>
#include <QSqlQuery>

#include "alert.h"

namespace Ui {
class ChangePasswordDialog;
}

class ChangePasswordDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ChangePasswordDialog(QWidget *parent = 0);
    ~ChangePasswordDialog();
    
private:
    Ui::ChangePasswordDialog *ui;
    QSqlDatabase db;

private slots:
    void slotSaveButtonClicked();
};

#endif // CHANGEPASSWORDDIALOG_H
