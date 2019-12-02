#include "alert.h"

Alert::Alert(QString message)
{
    this->setIcon(QMessageBox::Information);
    this->setWindowTitle("Message");
    this->setText(message);
    this->exec();
}

Alert::~Alert()
{

}
