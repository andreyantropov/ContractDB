#include "mydateedit.h"

MyDateEdit::MyDateEdit(QWidget *parent) :
    QDateEdit(parent)
{
    this->setDate(QDate::currentDate());
}

QString MyDateEdit::dateToDB()
{
    QDate d;
    d.setDate(this->date().year(),
              this->date().month(),
              this->date().day());
    return d.toString("yyyy-MM-dd");
}

void MyDateEdit::setNull()
{
    this->setDate(QDate::currentDate());
}

MyDateEdit::~MyDateEdit()
{

}
