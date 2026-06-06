#include "TeachersWidget.h"
#include "repositories/TeacherRepository.h"
#include "models/Teacher.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDate>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>

TeachersWidget::TeachersWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    loadTeachers();
}

// ===================== UI SETUP =====================

void TeachersWidget::setupUI()
{
    QVBoxLayout *mainLayout =
        new QVBoxLayout(this);

    QLabel *title =
        new QLabel("Teacher Management");

    title->setStyleSheet(
        "font-size:22px;"
        "font-weight:bold;"
    );

    mainLayout->addWidget(title);

    // ================= FORM =================

    QGridLayout *form =
        new QGridLayout();

    firstNameInput = new QLineEdit();
    lastNameInput = new QLineEdit();
    genderInput = new QLineEdit();
    dobInput = new QLineEdit();

    subjectInput = new QLineEdit();
    qualificationInput = new QLineEdit();

    phoneInput = new QLineEdit();
    emailInput = new QLineEdit();
    addressInput = new QLineEdit();

    form->addWidget(new QLabel("First Name"),0,0);
    form->addWidget(firstNameInput,0,1);

    form->addWidget(new QLabel("Last Name"),0,2);
    form->addWidget(lastNameInput,0,3);

    form->addWidget(new QLabel("Gender"),1,0);
    form->addWidget(genderInput,1,1);

    form->addWidget(new QLabel("DOB"),1,2);
    form->addWidget(dobInput,1,3);

    form->addWidget(new QLabel("Subject"),2,0);
    form->addWidget(subjectInput,2,1);

    form->addWidget(new QLabel("Qualification"),2,2);
    form->addWidget(qualificationInput,2,3);

    form->addWidget(new QLabel("Phone"),3,0);
    form->addWidget(phoneInput,3,1);

    form->addWidget(new QLabel("Email"),3,2);
    form->addWidget(emailInput,3,3);

    form->addWidget(new QLabel("Address"),4,0);
    form->addWidget(addressInput,4,1,1,3);

    mainLayout->addLayout(form);

    // ================= BUTTONS =================

    QHBoxLayout *btnLayout =
        new QHBoxLayout();

    registerBtn = new QPushButton("Register Teacher");
    updateBtn = new QPushButton("Update");
    suspendBtn = new QPushButton("Suspend");
    activateBtn = new QPushButton("Activate");
    inactiveBtn = new QPushButton("Inactive");
    clearBtn = new QPushButton("Clear");

    btnLayout->addWidget(registerBtn);
    btnLayout->addWidget(updateBtn);
    btnLayout->addWidget(suspendBtn);
    btnLayout->addWidget(activateBtn);
    btnLayout->addWidget(inactiveBtn);
    btnLayout->addWidget(clearBtn);

    mainLayout->addLayout(btnLayout);

    // ================= TABLE =================

    teacherTable = new QTableWidget();

    teacherTable->setColumnCount(6);

    teacherTable->setHorizontalHeaderLabels(
    {
        "ID",
        "Teacher ID",
        "Name",
        "Subject",
        "Status",
        "Phone"
    });

    mainLayout->addWidget(teacherTable);

    // ================= REGISTER =================

    connect(registerBtn,
            &QPushButton::clicked,
            this,
            [=]()
    {
        Teacher t;

        t.teacherId = generateTeacherId();
        t.firstName = firstNameInput->text();
        t.lastName = lastNameInput->text();
        t.gender = genderInput->text();
        t.dateOfBirth = dobInput->text();

        t.subject = subjectInput->text();
        t.qualification = qualificationInput->text();

        t.phone = phoneInput->text();
        t.email = emailInput->text();
        t.address = addressInput->text();

        t.status = "ACTIVE";

        if(TeacherRepository::createTeacher(t))
        {
            QMessageBox::information(
                this,
                "Success",
                "Teacher registered successfully"
            );

            loadTeachers();
            clearForm();
        }
        else
        {
            QMessageBox::warning(
                this,
                "Error",
                "Failed to register teacher"
            );
        }
    });

    // ================= UPDATE =================

    connect(updateBtn,
            &QPushButton::clicked,
            this,
            [=]()
    {
        if(selectedTeacherId < 0)
        {
            QMessageBox::warning(
                this,
                "Warning",
                "Please select a teacher"
            );
            return;
        }

        Teacher t;

        t.id = selectedTeacherId;

        t.firstName = firstNameInput->text();
        t.lastName = lastNameInput->text();
        t.gender = genderInput->text();
        t.dateOfBirth = dobInput->text();

        t.subject = subjectInput->text();
        t.qualification = qualificationInput->text();

        t.phone = phoneInput->text();
        t.email = emailInput->text();
        t.address = addressInput->text();

        if(TeacherRepository::updateTeacher(t))
        {
            QMessageBox::information(
                this,
                "Success",
                "Teacher updated"
            );

            loadTeachers();
            clearForm();
        }
    });

    // ================= SUSPEND =================

    connect(suspendBtn,
            &QPushButton::clicked,
            this,
            [=]()
    {
        if(selectedTeacherId < 0)
            return;

        TeacherRepository::suspendTeacher(
            selectedTeacherId);

        loadTeachers();
    });

    // ================= ACTIVATE =================

    connect(activateBtn,
            &QPushButton::clicked,
            this,
            [=]()
    {
        if(selectedTeacherId < 0)
            return;

        TeacherRepository::activateTeacher(
            selectedTeacherId);

        loadTeachers();
    });

    // ================= INACTIVE =================

    connect(inactiveBtn,
            &QPushButton::clicked,
            this,
            [=]()
    {
        if(selectedTeacherId < 0)
            return;

        TeacherRepository::setInactive(
            selectedTeacherId);

        loadTeachers();
    });

    // ================= CLEAR =================

    connect(clearBtn,
            &QPushButton::clicked,
            this,
            &TeachersWidget::clearForm);

    // ================= TABLE SELECT =================

    connect(teacherTable,
            &QTableWidget::cellClicked,
            this,
            [=](int row,int)
    {
        if(!teacherTable->item(row,0))
            return;

        selectedTeacherId =
            teacherTable->item(row,0)
            ->text().toInt();
    });
}

// ================= LOAD TEACHERS =================

void TeachersWidget::loadTeachers()
{
    auto list =
        TeacherRepository::getAllTeachers();

    teacherTable->setRowCount(0);

    for(int i=0;i<list.size();i++)
    {
        teacherTable->insertRow(i);

        teacherTable->setItem(
            i,0,
            new QTableWidgetItem(
                QString::number(list[i].id)));

        teacherTable->setItem(
            i,1,
            new QTableWidgetItem(
                list[i].teacherId));

        teacherTable->setItem(
            i,2,
            new QTableWidgetItem(
                list[i].firstName
                + " "
                + list[i].lastName));

        teacherTable->setItem(
            i,3,
            new QTableWidgetItem(
                list[i].subject));

        teacherTable->setItem(
            i,4,
            new QTableWidgetItem(
                list[i].status));

        teacherTable->setItem(
            i,5,
            new QTableWidgetItem(
                list[i].phone));
    }
}

// ================= CLEAR =================

void TeachersWidget::clearForm()
{
    firstNameInput->clear();
    lastNameInput->clear();
    genderInput->clear();
    dobInput->clear();

    subjectInput->clear();
    qualificationInput->clear();

    phoneInput->clear();
    emailInput->clear();
    addressInput->clear();

    selectedTeacherId = -1;
}

// ================= ID GENERATOR =================

QString TeachersWidget::generateTeacherId()
{
    return TeacherRepository::generateTeacherId();
}