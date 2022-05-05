/****************************************************************************
** Meta object code from reading C++ file 'UsersList.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Server/include/Pages/Users/UsersList.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UsersList.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UsersList_t {
    const uint offsetsAndSize[24];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_UsersList_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_UsersList_t qt_meta_stringdata_UsersList = {
    {
QT_MOC_LITERAL(0, 9), // "UsersList"
QT_MOC_LITERAL(10, 14), // "requestedUsers"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 21), // "Database::DatabaseCmd"
QT_MOC_LITERAL(48, 10), // "logMessage"
QT_MOC_LITERAL(59, 12), // "requestUsers"
QT_MOC_LITERAL(72, 10), // "clearTable"
QT_MOC_LITERAL(83, 14), // "on_usersLoaded"
QT_MOC_LITERAL(98, 17), // "on_usersLoadError"
QT_MOC_LITERAL(116, 18), // "Database::CmdError"
QT_MOC_LITERAL(135, 14), // "on_userClicked"
QT_MOC_LITERAL(150, 17) // "QTableWidgetItem*"

    },
    "UsersList\0requestedUsers\0\0"
    "Database::DatabaseCmd\0logMessage\0"
    "requestUsers\0clearTable\0on_usersLoaded\0"
    "on_usersLoadError\0Database::CmdError\0"
    "on_userClicked\0QTableWidgetItem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UsersList[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    2,   65,    2, 0x06,    3 /* Public */,
       4,    1,   70,    2, 0x26,    6 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   73,    2, 0x08,    8 /* Private */,
       6,    0,   74,    2, 0x08,    9 /* Private */,
       7,    1,   75,    2, 0x08,   10 /* Private */,
       8,    1,   78,    2, 0x08,   12 /* Private */,
      10,    1,   81,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11,    2,

       0        // eod
};

void UsersList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UsersList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->requestedUsers((*reinterpret_cast< std::add_pointer_t<Database::DatabaseCmd>>(_a[1]))); break;
        case 1: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->requestUsers(); break;
        case 4: _t->clearTable(); break;
        case 5: _t->on_usersLoaded((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 6: _t->on_usersLoadError((*reinterpret_cast< std::add_pointer_t<Database::CmdError>>(_a[1]))); break;
        case 7: _t->on_userClicked((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UsersList::*)(Database::DatabaseCmd );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UsersList::requestedUsers)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UsersList::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UsersList::logMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject UsersList::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_UsersList.offsetsAndSize,
    qt_meta_data_UsersList,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_UsersList_t
, QtPrivate::TypeAndForceComplete<UsersList, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::DatabaseCmd, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::CmdError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>


>,
    nullptr
} };


const QMetaObject *UsersList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UsersList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UsersList.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UsersList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void UsersList::requestedUsers(Database::DatabaseCmd _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UsersList::logMessage(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
