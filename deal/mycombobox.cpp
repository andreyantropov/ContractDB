#include "mycombobox.h"

MyComboBox::MyComboBox(QWidget *parent) :
    QComboBox(parent)
{
}

/*Процедура, принимающая на вход строку qr, содержащую запрос
и ссылку на элемент QCombobox.
Извлекает данные из базы в соответствии с запросом и заполняет ими
элемент QComboBox с помощью процедуры fillComboElems*/
void MyComboBox::fillComboBox(QString qr, QSqlDatabase db)
{
    if(db.open())
    {
        QSqlQuery query;
        query.exec(qr);
        this->clear();
        this->addItem("-");
        while(query.next())
            fillComboElems(query);
        db.close();
    }
}

/*Функция, принимающая на вход строку и ссылку на элемент QComboBox
Возвращает число в формате int - индекс элемента QComboBox, текст
которого совпадает со строкой*/
int MyComboBox::getIndex(QString str)
{
    for(int i = 0; i < this->count(); i++)
        if(str == this->itemText(i))
            return i;
    return 0;
}

/*Процедура,принимающая на вход ссылку на элемент QComboBox и запрос query.
Сравнивает ответ запроса со всем элементами QComboBox. Если этот элемент
уже встречался, то переходит к следующему. Иначе - добавляет его в QComboBox*/
void MyComboBox::fillComboElems(QSqlQuery query)
{
    bool flag = true;
    for(int i = 0; i < this->count(); i++)
        if(query.value(0).toString() == this->itemText(i))
            flag = false;
    if(flag)
        this->addItem(query.value(0).toString());
}

MyComboBox::~MyComboBox()
{

}
