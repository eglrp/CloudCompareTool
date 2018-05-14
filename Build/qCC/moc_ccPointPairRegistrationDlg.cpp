/****************************************************************************
** Meta object code from reading C++ file 'ccPointPairRegistrationDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qCC/ccPointPairRegistrationDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccPointPairRegistrationDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ccPointPairRegistrationDlg_t {
    QByteArrayData data[14];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccPointPairRegistrationDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccPointPairRegistrationDlg_t qt_meta_stringdata_ccPointPairRegistrationDlg = {
    {
QT_MOC_LITERAL(0, 0, 26), // "ccPointPairRegistrationDlg"
QT_MOC_LITERAL(1, 27, 16), // "showAlignedCloud"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 18), // "showReferenceCloud"
QT_MOC_LITERAL(4, 64, 21), // "addManualAlignedPoint"
QT_MOC_LITERAL(5, 86, 17), // "addManualRefPoint"
QT_MOC_LITERAL(6, 104, 14), // "unstackAligned"
QT_MOC_LITERAL(7, 119, 10), // "unstackRef"
QT_MOC_LITERAL(8, 130, 17), // "onDelButtonPushed"
QT_MOC_LITERAL(9, 148, 15), // "updateAlignInfo"
QT_MOC_LITERAL(10, 164, 5), // "apply"
QT_MOC_LITERAL(11, 170, 5), // "align"
QT_MOC_LITERAL(12, 176, 5), // "reset"
QT_MOC_LITERAL(13, 182, 6) // "cancel"

    },
    "ccPointPairRegistrationDlg\0showAlignedCloud\0"
    "\0showReferenceCloud\0addManualAlignedPoint\0"
    "addManualRefPoint\0unstackAligned\0"
    "unstackRef\0onDelButtonPushed\0"
    "updateAlignInfo\0apply\0align\0reset\0"
    "cancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccPointPairRegistrationDlg[] = {

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
       1,    1,   74,    2, 0x09 /* Protected */,
       3,    1,   77,    2, 0x09 /* Protected */,
       4,    0,   80,    2, 0x09 /* Protected */,
       5,    0,   81,    2, 0x09 /* Protected */,
       6,    0,   82,    2, 0x09 /* Protected */,
       7,    0,   83,    2, 0x09 /* Protected */,
       8,    0,   84,    2, 0x09 /* Protected */,
       9,    0,   85,    2, 0x09 /* Protected */,
      10,    0,   86,    2, 0x09 /* Protected */,
      11,    0,   87,    2, 0x09 /* Protected */,
      12,    0,   88,    2, 0x09 /* Protected */,
      13,    0,   89,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ccPointPairRegistrationDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ccPointPairRegistrationDlg *_t = static_cast<ccPointPairRegistrationDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showAlignedCloud((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->showReferenceCloud((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->addManualAlignedPoint(); break;
        case 3: _t->addManualRefPoint(); break;
        case 4: _t->unstackAligned(); break;
        case 5: _t->unstackRef(); break;
        case 6: _t->onDelButtonPushed(); break;
        case 7: _t->updateAlignInfo(); break;
        case 8: _t->apply(); break;
        case 9: _t->align(); break;
        case 10: _t->reset(); break;
        case 11: _t->cancel(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ccPointPairRegistrationDlg::staticMetaObject = {
    { &ccOverlayDialog::staticMetaObject, qt_meta_stringdata_ccPointPairRegistrationDlg.data,
      qt_meta_data_ccPointPairRegistrationDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ccPointPairRegistrationDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccPointPairRegistrationDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ccPointPairRegistrationDlg.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ccPickingListener"))
        return static_cast< ccPickingListener*>(this);
    if (!strcmp(_clname, "Ui::pointPairRegistrationDlg"))
        return static_cast< Ui::pointPairRegistrationDlg*>(this);
    return ccOverlayDialog::qt_metacast(_clname);
}

int ccPointPairRegistrationDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
