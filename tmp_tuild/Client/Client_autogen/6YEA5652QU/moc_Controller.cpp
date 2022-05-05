/****************************************************************************
** Meta object code from reading C++ file 'Controller.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Client/include/Controller.hpp"
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
    const uint offsetsAndSize[54];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 10), // "Controller"
QT_MOC_LITERAL(11, 11), // "send_to_log"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 7), // "message"
QT_MOC_LITERAL(32, 5), // "level"
QT_MOC_LITERAL(38, 16), // "createNotifyItem"
QT_MOC_LITERAL(55, 18), // "NotifyItemFactory*"
QT_MOC_LITERAL(74, 4), // "int&"
QT_MOC_LITERAL(79, 20), // "setNotifyItemPropery"
QT_MOC_LITERAL(100, 7), // "resized"
QT_MOC_LITERAL(108, 13), // "QResizeEvent*"
QT_MOC_LITERAL(122, 24), // "on_actionLogoutTriggered"
QT_MOC_LITERAL(147, 8), // "tryLogin"
QT_MOC_LITERAL(156, 15), // "ConnectSettings"
QT_MOC_LITERAL(172, 8), // "saveAuth"
QT_MOC_LITERAL(181, 8), // "readAuth"
QT_MOC_LITERAL(190, 9), // "showLogin"
QT_MOC_LITERAL(200, 11), // "on_conneted"
QT_MOC_LITERAL(212, 10), // "on_logined"
QT_MOC_LITERAL(223, 4), // "name"
QT_MOC_LITERAL(228, 4), // "role"
QT_MOC_LITERAL(233, 2), // "id"
QT_MOC_LITERAL(236, 14), // "on_loginFailed"
QT_MOC_LITERAL(251, 11), // "on_logouted"
QT_MOC_LITERAL(263, 10), // "logMessage"
QT_MOC_LITERAL(274, 8), // "_message"
QT_MOC_LITERAL(283, 11) // "resizeEvent"

    },
    "Controller\0send_to_log\0\0message\0level\0"
    "createNotifyItem\0NotifyItemFactory*\0"
    "int&\0setNotifyItemPropery\0resized\0"
    "QResizeEvent*\0on_actionLogoutTriggered\0"
    "tryLogin\0ConnectSettings\0saveAuth\0"
    "readAuth\0showLogin\0on_conneted\0"
    "on_logined\0name\0role\0id\0on_loginFailed\0"
    "on_logouted\0logMessage\0_message\0"
    "resizeEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  104,    2, 0x06,    1 /* Public */,
       5,    2,  109,    2, 0x06,    4 /* Public */,
       8,    3,  114,    2, 0x06,    7 /* Public */,
       9,    1,  121,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  124,    2, 0x0a,   13 /* Public */,
      12,    1,  125,    2, 0x0a,   14 /* Public */,
      14,    0,  128,    2, 0x0a,   16 /* Public */,
      15,    0,  129,    2, 0x0a,   17 /* Public */,
      16,    0,  130,    2, 0x08,   18 /* Private */,
      17,    0,  131,    2, 0x08,   19 /* Private */,
      18,    3,  132,    2, 0x08,   20 /* Private */,
      22,    2,  139,    2, 0x08,   24 /* Private */,
      23,    0,  144,    2, 0x08,   27 /* Private */,
      24,    2,  145,    2, 0x08,   28 /* Private */,
      26,    1,  150,    2, 0x08,   31 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 7,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::QVariant,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 10,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   19,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   25,    2,
    QMetaType::Void, 0x80000000 | 10,    2,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send_to_log((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->createNotifyItem((*reinterpret_cast< std::add_pointer_t<NotifyItemFactory*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int&>>(_a[2]))); break;
        case 2: _t->setNotifyItemPropery((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 3: _t->resized((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 4: _t->on_actionLogoutTriggered(); break;
        case 5: _t->tryLogin((*reinterpret_cast< std::add_pointer_t<ConnectSettings>>(_a[1]))); break;
        case 6: _t->saveAuth(); break;
        case 7: _t->readAuth(); break;
        case 8: _t->showLogin(); break;
        case 9: _t->on_conneted(); break;
        case 10: _t->on_logined((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 11: _t->on_loginFailed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 12: _t->on_logouted(); break;
        case 13: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 14: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::send_to_log)) {
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
            using _t = void (Controller::*)(QResizeEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::resized)) {
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
, QtPrivate::TypeAndForceComplete<Controller, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NotifyItemFactory *, std::false_type>, QtPrivate::TypeAndForceComplete<int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ConnectSettings, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>


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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Controller::send_to_log(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
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
void Controller::resized(QResizeEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
