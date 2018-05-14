/****************************************************************************
** Meta object code from reading C++ file 'ccDBRoot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qCC/db_tree/ccDBRoot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccDBRoot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ccCustomQTreeView_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccCustomQTreeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccCustomQTreeView_t qt_meta_stringdata_ccCustomQTreeView = {
    {
QT_MOC_LITERAL(0, 0, 17) // "ccCustomQTreeView"

    },
    "ccCustomQTreeView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccCustomQTreeView[] = {

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

void ccCustomQTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ccCustomQTreeView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_ccCustomQTreeView.data,
      qt_meta_data_ccCustomQTreeView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ccCustomQTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccCustomQTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ccCustomQTreeView.stringdata0))
        return static_cast<void*>(this);
    return QTreeView::qt_metacast(_clname);
}

int ccCustomQTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ccDBRoot_t {
    QByteArrayData data[46];
    char stringdata0[817];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccDBRoot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccDBRoot_t qt_meta_stringdata_ccDBRoot = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ccDBRoot"
QT_MOC_LITERAL(1, 9, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "dbIsEmpty"
QT_MOC_LITERAL(4, 37, 19), // "dbIsNotEmptyAnymore"
QT_MOC_LITERAL(5, 57, 15), // "changeSelection"
QT_MOC_LITERAL(6, 73, 14), // "QItemSelection"
QT_MOC_LITERAL(7, 88, 8), // "selected"
QT_MOC_LITERAL(8, 97, 10), // "deselected"
QT_MOC_LITERAL(9, 108, 23), // "reflectObjectPropChange"
QT_MOC_LITERAL(10, 132, 10), // "ccHObject*"
QT_MOC_LITERAL(11, 143, 3), // "obj"
QT_MOC_LITERAL(12, 147, 14), // "redrawCCObject"
QT_MOC_LITERAL(13, 162, 6), // "object"
QT_MOC_LITERAL(14, 169, 25), // "redrawCCObjectAndChildren"
QT_MOC_LITERAL(15, 195, 14), // "updateCCObject"
QT_MOC_LITERAL(16, 210, 22), // "deleteSelectedEntities"
QT_MOC_LITERAL(17, 233, 12), // "selectEntity"
QT_MOC_LITERAL(18, 246, 22), // "forceAdditiveSelection"
QT_MOC_LITERAL(19, 269, 14), // "selectEntities"
QT_MOC_LITERAL(20, 284, 23), // "std::unordered_set<int>"
QT_MOC_LITERAL(21, 308, 6), // "entIDs"
QT_MOC_LITERAL(22, 315, 20), // "ccHObject::Container"
QT_MOC_LITERAL(23, 336, 8), // "entities"
QT_MOC_LITERAL(24, 345, 11), // "incremental"
QT_MOC_LITERAL(25, 357, 15), // "showContextMenu"
QT_MOC_LITERAL(26, 373, 12), // "expandBranch"
QT_MOC_LITERAL(27, 386, 14), // "collapseBranch"
QT_MOC_LITERAL(28, 401, 26), // "gatherRecursiveInformation"
QT_MOC_LITERAL(29, 428, 14), // "sortChildrenAZ"
QT_MOC_LITERAL(30, 443, 14), // "sortChildrenZA"
QT_MOC_LITERAL(31, 458, 16), // "sortChildrenType"
QT_MOC_LITERAL(32, 475, 19), // "selectByTypeAndName"
QT_MOC_LITERAL(33, 495, 22), // "toggleSelectedEntities"
QT_MOC_LITERAL(34, 518, 32), // "toggleSelectedEntitiesVisibility"
QT_MOC_LITERAL(35, 551, 27), // "toggleSelectedEntitiesColor"
QT_MOC_LITERAL(36, 579, 29), // "toggleSelectedEntitiesNormals"
QT_MOC_LITERAL(37, 609, 24), // "toggleSelectedEntitiesSF"
QT_MOC_LITERAL(38, 634, 25), // "toggleSelectedEntitiesMat"
QT_MOC_LITERAL(39, 660, 28), // "toggleSelectedEntities3DName"
QT_MOC_LITERAL(40, 689, 13), // "addEmptyGroup"
QT_MOC_LITERAL(41, 703, 27), // "alignCameraWithEntityDirect"
QT_MOC_LITERAL(42, 731, 29), // "alignCameraWithEntityIndirect"
QT_MOC_LITERAL(43, 761, 20), // "enableBubbleViewMode"
QT_MOC_LITERAL(44, 782, 20), // "editLabelScalarValue"
QT_MOC_LITERAL(45, 803, 13) // "editAttribute"

    },
    "ccDBRoot\0selectionChanged\0\0dbIsEmpty\0"
    "dbIsNotEmptyAnymore\0changeSelection\0"
    "QItemSelection\0selected\0deselected\0"
    "reflectObjectPropChange\0ccHObject*\0"
    "obj\0redrawCCObject\0object\0"
    "redrawCCObjectAndChildren\0updateCCObject\0"
    "deleteSelectedEntities\0selectEntity\0"
    "forceAdditiveSelection\0selectEntities\0"
    "std::unordered_set<int>\0entIDs\0"
    "ccHObject::Container\0entities\0incremental\0"
    "showContextMenu\0expandBranch\0"
    "collapseBranch\0gatherRecursiveInformation\0"
    "sortChildrenAZ\0sortChildrenZA\0"
    "sortChildrenType\0selectByTypeAndName\0"
    "toggleSelectedEntities\0"
    "toggleSelectedEntitiesVisibility\0"
    "toggleSelectedEntitiesColor\0"
    "toggleSelectedEntitiesNormals\0"
    "toggleSelectedEntitiesSF\0"
    "toggleSelectedEntitiesMat\0"
    "toggleSelectedEntities3DName\0addEmptyGroup\0"
    "alignCameraWithEntityDirect\0"
    "alignCameraWithEntityIndirect\0"
    "enableBubbleViewMode\0editLabelScalarValue\0"
    "editAttribute"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccDBRoot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  189,    2, 0x06 /* Public */,
       3,    0,  190,    2, 0x06 /* Public */,
       4,    0,  191,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,  192,    2, 0x0a /* Public */,
       9,    1,  197,    2, 0x0a /* Public */,
      12,    1,  200,    2, 0x0a /* Public */,
      14,    1,  203,    2, 0x0a /* Public */,
      15,    1,  206,    2, 0x0a /* Public */,
      16,    0,  209,    2, 0x0a /* Public */,
      17,    2,  210,    2, 0x0a /* Public */,
      17,    1,  215,    2, 0x2a /* Public | MethodCloned */,
      19,    1,  218,    2, 0x0a /* Public */,
      19,    2,  221,    2, 0x0a /* Public */,
      19,    1,  226,    2, 0x2a /* Public | MethodCloned */,
      25,    1,  229,    2, 0x09 /* Protected */,
      26,    0,  232,    2, 0x09 /* Protected */,
      27,    0,  233,    2, 0x09 /* Protected */,
      28,    0,  234,    2, 0x09 /* Protected */,
      29,    0,  235,    2, 0x09 /* Protected */,
      30,    0,  236,    2, 0x09 /* Protected */,
      31,    0,  237,    2, 0x09 /* Protected */,
      32,    0,  238,    2, 0x09 /* Protected */,
      33,    0,  239,    2, 0x09 /* Protected */,
      34,    0,  240,    2, 0x09 /* Protected */,
      35,    0,  241,    2, 0x09 /* Protected */,
      36,    0,  242,    2, 0x09 /* Protected */,
      37,    0,  243,    2, 0x09 /* Protected */,
      38,    0,  244,    2, 0x09 /* Protected */,
      39,    0,  245,    2, 0x09 /* Protected */,
      40,    0,  246,    2, 0x09 /* Protected */,
      41,    0,  247,    2, 0x09 /* Protected */,
      42,    0,  248,    2, 0x09 /* Protected */,
      43,    0,  249,    2, 0x09 /* Protected */,
      44,    0,  250,    2, 0x09 /* Protected */,
      45,    0,  251,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   13,
    QMetaType::Void, 0x80000000 | 10,   13,
    QMetaType::Void, 0x80000000 | 10,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Bool,   11,   18,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 22, QMetaType::Bool,   23,   24,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::QPoint,    2,
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

