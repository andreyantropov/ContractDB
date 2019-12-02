#include "mycombobox.h"

MyComboBox::MyComboBox(QWidget *parent) :
    QComboBox(parent)
{
}

/*���������, ����������� �� ���� ������ qr, ���������� ������
� ������ �� ������� QCombobox.
��������� ������ �� ���� � ������������ � �������� � ��������� ���
������� QComboBox � ������� ��������� fillComboElems*/
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

/*�������, ����������� �� ���� ������ � ������ �� ������� QComboBox
���������� ����� � ������� int - ������ �������� QComboBox, �����
�������� ��������� �� �������*/
int MyComboBox::getIndex(QString str)
{
    for(int i = 0; i < this->count(); i++)
        if(str == this->itemText(i))
            return i;
    return 0;
}

/*���������,����������� �� ���� ������ �� ������� QComboBox � ������ query.
���������� ����� ������� �� ���� ���������� QComboBox. ���� ���� �������
��� ����������, �� ��������� � ����������. ����� - ��������� ��� � QComboBox*/
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
