/****************************************************************************
** Meta object code from reading C++ file 'generalwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "generalwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'generalwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HealingRule_t {
    QByteArrayData data[3];
    char stringdata[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HealingRule_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HealingRule_t qt_meta_stringdata_HealingRule = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HealingRule"
QT_MOC_LITERAL(1, 12, 6), // "onSave"
QT_MOC_LITERAL(2, 19, 0) // ""

    },
    "HealingRule\0onSave\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HealingRule[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void HealingRule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HealingRule *_t = static_cast<HealingRule *>(_o);
        switch (_id) {
        case 0: _t->onSave(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HealingRule::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HealingRule.data,
      qt_meta_data_HealingRule,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HealingRule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HealingRule::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HealingRule.stringdata))
        return static_cast<void*>(const_cast< HealingRule*>(this));
    return QWidget::qt_metacast(_clname);
}

int HealingRule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_HealerTab_t {
    QByteArrayData data[4];
    char stringdata[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HealerTab_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HealerTab_t qt_meta_stringdata_HealerTab = {
    {
QT_MOC_LITERAL(0, 0, 9), // "HealerTab"
QT_MOC_LITERAL(1, 10, 8), // "onDelete"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 16) // "onRequestNewRule"

    },
    "HealerTab\0onDelete\0\0onRequestNewRule"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HealerTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HealerTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HealerTab *_t = static_cast<HealerTab *>(_o);
        switch (_id) {
        case 0: _t->onDelete(); break;
        case 1: _t->onRequestNewRule(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HealerTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HealerTab.data,
      qt_meta_data_HealerTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HealerTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HealerTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HealerTab.stringdata))
        return static_cast<void*>(const_cast< HealerTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int HealerTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_GeneralWindow_t {
    QByteArrayData data[1];
    char stringdata[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneralWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneralWindow_t qt_meta_stringdata_GeneralWindow = {
    {
QT_MOC_LITERAL(0, 0, 13) // "GeneralWindow"

    },
    "GeneralWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralWindow[] = {

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

void GeneralWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject GeneralWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GeneralWindow.data,
      qt_meta_data_GeneralWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GeneralWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneralWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralWindow.stringdata))
        return static_cast<void*>(const_cast< GeneralWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int GeneralWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
