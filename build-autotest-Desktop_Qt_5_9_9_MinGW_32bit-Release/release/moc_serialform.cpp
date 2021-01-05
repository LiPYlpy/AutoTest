/****************************************************************************
** Meta object code from reading C++ file 'serialform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../autotest/serialform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialForm_t {
    QByteArrayData data[37];
    char stringdata0[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialForm_t qt_meta_stringdata_SerialForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SerialForm"
QT_MOC_LITERAL(1, 11, 10), // "SerialPara"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "portName"
QT_MOC_LITERAL(4, 32, 8), // "baudRate"
QT_MOC_LITERAL(5, 41, 8), // "dataBits"
QT_MOC_LITERAL(6, 50, 8), // "stopBits"
QT_MOC_LITERAL(7, 59, 6), // "parity"
QT_MOC_LITERAL(8, 66, 13), // "SendByteArray"
QT_MOC_LITERAL(9, 80, 9), // "byteArray"
QT_MOC_LITERAL(10, 90, 14), // "SendTxtCommand"
QT_MOC_LITERAL(11, 105, 11), // "commandList"
QT_MOC_LITERAL(12, 117, 8), // "SendByte"
QT_MOC_LITERAL(13, 126, 5), // "char&"
QT_MOC_LITERAL(14, 132, 4), // "byte"
QT_MOC_LITERAL(15, 137, 10), // "openThread"
QT_MOC_LITERAL(16, 148, 11), // "closeThread"
QT_MOC_LITERAL(17, 160, 11), // "SendUDPPara"
QT_MOC_LITERAL(18, 172, 8), // "thisPort"
QT_MOC_LITERAL(19, 181, 10), // "targetPort"
QT_MOC_LITERAL(20, 192, 8), // "targetIP"
QT_MOC_LITERAL(21, 201, 11), // "SetUdpAbort"
QT_MOC_LITERAL(22, 213, 9), // "SendByUdp"
QT_MOC_LITERAL(23, 223, 17), // "Send2DataAnalysis"
QT_MOC_LITERAL(24, 241, 16), // "Send2PacAnalysis"
QT_MOC_LITERAL(25, 258, 17), // "SendStandardState"
QT_MOC_LITERAL(26, 276, 13), // "standardArray"
QT_MOC_LITERAL(27, 290, 15), // "SendCommandList"
QT_MOC_LITERAL(28, 306, 7), // "lineStr"
QT_MOC_LITERAL(29, 314, 11), // "CommandOver"
QT_MOC_LITERAL(30, 326, 11), // "Send2RCForm"
QT_MOC_LITERAL(31, 338, 8), // "stateDis"
QT_MOC_LITERAL(32, 347, 10), // "resultList"
QT_MOC_LITERAL(33, 358, 15), // "SendExplainInfo"
QT_MOC_LITERAL(34, 374, 7), // "sysName"
QT_MOC_LITERAL(35, 382, 9), // "valueList"
QT_MOC_LITERAL(36, 392, 7) // "hexList"

    },
    "SerialForm\0SerialPara\0\0portName\0"
    "baudRate\0dataBits\0stopBits\0parity\0"
    "SendByteArray\0byteArray\0SendTxtCommand\0"
    "commandList\0SendByte\0char&\0byte\0"
    "openThread\0closeThread\0SendUDPPara\0"
    "thisPort\0targetPort\0targetIP\0SetUdpAbort\0"
    "SendByUdp\0Send2DataAnalysis\0"
    "Send2PacAnalysis\0SendStandardState\0"
    "standardArray\0SendCommandList\0lineStr\0"
    "CommandOver\0Send2RCForm\0stateDis\0"
    "resultList\0SendExplainInfo\0sysName\0"
    "valueList\0hexList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   94,    2, 0x06 /* Public */,
       8,    1,  105,    2, 0x06 /* Public */,
      10,    1,  108,    2, 0x06 /* Public */,
      12,    1,  111,    2, 0x06 /* Public */,
      15,    0,  114,    2, 0x06 /* Public */,
      16,    0,  115,    2, 0x06 /* Public */,
      17,    3,  116,    2, 0x06 /* Public */,
      21,    0,  123,    2, 0x06 /* Public */,
      22,    1,  124,    2, 0x06 /* Public */,
      23,    1,  127,    2, 0x06 /* Public */,
      24,    1,  130,    2, 0x06 /* Public */,
      25,    1,  133,    2, 0x06 /* Public */,
      27,    1,  136,    2, 0x06 /* Public */,
      29,    0,  139,    2, 0x06 /* Public */,
      30,    2,  140,    2, 0x06 /* Public */,
      33,    4,  145,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, QMetaType::QStringList,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort, QMetaType::UShort, QMetaType::QString,   18,   19,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, QMetaType::QStringList,   26,
    QMetaType::Void, QMetaType::QStringList,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   31,   32,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariantList, QMetaType::QVariantList, QMetaType::QStringList,   34,   35,   36,   32,

       0        // eod
};

void SerialForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialForm *_t = static_cast<SerialForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SerialPara((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: _t->SendByteArray((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->SendTxtCommand((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->SendByte((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 4: _t->openThread(); break;
        case 5: _t->closeThread(); break;
        case 6: _t->SendUDPPara((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->SetUdpAbort(); break;
        case 8: _t->SendByUdp((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->Send2DataAnalysis((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: _t->Send2PacAnalysis((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 11: _t->SendStandardState((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 12: _t->SendCommandList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 13: _t->CommandOver(); break;
        case 14: _t->Send2RCForm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 15: _t->SendExplainInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariantList(*)>(_a[2])),(*reinterpret_cast< QVariantList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SerialForm::*_t)(QString , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::SerialPara)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::SendByteArray)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::SendTxtCommand)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(char & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::SendByte)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::openThread)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::closeThread)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(quint16 , quint16 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::SendUDPPara)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::SetUdpAbort)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::SendByUdp)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::Send2DataAnalysis)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::Send2PacAnalysis)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::SendStandardState)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::SendCommandList)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::CommandOver)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::Send2RCForm)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (SerialForm::*_t)(int , QVariantList , QVariantList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialForm::SendExplainInfo)) {
                *result = 15;
                return;
            }
        }
    }
}

const QMetaObject SerialForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SerialForm.data,
      qt_meta_data_SerialForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SerialForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void SerialForm::SerialPara(QString _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialForm::SendByteArray(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialForm::SendTxtCommand(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SerialForm::SendByte(char & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SerialForm::openThread()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SerialForm::closeThread()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SerialForm::SendUDPPara(quint16 _t1, quint16 _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SerialForm::SetUdpAbort()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SerialForm::SendByUdp(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SerialForm::Send2DataAnalysis(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SerialForm::Send2PacAnalysis(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void SerialForm::SendStandardState(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void SerialForm::SendCommandList(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void SerialForm::CommandOver()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void SerialForm::Send2RCForm(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void SerialForm::SendExplainInfo(int _t1, QVariantList _t2, QVariantList _t3, QStringList _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
