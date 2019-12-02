/********************************************************************************
** Form generated from reading UI file 'changepassworddialog.ui'
**
** Created: Wed 20. Feb 17:08:59 2019
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORDDIALOG_H
#define UI_CHANGEPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChangePasswordDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *currentPasswordEdit;
    QLabel *label_2;
    QLineEdit *newPasswordEdit;
    QLabel *label_3;
    QLineEdit *confirmPasswordEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *saveButton;
    QPushButton *rejectButton;

    void setupUi(QDialog *ChangePasswordDialog)
    {
        if (ChangePasswordDialog->objectName().isEmpty())
            ChangePasswordDialog->setObjectName(QString::fromUtf8("ChangePasswordDialog"));
        ChangePasswordDialog->resize(300, 125);
        ChangePasswordDialog->setMinimumSize(QSize(300, 125));
        ChangePasswordDialog->setMaximumSize(QSize(300, 125));
        ChangePasswordDialog->setModal(true);
        gridLayout = new QGridLayout(ChangePasswordDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ChangePasswordDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        currentPasswordEdit = new QLineEdit(ChangePasswordDialog);
        currentPasswordEdit->setObjectName(QString::fromUtf8("currentPasswordEdit"));

        gridLayout->addWidget(currentPasswordEdit, 0, 1, 1, 1);

        label_2 = new QLabel(ChangePasswordDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        newPasswordEdit = new QLineEdit(ChangePasswordDialog);
        newPasswordEdit->setObjectName(QString::fromUtf8("newPasswordEdit"));

        gridLayout->addWidget(newPasswordEdit, 1, 1, 1, 1);

        label_3 = new QLabel(ChangePasswordDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        confirmPasswordEdit = new QLineEdit(ChangePasswordDialog);
        confirmPasswordEdit->setObjectName(QString::fromUtf8("confirmPasswordEdit"));

        gridLayout->addWidget(confirmPasswordEdit, 2, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        saveButton = new QPushButton(ChangePasswordDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setDefault(true);

        horizontalLayout_4->addWidget(saveButton);

        rejectButton = new QPushButton(ChangePasswordDialog);
        rejectButton->setObjectName(QString::fromUtf8("rejectButton"));

        horizontalLayout_4->addWidget(rejectButton);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 2);


        retranslateUi(ChangePasswordDialog);

        QMetaObject::connectSlotsByName(ChangePasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangePasswordDialog)
    {
        ChangePasswordDialog->setWindowTitle(QApplication::translate("ChangePasswordDialog", "\320\241\320\274\320\265\320\275\320\260 \320\277\320\260\321\200\320\276\320\273\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChangePasswordDialog", "\320\241\321\202\320\260\321\200\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChangePasswordDialog", "\320\235\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ChangePasswordDialog", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("ChangePasswordDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        rejectButton->setText(QApplication::translate("ChangePasswordDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChangePasswordDialog: public Ui_ChangePasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORDDIALOG_H
