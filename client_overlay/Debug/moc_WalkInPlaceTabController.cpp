/****************************************************************************
** Meta object code from reading C++ file 'WalkInPlaceTabController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/tabcontrollers/WalkInPlaceTabController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WalkInPlaceTabController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_walkinplace__WalkInPlaceTabController_t {
    QByteArrayData data[83];
    char stringdata0[1237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_walkinplace__WalkInPlaceTabController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_walkinplace__WalkInPlaceTabController_t qt_meta_stringdata_walkinplace__WalkInPlaceTabController = {
    {
QT_MOC_LITERAL(0, 0, 37), // "walkinplace::WalkInPlaceTabCo..."
QT_MOC_LITERAL(1, 38, 18), // "deviceCountChanged"
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 11), // "deviceCount"
QT_MOC_LITERAL(4, 70, 17), // "deviceInfoChanged"
QT_MOC_LITERAL(5, 88, 5), // "index"
QT_MOC_LITERAL(6, 94, 26), // "walkInPlaceProfilesChanged"
QT_MOC_LITERAL(7, 121, 19), // "enableStepDetection"
QT_MOC_LITERAL(8, 141, 6), // "enable"
QT_MOC_LITERAL(9, 148, 10), // "enableBeta"
QT_MOC_LITERAL(10, 159, 11), // "setStepTime"
QT_MOC_LITERAL(11, 171, 5), // "value"
QT_MOC_LITERAL(12, 177, 15), // "setHMDThreshold"
QT_MOC_LITERAL(13, 193, 2), // "xz"
QT_MOC_LITERAL(14, 196, 1), // "y"
QT_MOC_LITERAL(15, 198, 17), // "setAccuracyButton"
QT_MOC_LITERAL(16, 216, 8), // "buttonId"
QT_MOC_LITERAL(17, 225, 25), // "setAccuracyButtonAsToggle"
QT_MOC_LITERAL(18, 251, 3), // "val"
QT_MOC_LITERAL(19, 255, 21), // "setAccuracyButtonFlip"
QT_MOC_LITERAL(20, 277, 20), // "setHandWalkThreshold"
QT_MOC_LITERAL(21, 298, 13), // "walkThreshold"
QT_MOC_LITERAL(22, 312, 19), // "setHandJogThreshold"
QT_MOC_LITERAL(23, 332, 12), // "jogThreshold"
QT_MOC_LITERAL(24, 345, 19), // "setHandRunThreshold"
QT_MOC_LITERAL(25, 365, 12), // "runThreshold"
QT_MOC_LITERAL(26, 378, 12), // "setWalkTouch"
QT_MOC_LITERAL(27, 391, 11), // "setJogTouch"
QT_MOC_LITERAL(28, 403, 11), // "setRunTouch"
QT_MOC_LITERAL(29, 415, 15), // "setGameStepType"
QT_MOC_LITERAL(30, 431, 8), // "gameType"
QT_MOC_LITERAL(31, 440, 16), // "setControlSelect"
QT_MOC_LITERAL(32, 457, 7), // "control"
QT_MOC_LITERAL(33, 465, 19), // "applyStepPoseDetect"
QT_MOC_LITERAL(34, 485, 12), // "isTakingStep"
QT_MOC_LITERAL(35, 498, 17), // "vr::HmdVector3d_t"
QT_MOC_LITERAL(36, 516, 3), // "vel"
QT_MOC_LITERAL(37, 520, 9), // "threshold"
QT_MOC_LITERAL(38, 530, 4), // "roll"
QT_MOC_LITERAL(39, 535, 5), // "pitch"
QT_MOC_LITERAL(40, 541, 13), // "isShakingHead"
QT_MOC_LITERAL(41, 555, 16), // "isStepingInPlace"
QT_MOC_LITERAL(42, 572, 6), // "float*"
QT_MOC_LITERAL(43, 579, 3), // "pos"
QT_MOC_LITERAL(44, 583, 13), // "isJoggingStep"
QT_MOC_LITERAL(45, 597, 13), // "isRunningStep"
QT_MOC_LITERAL(46, 611, 25), // "updateAccuracyButtonState"
QT_MOC_LITERAL(47, 637, 8), // "uint32_t"
QT_MOC_LITERAL(48, 646, 8), // "deviceId"
QT_MOC_LITERAL(49, 655, 15), // "firstController"
QT_MOC_LITERAL(50, 671, 21), // "addWalkInPlaceProfile"
QT_MOC_LITERAL(51, 693, 4), // "name"
QT_MOC_LITERAL(52, 698, 23), // "applyWalkInPlaceProfile"
QT_MOC_LITERAL(53, 722, 24), // "deleteWalkInPlaceProfile"
QT_MOC_LITERAL(54, 747, 14), // "getDeviceCount"
QT_MOC_LITERAL(55, 762, 15), // "getDeviceSerial"
QT_MOC_LITERAL(56, 778, 11), // "getDeviceId"
QT_MOC_LITERAL(57, 790, 14), // "getDeviceClass"
QT_MOC_LITERAL(58, 805, 14), // "getDeviceState"
QT_MOC_LITERAL(59, 820, 13), // "getDeviceMode"
QT_MOC_LITERAL(60, 834, 11), // "getStepTime"
QT_MOC_LITERAL(61, 846, 11), // "getGameType"
QT_MOC_LITERAL(62, 858, 16), // "getControlSelect"
QT_MOC_LITERAL(63, 875, 17), // "getAccuracyButton"
QT_MOC_LITERAL(64, 893, 15), // "getHMDPitchDown"
QT_MOC_LITERAL(65, 909, 13), // "getHMDPitchUp"
QT_MOC_LITERAL(66, 923, 17), // "getHMDXZThreshold"
QT_MOC_LITERAL(67, 941, 16), // "getHMDYThreshold"
QT_MOC_LITERAL(68, 958, 20), // "getHandWalkThreshold"
QT_MOC_LITERAL(69, 979, 19), // "getHandJogThreshold"
QT_MOC_LITERAL(70, 999, 19), // "getHandRunThreshold"
QT_MOC_LITERAL(71, 1019, 12), // "getWalkTouch"
QT_MOC_LITERAL(72, 1032, 11), // "getJogTouch"
QT_MOC_LITERAL(73, 1044, 11), // "getRunTouch"
QT_MOC_LITERAL(74, 1056, 25), // "getAccuracyButtonIsToggle"
QT_MOC_LITERAL(75, 1082, 21), // "getAccuracyButtonFlip"
QT_MOC_LITERAL(76, 1104, 22), // "isStepDetectionEnabled"
QT_MOC_LITERAL(77, 1127, 14), // "isStepDetected"
QT_MOC_LITERAL(78, 1142, 13), // "getGraphPoses"
QT_MOC_LITERAL(79, 1156, 12), // "QList<qreal>"
QT_MOC_LITERAL(80, 1169, 14), // "setupStepGraph"
QT_MOC_LITERAL(81, 1184, 26), // "getWalkInPlaceProfileCount"
QT_MOC_LITERAL(82, 1211, 25) // "getWalkInPlaceProfileName"

    },
    "walkinplace::WalkInPlaceTabController\0"
    "deviceCountChanged\0\0deviceCount\0"
    "deviceInfoChanged\0index\0"
    "walkInPlaceProfilesChanged\0"
    "enableStepDetection\0enable\0enableBeta\0"
    "setStepTime\0value\0setHMDThreshold\0xz\0"
    "y\0setAccuracyButton\0buttonId\0"
    "setAccuracyButtonAsToggle\0val\0"
    "setAccuracyButtonFlip\0setHandWalkThreshold\0"
    "walkThreshold\0setHandJogThreshold\0"
    "jogThreshold\0setHandRunThreshold\0"
    "runThreshold\0setWalkTouch\0setJogTouch\0"
    "setRunTouch\0setGameStepType\0gameType\0"
    "setControlSelect\0control\0applyStepPoseDetect\0"
    "isTakingStep\0vr::HmdVector3d_t\0vel\0"
    "threshold\0roll\0pitch\0isShakingHead\0"
    "isStepingInPlace\0float*\0pos\0isJoggingStep\0"
    "isRunningStep\0updateAccuracyButtonState\0"
    "uint32_t\0deviceId\0firstController\0"
    "addWalkInPlaceProfile\0name\0"
    "applyWalkInPlaceProfile\0"
    "deleteWalkInPlaceProfile\0getDeviceCount\0"
    "getDeviceSerial\0getDeviceId\0getDeviceClass\0"
    "getDeviceState\0getDeviceMode\0getStepTime\0"
    "getGameType\0getControlSelect\0"
    "getAccuracyButton\0getHMDPitchDown\0"
    "getHMDPitchUp\0getHMDXZThreshold\0"
    "getHMDYThreshold\0getHandWalkThreshold\0"
    "getHandJogThreshold\0getHandRunThreshold\0"
    "getWalkTouch\0getJogTouch\0getRunTouch\0"
    "getAccuracyButtonIsToggle\0"
    "getAccuracyButtonFlip\0isStepDetectionEnabled\0"
    "isStepDetected\0getGraphPoses\0QList<qreal>\0"
    "setupStepGraph\0getWalkInPlaceProfileCount\0"
    "getWalkInPlaceProfileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_walkinplace__WalkInPlaceTabController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      56,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  294,    2, 0x06 /* Public */,
       4,    1,  297,    2, 0x06 /* Public */,
       6,    0,  300,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  301,    2, 0x0a /* Public */,
       9,    1,  304,    2, 0x0a /* Public */,
      10,    1,  307,    2, 0x0a /* Public */,
      12,    2,  310,    2, 0x0a /* Public */,
      15,    1,  315,    2, 0x0a /* Public */,
      17,    1,  318,    2, 0x0a /* Public */,
      19,    1,  321,    2, 0x0a /* Public */,
      20,    1,  324,    2, 0x0a /* Public */,
      22,    1,  327,    2, 0x0a /* Public */,
      24,    1,  330,    2, 0x0a /* Public */,
      26,    1,  333,    2, 0x0a /* Public */,
      27,    1,  336,    2, 0x0a /* Public */,
      28,    1,  339,    2, 0x0a /* Public */,
      29,    1,  342,    2, 0x0a /* Public */,
      31,    1,  345,    2, 0x0a /* Public */,
      33,    0,  348,    2, 0x0a /* Public */,
      34,    4,  349,    2, 0x0a /* Public */,
      40,    2,  358,    2, 0x0a /* Public */,
      41,    1,  363,    2, 0x0a /* Public */,
      44,    1,  366,    2, 0x0a /* Public */,
      45,    1,  369,    2, 0x0a /* Public */,
      46,    2,  372,    2, 0x0a /* Public */,
      50,    1,  377,    2, 0x0a /* Public */,
      52,    1,  380,    2, 0x0a /* Public */,
      53,    1,  383,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      54,    0,  386,    2, 0x02 /* Public */,
      55,    1,  387,    2, 0x02 /* Public */,
      56,    1,  390,    2, 0x02 /* Public */,
      57,    1,  393,    2, 0x02 /* Public */,
      58,    1,  396,    2, 0x02 /* Public */,
      59,    1,  399,    2, 0x02 /* Public */,
      60,    0,  402,    2, 0x02 /* Public */,
      61,    0,  403,    2, 0x02 /* Public */,
      62,    0,  404,    2, 0x02 /* Public */,
      63,    0,  405,    2, 0x02 /* Public */,
      64,    0,  406,    2, 0x02 /* Public */,
      65,    0,  407,    2, 0x02 /* Public */,
      66,    0,  408,    2, 0x02 /* Public */,
      67,    0,  409,    2, 0x02 /* Public */,
      68,    0,  410,    2, 0x02 /* Public */,
      69,    0,  411,    2, 0x02 /* Public */,
      70,    0,  412,    2, 0x02 /* Public */,
      71,    0,  413,    2, 0x02 /* Public */,
      72,    0,  414,    2, 0x02 /* Public */,
      73,    0,  415,    2, 0x02 /* Public */,
      74,    0,  416,    2, 0x02 /* Public */,
      75,    0,  417,    2, 0x02 /* Public */,
      76,    0,  418,    2, 0x02 /* Public */,
      77,    0,  419,    2, 0x02 /* Public */,
      78,    0,  420,    2, 0x02 /* Public */,
      80,    0,  421,    2, 0x02 /* Public */,
      81,    0,  422,    2, 0x02 /* Public */,
      82,    1,  423,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   13,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Float,   21,
    QMetaType::Void, QMetaType::Float,   23,
    QMetaType::Void, QMetaType::Float,   25,
    QMetaType::Void, QMetaType::Float,   11,
    QMetaType::Void, QMetaType::Float,   11,
    QMetaType::Void, QMetaType::Float,   11,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 35, 0x80000000 | 35, QMetaType::Double, QMetaType::Double,   36,   37,   38,   39,
    QMetaType::Bool, 0x80000000 | 35, 0x80000000 | 35,   36,   37,
    QMetaType::Bool, 0x80000000 | 42,   43,
    QMetaType::Bool, 0x80000000 | 42,   36,
    QMetaType::Bool, 0x80000000 | 42,   36,
    QMetaType::Void, 0x80000000 | 47, QMetaType::Bool,   48,   49,
    QMetaType::Void, QMetaType::QString,   51,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, QMetaType::UInt,    5,

 // methods: parameters
    QMetaType::UInt,
    QMetaType::QString, QMetaType::UInt,    5,
    QMetaType::UInt, QMetaType::UInt,    5,
    QMetaType::Int, QMetaType::UInt,    5,
    QMetaType::Int, QMetaType::UInt,    5,
    QMetaType::Int, QMetaType::UInt,    5,
    QMetaType::Double,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    0x80000000 | 79,
    QMetaType::Void,
    QMetaType::UInt,
    QMetaType::QString, QMetaType::UInt,    5,

       0        // eod
};

