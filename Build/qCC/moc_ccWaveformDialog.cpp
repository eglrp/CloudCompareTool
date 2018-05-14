/****************************************************************************
** Meta object code from reading C++ file 'ccWaveformDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qCC/ccWaveformDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccWaveformDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ccWaveWidget_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccWaveWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccWaveWidget_t qt_meta_stringdata_ccWaveWidget = {
    {
QT_MOC_LITERAL(0, 0, 12) // "ccWaveWidget"

    },
    "ccWaveWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccWaveWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ccWaveWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ccWaveWidget::staticMetaObject = {
    { &QCustomPlot::staticMetaObject, qt_meta_stringdata_ccWaveWidget.data,
      qt_meta_data_ccWaveWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ccWaveWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccWaveWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ccWaveWidget.stringdata0))
        return static_cast<void*>(this);
    return QCustomPlot::qt_metacast(_clname);
}

int ccWaveWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCustomPlot::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ccWaveDialog_t {
    QByteArrayData data[6];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccWaveDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccWaveDialog_t qt_meta_stringdata_ccWaveDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ccWaveDialog"
QT_MOC_LITERAL(1, 13, 19), // "onPointIndexChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "updateCurrentWaveform"
QT_MOC_LITERAL(4, 56, 27), // "onPointPickingButtonToggled"
QT_MOC_LITERAL(5, 84, 17) // "onExportWaveAsCSV"

    },
    "ccWaveDialog\0onPointIndexChanged\0\0"
    "updateCurrentWaveform\0onPointPickingButtonToggled\0"
    "onExportWaveAsCSV"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccWaveDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x09 /* Protected */,
       3,    0,   37,    2, 0x09 /* Protected */,
       4,    1,   38,    2, 0x09 /* Protected */,
       5,    0,   41,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void ccWaveDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ccWaveDialog *_t = static_cast<ccWaveDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onPointIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateCurrentWaveform(); break;
        case 2: _t->onPointPickingButtonToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onExportWaveAsCSV(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ccWaveDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ccWaveDialog.data,
      qt_meta_data_ccWaveDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ccWaveDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccWaveDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ccWaveDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ccPickingListener"))
        return static_cast< ccPickingListener*>(this);
    return QDialog::qt_metacast(_clname);
}

int ccWaveDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