void ccDBRoot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ccDBRoot *_t = static_cast<ccDBRoot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionChanged(); break;
        case 1: _t->dbIsEmpty(); break;
        case 2: _t->dbIsNotEmptyAnymore(); break;
        case 3: _t->changeSelection((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 4: _t->reflectObjectPropChange((*reinterpret_cast< ccHObject*(*)>(_a[1]))); break;
        case 5: _t->redrawCCObject((*reinterpret_cast< ccHObject*(*)>(_a[1]))); break;
        case 6: _t->redrawCCObjectAndChildren((*reinterpret_cast< ccHObject*(*)>(_a[1]))); break;
        case 7: _t->updateCCObject((*reinterpret_cast< ccHObject*(*)>(_a[1]))); break;
        case 8: _t->deleteSelectedEntities(); break;
        case 9: _t->selectEntity((*reinterpret_cast< ccHObject*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->selectEntity((*reinterpret_cast< ccHObject*(*)>(_a[1]))); break;
        case 11: _t->selectEntities((*reinterpret_cast< std::unordered_set<int>(*)>(_a[1]))); break;
        case 12: _t->selectEntities((*reinterpret_cast< const ccHObject::Container(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->selectEntities((*reinterpret_cast< const ccHObject::Container(*)>(_a[1]))); break;
        case 14: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 15: _t->expandBranch(); break;
        case 16: _t->collapseBranch(); break;
        case 17: _t->gatherRecursiveInformation(); break;
        case 18: _t->sortChildrenAZ(); break;
        case 19: _t->sortChildrenZA(); break;
        case 20: _t->sortChildrenType(); break;
        case 21: _t->selectByTypeAndName(); break;
        case 22: _t->toggleSelectedEntities(); break;
        case 23: _t->toggleSelectedEntitiesVisibility(); break;
        case 24: _t->toggleSelectedEntitiesColor(); break;
        case 25: _t->toggleSelectedEntitiesNormals(); break;
        case 26: _t->toggleSelectedEntitiesSF(); break;
        case 27: _t->toggleSelectedEntitiesMat(); break;
        case 28: _t->toggleSelectedEntities3DName(); break;
        case 29: _t->addEmptyGroup(); break;
        case 30: _t->alignCameraWithEntityDirect(); break;
        case 31: _t->alignCameraWithEntityIndirect(); break;
        case 32: _t->enableBubbleViewMode(); break;
        case 33: _t->editLabelScalarValue(); break;
        case 34: _t->editAttribute(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ccDBRoot::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ccDBRoot::selectionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ccDBRoot::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ccDBRoot::dbIsEmpty)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ccDBRoot::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ccDBRoot::dbIsNotEmptyAnymore)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ccDBRoot::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_ccDBRoot.data,
      qt_meta_data_ccDBRoot,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ccDBRoot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccDBRoot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ccDBRoot.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int ccDBRoot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void ccDBRoot::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ccDBRoot::dbIsEmpty()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ccDBRoot::dbIsNotEmptyAnymore()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
