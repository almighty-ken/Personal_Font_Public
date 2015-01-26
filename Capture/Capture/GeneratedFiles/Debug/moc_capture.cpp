/****************************************************************************
** Meta object code from reading C++ file 'capture.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../capture.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Capture_t {
    QByteArrayData data[10];
    char stringdata[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Capture_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Capture_t qt_meta_stringdata_Capture = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 5),
QT_MOC_LITERAL(2, 14, 0),
QT_MOC_LITERAL(3, 15, 5),
QT_MOC_LITERAL(4, 21, 13),
QT_MOC_LITERAL(5, 35, 5),
QT_MOC_LITERAL(6, 41, 4),
QT_MOC_LITERAL(7, 46, 10),
QT_MOC_LITERAL(8, 57, 13),
QT_MOC_LITERAL(9, 71, 8)
    },
    "Capture\0slot1\0\0slot2\0result_output\0"
    "again\0back\0Full_Scope\0Change_Thread\0"
    "make_one\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Capture[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08,
       3,    0,   55,    2, 0x08,
       4,    0,   56,    2, 0x08,
       5,    0,   57,    2, 0x08,
       6,    0,   58,    2, 0x08,
       7,    0,   59,    2, 0x08,
       8,    0,   60,    2, 0x08,
       9,    0,   61,    2, 0x08,

 // slots: parameters
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

void Capture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Capture *_t = static_cast<Capture *>(_o);
        switch (_id) {
        case 0: _t->slot1(); break;
        case 1: _t->slot2(); break;
        case 2: _t->result_output(); break;
        case 3: _t->again(); break;
        case 4: _t->back(); break;
        case 5: _t->Full_Scope(); break;
        case 6: _t->Change_Thread(); break;
        case 7: _t->make_one(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Capture::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Capture.data,
      qt_meta_data_Capture,  qt_static_metacall, 0, 0}
};


const QMetaObject *Capture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Capture::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Capture.stringdata))
        return static_cast<void*>(const_cast< Capture*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Capture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
