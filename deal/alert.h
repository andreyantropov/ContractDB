#ifndef ALERT_H
#define ALERT_H

#include <QMessageBox>

class Alert : public QMessageBox
{
public:
    explicit Alert(QString message);
    ~Alert();
};

#endif // ALERT_H
