/****************************************************************************
** Meta object code from reading C++ file 'mypaintusb.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mypaintusb.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mypaintusb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_myPaintusb_t {
    QByteArrayData data[10];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myPaintusb_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myPaintusb_t qt_meta_stringdata_myPaintusb = {
    {
QT_MOC_LITERAL(0, 0, 10), // "myPaintusb"
QT_MOC_LITERAL(1, 11, 12), // "updatepoints"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "argfordraw*"
QT_MOC_LITERAL(4, 37, 3), // "arg"
QT_MOC_LITERAL(5, 41, 22), // "updateonencirclepoints"
QT_MOC_LITERAL(6, 64, 6), // "float*"
QT_MOC_LITERAL(7, 71, 1), // "v"
QT_MOC_LITERAL(8, 73, 3), // "max"
QT_MOC_LITERAL(9, 77, 3) // "min"

    },
    "myPaintusb\0updatepoints\0\0argfordraw*\0"
    "arg\0updateonencirclepoints\0float*\0v\0"
    "max\0min"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myPaintusb[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       5,    3,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Float, QMetaType::Float,    7,    8,    9,

       0        // eod
};

void myPaintusb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myPaintusb *_t = static_cast<myPaintusb *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatepoints((*reinterpret_cast< argfordraw*(*)>(_a[1]))); break;
        case 1: _t->updateonencirclepoints((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject myPaintusb::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myPaintusb.data,
      qt_meta_data_myPaintusb,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *myPaintusb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myPaintusb::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_myPaintusb.stringdata0))
        return static_cast<void*>(const_cast< myPaintusb*>(this));
    return QWidget::qt_metacast(_clname);
}

int myPaintusb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
