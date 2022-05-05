/****************************************************************************
** Meta object code from reading C++ file 'iiServer.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../libs/iiServer/include/iiServer/iiServer.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iiServer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_iiServer_t {
    const uint offsetsAndSize[24];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_iiServer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_iiServer_t qt_meta_stringdata_iiServer = {
    {
QT_MOC_LITERAL(0, 8), // "iiServer"
QT_MOC_LITERAL(9, 10), // "logMessage"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 21), // "listeningStateChanged"
QT_MOC_LITERAL(43, 12), // "QHostAddress"
QT_MOC_LITERAL(56, 10), // "addCommand"
QT_MOC_LITERAL(67, 21), // "Database::DatabaseCmd"
QT_MOC_LITERAL(89, 16), // "acceptConnection"
QT_MOC_LITERAL(106, 17), // "handshakeComplete"
QT_MOC_LITERAL(124, 18), // "clientDisconnected"
QT_MOC_LITERAL(143, 14), // "recivedMessage"
QT_MOC_LITERAL(158, 15) // "iiNPack::Header"

    },
    "iiServer\0logMessage\0\0listeningStateChanged\0"
    "QHostAddress\0addCommand\0Database::DatabaseCmd\0"
    "acceptConnection\0handshakeComplete\0"
    "clientDisconnected\0recivedMessage\0"
    "iiNPack::Header"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iiServer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    1 /* Public */,
       1,    1,   67,    2, 0x26,    4 /* Public | MethodCloned */,
       3,    3,   70,    2, 0x06,    6 /* Public */,
       5,    1,   77,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   80,    2, 0x09,   12 /* Protected */,
       8,    0,   81,    2, 0x09,   13 /* Protected */,
       9,    0,   82,    2, 0x09,   14 /* Protected */,
      10,    2,   83,    2, 0x09,   15 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::UShort, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QByteArray,    2,    2,

       0        // eod
};

void iiServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<iiServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->listeningStateChanged((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 3: _t->addCommand((*reinterpret_cast< std::add_pointer_t<Database::DatabaseCmd>>(_a[1]))); break;
        case 4: _t->acceptConnection(); break;
        case 5: _t->handshakeComplete(); break;
        case 6: _t->clientDisconnected(); break;
        case 7: _t->recivedMessage((*reinterpret_cast< std::add_pointer_t<iiNPack::Header>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
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
            using _t = void (iiServer::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iiServer::logMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (iiServer::*)(QHostAddress , quint16 , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iiServer::listeningStateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (iiServer::*)(Database::DatabaseCmd );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iiServer::addCommand)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject iiServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_iiServer.offsetsAndSize,
    qt_meta_data_iiServer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_iiServer_t
, QtPrivate::TypeAndForceComplete<iiServer, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::DatabaseCmd, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<iiNPack::Header, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>


>,
    nullptr
} };


const QMetaObject *iiServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iiServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iiServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int iiServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void iiServer::logMessage(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void iiServer::listeningStateChanged(QHostAddress _t1, quint16 _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void iiServer::addCommand(Database::DatabaseCmd _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
