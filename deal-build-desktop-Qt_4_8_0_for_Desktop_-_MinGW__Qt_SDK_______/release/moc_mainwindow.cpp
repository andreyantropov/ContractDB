/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon 24. Jun 11:21:35 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../deal/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      32,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      98,   91,   11,   11, 0x08,
     132,  128,   11,   11, 0x08,
     172,  128,   11,   11, 0x08,
     205,   11,   11,   11, 0x08,
     242,   11,   11,   11, 0x08,
     272,   11,   11,   11, 0x08,
     306,   11,   11,   11, 0x08,
     333,   11,   11,   11, 0x08,
     362,   11,   11,   11, 0x08,
     384,   11,   11,   11, 0x08,
     407,  399,   11,   11, 0x08,
     435,  399,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0slotRefreshFilter()\0"
    "slotLoginButtonClicked()\0"
    "slotChangePasswordButtonClicked()\0"
    "isHide\0slotFilterButtonClicked(bool)\0"
    "row\0slotUpdateApplicationButtonClicked(int)\0"
    "slotUpdateDealButtonClicked(int)\0"
    "slotDeleteApplicationButtonClicked()\0"
    "slotDeleteDealButtonClicked()\0"
    "slotAddApplicationButtonClicked()\0"
    "slotAddDealButtonClicked()\0"
    "slotUpdateApplicationTable()\0"
    "slotUpdateDealTable()\0slotFileOpen()\0"
    "newDate\0slotSinceDateChanged(QDate)\0"
    "slotToDateChanged(QDate)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->slotRefreshFilter(); break;
        case 1: _t->slotLoginButtonClicked(); break;
        case 2: _t->slotChangePasswordButtonClicked(); break;
        case 3: _t->slotFilterButtonClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->slotUpdateApplicationButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotUpdateDealButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slotDeleteApplicationButtonClicked(); break;
        case 7: _t->slotDeleteDealButtonClicked(); break;
        case 8: _t->slotAddApplicationButtonClicked(); break;
        case 9: _t->slotAddDealButtonClicked(); break;
        case 10: _t->slotUpdateApplicationTable(); break;
        case 11: _t->slotUpdateDealTable(); break;
        case 12: _t->slotFileOpen(); break;
        case 13: _t->slotSinceDateChanged((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 14: _t->slotToDateChanged((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
