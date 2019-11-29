/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../promotion/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[364];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_ajouterPromo_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 25), // "on_supprimerPromo_clicked"
QT_MOC_LITERAL(4, 62, 28), // "on_modifierpromotion_clicked"
QT_MOC_LITERAL(5, 91, 20), // "on_recherche_clicked"
QT_MOC_LITERAL(6, 112, 19), // "on_tri_prix_clicked"
QT_MOC_LITERAL(7, 132, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(8, 156, 19), // "on_imprimer_clicked"
QT_MOC_LITERAL(9, 176, 22), // "on_Stat_currentChanged"
QT_MOC_LITERAL(10, 199, 5), // "index"
QT_MOC_LITERAL(11, 205, 23), // "on_ajouterPub_2_clicked"
QT_MOC_LITERAL(12, 229, 23), // "on_lineEdit_textChanged"
QT_MOC_LITERAL(13, 253, 4), // "arg1"
QT_MOC_LITERAL(14, 258, 33), // "on_comboBox_2_currentIndexCha..."
QT_MOC_LITERAL(15, 292, 20), // "on_tri_pub_2_clicked"
QT_MOC_LITERAL(16, 313, 24), // "on_modifierpub_2_clicked"
QT_MOC_LITERAL(17, 338, 25) // "on_supprimerPub_2_clicked"

    },
    "MainWindow\0on_ajouterPromo_clicked\0\0"
    "on_supprimerPromo_clicked\0"
    "on_modifierpromotion_clicked\0"
    "on_recherche_clicked\0on_tri_prix_clicked\0"
    "on_pushButton_2_clicked\0on_imprimer_clicked\0"
    "on_Stat_currentChanged\0index\0"
    "on_ajouterPub_2_clicked\0on_lineEdit_textChanged\0"
    "arg1\0on_comboBox_2_currentIndexChanged\0"
    "on_tri_pub_2_clicked\0on_modifierpub_2_clicked\0"
    "on_supprimerPub_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    1,   91,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    1,   95,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajouterPromo_clicked(); break;
        case 1: _t->on_supprimerPromo_clicked(); break;
        case 2: _t->on_modifierpromotion_clicked(); break;
        case 3: _t->on_recherche_clicked(); break;
        case 4: _t->on_tri_prix_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_imprimer_clicked(); break;
        case 7: _t->on_Stat_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_ajouterPub_2_clicked(); break;
        case 9: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_tri_pub_2_clicked(); break;
        case 12: _t->on_modifierpub_2_clicked(); break;
        case 13: _t->on_supprimerPub_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
