/****************************************************************************
** Meta object code from reading C++ file 'NotifyItem.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../libs/Widgets/include/Widgets/Notifier/NotifyItem.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NotifyItem.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NotifyItem_t {
    const uint offsetsAndSize[62];
    char stringdata0[349];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NotifyItem_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NotifyItem_t qt_meta_stringdata_NotifyItem = {
    {
QT_MOC_LITERAL(0, 10), // "NotifyItem"
QT_MOC_LITERAL(11, 7), // "clicked"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 7), // "resized"
QT_MOC_LITERAL(28, 13), // "QResizeEvent*"
QT_MOC_LITERAL(42, 9), // "activated"
QT_MOC_LITERAL(52, 12), // "onActivation"
QT_MOC_LITERAL(65, 14), // "onDiactivation"
QT_MOC_LITERAL(80, 11), // "diactivated"
QT_MOC_LITERAL(92, 9), // "completed"
QT_MOC_LITERAL(102, 8), // "activate"
QT_MOC_LITERAL(111, 3), // "pos"
QT_MOC_LITERAL(115, 10), // "diactivate"
QT_MOC_LITERAL(126, 13), // "forceComplete"
QT_MOC_LITERAL(140, 11), // "NotifyLevel"
QT_MOC_LITERAL(152, 18), // "setCompleteTimeout"
QT_MOC_LITERAL(171, 2), // "ms"
QT_MOC_LITERAL(174, 14), // "setNotifyLevel"
QT_MOC_LITERAL(189, 8), // "setTitle"
QT_MOC_LITERAL(198, 15), // "setSchemeByType"
QT_MOC_LITERAL(214, 15), // "mousePressEvent"
QT_MOC_LITERAL(230, 12), // "QMouseEvent*"
QT_MOC_LITERAL(243, 12), // "on_activated"
QT_MOC_LITERAL(256, 9), // "setActive"
QT_MOC_LITERAL(266, 5), // "title"
QT_MOC_LITERAL(272, 5), // "level"
QT_MOC_LITERAL(278, 15), // "completeTimeout"
QT_MOC_LITERAL(294, 13), // "NotifySuccess"
QT_MOC_LITERAL(308, 14), // "NotififyNormal"
QT_MOC_LITERAL(323, 13), // "NotifyWarning"
QT_MOC_LITERAL(337, 11) // "NotifyError"

    },
    "NotifyItem\0clicked\0\0resized\0QResizeEvent*\0"
    "activated\0onActivation\0onDiactivation\0"
    "diactivated\0completed\0activate\0pos\0"
    "diactivate\0forceComplete\0NotifyLevel\0"
    "setCompleteTimeout\0ms\0setNotifyLevel\0"
    "setTitle\0setSchemeByType\0mousePressEvent\0"
    "QMouseEvent*\0on_activated\0setActive\0"
    "title\0level\0completeTimeout\0NotifySuccess\0"
    "NotififyNormal\0NotifyWarning\0NotifyError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotifyItem[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       4,  156, // properties
       1,  176, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  122,    2, 0x06,    5 /* Public */,
       3,    1,  123,    2, 0x06,    6 /* Public */,
       5,    0,  126,    2, 0x06,    8 /* Public */,
       6,    0,  127,    2, 0x06,    9 /* Public */,
       7,    0,  128,    2, 0x06,   10 /* Public */,
       8,    0,  129,    2, 0x06,   11 /* Public */,
       9,    0,  130,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,  131,    2, 0x0a,   13 /* Public */,
      12,    0,  134,    2, 0x0a,   15 /* Public */,
      13,    1,  135,    2, 0x0a,   16 /* Public */,
      13,    0,  138,    2, 0x2a,   18 /* Public | MethodCloned */,
      15,    1,  139,    2, 0x0a,   19 /* Public */,
      17,    1,  142,    2, 0x0a,   21 /* Public */,
      18,    1,  145,    2, 0x0a,   23 /* Public */,
      19,    1,  148,    2, 0x09,   25 /* Protected */,
      20,    1,  151,    2, 0x09,   27 /* Protected */,
      22,    0,  154,    2, 0x09,   29 /* Protected */,
      23,    0,  155,    2, 0x09,   30 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      24, QMetaType::QString, 0x00015102, uint(-1), 0,
      25, 0x80000000 | 14, 0x0001500b, uint(-1), 0,
      26, QMetaType::Int, 0x00015103, uint(-1), 0,
      13, 0x80000000 | 14, 0x0001500a, uint(-1), 0,

 // enums: name, alias, flags, count, data
      14,   14, 0x0,    4,  181,

 // enum data: key, value
      27, uint(NotifyItem::NotifySuccess),
      28, uint(NotifyItem::NotififyNormal),
      29, uint(NotifyItem::NotifyWarning),
      30, uint(NotifyItem::NotifyError),

       0        // eod
};

void NotifyItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NotifyItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->resized((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 2: _t->activated(); break;
        case 3: _t->onActivation(); break;
        case 4: _t->onDiactivation(); break;
        case 5: _t->diactivated(); break;
        case 6: _t->completed(); break;
        case 7: _t->activate((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 8: _t->diactivate(); break;
        case 9: _t->forceComplete((*reinterpret_cast< std::add_pointer_t<NotifyLevel>>(_a[1]))); break;
        case 10: _t->forceComplete(); break;
        case 11: _t->setCompleteTimeout((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->setNotifyLevel((*reinterpret_cast< std::add_pointer_t<NotifyLevel>>(_a[1]))); break;
        case 13: _t->setTitle((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->setSchemeByType((*reinterpret_cast< std::add_pointer_t<NotifyLevel>>(_a[1]))); break;
        case 15: _t->mousePressEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 16: _t->on_activated(); break;
        case 17: _t->setActive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NotifyItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotifyItem::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NotifyItem::*)(QResizeEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotifyItem::resized)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NotifyItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotifyItem::activated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NotifyItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotifyItem::onActivation)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NotifyItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotifyItem::onDiactivation)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NotifyItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotifyItem::diactivated)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (NotifyItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotifyItem::completed)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<NotifyItem *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: *reinterpret_cast< NotifyLevel*>(_v) = _t->notifyLevel(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->completeTimeout(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<NotifyItem *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setNotifyLevel(*reinterpret_cast< NotifyLevel*>(_v)); break;
        case 2: _t->setCompleteTimeout(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->forceComplete(*reinterpret_cast< NotifyLevel*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject NotifyItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_NotifyItem.offsetsAndSize,
    qt_meta_data_NotifyItem,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NotifyItem_t
, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<NotifyLevel, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<NotifyLevel, std::true_type>, QtPrivate::TypeAndForceComplete<NotifyItem, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NotifyLevel, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NotifyLevel, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NotifyLevel, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *NotifyItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotifyItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NotifyItem.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int NotifyItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void NotifyItem::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NotifyItem::resized(QResizeEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NotifyItem::activated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void NotifyItem::onActivation()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void NotifyItem::onDiactivation()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void NotifyItem::diactivated()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void NotifyItem::completed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
