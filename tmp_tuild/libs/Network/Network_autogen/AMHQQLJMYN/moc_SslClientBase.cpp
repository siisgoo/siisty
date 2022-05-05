/****************************************************************************
** Meta object code from reading C++ file 'SslClientBase.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../libs/Network/include/Network/SslClientBase.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SslClientBase.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SslClientBase_t {
    const uint offsetsAndSize[50];
    char stringdata0[363];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SslClientBase_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SslClientBase_t qt_meta_stringdata_SslClientBase = {
    {
QT_MOC_LITERAL(0, 13), // "SslClientBase"
QT_MOC_LITERAL(14, 14), // "recivedMessage"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 15), // "iiNPack::Header"
QT_MOC_LITERAL(46, 5), // "_data"
QT_MOC_LITERAL(52, 9), // "connected"
QT_MOC_LITERAL(62, 12), // "disconnected"
QT_MOC_LITERAL(75, 9), // "encrypted"
QT_MOC_LITERAL(85, 15), // "peerVerifyError"
QT_MOC_LITERAL(101, 9), // "QSslError"
QT_MOC_LITERAL(111, 9), // "sslErrors"
QT_MOC_LITERAL(121, 16), // "QList<QSslError>"
QT_MOC_LITERAL(138, 13), // "errorOccurred"
QT_MOC_LITERAL(152, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(181, 27), // "proxyAuthenticationRequired"
QT_MOC_LITERAL(209, 13), // "QNetworkProxy"
QT_MOC_LITERAL(223, 15), // "QAuthenticator*"
QT_MOC_LITERAL(239, 12), // "stateChanged"
QT_MOC_LITERAL(252, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(281, 10), // "logMessage"
QT_MOC_LITERAL(292, 11), // "sendMessage"
QT_MOC_LITERAL(304, 13), // "dataAvailable"
QT_MOC_LITERAL(318, 18), // "socketStateChanged"
QT_MOC_LITERAL(337, 13), // "onSocketError"
QT_MOC_LITERAL(351, 11) // "onSslErrors"

    },
    "SslClientBase\0recivedMessage\0\0"
    "iiNPack::Header\0_data\0connected\0"
    "disconnected\0encrypted\0peerVerifyError\0"
    "QSslError\0sslErrors\0QList<QSslError>\0"
    "errorOccurred\0QAbstractSocket::SocketError\0"
    "proxyAuthenticationRequired\0QNetworkProxy\0"
    "QAuthenticator*\0stateChanged\0"
    "QAbstractSocket::SocketState\0logMessage\0"
    "sendMessage\0dataAvailable\0socketStateChanged\0"
    "onSocketError\0onSslErrors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SslClientBase[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  104,    2, 0x06,    1 /* Public */,
       5,    0,  109,    2, 0x06,    4 /* Public */,
       6,    0,  110,    2, 0x06,    5 /* Public */,
       7,    0,  111,    2, 0x06,    6 /* Public */,
       8,    1,  112,    2, 0x06,    7 /* Public */,
      10,    1,  115,    2, 0x06,    9 /* Public */,
      12,    1,  118,    2, 0x06,   11 /* Public */,
      14,    2,  121,    2, 0x06,   13 /* Public */,
      17,    1,  126,    2, 0x06,   16 /* Public */,
      19,    2,  129,    2, 0x06,   18 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    1,  134,    2, 0x0a,   21 /* Public */,
      21,    0,  137,    2, 0x09,   23 /* Protected */,
      22,    1,  138,    2, 0x09,   24 /* Protected */,
      23,    1,  141,    2, 0x09,   26 /* Protected */,
      24,    1,  144,    2, 0x09,   28 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 16,    2,    2,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 11,    2,

       0        // eod
};

void SslClientBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SslClientBase *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->recivedMessage((*reinterpret_cast< std::add_pointer_t<iiNPack::Header>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 1: _t->connected(); break;
        case 2: _t->disconnected(); break;
        case 3: _t->encrypted(); break;
        case 4: _t->peerVerifyError((*reinterpret_cast< std::add_pointer_t<QSslError>>(_a[1]))); break;
        case 5: _t->sslErrors((*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[1]))); break;
        case 6: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 7: _t->proxyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QNetworkProxy>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 8: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 9: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 10: _t->sendMessage((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 11: _t->dataAvailable(); break;
        case 12: _t->socketStateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 13: _t->onSocketError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 14: _t->onSslErrors((*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SslClientBase::*)(iiNPack::Header , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SslClientBase::recivedMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SslClientBase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SslClientBase::connected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SslClientBase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SslClientBase::disconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SslClientBase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SslClientBase::encrypted)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SslClientBase::*)(const QSslError & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SslClientBase::peerVerifyError)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SslClientBase::*)(const QList<QSslError> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SslClientBase::sslErrors)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SslClientBase::*)(QAbstractSocket::SocketError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SslClientBase::errorOccurred)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SslClientBase::*)(const QNetworkProxy & , QAuthenticator * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SslClientBase::proxyAuthenticationRequired)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SslClientBase::*)(QAbstractSocket::SocketState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SslClientBase::stateChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SslClientBase::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SslClientBase::logMessage)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject SslClientBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SslClientBase.offsetsAndSize,
    qt_meta_data_SslClientBase,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SslClientBase_t
, QtPrivate::TypeAndForceComplete<SslClientBase, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<iiNPack::Header, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QSslError &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QList<QSslError> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QNetworkProxy &, std::false_type>, QtPrivate::TypeAndForceComplete<QAuthenticator *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketState, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketState, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QList<QSslError> &, std::false_type>


>,
    nullptr
} };


const QMetaObject *SslClientBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SslClientBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SslClientBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SslClientBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void SslClientBase::recivedMessage(iiNPack::Header _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SslClientBase::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SslClientBase::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SslClientBase::encrypted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SslClientBase::peerVerifyError(const QSslError & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SslClientBase::sslErrors(const QList<QSslError> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SslClientBase::errorOccurred(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SslClientBase::proxyAuthenticationRequired(const QNetworkProxy & _t1, QAuthenticator * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SslClientBase::stateChanged(QAbstractSocket::SocketState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SslClientBase::logMessage(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
