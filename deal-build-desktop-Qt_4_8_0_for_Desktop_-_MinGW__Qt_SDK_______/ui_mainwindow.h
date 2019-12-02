/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 27. May 16:19:06 2019
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include <mycombobox.h>
#include <mydateedit.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QLabel *user;
    QSpacerItem *horizontalSpacer;
    QPushButton *loginButton;
    QPushButton *changePasswordButton;
    QTabWidget *tabWidget;
    QWidget *applicationTab;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QFrame *line;
    QLabel *label_10;
    QFrame *line_2;
    QLabel *label_11;
    QFrame *line_3;
    QLabel *label_12;
    QFrame *line_4;
    QLabel *label_13;
    QFrame *line_5;
    QGroupBox *dateGroupBox;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLabel *label_2;
    MyDateEdit *sinceDate;
    MyDateEdit *toDate;
    MyComboBox *secCombo;
    MyComboBox *themeCombo;
    MyComboBox *typeCombo;
    MyComboBox *orgCombo;
    QFrame *line_6;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addApplicationButton;
    QPushButton *deleteApplicationButton;
    QPushButton *filterButton;
    QPushButton *resetButton;
    QTableView *applicationTable;
    QLineEdit *dealEdit;
    QWidget *dealTab;
    QGridLayout *gridLayout_10;
    QTableView *dealTable;
    QPushButton *deleteDealButton;
    QPushButton *addDealButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1258, 851);
        QFont font;
        font.setPointSize(18);
        MainWindow->setFont(font);
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QFont font1;
        font1.setPointSize(12);
        centralWidget->setFont(font1);
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        user = new QLabel(centralWidget);
        user->setObjectName(QString::fromUtf8("user"));

        gridLayout_3->addWidget(user, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(966, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        loginButton = new QPushButton(centralWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        gridLayout_3->addWidget(loginButton, 0, 2, 1, 1);

        changePasswordButton = new QPushButton(centralWidget);
        changePasswordButton->setObjectName(QString::fromUtf8("changePasswordButton"));

        gridLayout_3->addWidget(changePasswordButton, 0, 3, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setTabPosition(QTabWidget::West);
        applicationTab = new QWidget();
        applicationTab->setObjectName(QString::fromUtf8("applicationTab"));
        gridLayout_2 = new QGridLayout(applicationTab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_9 = new QLabel(applicationTab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        line = new QFrame(applicationTab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 0, 1, 2, 1);

        label_10 = new QLabel(applicationTab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 0, 2, 1, 1);

        line_2 = new QFrame(applicationTab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 0, 3, 2, 1);

        label_11 = new QLabel(applicationTab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 0, 4, 1, 1);

        line_3 = new QFrame(applicationTab);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 0, 5, 2, 1);

        label_12 = new QLabel(applicationTab);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 0, 6, 1, 1);

        line_4 = new QFrame(applicationTab);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_4, 0, 7, 2, 1);

        label_13 = new QLabel(applicationTab);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 0, 8, 1, 1);

        line_5 = new QFrame(applicationTab);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_5, 0, 9, 2, 1);

        dateGroupBox = new QGroupBox(applicationTab);
        dateGroupBox->setObjectName(QString::fromUtf8("dateGroupBox"));
        dateGroupBox->setCheckable(true);
        dateGroupBox->setChecked(false);
        gridLayout_4 = new QGridLayout(dateGroupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(dateGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(dateGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        sinceDate = new MyDateEdit(dateGroupBox);
        sinceDate->setObjectName(QString::fromUtf8("sinceDate"));

        gridLayout_4->addWidget(sinceDate, 0, 1, 1, 1);

        toDate = new MyDateEdit(dateGroupBox);
        toDate->setObjectName(QString::fromUtf8("toDate"));

        gridLayout_4->addWidget(toDate, 1, 1, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 3);

        gridLayout_2->addWidget(dateGroupBox, 0, 10, 2, 1);

        secCombo = new MyComboBox(applicationTab);
        secCombo->setObjectName(QString::fromUtf8("secCombo"));

        gridLayout_2->addWidget(secCombo, 1, 0, 1, 1);

        themeCombo = new MyComboBox(applicationTab);
        themeCombo->setObjectName(QString::fromUtf8("themeCombo"));

        gridLayout_2->addWidget(themeCombo, 1, 4, 1, 1);

        typeCombo = new MyComboBox(applicationTab);
        typeCombo->setObjectName(QString::fromUtf8("typeCombo"));

        gridLayout_2->addWidget(typeCombo, 1, 6, 1, 1);

        orgCombo = new MyComboBox(applicationTab);
        orgCombo->setObjectName(QString::fromUtf8("orgCombo"));

        gridLayout_2->addWidget(orgCombo, 1, 8, 1, 1);

        line_6 = new QFrame(applicationTab);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_6, 2, 0, 1, 11);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        addApplicationButton = new QPushButton(applicationTab);
        addApplicationButton->setObjectName(QString::fromUtf8("addApplicationButton"));

        gridLayout->addWidget(addApplicationButton, 0, 1, 1, 1);

        deleteApplicationButton = new QPushButton(applicationTab);
        deleteApplicationButton->setObjectName(QString::fromUtf8("deleteApplicationButton"));

        gridLayout->addWidget(deleteApplicationButton, 0, 2, 1, 1);

        filterButton = new QPushButton(applicationTab);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));

        gridLayout->addWidget(filterButton, 0, 4, 1, 1);

        resetButton = new QPushButton(applicationTab);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout->addWidget(resetButton, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 3, 0, 1, 11);

        applicationTable = new QTableView(applicationTab);
        applicationTable->setObjectName(QString::fromUtf8("applicationTable"));

        gridLayout_2->addWidget(applicationTable, 4, 0, 1, 11);

        dealEdit = new QLineEdit(applicationTab);
        dealEdit->setObjectName(QString::fromUtf8("dealEdit"));

        gridLayout_2->addWidget(dealEdit, 1, 2, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(4, 1);
        gridLayout_2->setColumnStretch(6, 1);
        gridLayout_2->setColumnStretch(8, 1);
        gridLayout_2->setColumnStretch(10, 1);
        tabWidget->addTab(applicationTab, QString());
        dealTab = new QWidget();
        dealTab->setObjectName(QString::fromUtf8("dealTab"));
        gridLayout_10 = new QGridLayout(dealTab);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        dealTable = new QTableView(dealTab);
        dealTable->setObjectName(QString::fromUtf8("dealTable"));

        gridLayout_10->addWidget(dealTable, 1, 0, 1, 3);

        deleteDealButton = new QPushButton(dealTab);
        deleteDealButton->setObjectName(QString::fromUtf8("deleteDealButton"));

        gridLayout_10->addWidget(deleteDealButton, 0, 2, 1, 1);

        addDealButton = new QPushButton(dealTab);
        addDealButton->setObjectName(QString::fromUtf8("addDealButton"));

        gridLayout_10->addWidget(addDealButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        tabWidget->addTab(dealTab, QString());

        gridLayout_3->addWidget(tabWidget, 1, 0, 1, 4);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\276\320\262", 0, QApplication::UnicodeUTF8));
        user->setText(QString());
#ifndef QT_NO_TOOLTIP
        loginButton->setToolTip(QApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        loginButton->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        changePasswordButton->setToolTip(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\276\320\272\320\275\320\276 \321\201\320\274\320\265\320\275\321\213 \320\277\320\260\321\200\320\276\320\273\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        changePasswordButton->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\320\241\320\265\320\272\321\202\320\276\321\200:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\263\320\276\320\262\320\276\321\200:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\260:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "\320\236\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        dateGroupBox->setTitle(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\241:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\276:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addApplicationButton->setToolTip(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\320\276\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addApplicationButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deleteApplicationButton->setToolTip(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleteApplicationButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        filterButton->setToolTip(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200 \320\262\321\213\320\261\320\276\321\200\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\270\320\267 \320\221\320\224", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        filterButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        resetButton->setToolTip(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\204\320\270\320\273\321\214\321\202\321\200\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        resetButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(applicationTab), QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deleteDealButton->setToolTip(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\321\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleteDealButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addDealButton->setToolTip(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\276\320\263\320\276\320\262\320\276\321\200", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addDealButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(dealTab), QApplication::translate("MainWindow", "\320\224\320\276\320\263\320\276\320\262\320\276\321\200\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
