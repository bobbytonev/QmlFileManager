/****************************************************************************
** Meta object code from reading C++ file 'FileManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "FileManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileManager_t {
    QByteArrayData data[20];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileManager_t qt_meta_stringdata_FileManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FileManager"
QT_MOC_LITERAL(1, 12, 12), // "filesChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "getExternalDevices"
QT_MOC_LITERAL(4, 45, 9), // "newFolder"
QT_MOC_LITERAL(5, 55, 4), // "path"
QT_MOC_LITERAL(6, 60, 10), // "deleteFile"
QT_MOC_LITERAL(7, 71, 8), // "filePath"
QT_MOC_LITERAL(8, 80, 6), // "folder"
QT_MOC_LITERAL(9, 87, 6), // "rename"
QT_MOC_LITERAL(10, 94, 8), // "fileName"
QT_MOC_LITERAL(11, 103, 8), // "copyMove"
QT_MOC_LITERAL(12, 112, 11), // "newFilePath"
QT_MOC_LITERAL(13, 124, 4), // "copy"
QT_MOC_LITERAL(14, 129, 12), // "startProgram"
QT_MOC_LITERAL(15, 142, 7), // "program"
QT_MOC_LITERAL(16, 150, 8), // "startApp"
QT_MOC_LITERAL(17, 159, 6), // "reload"
QT_MOC_LITERAL(18, 166, 5), // "regex"
QT_MOC_LITERAL(19, 172, 5) // "files"

    },
    "FileManager\0filesChanged\0\0getExternalDevices\0"
    "newFolder\0path\0deleteFile\0filePath\0"
    "folder\0rename\0fileName\0copyMove\0"
    "newFilePath\0copy\0startProgram\0program\0"
    "startApp\0reload\0regex\0files"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   90, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x02 /* Public */,
       4,    1,   61,    2, 0x02 /* Public */,
       6,    2,   64,    2, 0x02 /* Public */,
       9,    2,   69,    2, 0x02 /* Public */,
      11,    3,   74,    2, 0x02 /* Public */,
      14,    1,   81,    2, 0x02 /* Public */,
      16,    1,   84,    2, 0x02 /* Public */,
      17,    1,   87,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    7,   12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Bool, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QStringList,   18,

 // properties: name, type, flags
      19, QMetaType::QVariantList, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void FileManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filesChanged(); break;
        case 1: { QVariantList _r = _t->getExternalDevices();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->newFolder((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->deleteFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->rename((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->copyMove((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->startProgram((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { bool _r = _t->startApp((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->reload((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileManager::filesChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FileManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->files(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FileManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFiles(*reinterpret_cast< QVariantList*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject FileManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FileManager.data,
    qt_meta_data_FileManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FileManager::filesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
