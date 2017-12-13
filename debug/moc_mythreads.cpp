/****************************************************************************
** Meta object code from reading C++ file 'mythreads.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mythreads.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mythreads.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RWThread_t {
    QByteArrayData data[11];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RWThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RWThread_t qt_meta_stringdata_RWThread = {
    {
QT_MOC_LITERAL(0, 0, 8), // "RWThread"
QT_MOC_LITERAL(1, 9, 14), // "sigECTtransfer"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "unsigned char*"
QT_MOC_LITERAL(4, 40, 16), // "sigTDlastransfer"
QT_MOC_LITERAL(5, 57, 11), // "quitprocess"
QT_MOC_LITERAL(6, 69, 7), // "rwcount"
QT_MOC_LITERAL(7, 77, 10), // "readbuffer"
QT_MOC_LITERAL(8, 88, 2), // "st"
QT_MOC_LITERAL(9, 91, 7), // "stoprun"
QT_MOC_LITERAL(10, 99, 4) // "flag"

    },
    "RWThread\0sigECTtransfer\0\0unsigned char*\0"
    "sigTDlastransfer\0quitprocess\0rwcount\0"
    "readbuffer\0st\0stoprun\0flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RWThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       4,    2,   49,    2, 0x06 /* Public */,
       5,    0,   54,    2, 0x06 /* Public */,
       6,    0,   55,    2, 0x06 /* Public */,
       7,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void RWThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RWThread *_t = static_cast<RWThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigECTtransfer((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sigTDlastransfer((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->quitprocess(); break;
        case 3: _t->rwcount(); break;
        case 4: _t->readbuffer((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->stoprun((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RWThread::*_t)(unsigned char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RWThread::sigECTtransfer)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RWThread::*_t)(unsigned char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RWThread::sigTDlastransfer)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RWThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RWThread::quitprocess)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RWThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RWThread::rwcount)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RWThread::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RWThread::readbuffer)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject RWThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_RWThread.data,
      qt_meta_data_RWThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RWThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RWThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RWThread.stringdata0))
        return static_cast<void*>(const_cast< RWThread*>(this));
    return QThread::qt_metacast(_clname);
}

int RWThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RWThread::sigECTtransfer(unsigned char * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RWThread::sigTDlastransfer(unsigned char * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RWThread::quitprocess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void RWThread::rwcount()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void RWThread::readbuffer(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_processThreadobj_t {
    QByteArrayData data[17];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_processThreadobj_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_processThreadobj_t qt_meta_stringdata_processThreadobj = {
    {
QT_MOC_LITERAL(0, 0, 16), // "processThreadobj"
QT_MOC_LITERAL(1, 17, 10), // "readbuffer"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "sigdrawECTusbdata"
QT_MOC_LITERAL(4, 47, 11), // "argfordraw*"
QT_MOC_LITERAL(5, 59, 23), // "sigdrawECTonecircledata"
QT_MOC_LITERAL(6, 83, 6), // "float*"
QT_MOC_LITERAL(7, 90, 20), // "sigdrawECTdifference"
QT_MOC_LITERAL(8, 111, 19), // "sigdrawTDlasusbdata"
QT_MOC_LITERAL(9, 131, 19), // "sigECTonecircledata"
QT_MOC_LITERAL(10, 151, 9), // "tryamtlab"
QT_MOC_LITERAL(11, 161, 21), // "transferforECTdrawing"
QT_MOC_LITERAL(12, 183, 14), // "unsigned char*"
QT_MOC_LITERAL(13, 198, 6), // "buffer"
QT_MOC_LITERAL(14, 205, 10), // "bufferlong"
QT_MOC_LITERAL(15, 216, 23), // "transferforTDlasdrawing"
QT_MOC_LITERAL(16, 240, 14) // "tomatlabhelper"

    },
    "processThreadobj\0readbuffer\0\0"
    "sigdrawECTusbdata\0argfordraw*\0"
    "sigdrawECTonecircledata\0float*\0"
    "sigdrawECTdifference\0sigdrawTDlasusbdata\0"
    "sigECTonecircledata\0tryamtlab\0"
    "transferforECTdrawing\0unsigned char*\0"
    "buffer\0bufferlong\0transferforTDlasdrawing\0"
    "tomatlabhelper"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_processThreadobj[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       5,    3,   70,    2, 0x06 /* Public */,
       7,    3,   77,    2, 0x06 /* Public */,
       8,    1,   84,    2, 0x06 /* Public */,
       9,    1,   87,    2, 0x06 /* Public */,
      10,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,   93,    2, 0x0a /* Public */,
      15,    2,   98,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Float, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Float, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int,   13,   14,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int,   13,   14,
    QMetaType::Void,

       0        // eod
};

void processThreadobj::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        processThreadobj *_t = static_cast<processThreadobj *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readbuffer((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 1: _t->sigdrawECTusbdata((*reinterpret_cast< argfordraw*(*)>(_a[1]))); break;
        case 2: _t->sigdrawECTonecircledata((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 3: _t->sigdrawECTdifference((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 4: _t->sigdrawTDlasusbdata((*reinterpret_cast< argfordraw*(*)>(_a[1]))); break;
        case 5: _t->sigECTonecircledata((*reinterpret_cast< float*(*)>(_a[1]))); break;
        case 6: _t->tryamtlab((*reinterpret_cast< argfordraw*(*)>(_a[1]))); break;
        case 7: _t->transferforECTdrawing((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->transferforTDlasdrawing((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->tomatlabhelper(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (processThreadobj::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processThreadobj::readbuffer)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (processThreadobj::*_t)(argfordraw * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processThreadobj::sigdrawECTusbdata)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (processThreadobj::*_t)(float * , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processThreadobj::sigdrawECTonecircledata)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (processThreadobj::*_t)(float * , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processThreadobj::sigdrawECTdifference)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (processThreadobj::*_t)(argfordraw * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processThreadobj::sigdrawTDlasusbdata)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (processThreadobj::*_t)(float * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processThreadobj::sigECTonecircledata)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (processThreadobj::*_t)(argfordraw * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processThreadobj::tryamtlab)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject processThreadobj::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_processThreadobj.data,
      qt_meta_data_processThreadobj,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *processThreadobj::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *processThreadobj::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_processThreadobj.stringdata0))
        return static_cast<void*>(const_cast< processThreadobj*>(this));
    return QObject::qt_metacast(_clname);
}

int processThreadobj::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void processThreadobj::readbuffer(quint16 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void processThreadobj::sigdrawECTusbdata(argfordraw * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void processThreadobj::sigdrawECTonecircledata(float * _t1, float _t2, float _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void processThreadobj::sigdrawECTdifference(float * _t1, float _t2, float _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void processThreadobj::sigdrawTDlasusbdata(argfordraw * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void processThreadobj::sigECTonecircledata(float * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void processThreadobj::tryamtlab(argfordraw * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
