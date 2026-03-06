/****************************************************************************
** Meta object code from reading C++ file 'addtaskdialog.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../addtaskdialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addtaskdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13AddTaskDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto AddTaskDialog::qt_create_metaobjectdata<qt_meta_tag_ZN13AddTaskDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AddTaskDialog",
        "taskCreated",
        "",
        "title",
        "desc",
        "priority",
        "project",
        "startDate",
        "endDate",
        "dueTime",
        "endTime",
        "cancelled",
        "onCreateClicked",
        "onClose"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'taskCreated'
        QtMocHelpers::SignalData<void(const QString &, const QString &, const QString &, const QString &, const QDate &, const QDate &, const QTime &, const QTime &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 4 }, { QMetaType::QString, 5 }, { QMetaType::QString, 6 },
            { QMetaType::QDate, 7 }, { QMetaType::QDate, 8 }, { QMetaType::QTime, 9 }, { QMetaType::QTime, 10 },
        }}),
        // Signal 'cancelled'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onCreateClicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onClose'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AddTaskDialog, qt_meta_tag_ZN13AddTaskDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AddTaskDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AddTaskDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AddTaskDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13AddTaskDialogE_t>.metaTypes,
    nullptr
} };

void AddTaskDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AddTaskDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->taskCreated((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QDate>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<QDate>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QTime>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<QTime>>(_a[8]))); break;
        case 1: _t->cancelled(); break;
        case 2: _t->onCreateClicked(); break;
        case 3: _t->onClose(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AddTaskDialog::*)(const QString & , const QString & , const QString & , const QString & , const QDate & , const QDate & , const QTime & , const QTime & )>(_a, &AddTaskDialog::taskCreated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (AddTaskDialog::*)()>(_a, &AddTaskDialog::cancelled, 1))
            return;
    }
}

const QMetaObject *AddTaskDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddTaskDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AddTaskDialogE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddTaskDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddTaskDialog::taskCreated(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QDate & _t5, const QDate & _t6, const QTime & _t7, const QTime & _t8)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8);
}

// SIGNAL 1
void AddTaskDialog::cancelled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
