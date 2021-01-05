/****************************************************************************
** Meta object code from reading C++ file 'analysispac.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../autotest/analysispac.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analysispac.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnalysisPac_t {
    QByteArrayData data[10];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnalysisPac_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnalysisPac_t qt_meta_stringdata_AnalysisPac = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AnalysisPac"
QT_MOC_LITERAL(1, 12, 12), // "Send2Display"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "sysName"
QT_MOC_LITERAL(4, 34, 9), // "valueList"
QT_MOC_LITERAL(5, 44, 7), // "hexList"
QT_MOC_LITERAL(6, 52, 10), // "resultList"
QT_MOC_LITERAL(7, 63, 12), // "DetectisOver"
QT_MOC_LITERAL(8, 76, 7), // "command"
QT_MOC_LITERAL(9, 84, 14) // "CommandnotFind"

    },
    "AnalysisPac\0Send2Display\0\0sysName\0"
    "valueList\0hexList\0resultList\0DetectisOver\0"
    "command\0CommandnotFind"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnalysisPac[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   29,    2, 0x06 /* Public */,
       7,    2,   38,    2, 0x06 /* Public */,
       9,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QVariantList, QMetaType::QVariantList, QMetaType::QStringList,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    8,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void AnalysisPac::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnalysisPac *_t = static_cast<AnalysisPac *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Send2Display((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariantList(*)>(_a[2])),(*reinterpret_cast< QVariantList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 1: _t->DetectisOver((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 2: _t->CommandnotFind((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AnalysisPac::*_t)(int , QVariantList , QVariantList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnalysisPac::Send2Display)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AnalysisPac::*_t)(QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnalysisPac::DetectisOver)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AnalysisPac::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnalysisPac::CommandnotFind)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject AnalysisPac::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AnalysisPac.data,
      qt_meta_data_AnalysisPac,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AnalysisPac::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnalysisPac::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnalysisPac.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AnalysisPac::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AnalysisPac::Send2Display(int _t1, QVariantList _t2, QVariantList _t3, QStringList _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AnalysisPac::DetectisOver(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AnalysisPac::CommandnotFind(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_PacWriter_t {
    QByteArrayData data[3];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PacWriter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PacWriter_t qt_meta_stringdata_PacWriter = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PacWriter"
QT_MOC_LITERAL(1, 10, 10), // "ExcuteData"
QT_MOC_LITERAL(2, 21, 0) // ""

    },
    "PacWriter\0ExcuteData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacWriter[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void PacWriter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PacWriter *_t = static_cast<PacWriter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ExcuteData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PacWriter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacWriter::ExcuteData)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PacWriter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PacWriter.data,
      qt_meta_data_PacWriter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PacWriter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacWriter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacWriter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PacWriter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PacWriter::ExcuteData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_PacController_t {
    QByteArrayData data[14];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PacController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PacController_t qt_meta_stringdata_PacController = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PacController"
QT_MOC_LITERAL(1, 14, 9), // "Send2Save"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "byteArray"
QT_MOC_LITERAL(4, 35, 16), // "SetStandardState"
QT_MOC_LITERAL(5, 52, 13), // "standardArray"
QT_MOC_LITERAL(6, 66, 13), // "ReSendCommand"
QT_MOC_LITERAL(7, 80, 7), // "command"
QT_MOC_LITERAL(8, 88, 10), // "resultList"
QT_MOC_LITERAL(9, 99, 12), // "DetectFailed"
QT_MOC_LITERAL(10, 112, 15), // "SendExplainInfo"
QT_MOC_LITERAL(11, 128, 7), // "sysName"
QT_MOC_LITERAL(12, 136, 9), // "valueList"
QT_MOC_LITERAL(13, 146, 7) // "hexList"

    },
    "PacController\0Send2Save\0\0byteArray\0"
    "SetStandardState\0standardArray\0"
    "ReSendCommand\0command\0resultList\0"
    "DetectFailed\0SendExplainInfo\0sysName\0"
    "valueList\0hexList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    2,   45,    2, 0x06 /* Public */,
       9,    1,   50,    2, 0x06 /* Public */,
      10,    4,   53,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    7,    8,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariantList, QMetaType::QVariantList, QMetaType::QStringList,   11,   12,   13,    8,

       0        // eod
};

void PacController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PacController *_t = static_cast<PacController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Send2Save((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->SetStandardState((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->ReSendCommand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 3: _t->DetectFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->SendExplainInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariantList(*)>(_a[2])),(*reinterpret_cast< QVariantList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PacController::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacController::Send2Save)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PacController::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacController::SetStandardState)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PacController::*_t)(QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacController::ReSendCommand)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PacController::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacController::DetectFailed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PacController::*_t)(int , QVariantList , QVariantList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacController::SendExplainInfo)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject PacController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PacController.data,
      qt_meta_data_PacController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PacController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PacController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PacController::Send2Save(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PacController::SetStandardState(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PacController::ReSendCommand(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PacController::DetectFailed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PacController::SendExplainInfo(int _t1, QVariantList _t2, QVariantList _t3, QStringList _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
