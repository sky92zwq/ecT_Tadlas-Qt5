/****************************************************************************
** Meta object code from reading C++ file 'tdlasdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tdlasdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tdlasdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tdlasDialog_t {
    QByteArrayData data[19];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tdlasDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tdlasDialog_t qt_meta_stringdata_tdlasDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "tdlasDialog"
QT_MOC_LITERAL(1, 12, 8), // "mystatus"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "QString&"
QT_MOC_LITERAL(4, 31, 3), // "str"
QT_MOC_LITERAL(5, 35, 9), // "acceptusb"
QT_MOC_LITERAL(6, 45, 14), // "CS_ftfunction*"
QT_MOC_LITERAL(7, 60, 1), // "u"
QT_MOC_LITERAL(8, 62, 26), // "on_lazer1openclose_clicked"
QT_MOC_LITERAL(9, 89, 12), // "setlazeropen"
QT_MOC_LITERAL(10, 102, 5), // "lazer"
QT_MOC_LITERAL(11, 108, 13), // "setlazerclose"
QT_MOC_LITERAL(12, 122, 22), // "on_setlazer1tc_clicked"
QT_MOC_LITERAL(13, 145, 14), // "on_das_clicked"
QT_MOC_LITERAL(14, 160, 7), // "checked"
QT_MOC_LITERAL(15, 168, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(16, 189, 16), // "QAbstractButton*"
QT_MOC_LITERAL(17, 206, 6), // "button"
QT_MOC_LITERAL(18, 213, 14) // "on_wms_clicked"

    },
    "tdlasDialog\0mystatus\0\0QString&\0str\0"
    "acceptusb\0CS_ftfunction*\0u\0"
    "on_lazer1openclose_clicked\0setlazeropen\0"
    "lazer\0setlazerclose\0on_setlazer1tc_clicked\0"
    "on_das_clicked\0checked\0on_buttonBox_clicked\0"
    "QAbstractButton*\0button\0on_wms_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tdlasDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   62,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    1,   73,    2, 0x08 /* Private */,
      15,    1,   76,    2, 0x08 /* Private */,
      18,    1,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::UShort,   10,
    QMetaType::Bool, QMetaType::UShort,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::Bool,   14,

       0        // eod
};

void tdlasDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tdlasDialog *_t = static_cast<tdlasDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mystatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->acceptusb((*reinterpret_cast< CS_ftfunction*(*)>(_a[1]))); break;
        case 2: _t->on_lazer1openclose_clicked(); break;
        case 3: { bool _r = _t->setlazeropen((*reinterpret_cast< quint16(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->setlazerclose((*reinterpret_cast< quint16(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->on_setlazer1tc_clicked(); break;
        case 6: _t->on_das_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 8: _t->on_wms_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (tdlasDialog::*_t)(QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tdlasDialog::mystatus)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject tdlasDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_tdlasDialog.data,
      qt_meta_data_tdlasDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *tdlasDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tdlasDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_tdlasDialog.stringdata0))
        return static_cast<void*>(const_cast< tdlasDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int tdlasDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void tdlasDialog::mystatus(QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
