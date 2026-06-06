#ifndef TEACHERSWIDGET_H
#define TEACHERSWIDGET_H

#include <QWidget>
#include <QString>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QList>

#include "models/Teacher.h"

class TeachersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TeachersWidget(QWidget *parent = nullptr);

private:
    void setupUI();
    void loadTeachers();
    void clearForm();

    QString generateTeacherId();

private:

    // ================= FORM INPUTS =================

    QLineEdit *firstNameInput;
    QLineEdit *lastNameInput;
    QLineEdit *genderInput;
    QLineEdit *dobInput;

    QLineEdit *subjectInput;
    QLineEdit *qualificationInput;

    QLineEdit *phoneInput;
    QLineEdit *emailInput;
    QLineEdit *addressInput;

    // ================= BUTTONS =================

    QPushButton *registerBtn;
    QPushButton *updateBtn;
    QPushButton *suspendBtn;
    QPushButton *activateBtn;
    QPushButton *inactiveBtn;
    QPushButton *clearBtn;

    // ================= TABLE =================

    QTableWidget *teacherTable;

    // ================= DATA =================

    int selectedTeacherId = -1;

    QList<Teacher> teachersCache;
};

#endif // TEACHERSWIDGET_H