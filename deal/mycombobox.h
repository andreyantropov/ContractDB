#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

class MyComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit MyComboBox(QWidget *parent = 0);
    ~MyComboBox();

    void fillComboBox(QString qr, QSqlDatabase db); //Процедура, заполняющая QComboBox данными из запроса qr
    int getIndex(QString str); //Функция, возвращающая индекс элемента QComboBox, текст которого совпадает с str

private:
    void fillComboElems(QSqlQuery query); //Процедура, добавляющая элементы в QComboBox из запроса query, сохраняя текущий индекс
    
};

#endif // MYCOMBOBOX_H
