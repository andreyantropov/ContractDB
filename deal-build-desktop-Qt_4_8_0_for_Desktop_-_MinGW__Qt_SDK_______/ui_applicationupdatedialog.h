/********************************************************************************
** Form generated from reading UI file 'applicationupdatedialog.ui'
**
** Created: Wed 20. Feb 17:08:59 2019
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATIONUPDATEDIALOG_H
#define UI_APPLICATIONUPDATEDIALOG_H

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

class Ui_ApplicationUpdateDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *linkEdit;
    QPushButton *winScanButton;
    QPushButton *saveButton;
    QPushButton *rejectButton;
    QPushButton *selectFileButton;
    QLineEdit *applicationEdit;
    MyComboBox *secCombo;
    MyComboBox *dealCombo;
    MyComboBox *typeCombo;

    void setupUi(QDialog *ApplicationUpdateDialog)
    {
        if (ApplicationUpdateDialog->objectName().isEmpty())
            ApplicationUpdateDialog->setObjectName(QString::fromUtf8("ApplicationUpdateDialog"));
        ApplicationUpdateDialog->resize(450, 300);
        ApplicationUpdateDialog->setMinimumSize(QSize(450, 300));
        ApplicationUpdateDialog->setMaximumSize(QSize(450, 300));
        ApplicationUpdateDialog->setModal(true);
        gridLayout = new QGridLayout(ApplicationUpdateDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ApplicationUpdateDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(ApplicationUpdateDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(ApplicationUpdateDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(ApplicationUpdateDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(ApplicationUpdateDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        linkEdit = new QLineEdit(ApplicationUpdateDialog);
        linkEdit->setObjectName(QString::fromUtf8("linkEdit"));
        linkEdit->setEnabled(false);

        gridLayout->addWidget(linkEdit, 4, 1, 1, 3);

        winScanButton = new QPushButton(ApplicationUpdateDialog);
        winScanButton->setObjectName(QString::fromUtf8("winScanButton"));

        gridLayout->addWidget(winScanButton, 4, 5, 1, 1);

        saveButton = new QPushButton(ApplicationUpdateDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setDefault(true);

        gridLayout->addWidget(saveButton, 5, 0, 1, 3);

        rejectButton = new QPushButton(ApplicationUpdateDialog);
        rejectButton->setObjectName(QString::fromUtf8("rejectButton"));

        gridLayout->addWidget(rejectButton, 5, 3, 1, 3);

        selectFileButton = new QPushButton(ApplicationUpdateDialog);
        selectFileButton->setObjectName(QString::fromUtf8("selectFileButton"));

        gridLayout->addWidget(selectFileButton, 4, 4, 1, 1);

        applicationEdit = new QLineEdit(ApplicationUpdateDialog);
        applicationEdit->setObjectName(QString::fromUtf8("applicationEdit"));

        gridLayout->addWidget(applicationEdit, 3, 1, 1, 5);

        secCombo = new MyComboBox(ApplicationUpdateDialog);
        secCombo->setObjectName(QString::fromUtf8("secCombo"));
        secCombo->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(secCombo, 0, 1, 1, 5);

        dealCombo = new MyComboBox(ApplicationUpdateDialog);
        dealCombo->setObjectName(QString::fromUtf8("dealCombo"));

        gridLayout->addWidget(dealCombo, 1, 1, 1, 5);

        typeCombo = new MyComboBox(ApplicationUpdateDialog);
        typeCombo->setObjectName(QString::fromUtf8("typeCombo"));

        gridLayout->addWidget(typeCombo, 2, 1, 1, 5);

        QWidget::setTabOrder(applicationEdit, linkEdit);
        QWidget::setTabOrder(linkEdit, selectFileButton);
        QWidget::setTabOrder(selectFileButton, winScanButton);
        QWidget::setTabOrder(winScanButton, saveButton);
        QWidget::setTabOrder(saveButton, rejectButton);

        retranslateUi(ApplicationUpdateDialog);

        QMetaObject::connectSlotsByName(ApplicationUpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *ApplicationUpdateDialog)
    {
        ApplicationUpdateDialog->setWindowTitle(QApplication::translate("ApplicationUpdateDialog", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ApplicationUpdateDialog", "\320\241\320\265\320\272\321\202\320\276\321\200:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ApplicationUpdateDialog", "\320\224\320\276\320\263\320\276\320\262\320\276\321\200:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ApplicationUpdateDialog", "\320\242\320\270\320\277 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ApplicationUpdateDialog", "\320\237\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ApplicationUpdateDialog", "\320\241\321\201\321\213\320\273\320\272\320\260:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        winScanButton->setToolTip(QApplication::translate("ApplicationUpdateDialog", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 WinScan2PDF \320\264\320\273\321\217 \321\201\320\272\320\260\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        winScanButton->setText(QApplication::translate("ApplicationUpdateDialog", "WinScan2PDF", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("ApplicationUpdateDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QApplication::translate("ApplicationUpdateDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        rejectButton->setText(QApplication::translate("ApplicationUpdateDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        selectFileButton->setToolTip(QApplication::translate("ApplicationUpdateDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        selectFileButton->setText(QApplication::translate("ApplicationUpdateDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ApplicationUpdateDialog: public Ui_ApplicationUpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATIONUPDATEDIALOG_H
