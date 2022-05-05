/****************************************************************************
** Meta object code from reading C++ file 'Database.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../libs/Database/include/Database/Database.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Database.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Database__DriverAssistant_t {
    const uint offsetsAndSize[16];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Database__DriverAssistant_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Database__DriverAssistant_t qt_meta_stringdata_Database__DriverAssistant = {
    {
QT_MOC_LITERAL(0, 25), // "Database::DriverAssistant"
QT_MOC_LITERAL(26, 7), // "success"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 3), // "obj"
QT_MOC_LITERAL(39, 6), // "failed"
QT_MOC_LITERAL(46, 18), // "Database::CmdError"
QT_MOC_LITERAL(65, 7), // "Success"
QT_MOC_LITERAL(73, 6) // "Failed"

    },
    "Database::DriverAssistant\0success\0\0"
    "obj\0failed\0Database::CmdError\0Success\0"
    "Failed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Database__DriverAssistant[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       4,    1,   41,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   44,    2, 0x0a,    5 /* Public */,
       7,    1,   47,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void Database::DriverAssistant::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DriverAssistant *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->success((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 1: _t->failed((*reinterpret_cast< std::add_pointer_t<Database::CmdError>>(_a[1]))); break;
        case 2: _t->Success((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 3: _t->Failed((*reinterpret_cast< std::add_pointer_t<Database::CmdError>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DriverAssistant::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DriverAssistant::success)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DriverAssistant::*)(Database::CmdError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DriverAssistant::failed)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Database::DriverAssistant::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Database__DriverAssistant.offsetsAndSize,
    qt_meta_data_Database__DriverAssistant,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Database__DriverAssistant_t
, QtPrivate::TypeAndForceComplete<DriverAssistant, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::CmdError, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::CmdError, std::false_type>


>,
    nullptr
} };


const QMetaObject *Database::DriverAssistant::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Database::DriverAssistant::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Database__DriverAssistant.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Database::DriverAssistant::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Database::DriverAssistant::success(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Database::DriverAssistant::failed(Database::CmdError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_Database__Driver_t {
    const uint offsetsAndSize[44];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Database__Driver_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Database__Driver_t qt_meta_stringdata_Database__Driver = {
    {
QT_MOC_LITERAL(0, 16), // "Database::Driver"
QT_MOC_LITERAL(17, 6), // "Inited"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 20), // "InitizlizationFailed"
QT_MOC_LITERAL(46, 9), // "QSqlError"
QT_MOC_LITERAL(56, 10), // "logMessage"
QT_MOC_LITERAL(67, 20), // "setNotifyItemPropery"
QT_MOC_LITERAL(88, 16), // "createNotifyItem"
QT_MOC_LITERAL(105, 18), // "NotifyItemFactory*"
QT_MOC_LITERAL(124, 4), // "int&"
QT_MOC_LITERAL(129, 3), // "uid"
QT_MOC_LITERAL(133, 3), // "Run"
QT_MOC_LITERAL(137, 4), // "Stop"
QT_MOC_LITERAL(142, 6), // "worker"
QT_MOC_LITERAL(149, 10), // "addCommand"
QT_MOC_LITERAL(160, 21), // "Database::DatabaseCmd"
QT_MOC_LITERAL(182, 14), // "executeCommand"
QT_MOC_LITERAL(197, 16), // "Database::RoleId"
QT_MOC_LITERAL(214, 4), // "role"
QT_MOC_LITERAL(219, 1), // "o"
QT_MOC_LITERAL(221, 16), // "DriverAssistant*"
QT_MOC_LITERAL(238, 15) // "autoExecCommand"

    },
    "Database::Driver\0Inited\0\0InitizlizationFailed\0"
    "QSqlError\0logMessage\0setNotifyItemPropery\0"
    "createNotifyItem\0NotifyItemFactory*\0"
    "int&\0uid\0Run\0Stop\0worker\0addCommand\0"
    "Database::DatabaseCmd\0executeCommand\0"
    "Database::RoleId\0role\0o\0DriverAssistant*\0"
    "autoExecCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Database__Driver[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,
       3,    1,   87,    2, 0x06,    2 /* Public */,
       5,    2,   90,    2, 0x06,    4 /* Public */,
       5,    1,   95,    2, 0x26,    7 /* Public | MethodCloned */,
       6,    3,   98,    2, 0x06,    9 /* Public */,
       7,    2,  105,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  110,    2, 0x0a,   16 /* Public */,
      12,    0,  111,    2, 0x0a,   17 /* Public */,
      13,    0,  112,    2, 0x08,   18 /* Private */,
      14,    1,  113,    2, 0x08,   19 /* Private */,
      16,    3,  116,    2, 0x08,   21 /* Private */,
      21,    1,  123,    2, 0x08,   25 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::QVariant,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 9,    2,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17, QMetaType::QJsonObject, 0x80000000 | 20,   18,   19,    2,
    QMetaType::Bool, QMetaType::QJsonObject,   19,

       0        // eod
};

void Database::Driver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Driver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Inited(); break;
        case 1: _t->InitizlizationFailed((*reinterpret_cast< std::add_pointer_t<QSqlError>>(_a[1]))); break;
        case 2: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->setNotifyItemPropery((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 5: _t->createNotifyItem((*reinterpret_cast< std::add_pointer_t<NotifyItemFactory*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int&>>(_a[2]))); break;
        case 6: _t->Run(); break;
        case 7: _t->Stop(); break;
        case 8: _t->worker(); break;
        case 9: _t->addCommand((*reinterpret_cast< std::add_pointer_t<Database::DatabaseCmd>>(_a[1]))); break;
        case 10: _t->executeCommand((*reinterpret_cast< std::add_pointer_t<Database::RoleId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<DriverAssistant*>>(_a[3]))); break;
        case 11: { bool _r = _t->autoExecCommand((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Database::DatabaseCmd >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DriverAssistant* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Driver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Driver::Inited)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Driver::*)(QSqlError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Driver::InitizlizationFailed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Driver::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Driver::logMessage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Driver::*)(int , const QByteArray & , const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Driver::setNotifyItemPropery)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Driver::*)(NotifyItemFactory * , int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Driver::createNotifyItem)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Database::Driver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Database__Driver.offsetsAndSize,
    qt_meta_data_Database__Driver,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Database__Driver_t
, QtPrivate::TypeAndForceComplete<Driver, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSqlError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NotifyItemFactory *, std::false_type>, QtPrivate::TypeAndForceComplete<int &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::DatabaseCmd, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::RoleId, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<DriverAssistant *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>


>,
    nullptr
} };


const QMetaObject *Database::Driver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Database::Driver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Database__Driver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Database::Driver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Database::Driver::Inited()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Database::Driver::InitizlizationFailed(QSqlError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Database::Driver::logMessage(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void Database::Driver::setNotifyItemPropery(int _t1, const QByteArray & _t2, const QVariant & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Database::Driver::createNotifyItem(NotifyItemFactory * _t1, int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
