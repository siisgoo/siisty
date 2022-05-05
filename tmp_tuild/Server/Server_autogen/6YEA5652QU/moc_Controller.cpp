/****************************************************************************
** Meta object code from reading C++ file 'Controller.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Server/include/Controller.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    const uint offsetsAndSize[62];
    char stringdata0[448];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 10), // "Controller"
QT_MOC_LITERAL(11, 7), // "resized"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 13), // "QResizeEvent*"
QT_MOC_LITERAL(34, 16), // "createNotifyItem"
QT_MOC_LITERAL(51, 18), // "NotifyItemFactory*"
QT_MOC_LITERAL(70, 4), // "int&"
QT_MOC_LITERAL(75, 20), // "setNotifyItemPropery"
QT_MOC_LITERAL(96, 3), // "uid"
QT_MOC_LITERAL(100, 4), // "name"
QT_MOC_LITERAL(105, 5), // "value"
QT_MOC_LITERAL(111, 11), // "send_to_log"
QT_MOC_LITERAL(123, 18), // "changeServeAddress"
QT_MOC_LITERAL(142, 13), // "QHostAddress&"
QT_MOC_LITERAL(156, 17), // "changeLoggingLeve"
QT_MOC_LITERAL(174, 5), // "level"
QT_MOC_LITERAL(180, 11), // "setupServer"
QT_MOC_LITERAL(192, 24), // "on_listeningStateChanged"
QT_MOC_LITERAL(217, 12), // "QHostAddress"
QT_MOC_LITERAL(230, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(254, 32), // "on_actionToggle_server_triggered"
QT_MOC_LITERAL(287, 16), // "on_databaseError"
QT_MOC_LITERAL(304, 18), // "Database::CmdError"
QT_MOC_LITERAL(323, 17), // "on_databaseInited"
QT_MOC_LITERAL(341, 31), // "on_databaseInitializationFailed"
QT_MOC_LITERAL(373, 9), // "QSqlError"
QT_MOC_LITERAL(383, 1), // "e"
QT_MOC_LITERAL(385, 20), // "changeIndicatorState"
QT_MOC_LITERAL(406, 10), // "logMessage"
QT_MOC_LITERAL(417, 18), // "on_clearLogClicked"
QT_MOC_LITERAL(436, 11) // "resizeEvent"

    },
    "Controller\0resized\0\0QResizeEvent*\0"
    "createNotifyItem\0NotifyItemFactory*\0"
    "int&\0setNotifyItemPropery\0uid\0name\0"
    "value\0send_to_log\0changeServeAddress\0"
    "QHostAddress&\0changeLoggingLeve\0level\0"
    "setupServer\0on_listeningStateChanged\0"
    "QHostAddress\0on_actionQuit_triggered\0"
    "on_actionToggle_server_triggered\0"
    "on_databaseError\0Database::CmdError\0"
    "on_databaseInited\0on_databaseInitializationFailed\0"
    "QSqlError\0e\0changeIndicatorState\0"
    "logMessage\0on_clearLogClicked\0resizeEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  122,    2, 0x06,    1 /* Public */,
       4,    2,  125,    2, 0x06,    3 /* Public */,
       7,    3,  130,    2, 0x06,    6 /* Public */,
      11,    2,  137,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    2,  142,    2, 0x0a,   13 /* Public */,
      14,    1,  147,    2, 0x0a,   16 /* Public */,
      16,    0,  150,    2, 0x08,   18 /* Private */,
      17,    3,  151,    2, 0x08,   19 /* Private */,
      19,    0,  158,    2, 0x08,   23 /* Private */,
      20,    0,  159,    2, 0x08,   24 /* Private */,
      21,    1,  160,    2, 0x08,   25 /* Private */,
      23,    0,  163,    2, 0x08,   27 /* Private */,
      24,    1,  164,    2, 0x08,   28 /* Private */,
      27,    3,  167,    2, 0x08,   30 /* Private */,
      28,    2,  174,    2, 0x08,   34 /* Private */,
      28,    1,  179,    2, 0x28,   37 /* Private | MethodCloned */,
      29,    0,  182,    2, 0x08,   39 /* Private */,
      30,    1,  183,    2, 0x08,   40 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 6,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::QVariant,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13, QMetaType::UShort,    2,    2,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18, QMetaType::UShort, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 18, QMetaType::UShort, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resized((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 1: _t->createNotifyItem((*reinterpret_cast< std::add_pointer_t<NotifyItemFactory*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int&>>(_a[2]))); break;
        case 2: _t->setNotifyItemPropery((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 3: _t->send_to_log((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->changeServeAddress((*reinterpret_cast< std::add_pointer_t<QHostAddress&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2]))); break;
        case 5: _t->changeLoggingLeve((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setupServer(); break;
        case 7: _t->on_listeningStateChanged((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 8: _t->on_actionQuit_triggered(); break;
        case 9: _t->on_actionToggle_server_triggered(); break;
        case 10: _t->on_databaseError((*reinterpret_cast< std::add_pointer_t<Database::CmdError>>(_a[1]))); break;
        case 11: _t->on_databaseInited(); break;
        case 12: _t->on_databaseInitializationFailed((*reinterpret_cast< std::add_pointer_t<QSqlError>>(_a[1]))); break;
        case 13: _t->changeIndicatorState((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 14: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 15: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->on_clearLogClicked(); break;
        case 17: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)(QResizeEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::resized)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controller::*)(NotifyItemFactory * , int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::createNotifyItem)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Controller::*)(int , const QByteArray & , const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::setNotifyItemPropery)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Controller::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::send_to_log)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Controller.offsetsAndSize,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Controller_t
, QtPrivate::TypeAndForceComplete<Controller, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NotifyItemFactory *, std::false_type>, QtPrivate::TypeAndForceComplete<int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress &, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Database::CmdError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSqlError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>, QtPrivate::TypeAndForceComplete<quint16, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>


>,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Controller::resized(QResizeEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::createNotifyItem(NotifyItemFactory * _t1, int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controller::setNotifyItemPropery(int _t1, const QByteArray & _t2, const QVariant & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controller::send_to_log(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
