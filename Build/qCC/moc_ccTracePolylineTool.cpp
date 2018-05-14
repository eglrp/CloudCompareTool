/****************************************************************************
** Meta object code from reading C++ file 'ccTracePolylineTool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qCC/ccTracePolylineTool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccTracePolylineTool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ccTracePolylineTool_t {
    QByteArrayData data[18];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccTracePolylineTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccTracePolylineTool_t qt_meta_stringdata_ccTracePolylineTool = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ccTracePolylineTool"
QT_MOC_LITERAL(1, 20, 5), // "apply"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "cancel"
QT_MOC_LITERAL(4, 34, 10), // "exportLine"
QT_MOC_LITERAL(5, 45, 15), // "continueEdition"
QT_MOC_LITERAL(6, 61, 9), // "resetLine"
QT_MOC_LITERAL(7, 71, 13), // "closePolyLine"
QT_MOC_LITERAL(8, 85, 1), // "x"
QT_MOC_LITERAL(9, 87, 1), // "y"
QT_MOC_LITERAL(10, 89, 17), // "updatePolyLineTip"
QT_MOC_LITERAL(11, 107, 16), // "Qt::MouseButtons"
QT_MOC_LITERAL(12, 124, 7), // "buttons"
QT_MOC_LITERAL(13, 132, 18), // "onWidthSizeChanged"
QT_MOC_LITERAL(14, 151, 19), // "onShortcutTriggered"
QT_MOC_LITERAL(15, 171, 12), // "onItemPicked"
QT_MOC_LITERAL(16, 184, 10), // "PickedItem"
QT_MOC_LITERAL(17, 195, 2) // "pi"

    },
    "ccTracePolylineTool\0apply\0\0cancel\0"
    "exportLine\0continueEdition\0resetLine\0"
    "closePolyLine\0x\0y\0updatePolyLineTip\0"
    "Qt::MouseButtons\0buttons\0onWidthSizeChanged\0"
    "onShortcutTriggered\0onItemPicked\0"
    "PickedItem\0pi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccTracePolylineTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x09 /* Protected */,
       3,    0,   75,    2, 0x09 /* Protected */,
       4,    0,   76,    2, 0x09 /* Protected */,
       5,    0,   77,    2, 0x09 /* Protected */,
       6,    0,   78,    2, 0x09 /* Protected */,
       7,    2,   79,    2, 0x09 /* Protected */,
       7,    1,   84,    2, 0x29 /* Protected | MethodCloned */,
       7,    0,   87,    2, 0x29 /* Protected | MethodCloned */,
      10,    3,   88,    2, 0x09 /* Protected */,
      13,    1,   95,    2, 0x09 /* Protected */,
      14,    1,   98,    2, 0x09 /* Protected */,
      15,    1,  101,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 11,    8,    9,   12,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void ccTracePolylineTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ccTracePolylineTool *_t = static_cast<ccTracePolylineTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->apply(); break;
        case 1: _t->cancel(); break;
        case 2: _t->exportLine(); break;
        case 3: _t->continueEdition(); break;
        case 4: _t->resetLine(); break;
        case 5: _t->closePolyLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->closePolyLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->closePolyLine(); break;
        case 8: _t->updatePolyLineTip((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Qt::MouseButtons(*)>(_a[3]))); break;
        case 9: _t->onWidthSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onShortcutTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onItemPicked((*reinterpret_cast< const PickedItem(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ccTracePolylineTool::staticMetaObject = {
    { &ccOverlayDialog::staticMetaObject, qt_meta_stringdata_ccTracePolylineTool.data,
      qt_meta_data_ccTracePolylineTool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ccTracePolylineTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccTracePolylineTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ccTracePolylineTool.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ccPickingListener"))
        return static_cast< ccPickingListener*>(this);
    if (!strcmp(_clname, "Ui::TracePolyLineDlg"))
        return static_cast< Ui::TracePolyLineDlg*>(this);
    return ccOverlayDialog::qt_metacast(_clname);
}

int ccTracePolylineTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ccOverlayDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
