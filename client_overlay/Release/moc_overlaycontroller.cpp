/****************************************************************************
** Meta object code from reading C++ file 'overlaycontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/overlaycontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'overlaycontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_walkinplace__OverlayController_t {
    QByteArrayData data[13];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_walkinplace__OverlayController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_walkinplace__OverlayController_t qt_meta_stringdata_walkinplace__OverlayController = {
    {
QT_MOC_LITERAL(0, 0, 30), // "walkinplace::OverlayController"
QT_MOC_LITERAL(1, 31, 19), // "keyBoardInputSignal"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 5), // "input"
QT_MOC_LITERAL(4, 58, 9), // "userValue"
QT_MOC_LITERAL(5, 68, 13), // "renderOverlay"
QT_MOC_LITERAL(6, 82, 15), // "OnRenderRequest"
QT_MOC_LITERAL(7, 98, 19), // "OnTimeoutPumpEvents"
QT_MOC_LITERAL(8, 118, 12), // "showKeyboard"
QT_MOC_LITERAL(9, 131, 12), // "existingText"
QT_MOC_LITERAL(10, 144, 16), // "getVersionString"
QT_MOC_LITERAL(11, 161, 19), // "getVRRuntimePathUrl"
QT_MOC_LITERAL(12, 181, 11) // "desktopMode"

    },
    "walkinplace::OverlayController\0"
    "keyBoardInputSignal\0\0input\0userValue\0"
    "renderOverlay\0OnRenderRequest\0"
    "OnTimeoutPumpEvents\0showKeyboard\0"
    "existingText\0getVersionString\0"
    "getVRRuntimePathUrl\0desktopMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_walkinplace__OverlayController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       1,    1,   64,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    2,   70,    2, 0x0a /* Public */,
       8,    1,   75,    2, 0x2a /* Public | MethodCloned */,

 // methods: name, argc, parameters, tag, flags
      10,    0,   78,    2, 0x02 /* Public */,
      11,    0,   79,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::ULong,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::ULong,    9,    4,
    QMetaType::Void, QMetaType::QString,    9,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QUrl,

 // properties: name, type, flags
      12, QMetaType::Bool, 0x00095001,

       0        // eod
};

void walkinplace::OverlayController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OverlayController *_t = static_cast<OverlayController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->keyBoardInputSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 1: _t->keyBoardInputSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->renderOverlay(); break;
        case 3: _t->OnRenderRequest(); break;
        case 4: _t->OnTimeoutPumpEvents(); break;
        case 5: _t->showKeyboard((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 6: _t->showKeyboard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { QString _r = _t->getVersionString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QUrl _r = _t->getVRRuntimePathUrl();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OverlayController::*_t)(QString , unsigned long );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OverlayController::keyBoardInputSignal)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        OverlayController *_t = static_cast<OverlayController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isDesktopMode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject walkinplace::OverlayController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_walkinplace__OverlayController.data,
      qt_meta_data_walkinplace__OverlayController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *walkinplace::OverlayController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *walkinplace::OverlayController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_walkinplace__OverlayController.stringdata0))
        return static_cast<void*>(const_cast< OverlayController*>(this));
    return QObject::qt_metacast(_clname);
}

int walkinplace::OverlayController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void walkinplace::OverlayController::keyBoardInputSignal(QString _t1, unsigned long _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
