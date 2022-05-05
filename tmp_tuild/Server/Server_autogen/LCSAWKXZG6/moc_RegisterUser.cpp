/****************************************************************************
** Meta object code from reading C++ file 'RegisterUser.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Server/include/Pages/Users/RegisterUser.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RegisterUser.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RegisterUser_t {
    const uint offsetsAndSize[48];
    char stringdata0[410];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RegisterUser_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RegisterUser_t qt_meta_stringdata_RegisterUser = {
    {
QT_MOC_LITERAL(0, 12), // "RegisterUser"
QT_MOC_LITERAL(13, 14), // "registrateUser"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 21), // "Database::DatabaseCmd"
QT_MOC_LITERAL(51, 21), // "requestedWaponDetails"
QT_MOC_LITERAL(73, 20), // "requestedUserDetails"
QT_MOC_LITERAL(94, 15), // "imgFileNotValid"
QT_MOC_LITERAL(110, 12), // "imgFileValid"
QT_MOC_LITERAL(123, 10), // "logMessage"
QT_MOC_LITERAL(134, 18), // "on_dbWaponsChanged"
QT_MOC_LITERAL(153, 16), // "on_waponsFetched"
QT_MOC_LITERAL(170, 6), // "wapons"
QT_MOC_LITERAL(177, 20), // "on_waponsFetchFailed"
QT_MOC_LITERAL(198, 18), // "Database::CmdError"
QT_MOC_LITERAL(217, 19), // "requestWaponDetails"
QT_MOC_LITERAL(237, 28), // "on_register_buttons_accepted"
QT_MOC_LITERAL(266, 28), // "on_register_buttons_rejected"
QT_MOC_LITERAL(295, 14), // "on_saveSuccess"
QT_MOC_LITERAL(310, 13), // "on_saveFailed"
QT_MOC_LITERAL(324, 17), // "openImgFileChooer"
QT_MOC_LITERAL(342, 19), // "on_imgFilePathValid"
QT_MOC_LITERAL(362, 22), // "on_imgFilePathNotValid"
QT_MOC_LITERAL(385, 19), // "validateImgFilePath"
QT_MOC_LITERAL(405, 4) // "file"

    },
    "RegisterUser\0registrateUser\0\0"
    "Database::DatabaseCmd\0requestedWaponDetails\0"
    "requestedUserDetails\0imgFileNotValid\0"
    "imgFileValid\0logMessage\0on_dbWaponsChanged\0"
    "on_waponsFetched\0wapons\0on_waponsFetchFailed\0"
    "Database::CmdError\0requestWaponDetails\0"
    "on_register_buttons_accepted\0"
    "on_register_buttons_rejected\0"
    "on_saveSuccess\0on_saveFailed\0"
    "openImgFileChooer\0on_imgFilePathValid\0"
    "on_imgFilePathNotValid\0validateImgFilePath\0"
    "file"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RegisterUser[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  128,    2, 0x06,    1 /* Public */,
       4,    1,  131,    2, 0x06,    3 /* Public */,
       5,    1,  134,    2, 0x06,    5 /* Public */,
       6,    0,  137,    2, 0x06,    7 /* Public */,
       7,    0,  138,    2, 0x06,    8 /* Public */,
       8,    2,  139,    2, 0x06,    9 /* Public */,
       8,    1,  144,    2, 0x26,   12 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,  147,    2, 0x0a,   14 /* Public */,
      10,    1,  148,    2, 0x08,   15 /* Private */,
      12,    1,  151,    2, 0x08,   17 /* Private */,
      14,    0,  154,    2, 0x08,   19 /* Private */,
      15,    0,  155,    2, 0x08,   20 /* Private */,
      16,    0,  156,    2, 0x08,   21 /* Private */,
      17,    1,  157,    2, 0x08,   22 /* Private */,
      18,    1,  160,    2, 0x08,   24 /* Private */,
      19,    0,  163,    2, 0x08,   26 /* Private */,
      20,    0,  164,    2, 0x08,   27 /* Private */,
      21,    0,  165,    2, 0x08,   28 /* Private */,
      22,    1,  166,    2, 0x08,   29 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   11,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,

       0        // eod
};

void RegisterUser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RegisterUser *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->registrateUser((*reinterpret_cast< std::add_pointer_t<Database::DatabaseCmd>>(_a[1]))); break;
        case 1: _t->requestedWaponDetails((*reinterpret_cast< std::add_pointer_t<Database::DatabaseCmd>>(_a[1]))); break;
        case 2: _t->requestedUserDetails((*reinterpret_cast< std::add_pointer_t<Database::DatabaseCmd>>(_a[1]))); break;
        case 3: _t->imgFileNotValid(); break;
        case 4: _t->imgFileValid(); break;
        case 5: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_dbWaponsChanged(); break;
        case 8: _t->on_waponsFetched((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 9: _t->on_waponsFetchFailed((*reinterpret_cast< std::add_pointer_t<Database::CmdError>>(_a[1]))); break;
        case 10: _t->requestWaponDetails(); break;
        case 11: _t->on_register_buttons_accepted(); break;
        case 12: _t->on_register_buttons_rejected(); break;
        case 13: _t->on_saveSuccess((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 14: _t->on_saveFailed((*reinterpret_cast< std::add_pointer_t<Database::CmdError>>(_a[1]))); break;
        case 15: _t->openImgFileChooer(); break;
        case 16: _t->on_imgFilePathValid(); break;
        case 17: _t->on_imgFilePathNotValid(); break;
        case 18: _t->validateImgFilePath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Database::DatabaseCmd >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Database::DatabaseCmd >(); break;
            }
            break;
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
            using _t = void (RegisterUser::*)(Database::DatabaseCmd );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RegisterUser::registrateUser)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RegisterUser::*)(Database::DatabaseCmd );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RegisterUser::requestedWaponDetails)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RegisterUser::*)(Database::DatabaseCmd );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RegisterUser::requestedUserDetails)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RegisterUser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RegisterUser::imgFileNotValid)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RegisterUser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RegisterUser::imgFileValid)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (RegisterUser::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RegisterUser::logMessage)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject RegisterUser::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_RegisterUser.offsetsAndSize,
    qt_meta_data_RegisterUser,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RegisterUser_t
, QtPrivate::TypeAndForceComplete<RegisterUser, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::DatabaseCmd, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::DatabaseCmd, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::DatabaseCmd, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::CmdError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::CmdError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *RegisterUser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegisterUser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RegisterUser.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RegisterUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void RegisterUser::registrateUser(Database::DatabaseCmd _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RegisterUser::requestedWaponDetails(Database::DatabaseCmd _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RegisterUser::requestedUserDetails(Database::DatabaseCmd _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RegisterUser::imgFileNotValid()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void RegisterUser::imgFileValid()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void RegisterUser::logMessage(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
