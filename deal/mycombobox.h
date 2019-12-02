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

    void fillComboBox(QString qr, QSqlDatabase db); //���������, ����������� QComboBox ������� �� ������� qr
    int getIndex(QString str); //�������, ������������ ������ �������� QComboBox, ����� �������� ��������� � str

private:
    void fillComboElems(QSqlQuery query); //���������, ����������� �������� � QComboBox �� ������� query, �������� ������� ������
    
};

#endif // MYCOMBOBOX_H
