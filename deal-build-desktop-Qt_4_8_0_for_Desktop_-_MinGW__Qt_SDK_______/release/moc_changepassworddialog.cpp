/****************************************************************************
** Meta object code from reading C++ file 'changepassworddialog.h'
**
** Created: Mon 25. Feb 13:54:43 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../deal/changepassworddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changepassworddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChangePasswordDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChangePasswordDialog[] = {
    "ChangePasswordDialog\0\0slotSaveButtonClicked()\0"
};

void ChangePasswordDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChangePasswordDialog *_t = static_cast<ChangePasswordDialog *>(_o);
        switch (_id) {
        case 0: _t->slotSaveButtonClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ChangePasswordDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChangePasswordDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChangePasswordDialog,
      qt_meta_data_ChangePasswordDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChangePasswordDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChangePasswordDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChangePasswordDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChangePasswordDialog))
        return static_cast<void*>(const_cast< ChangePasswordDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChangePasswordDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
