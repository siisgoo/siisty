/****************************************************************************
** Meta object code from reading C++ file 'NotifyProgressItem.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../libs/Widgets/include/Widgets/Notifier/NotifyProgressItem.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NotifyProgressItem.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NotifyProgressItem_t {
    const uint offsetsAndSize[26];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NotifyProgressItem_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NotifyProgressItem_t qt_meta_stringdata_NotifyProgressItem = {
    {
QT_MOC_LITERAL(0, 18), // "NotifyProgressItem"
QT_MOC_LITERAL(19, 15), // "progressChanged"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 18), // "setExitOnCompleted"
QT_MOC_LITERAL(55, 11), // "setProgress"
QT_MOC_LITERAL(67, 5), // "count"
QT_MOC_LITERAL(73, 14), // "setMaxProgress"
QT_MOC_LITERAL(88, 11), // "endProgress"
QT_MOC_LITERAL(100, 11), // "NotifyLevel"
QT_MOC_LITERAL(112, 7), // "success"
QT_MOC_LITERAL(120, 8), // "progress"
QT_MOC_LITERAL(129, 11), // "maxProgress"
QT_MOC_LITERAL(141, 14) // "exitOnComplete"

    },
    "NotifyProgressItem\0progressChanged\0\0"
    "setExitOnCompleted\0setProgress\0count\0"
    "setMaxProgress\0endProgress\0NotifyLevel\0"
    "success\0progress\0maxProgress\0"
    "exitOnComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotifyProgressItem[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   59, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   47,    2, 0x0a,    6 /* Public */,
       4,    1,   50,    2, 0x0a,    8 /* Public */,
       6,    1,   53,    2, 0x0a,   10 /* Public */,
       7,    1,   56,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 8,    9,

 // properties: name, type, flags
      10, QMetaType::Int, 0x00015102, uint(-1), 0,
      11, QMetaType::Int, 0x00015102, uint(-1), 0,
      12, QMetaType::Bool, 0x00015003, uint(-1), 0,

       0        // eod
};

void NotifyProgressItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NotifyProgressItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->progressChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->setExitOnCompleted((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->setProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->setMaxProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->endProgress((*reinterpret_cast< std::add_pointer_t<NotifyLevel>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NotifyProgressItem::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotifyProgressItem::progressChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<NotifyProgressItem *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 2: *reinterpret_cast< bool*>(_v) = _t->_exitOnComplete; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<NotifyProgressItem *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setProgress(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setMaxProgress(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setExitOnCompleted(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject NotifyProgressItem::staticMetaObject = { {
    QMetaObject::SuperData::link<NotifyItem::staticMetaObject>(),
    qt_meta_stringdata_NotifyProgressItem.offsetsAndSize,
    qt_meta_data_NotifyProgressItem,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NotifyProgressItem_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<NotifyProgressItem, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NotifyLevel, std::false_type>


>,
    nullptr
} };


const QMetaObject *NotifyProgressItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotifyProgressItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NotifyProgressItem.stringdata0))
        return static_cast<void*>(this);
    return NotifyItem::qt_metacast(_clname);
}

int NotifyProgressItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NotifyItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void NotifyProgressItem::progressChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
