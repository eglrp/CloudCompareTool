/****************************************************************************
** Meta object code from reading C++ file 'ccPickingHub.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qCC/ccPickingHub.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccPickingHub.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ccPickingHub_t {
    QByteArrayData data[8];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccPickingHub_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccPickingHub_t qt_meta_stringdata_ccPickingHub = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ccPickingHub"
QT_MOC_LITERAL(1, 13, 21), // "onActiveWindowChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 14), // "QMdiSubWindow*"
QT_MOC_LITERAL(4, 51, 21), // "onActiveWindowDeleted"
QT_MOC_LITERAL(5, 73, 17), // "processPickedItem"
QT_MOC_LITERAL(6, 91, 10), // "ccHObject*"
QT_MOC_LITERAL(7, 102, 9) // "CCVector3"

    },
    "ccPickingHub\0onActiveWindowChanged\0\0"
    "QMdiSubWindow*\0onActiveWindowDeleted\0"
    "processPickedItem\0ccHObject*\0CCVector3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccPickingHub[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       5,    5,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QObjectStar,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UInt, QMetaType::Int, QMetaType::Int, 0x80000000 | 7,    2,    2,    2,    2,    2,

       0        // eod
};

void ccPickingHub::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ccPickingHub *_t = static_cast<ccPickingHub *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onActiveWindowChanged((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        case 1: _t->onActiveWindowDeleted((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 2: _t->processPickedItem((*reinterpret_cast< ccHObject*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< const CCVector3(*)>(_a[5]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ccPickingHub::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ccPickingHub.data,
      qt_meta_data_ccPickingHub,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ccPickingHub::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccPickingHub::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ccPickingHub.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ccPickingHub::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
