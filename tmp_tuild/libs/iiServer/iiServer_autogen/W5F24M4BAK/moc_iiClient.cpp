/****************************************************************************
** Meta object code from reading C++ file 'iiClient.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../libs/iiServer/include/iiServer/iiClient.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iiClient.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_iiClient_t {
    const uint offsetsAndSize[32];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_iiClient_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_iiClient_t qt_meta_stringdata_iiClient = {
    {
QT_MOC_LITERAL(0, 8), // "iiClient"
QT_MOC_LITERAL(9, 10), // "identified"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 20), // "identificationFailed"
QT_MOC_LITERAL(42, 18), // "Database::CmdError"
QT_MOC_LITERAL(61, 10), // "addCommand"
QT_MOC_LITERAL(72, 21), // "Database::DatabaseCmd"
QT_MOC_LITERAL(94, 8), // "identify"
QT_MOC_LITERAL(103, 5), // "login"
QT_MOC_LITERAL(109, 8), // "password"
QT_MOC_LITERAL(118, 14), // "processRequest"
QT_MOC_LITERAL(133, 13), // "on_identified"
QT_MOC_LITERAL(147, 23), // "on_identificationFailed"
QT_MOC_LITERAL(171, 3), // "err"
QT_MOC_LITERAL(175, 17), // "on_requestSuccess"
QT_MOC_LITERAL(193, 16) // "on_requestFailed"

    },
    "iiClient\0identified\0\0identificationFailed\0"
    "Database::CmdError\0addCommand\0"
    "Database::DatabaseCmd\0identify\0login\0"
    "password\0processRequest\0on_identified\0"
    "on_identificationFailed\0err\0"
    "on_requestSuccess\0on_requestFailed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iiClient[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       3,    1,   71,    2, 0x06,    3 /* Public */,
       5,    1,   74,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    2,   77,    2, 0x0a,    7 /* Public */,
      10,    2,   82,    2, 0x0a,   10 /* Public */,
      11,    1,   87,    2, 0x08,   13 /* Private */,
      12,    1,   90,    2, 0x08,   15 /* Private */,
      14,    1,   93,    2, 0x08,   17 /* Private */,
      15,    1,   96,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,
    QMetaType::Void, QMetaType::QJsonObject, QMetaType::LongLong,    2,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, 0x80000000 | 4,   13,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void iiClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<iiClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->identified((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 1: _t->identificationFailed((*reinterpret_cast< std::add_pointer_t<Database::CmdError>>(_a[1]))); break;
        case 2: _t->addCommand((*reinterpret_cast< std::add_pointer_t<Database::DatabaseCmd>>(_a[1]))); break;
        case 3: _t->identify((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->processRequest((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 5: _t->on_identified((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 6: _t->on_identificationFailed((*reinterpret_cast< std::add_pointer_t<Database::CmdError>>(_a[1]))); break;
        case 7: _t->on_requestSuccess((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 8: _t->on_requestFailed((*reinterpret_cast< std::add_pointer_t<Database::CmdError>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Database::DatabaseCmd >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (iiClient::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iiClient::identified)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (iiClient::*)(Database::CmdError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iiClient::identificationFailed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (iiClient::*)(Database::DatabaseCmd );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iiClient::addCommand)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject iiClient::staticMetaObject = { {
    QMetaObject::SuperData::link<SslClientBase::staticMetaObject>(),
    qt_meta_stringdata_iiClient.offsetsAndSize,
    qt_meta_data_iiClient,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_iiClient_t
, QtPrivate::TypeAndForceComplete<iiClient, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::CmdError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::DatabaseCmd, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::CmdError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::CmdError, std::false_type>


>,
    nullptr
} };


const QMetaObject *iiClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iiClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iiClient.stringdata0))
        return static_cast<void*>(this);
    return SslClientBase::qt_metacast(_clname);
}

int iiClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SslClientBase::qt_metacall(_c, _id, _a);
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
void iiClient::identified(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void iiClient::identificationFailed(Database::CmdError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void iiClient::addCommand(Database::DatabaseCmd _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
