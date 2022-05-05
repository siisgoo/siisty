/****************************************************************************
** Meta object code from reading C++ file 'QLedIndicator.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../libs/Widgets/include/Widgets/QLedIndicator.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QLedIndicator.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QLedIndicator_t {
    const uint offsetsAndSize[28];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_QLedIndicator_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_QLedIndicator_t qt_meta_stringdata_QLedIndicator = {
    {
QT_MOC_LITERAL(0, 13), // "QLedIndicator"
QT_MOC_LITERAL(14, 15), // "ledStateChanged"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 8), // "LedState"
QT_MOC_LITERAL(40, 5), // "state"
QT_MOC_LITERAL(46, 11), // "setLedState"
QT_MOC_LITERAL(58, 10), // "setLedSize"
QT_MOC_LITERAL(69, 4), // "size"
QT_MOC_LITERAL(74, 8), // "ledState"
QT_MOC_LITERAL(83, 7), // "ledSize"
QT_MOC_LITERAL(91, 5), // "Error"
QT_MOC_LITERAL(97, 8), // "Inactive"
QT_MOC_LITERAL(106, 6), // "Active"
QT_MOC_LITERAL(113, 7) // "Warning"

    },
    "QLedIndicator\0ledStateChanged\0\0LedState\0"
    "state\0setLedState\0setLedSize\0size\0"
    "ledState\0ledSize\0Error\0Inactive\0Active\0"
    "Warning"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLedIndicator[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   59, // properties
       1,   69, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    3 /* Public */,
       1,    1,   47,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   50,    2, 0x0a,    7 /* Public */,
       5,    1,   53,    2, 0x0a,    9 /* Public */,
       6,    1,   56,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    7,

 // properties: name, type, flags
       8, 0x80000000 | 3, 0x0001510b, uint(0), 0,
       9, QMetaType::Int, 0x00015103, uint(-1), 0,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    4,   74,

 // enum data: key, value
      10, uint(QLedIndicator::Error),
      11, uint(QLedIndicator::Inactive),
      12, uint(QLedIndicator::Active),
      13, uint(QLedIndicator::Warning),

       0        // eod
};

void QLedIndicator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QLedIndicator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ledStateChanged((*reinterpret_cast< std::add_pointer_t<LedState>>(_a[1]))); break;
        case 1: _t->ledStateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->setLedState((*reinterpret_cast< std::add_pointer_t<LedState>>(_a[1]))); break;
        case 3: _t->setLedState((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setLedSize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QLedIndicator::*)(const LedState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLedIndicator::ledStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QLedIndicator::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLedIndicator::ledStateChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QLedIndicator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< LedState*>(_v) = _t->ledState(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->ledSize(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QLedIndicator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLedState(*reinterpret_cast< LedState*>(_v)); break;
        case 1: _t->setLedSize(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QLedIndicator::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QLedIndicator.offsetsAndSize,
    qt_meta_data_QLedIndicator,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_QLedIndicator_t
, QtPrivate::TypeAndForceComplete<LedState, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QLedIndicator, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const LedState, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const LedState, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>


>,
    nullptr
} };


const QMetaObject *QLedIndicator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLedIndicator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QLedIndicator.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QLedIndicator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QLedIndicator::ledStateChanged(const LedState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QLedIndicator::ledStateChanged(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
