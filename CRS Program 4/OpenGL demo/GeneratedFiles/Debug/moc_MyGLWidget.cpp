/****************************************************************************
** Meta object code from reading C++ file 'MyGLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyGLWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyGLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGLWidget_t {
    QByteArrayData data[16];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyGLWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyGLWidget_t qt_meta_stringdata_MyGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 2),
QT_MOC_LITERAL(2, 14, 0),
QT_MOC_LITERAL(3, 15, 4),
QT_MOC_LITERAL(4, 20, 4),
QT_MOC_LITERAL(5, 25, 5),
QT_MOC_LITERAL(6, 31, 6),
QT_MOC_LITERAL(7, 38, 7),
QT_MOC_LITERAL(8, 46, 4),
QT_MOC_LITERAL(9, 51, 6),
QT_MOC_LITERAL(10, 58, 7),
QT_MOC_LITERAL(11, 66, 9),
QT_MOC_LITERAL(12, 76, 10),
QT_MOC_LITERAL(13, 87, 11),
QT_MOC_LITERAL(14, 99, 10),
QT_MOC_LITERAL(15, 110, 11)
    },
    "MyGLWidget\0up\0\0down\0left\0right\0zoomIn\0"
    "zoomOut\0load\0string\0lightUp\0lightDown\0"
    "lightXPlus\0lightXMinus\0lightZPlus\0"
    "lightZMinus\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a,
       3,    0,   80,    2, 0x0a,
       4,    0,   81,    2, 0x0a,
       5,    0,   82,    2, 0x0a,
       6,    0,   83,    2, 0x0a,
       7,    0,   84,    2, 0x0a,
       8,    1,   85,    2, 0x0a,
      10,    0,   88,    2, 0x0a,
      11,    0,   89,    2, 0x0a,
      12,    0,   90,    2, 0x0a,
      13,    0,   91,    2, 0x0a,
      14,    0,   92,    2, 0x0a,
      15,    0,   93,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGLWidget *_t = static_cast<MyGLWidget *>(_o);
        switch (_id) {
        case 0: _t->up(); break;
        case 1: _t->down(); break;
        case 2: _t->left(); break;
        case 3: _t->right(); break;
        case 4: _t->zoomIn(); break;
        case 5: _t->zoomOut(); break;
        case 6: _t->load((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 7: _t->lightUp(); break;
        case 8: _t->lightDown(); break;
        case 9: _t->lightXPlus(); break;
        case 10: _t->lightXMinus(); break;
        case 11: _t->lightZPlus(); break;
        case 12: _t->lightZMinus(); break;
        default: ;
        }
    }
}

const QMetaObject MyGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyGLWidget.data,
      qt_meta_data_MyGLWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget.stringdata))
        return static_cast<void*>(const_cast< MyGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
