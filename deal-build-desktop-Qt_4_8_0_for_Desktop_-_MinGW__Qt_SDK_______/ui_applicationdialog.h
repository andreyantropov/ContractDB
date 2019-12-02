/********************************************************************************
** Form generated from reading UI file 'applicationdialog.ui'
**
** Created: Wed 20. Feb 17:08:59 2019
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATIONDIALOG_H
#define UI_APPLICATIONDIALOG_H

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

QT_BEGIN_NAMESPACE

class Ui_ApplicationDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    MyComboBox *secCombo;
    QLabel *label_2;
    MyComboBox *dealCombo;
    QLabel *label_3;
    MyComboBox *typeCombo;
    QLabel *label_4;
    QLineEdit *applicationEdit;
    QLabel *label_5;
    QLineEdit *linkEdit;
    QPushButton *selectFileButton;
    QPushButton *winScanButton;
    QPushButton *saveButton;
    QPushButton *rejectButton;

    void setupUi(QDialog *ApplicationDialog)
    {
        if (ApplicationDialog->objectName().isEmpty())
            ApplicationDialog->setObjectName(QString::fromUtf8("ApplicationDialog"));
        ApplicationDialog->setEnabled(true);
        ApplicationDialog->resize(450, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ApplicationDialog->sizePolicy().hasHeightForWidth());
        ApplicationDialog->setSizePolicy(sizePolicy);
        ApplicationDialog->setMinimumSize(QSize(450, 300));
        ApplicationDialog->setMaximumSize(QSize(450, 300));
        ApplicationDialog->setSizeGripEnabled(false);
        ApplicationDialog->setModal(true);
        gridLayout = new QGridLayout(ApplicationDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ApplicationDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        secCombo = new MyComboBox(ApplicationDialog);
        secCombo->setObjectName(QString::fromUtf8("secCombo"));

        gridLayout->addWidget(secCombo, 0, 1, 1, 6);

        label_2 = new QLabel(ApplicationDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        dealCombo = new MyComboBox(ApplicationDialog);
        dealCombo->setObjectName(QString::fromUtf8("dealCombo"));

        gridLayout->addWidget(dealCombo, 1, 1, 1, 6);

        label_3 = new QLabel(ApplicationDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        typeCombo = new MyComboBox(ApplicationDialog);
        typeCombo->setObjectName(QString::fromUtf8("typeCombo"));

        gridLayout->addWidget(typeCombo, 2, 1, 1, 6);

        label_4 = new QLabel(ApplicationDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        applicationEdit = new QLineEdit(ApplicationDialog);
        applicationEdit->setObjectName(QString::fromUtf8("applicationEdit"));

        gridLayout->addWidget(applicationEdit, 3, 1, 1, 6);

        label_5 = new QLabel(ApplicationDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        linkEdit = new QLineEdit(ApplicationDialog);
        linkEdit->setObjectName(QString::fromUtf8("linkEdit"));
        linkEdit->setEnabled(false);

        gridLayout->addWidget(linkEdit, 4, 1, 1, 4);

        selectFileButton = new QPushButton(ApplicationDialog);
        selectFileButton->setObjectName(QString::fromUtf8("selectFileButton"));

        gridLayout->addWidget(selectFileButton, 4, 5, 1, 1);

        winScanButton = new QPushButton(ApplicationDialog);
        winScanButton->setObjectName(QString::fromUtf8("winScanButton"));

        gridLayout->addWidget(winScanButton, 4, 6, 1, 1);

        saveButton = new QPushButton(ApplicationDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setDefault(true);

        gridLayout->addWidget(saveButton, 5, 0, 1, 4);

        rejectButton = new QPushButton(ApplicationDialog);
        rejectButton->setObjectName(QString::fromUtf8("rejectButton"));

        gridLayout->addWidget(rejectButton, 5, 4, 1, 3);


        retranslateUi(ApplicationDialog);

        QMetaObject::connectSlotsByName(ApplicationDialog);
    } // setupUi

    void retranslateUi(QDialog *ApplicationDialog)
    {
        ApplicationDialog->setWindowTitle(QApplication::translate("ApplicationDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ApplicationDialog", "\320\241\320\265\320\272\321\202\320\276\321\200:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ApplicationDialog", "\320\224\320\276\320\263\320\276\320\262\320\276\321\200:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ApplicationDialog", "\320\242\320\270\320\277 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ApplicationDialog", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ApplicationDialog", "\320\241\321\201\321\213\320\273\320\272\320\260:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        selectFileButton->setToolTip(QApplication::translate("ApplicationDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        selectFileButton->setText(QApplication::translate("ApplicationDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        winScanButton->setToolTip(QApplication::translate("ApplicationDialog", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 WinScan2PDF \320\264\320\273\321\217 \321\201\320\272\320\260\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        winScanButton->setText(QApplication::translate("ApplicationDialog", "WinScan2PDF", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("ApplicationDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QApplication::translate("ApplicationDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        rejectButton->setText(QApplication::translate("ApplicationDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ApplicationDialog: public Ui_ApplicationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATIONDIALOG_H