void walkinplace::WalkInPlaceTabController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WalkInPlaceTabController *_t = static_cast<WalkInPlaceTabController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deviceCountChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->deviceInfoChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->walkInPlaceProfilesChanged(); break;
        case 3: _t->enableStepDetection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->enableBeta((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setStepTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setHMDThreshold((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 7: _t->setAccuracyButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setAccuracyButtonAsToggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setAccuracyButtonFlip((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setHandWalkThreshold((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->setHandJogThreshold((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: _t->setHandRunThreshold((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 13: _t->setWalkTouch((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 14: _t->setJogTouch((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 15: _t->setRunTouch((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 16: _t->setGameStepType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->setControlSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->applyStepPoseDetect(); break;
        case 19: { bool _r = _t->isTakingStep((*reinterpret_cast< vr::HmdVector3d_t(*)>(_a[1])),(*reinterpret_cast< vr::HmdVector3d_t(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 20: { bool _r = _t->isShakingHead((*reinterpret_cast< vr::HmdVector3d_t(*)>(_a[1])),(*reinterpret_cast< vr::HmdVector3d_t(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 21: { bool _r = _t->isStepingInPlace((*reinterpret_cast< float*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: { bool _r = _t->isJoggingStep((*reinterpret_cast< float*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 23: { bool _r = _t->isRunningStep((*reinterpret_cast< float*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: _t->updateAccuracyButtonState((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 25: _t->addWalkInPlaceProfile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->applyWalkInPlaceProfile((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 27: _t->deleteWalkInPlaceProfile((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 28: { uint _r = _t->getDeviceCount();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 29: { QString _r = _t->getDeviceSerial((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 30: { uint _r = _t->getDeviceId((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 31: { int _r = _t->getDeviceClass((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 32: { int _r = _t->getDeviceState((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 33: { int _r = _t->getDeviceMode((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 34: { double _r = _t->getStepTime();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 35: { int _r = _t->getGameType();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 36: { int _r = _t->getControlSelect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 37: { int _r = _t->getAccuracyButton();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 38: { int _r = _t->getHMDPitchDown();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 39: { int _r = _t->getHMDPitchUp();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 40: { float _r = _t->getHMDXZThreshold();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 41: { float _r = _t->getHMDYThreshold();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 42: { float _r = _t->getHandWalkThreshold();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 43: { float _r = _t->getHandJogThreshold();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 44: { float _r = _t->getHandRunThreshold();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 45: { float _r = _t->getWalkTouch();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 46: { float _r = _t->getJogTouch();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 47: { float _r = _t->getRunTouch();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 48: { bool _r = _t->getAccuracyButtonIsToggle();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 49: { bool _r = _t->getAccuracyButtonFlip();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 50: { bool _r = _t->isStepDetectionEnabled();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 51: { bool _r = _t->isStepDetected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 52: { QList<qreal> _r = _t->getGraphPoses();
            if (_a[0]) *reinterpret_cast< QList<qreal>*>(_a[0]) = _r; }  break;
        case 53: _t->setupStepGraph(); break;
        case 54: { uint _r = _t->getWalkInPlaceProfileCount();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 55: { QString _r = _t->getWalkInPlaceProfileName((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WalkInPlaceTabController::*_t)(unsigned  );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WalkInPlaceTabController::deviceCountChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WalkInPlaceTabController::*_t)(unsigned  );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WalkInPlaceTabController::deviceInfoChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WalkInPlaceTabController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WalkInPlaceTabController::walkInPlaceProfilesChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject walkinplace::WalkInPlaceTabController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_walkinplace__WalkInPlaceTabController.data,
      qt_meta_data_walkinplace__WalkInPlaceTabController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *walkinplace::WalkInPlaceTabController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *walkinplace::WalkInPlaceTabController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_walkinplace__WalkInPlaceTabController.stringdata0))
        return static_cast<void*>(const_cast< WalkInPlaceTabController*>(this));
    return QObject::qt_metacast(_clname);
}

int walkinplace::WalkInPlaceTabController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 56)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 56;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 56)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 56;
    }
    return _id;
}

// SIGNAL 0
void walkinplace::WalkInPlaceTabController::deviceCountChanged(unsigned  _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void walkinplace::WalkInPlaceTabController::deviceInfoChanged(unsigned  _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void walkinplace::WalkInPlaceTabController::walkInPlaceProfilesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
