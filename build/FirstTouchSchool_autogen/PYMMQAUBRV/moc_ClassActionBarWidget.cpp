/****************************************************************************
** Meta object code from reading C++ file 'ClassActionBarWidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/widgets/class/ClassActionBarWidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClassActionBarWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
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
struct qt_meta_tag_ZN20ClassActionBarWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto ClassActionBarWidget::qt_create_metaobjectdata<qt_meta_tag_ZN20ClassActionBarWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ClassActionBarWidget",
        "promoteClicked",
        "",
        "repeatClicked",
        "transferClicked",
        "expelClicked",
        "graduateClicked",
        "printClicked",
        "exportClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'promoteClicked'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'repeatClicked'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'transferClicked'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'expelClicked'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'graduateClicked'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'printClicked'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'exportClicked'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ClassActionBarWidget, qt_meta_tag_ZN20ClassActionBarWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ClassActionBarWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20ClassActionBarWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20ClassActionBarWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20ClassActionBarWidgetE_t>.metaTypes,
    nullptr
} };

void ClassActionBarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ClassActionBarWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->promoteClicked(); break;
        case 1: _t->repeatClicked(); break;
        case 2: _t->transferClicked(); break;
        case 3: _t->expelClicked(); break;
        case 4: _t->graduateClicked(); break;
        case 5: _t->printClicked(); break;
        case 6: _t->exportClicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ClassActionBarWidget::*)()>(_a, &ClassActionBarWidget::promoteClicked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClassActionBarWidget::*)()>(_a, &ClassActionBarWidget::repeatClicked, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClassActionBarWidget::*)()>(_a, &ClassActionBarWidget::transferClicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClassActionBarWidget::*)()>(_a, &ClassActionBarWidget::expelClicked, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClassActionBarWidget::*)()>(_a, &ClassActionBarWidget::graduateClicked, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClassActionBarWidget::*)()>(_a, &ClassActionBarWidget::printClicked, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClassActionBarWidget::*)()>(_a, &ClassActionBarWidget::exportClicked, 6))
            return;
    }
}

const QMetaObject *ClassActionBarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClassActionBarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20ClassActionBarWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClassActionBarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ClassActionBarWidget::promoteClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ClassActionBarWidget::repeatClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ClassActionBarWidget::transferClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ClassActionBarWidget::expelClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ClassActionBarWidget::graduateClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ClassActionBarWidget::printClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ClassActionBarWidget::exportClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
