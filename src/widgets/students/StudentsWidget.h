#ifndef STUDENTSWIDGET_H
#define STUDENTSWIDGET_H

#include <QWidget>
#include <QString>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QList>

#include "models/Student.h"
#include "widgets/class/ClassWidget.h"


class StudentsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StudentsWidget(QWidget *parent = nullptr);

private:
    void setupUI();
    void loadStudents();
    void clearForm();

    QString generateStudentId();

private:

    // ================= FORM INPUTS =================
    QLineEdit *firstNameInput;
    QLineEdit *lastNameInput;
    QLineEdit *genderInput;
    QLineEdit *dobInput;
    QLineEdit *classInput;
    QLineEdit *phoneInput;
    QLineEdit *parentNameInput;
    QLineEdit *parentPhoneInput;
    QLineEdit *addressInput;

    // ================= BUTTONS =================
    QPushButton *registerBtn;
    QPushButton *updateBtn;
    QPushButton *suspendBtn;
    QPushButton *graduateBtn;
    QPushButton *activateBtn;
    QPushButton *inactiveBtn;
    QPushButton *clearBtn;

    // ================= TABLE =================
    QTableWidget *studentTable;

    // ================= DATA =================
    int selectedStudentId = -1;

    // Holds all loaded students
    QList<Student> studentsCache;


    public slots:

    void showClassStudents(QString className);
};

#endif // STUDENTSWIDGET_H