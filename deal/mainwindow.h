#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
#include <QProcess>
#include <QTextCodec>
#include <QDebug>
#include <QCleanlooksStyle>
#include <QTableView>
#include <QComboBox>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QCloseEvent>
#include <QRegExp>
#include <QCheckBox>
#include <QSignalMapper>
#include <QCompleter>

#include "mysqlquerymodel.h"
#include "mycombobox.h"
#include "MyDirFunctions.h"
#include "alert.h"
#include "dealupdatedialog.h"
#include "applicationupdatedialog.h"
#include "applicationdialog.h"
#include "dealdialog.h"
#include "changepassworddialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui; //����������� ���� ����������
    QSqlDatabase db; //���� ������
    MySqlQueryModel *applicationModel, *dealModel;
    QStringList applicationHeaderList, dealHeaderList;
    QString currentLink; //������, �������� ������� ������ �� ������������� ����
    QString currentDealLink; //������, �������� ������ �� ������� �������

    void login(bool isPassword); //��������� ��� ������������� �������, ���� ������ ������ ������
    void fillHeaders(QSqlQueryModel *model, QStringList headerList);
    void insertCheckBox(QTableView *table);
    void insertUpdateButtons(QTableView *table, bool type);
    void fillTable(QTableView *table, MySqlQueryModel *model, QString query, QStringList headers, bool type);
    void setColumnsWidth(QTableView *table, bool type); //���������, �������� ������ �������� ������� table
    QString getString(QTableView *table, QModelIndex index); //�������, ������������ ������, ���������� � �������� item
    QStringList getCompleterList(QString qr); //�������, ������������ ������ ��� ���������� ������� ���������

private slots:
    void slotRefreshFilter();
    void slotLoginButtonClicked(); //���������, ����������� ���� QInputDialog ��� ����� ������
    void slotChangePasswordButtonClicked(); //���������, ���������� ������ ��
    void slotFilterButtonClicked(bool isHide);
    void slotUpdateApplicationButtonClicked(int row); //���������, ���������� ������ �� ������� �� ������� "��������������" ��� ������� �� ������ "Correct"
    void slotUpdateDealButtonClicked(int row);
    void slotDeleteApplicationButtonClicked(); //���������, ��������� ������ � ��������� ������ �� ��
    void slotDeleteDealButtonClicked();
    void slotAddApplicationButtonClicked(); //���������, ����������� ����� ��������/���������� � ����
    void slotAddDealButtonClicked();
    void slotUpdateApplicationTable(); //���������, ��������� � ������� ��������� �������
    void slotUpdateDealTable();
    void slotFileOpen(); //���������, ����������� ���� ��� ������� �� ������
    void slotSinceDateChanged(QDate newDate); //���������, ������������� ��������� ��������� QDateEdit
    void slotToDateChanged(QDate newDate);

};

#endif // MAINWINDOW_H
