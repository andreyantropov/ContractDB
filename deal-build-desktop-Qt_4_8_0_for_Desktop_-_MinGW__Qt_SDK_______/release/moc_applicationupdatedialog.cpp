/****************************************************************************
** Meta object code from reading C++ file 'applicationupdatedialog.h'
**
** Created: Tue 26. Feb 08:50:35 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../deal/applicationupdatedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'applicationupdatedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ApplicationUpdateDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      37,   25,   24,   24, 0x08,
      66,   24,   24,   24, 0x08,
      96,   24,   24,   24, 0x08,
     123,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ApplicationUpdateDialog[] = {
    "ApplicationUpdateDialog\0\0currentText\0"
    "slotSecComboChanged(QString)\0"
    "slotSelectFileButtonClicked()\0"
    "slotWinScanButtonClicked()\0"
    "slotSaveButtonClicked()\0"
};

void ApplicationUpdateDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApplicationUpdateDialog *_t = static_cast<ApplicationUpdateDialog *>(_o);
        switch (_id) {
        case 0: _t->slotSecComboChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotSelectFileButtonClicked(); break;
        case 2: _t->slotWinScanButtonClicked(); break;
        case 3: _t->slotSaveButtonClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ApplicationUpdateDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ApplicationUpdateDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ApplicationUpdateDialog,
      qt_meta_data_ApplicationUpdateDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ApplicationUpdateDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ApplicationUpdateDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ApplicationUpdateDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApplicationUpdateDialog))
        return static_cast<void*>(const_cast< ApplicationUpdateDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ApplicationUpdateDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
