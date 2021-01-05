/****************************************************************************
** Meta object code from reading C++ file 'udpport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../autotest/udpport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UDPPort_t {
    QByteArrayData data[4];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UDPPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UDPPort_t qt_meta_stringdata_UDPPort = {
    {
QT_MOC_LITERAL(0, 0, 7), // "UDPPort"
QT_MOC_LITERAL(1, 8, 11), // "ReceiveData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8) // "recvdata"

    },
    "UDPPort\0ReceiveData\0\0recvdata"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UDPPort[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

       0        // eod
};

void UDPPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UDPPort *_t = static_cast<UDPPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReceiveData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (UDPPort::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPPort::ReceiveData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject UDPPort::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UDPPort.data,
      qt_meta_data_UDPPort,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UDPPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDPPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UDPPort.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UDPPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void UDPPort::ReceiveData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_UDPController_t {
    QByteArrayData data[10];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UDPController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UDPController_t qt_meta_stringdata_UDPController = {
    {
QT_MOC_LITERAL(0, 0, 13), // "UDPController"
QT_MOC_LITERAL(1, 14, 10), // "SetUDPPara"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "thisPort"
QT_MOC_LITERAL(4, 35, 10), // "targetPort"
QT_MOC_LITERAL(5, 46, 8), // "targetIP"
QT_MOC_LITERAL(6, 55, 11), // "SetUdpAbort"
QT_MOC_LITERAL(7, 67, 11), // "SendUdpData"
QT_MOC_LITERAL(8, 79, 9), // "byteArray"
QT_MOC_LITERAL(9, 89, 9) // "WriteData"

    },
    "UDPController\0SetUDPPara\0\0thisPort\0"
    "targetPort\0targetIP\0SetUdpAbort\0"
    "SendUdpData\0byteArray\0WriteData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UDPController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       6,    0,   41,    2, 0x06 /* Public */,
       7,    1,   42,    2, 0x06 /* Public */,
       9,    1,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::UShort, QMetaType::QString,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QByteArray,    8,

       0        // eod
};

void UDPController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UDPController *_t = static_cast<UDPController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetUDPPara((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->SetUdpAbort(); break;
        case 2: _t->SendUdpData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->WriteData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (UDPController::*_t)(quint16 , quint16 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPController::SetUDPPara)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UDPController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPController::SetUdpAbort)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UDPController::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPController::SendUdpData)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (UDPController::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPController::WriteData)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject UDPController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UDPController.data,
      qt_meta_data_UDPController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UDPController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDPController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UDPController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UDPController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void UDPController::SetUDPPara(quint16 _t1, quint16 _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UDPController::SetUdpAbort()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UDPController::SendUdpData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UDPController::WriteData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
