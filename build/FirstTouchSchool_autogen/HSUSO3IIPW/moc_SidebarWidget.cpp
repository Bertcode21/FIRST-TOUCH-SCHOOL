/****************************************************************************
** Meta object code from reading C++ file 'SidebarWidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/widgets/dashboard/SidebarWidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SidebarWidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13SidebarWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto SidebarWidget::qt_create_metaobjectdata<qt_meta_tag_ZN13SidebarWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SidebarWidget",
        "dashboardClicked",
        "",
        "studentsClicked",
        "teachersClicked",
        "academicClicked",
        "resultsClicked",
        "feesClicked",
        "classClicked",
        "financeClicked",
        "attendanceClicked",
        "settingsClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dashboardClicked'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'studentsClicked'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'teachersClicked'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'academicClicked'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'resultsClicked'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'feesClicked'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'classClicked'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'financeClicked'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'attendanceClicked'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'settingsClicked'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SidebarWidget, qt_meta_tag_ZN13SidebarWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SidebarWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SidebarWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SidebarWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13SidebarWidgetE_t>.metaTypes,
    nullptr
} };

void SidebarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SidebarWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dashboardClicked(); break;
        case 1: _t->studentsClicked(); break;
        case 2: _t->teachersClicked(); break;
        case 3: _t->academicClicked(); break;
        case 4: _t->resultsClicked(); break;
        case 5: _t->feesClicked(); break;
        case 6: _t->classClicked(); break;
        case 7: _t->financeClicked(); break;
        case 8: _t->attendanceClicked(); break;
        case 9: _t->settingsClicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SidebarWidget::*)()>(_a, &SidebarWidget::dashboardClicked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SidebarWidget::*)()>(_a, &SidebarWidget::studentsClicked, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SidebarWidget::*)()>(_a, &SidebarWidget::teachersClicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (SidebarWidget::*)()>(_a, &SidebarWidget::academicClicked, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (SidebarWidget::*)()>(_a, &SidebarWidget::resultsClicked, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (SidebarWidget::*)()>(_a, &SidebarWidget::feesClicked, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (SidebarWidget::*)()>(_a, &SidebarWidget::classClicked, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (SidebarWidget::*)()>(_a, &SidebarWidget::financeClicked, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (SidebarWidget::*)()>(_a, &SidebarWidget::attendanceClicked, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (SidebarWidget::*)()>(_a, &SidebarWidget::settingsClicked, 9))
            return;
    }
}

const QMetaObject *SidebarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SidebarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SidebarWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int SidebarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SidebarWidget::dashboardClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SidebarWidget::studentsClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SidebarWidget::teachersClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SidebarWidget::academicClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SidebarWidget::resultsClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SidebarWidget::feesClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SidebarWidget::classClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SidebarWidget::financeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SidebarWidget::attendanceClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void SidebarWidget::settingsClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
