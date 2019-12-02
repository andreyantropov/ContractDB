/********************************************************************************
** Form generated from reading UI file 'dealupdatedialog.ui'
**
** Created: Mon 27. May 16:18:24 2019
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEALUPDATEDIALOG_H
#define UI_DEALUPDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <mycombobox.h>
#include <mydateedit.h>

QT_BEGIN_NAMESPACE

class Ui_DealUpdateDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *dealEdit;
    QLabel *label_3;
    QLineEdit *themeEdit;
    QLabel *label_4;
    QLineEdit *itemEdit;
    QPushButton *saveButton;
    QPushButton *rejectButton;
    MyComboBox *secCombo;
    QLabel *label_5;
    MyComboBox *orgCombo;
    QLabel *label_6;
    MyDateEdit *dateEdit;

    void setupUi(QDialog *DealUpdateDialog)
    {
        if (DealUpdateDialog->objectName().isEmpty())
            DealUpdateDialog->setObjectName(QString::fromUtf8("DealUpdateDialog"));
        DealUpdateDialog->resize(450, 300);
        DealUpdateDialog->setMinimumSize(QSize(450, 300));
        DealUpdateDialog->setMaximumSize(QSize(450, 300));
        QFont font;
        font.setPointSize(10);
        DealUpdateDialog->setFont(font);
        DealUpdateDialog->setModal(true);
        gridLayout = new QGridLayout(DealUpdateDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DealUpdateDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(DealUpdateDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        dealEdit = new QLineEdit(DealUpdateDialog);
        dealEdit->setObjectName(QString::fromUtf8("dealEdit"));

        gridLayout->addWidget(dealEdit, 2, 1, 1, 3);

        label_3 = new QLabel(DealUpdateDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        themeEdit = new QLineEdit(DealUpdateDialog);
        themeEdit->setObjectName(QString::fromUtf8("themeEdit"));

        gridLayout->addWidget(themeEdit, 4, 1, 1, 3);

        label_4 = new QLabel(DealUpdateDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        itemEdit = new QLineEdit(DealUpdateDialog);
        itemEdit->setObjectName(QString::fromUtf8("itemEdit"));

        gridLayout->addWidget(itemEdit, 5, 1, 1, 3);

        saveButton = new QPushButton(DealUpdateDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setDefault(true);

        gridLayout->addWidget(saveButton, 7, 0, 1, 2);

        rejectButton = new QPushButton(DealUpdateDialog);
        rejectButton->setObjectName(QString::fromUtf8("rejectButton"));

        gridLayout->addWidget(rejectButton, 7, 2, 1, 2);

        secCombo = new MyComboBox(DealUpdateDialog);
        secCombo->setObjectName(QString::fromUtf8("secCombo"));

        gridLayout->addWidget(secCombo, 0, 1, 1, 3);

        label_5 = new QLabel(DealUpdateDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        orgCombo = new MyComboBox(DealUpdateDialog);
        orgCombo->setObjectName(QString::fromUtf8("orgCombo"));

        gridLayout->addWidget(orgCombo, 1, 1, 1, 3);

        label_6 = new QLabel(DealUpdateDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        dateEdit = new MyDateEdit(DealUpdateDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        gridLayout->addWidget(dateEdit, 3, 1, 1, 3);


        retranslateUi(DealUpdateDialog);

        QMetaObject::connectSlotsByName(DealUpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *DealUpdateDialog)
    {
        DealUpdateDialog->setWindowTitle(QApplication::translate("DealUpdateDialog", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DealUpdateDialog", "\320\241\320\265\320\272\321\202\320\276\321\200:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DealUpdateDialog", "\320\224\320\276\320\263\320\276\320\262\320\276\321\200:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DealUpdateDialog", "\320\242\320\265\320\274\320\260:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DealUpdateDialog", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("DealUpdateDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QApplication::translate("DealUpdateDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        rejectButton->setText(QApplication::translate("DealUpdateDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DealUpdateDialog", "\320\236\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DealUpdateDialog", "\320\224\320\260\321\202\320\260 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DealUpdateDialog: public Ui_DealUpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEALUPDATEDIALOG_H
