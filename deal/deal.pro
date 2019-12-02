#-------------------------------------------------
#
# Project created by QtCreator 2018-04-28T11:16:43
#
#-------------------------------------------------

QT       += core gui sql

win32 {
        RC_FILE += file.rc
        OTHER_FILES += file.rc
}

VERSION = 1.2.5.5
QMAKE_TARGET_COMPANY = Cats Under Cover
QMAKE_TARGET_COPYRIGHT = Cats Under Cover

TARGET = deal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    applicationupdatedialog.cpp \
    dealupdatedialog.cpp \
    MyDirFunctions.cpp \
    alert.cpp \
    mycombobox.cpp \
    applicationdialog.cpp \
    dealdialog.cpp \
    mydateedit.cpp \
    changepassworddialog.cpp \
    mysqlquerymodel.cpp

HEADERS  += mainwindow.h \
    applicationupdatedialog.h \
    dealupdatedialog.h \
    MyDirFunctions.h \
    alert.h \
    mycombobox.h \
    applicationdialog.h \
    dealdialog.h \
    mydateedit.h \
    changepassworddialog.h \
    mysqlquerymodel.h

FORMS    += mainwindow.ui \
    applicationupdatedialog.ui \
    dealupdatedialog.ui \
    applicationdialog.ui \
    dealdialog.ui \
    changepassworddialog.ui
