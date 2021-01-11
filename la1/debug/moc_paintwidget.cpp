/****************************************************************************
** Meta object code from reading C++ file 'paintwidget.h'
**
** Created: Tue 1. May 20:49:38 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../paintwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KeyLine[] = {

 // content:
       6,       // revision
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

static const char qt_meta_stringdata_KeyLine[] = {
    "KeyLine\0"
};

void KeyLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData KeyLine::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KeyLine::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_KeyLine,
      qt_meta_data_KeyLine, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KeyLine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KeyLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KeyLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KeyLine))
        return static_cast<void*>(const_cast< KeyLine*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int KeyLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_PaintWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x0a,
      36,   13,   12,   12, 0x0a,
      57,   13,   12,   12, 0x0a,
      78,   12,   12,   12, 0x0a,
      87,   12,   12,   12, 0x0a,
      98,   12,   12,   12, 0x0a,
     113,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PaintWidget[] = {
    "PaintWidget\0\0_text\0ChangeX(QString)\0"
    "ChangeName1(QString)\0ChangeName2(QString)\0"
    "Action()\0InputMas()\0OutputAnswer()\0"
    "Refreash()\0"
};

void PaintWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PaintWidget *_t = static_cast<PaintWidget *>(_o);
        switch (_id) {
        case 0: _t->ChangeX((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->ChangeName1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->ChangeName2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->Action(); break;
        case 4: _t->InputMas(); break;
        case 5: _t->OutputAnswer(); break;
        case 6: _t->Refreash(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PaintWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PaintWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PaintWidget,
      qt_meta_data_PaintWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PaintWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PaintWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PaintWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PaintWidget))
        return static_cast<void*>(const_cast< PaintWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PaintWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
