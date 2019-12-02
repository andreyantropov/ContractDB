#ifndef MYDATEEDIT_H
#define MYDATEEDIT_H

#include <QDateEdit>

class MyDateEdit : public QDateEdit
{
    Q_OBJECT

public:
    explicit MyDateEdit(QWidget *parent = 0);
    ~MyDateEdit();

    void setNull();
    QString dateToDB();
};

#endif // MYDATEEDIT_H
