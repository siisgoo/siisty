/****************************************************************************
** Meta object code from reading C++ file 'NotifyManager.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../libs/Widgets/include/Widgets/Notifier/NotifyManager.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NotifyManager.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NotifyManager_t {
    const uint offsetsAndSize[52];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NotifyManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NotifyManager_t qt_meta_stringdata_NotifyManager = {
    {
QT_MOC_LITERAL(0, 13), // "NotifyManager"
QT_MOC_LITERAL(14, 13), // "windowResized"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 13), // "QResizeEvent*"
QT_MOC_LITERAL(43, 15), // "maxWidthChanged"
QT_MOC_LITERAL(59, 16), // "activeItemsCount"
QT_MOC_LITERAL(76, 32), // "std::function<bool(NotifyItem*)>"
QT_MOC_LITERAL(109, 6), // "filter"
QT_MOC_LITERAL(116, 11), // "activeItems"
QT_MOC_LITERAL(128, 18), // "QList<NotifyItem*>"
QT_MOC_LITERAL(147, 10), // "itemsCount"
QT_MOC_LITERAL(158, 14), // "setItemPropery"
QT_MOC_LITERAL(173, 3), // "uid"
QT_MOC_LITERAL(177, 4), // "name"
QT_MOC_LITERAL(182, 5), // "value"
QT_MOC_LITERAL(188, 16), // "createNotifyItem"
QT_MOC_LITERAL(205, 18), // "NotifyItemFactory*"
QT_MOC_LITERAL(224, 4), // "int&"
QT_MOC_LITERAL(229, 16), // "findMaxItemWidth"
QT_MOC_LITERAL(246, 12), // "NextPosition"
QT_MOC_LITERAL(259, 1), // "n"
QT_MOC_LITERAL(261, 10), // "reorganize"
QT_MOC_LITERAL(272, 11), // "resizeItems"
QT_MOC_LITERAL(284, 5), // "width"
QT_MOC_LITERAL(290, 8), // "hideItem"
QT_MOC_LITERAL(299, 10) // "removeItem"

    },
    "NotifyManager\0windowResized\0\0QResizeEvent*\0"
    "maxWidthChanged\0activeItemsCount\0"
    "std::function<bool(NotifyItem*)>\0"
    "filter\0activeItems\0QList<NotifyItem*>\0"
    "itemsCount\0setItemPropery\0uid\0name\0"
    "value\0createNotifyItem\0NotifyItemFactory*\0"
    "int&\0findMaxItemWidth\0NextPosition\0n\0"
    "reorganize\0resizeItems\0width\0hideItem\0"
    "removeItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotifyManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,
       4,    1,  107,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,  110,    2, 0x0a,    5 /* Public */,
       5,    0,  113,    2, 0x2a,    7 /* Public | MethodCloned */,
       8,    1,  114,    2, 0x10a,    8 /* Public | MethodIsConst  */,
       8,    0,  117,    2, 0x12a,   10 /* Public | MethodCloned | MethodIsConst  */,
      10,    0,  118,    2, 0x0a,   11 /* Public */,
      11,    3,  119,    2, 0x0a,   12 /* Public */,
      15,    2,  126,    2, 0x0a,   16 /* Public */,
      18,    0,  131,    2, 0x08,   19 /* Private */,
      19,    1,  132,    2, 0x08,   20 /* Private */,
      21,    0,  135,    2, 0x08,   22 /* Private */,
      22,    1,  136,    2, 0x08,   23 /* Private */,
      24,    0,  139,    2, 0x08,   25 /* Private */,
      25,    0,  140,    2, 0x08,   26 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 6,    7,
    QMetaType::Int,
    0x80000000 | 9, 0x80000000 | 6,    7,
    0x80000000 | 9,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::QVariant,   12,   13,   14,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 17,    2,   12,
    QMetaType::Int,
    QMetaType::QPoint, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NotifyManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NotifyManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->windowResized((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 1: _t->maxWidthChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: { int _r = _t->activeItemsCount((*reinterpret_cast< std::add_pointer_t<std::function<bool(NotifyItem*)>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->activeItemsCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { QList<NotifyItem*> _r = _t->activeItems((*reinterpret_cast< std::add_pointer_t<std::function<bool(NotifyItem*)>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<NotifyItem*>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QList<NotifyItem*> _r = _t->activeItems();
            if (_a[0]) *reinterpret_cast< QList<NotifyItem*>*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->itemsCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setItemPropery((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 8: _t->createNotifyItem((*reinterpret_cast< std::add_pointer_t<NotifyItemFactory*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int&>>(_a[2]))); break;
        case 9: { int _r = _t->findMaxItemWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { QPoint _r = _t->NextPosition((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPoint*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->reorganize(); break;
        case 12: _t->resizeItems((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->hideItem(); break;
        case 14: _t->removeItem(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NotifyManager::*)(QResizeEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotifyManager::windowResized)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NotifyManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotifyManager::maxWidthChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject NotifyManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NotifyManager.offsetsAndSize,
    qt_meta_data_NotifyManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NotifyManager_t
, QtPrivate::TypeAndForceComplete<NotifyManager, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<std::function<bool(NotifyItem*)>, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QList<NotifyItem*>, std::false_type>, QtPrivate::TypeAndForceComplete<std::function<bool(NotifyItem*)>, std::false_type>, QtPrivate::TypeAndForceComplete<QList<NotifyItem*>, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NotifyItemFactory *, std::false_type>, QtPrivate::TypeAndForceComplete<int &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *NotifyManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotifyManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NotifyManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NotifyManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void NotifyManager::windowResized(QResizeEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NotifyManager::maxWidthChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
