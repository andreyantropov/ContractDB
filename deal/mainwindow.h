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
    Ui::MainWindow *ui; //Графическое окно приложения
    QSqlDatabase db; //База данных
    MySqlQueryModel *applicationModel, *dealModel;
    QStringList applicationHeaderList, dealHeaderList;
    QString currentLink; //Строка, хранящая текущую ссылку на редактируемый файл
    QString currentDealLink; //Строка, хранящая ссылку на текущий договор

    void login(bool isPassword); //Процедура для разблокировки вкладок, если введен верный пароль
    void fillHeaders(QSqlQueryModel *model, QStringList headerList);
    void insertCheckBox(QTableView *table);
    void insertUpdateButtons(QTableView *table, bool type);
    void fillTable(QTableView *table, MySqlQueryModel *model, QString query, QStringList headers, bool type);
    void setColumnsWidth(QTableView *table, bool type); //Процедура, задающая ширину столбцов таблицы table
    QString getString(QTableView *table, QModelIndex index); //Функция, возвращающая строку, хранящуюся в элементе item
    QStringList getCompleterList(QString qr); //Функция, возвращающая данные для комплитера номеров договоров

private slots:
    void slotRefreshFilter();
    void slotLoginButtonClicked(); //Процедура, открывающая окно QInputDialog для ввода пароля
    void slotChangePasswordButtonClicked(); //Процедура, изменяющая пароль БД
    void slotFilterButtonClicked(bool isHide);
    void slotUpdateApplicationButtonClicked(int row); //Процедура, передающая данные из таблицы во вкладку "Редактирование" при нажатии на кнопку "Correct"
    void slotUpdateDealButtonClicked(int row);
    void slotDeleteApplicationButtonClicked(); //Процедура, удаляющая данные о выбранной строки из БД
    void slotDeleteDealButtonClicked();
    void slotAddApplicationButtonClicked(); //Процедура, добавляющая новые договора/приложения в базу
    void slotAddDealButtonClicked();
    void slotUpdateApplicationTable(); //Процедура, выводящая в таблицу результат запроса
    void slotUpdateDealTable();
    void slotFileOpen(); //Процедура, открывающая файл при нажатии на ссылку
    void slotSinceDateChanged(QDate newDate); //Процедура, отслеживающая изменение состояния QDateEdit
    void slotToDateChanged(QDate newDate);

};

#endif // MAINWINDOW_H
