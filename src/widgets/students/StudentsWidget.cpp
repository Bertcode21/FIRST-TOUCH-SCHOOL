#include "StudentsWidget.h"
#include "repositories/StudentRepository.h"
#include "models/Student.h"

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

StudentsWidget::StudentsWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    loadStudents();
}

// ===================== UI SETUP =====================
void StudentsWidget::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *title = new QLabel("Student Management");
    title->setStyleSheet("font-size:22px;font-weight:bold;");
    mainLayout->addWidget(title);

    // ================= FORM =================
    QGridLayout *form = new QGridLayout();

    firstNameInput = new QLineEdit();
    lastNameInput = new QLineEdit();
    genderInput = new QLineEdit();
    dobInput = new QLineEdit();
    classInput = new QLineEdit();
    phoneInput = new QLineEdit();
    parentNameInput = new QLineEdit();
    parentPhoneInput = new QLineEdit();
    addressInput = new QLineEdit();

    form->addWidget(new QLabel("First Name"), 0, 0);
    form->addWidget(firstNameInput, 0, 1);

    form->addWidget(new QLabel("Last Name"), 0, 2);
    form->addWidget(lastNameInput, 0, 3);

    form->addWidget(new QLabel("Gender"), 1, 0);
    form->addWidget(genderInput, 1, 1);

    form->addWidget(new QLabel("DOB"), 1, 2);
    form->addWidget(dobInput, 1, 3);

    form->addWidget(new QLabel("Class"), 2, 0);
    form->addWidget(classInput, 2, 1);

    form->addWidget(new QLabel("Phone"), 2, 2);
    form->addWidget(phoneInput, 2, 3);

    form->addWidget(new QLabel("Parent Name"), 3, 0);
    form->addWidget(parentNameInput, 3, 1);

    form->addWidget(new QLabel("Parent Phone"), 3, 2);
    form->addWidget(parentPhoneInput, 3, 3);

    form->addWidget(new QLabel("Address"), 4, 0);
    form->addWidget(addressInput, 4, 1, 1, 3);

    mainLayout->addLayout(form);

    // ================= BUTTONS =================
    QHBoxLayout *btnLayout = new QHBoxLayout();

    registerBtn = new QPushButton("Register Student");
    updateBtn = new QPushButton("Update");
    suspendBtn = new QPushButton("Suspend");
    graduateBtn = new QPushButton("Graduate");
    activateBtn = new QPushButton("Activate");
    inactiveBtn = new QPushButton("Inactive");
    clearBtn = new QPushButton("Clear");

    btnLayout->addWidget(registerBtn);
    btnLayout->addWidget(updateBtn);
    btnLayout->addWidget(suspendBtn);
    btnLayout->addWidget(graduateBtn);
    btnLayout->addWidget(activateBtn);
    btnLayout->addWidget(inactiveBtn);
    btnLayout->addWidget(clearBtn);

    mainLayout->addLayout(btnLayout);

    // ================= TABLE =================
    studentTable = new QTableWidget();
    studentTable->setColumnCount(6);

    studentTable->setHorizontalHeaderLabels(
        {"ID", "Student ID", "Name", "Class", "Status", "Phone"}
    );

    mainLayout->addWidget(studentTable);

    // ================= REGISTER =================
    connect(registerBtn, &QPushButton::clicked, this, [=]()
    {
        Student s;

        s.studentId = generateStudentId();
        s.firstName = firstNameInput->text();
        s.lastName = lastNameInput->text();
        s.gender = genderInput->text();
        s.dateOfBirth = dobInput->text();
        s.className = classInput->text();
        s.phone = phoneInput->text();
        s.parentName = parentNameInput->text();
        s.parentPhone = parentPhoneInput->text();
        s.address = addressInput->text();
        s.status = "ACTIVE";

        if (StudentRepository::createStudent(s))
        {
            QMessageBox::information(this, "Success", "Student registered");
            loadStudents();
            clearForm();
        }
        else
        {
            QMessageBox::warning(this, "Error", "Failed to register student");
        }
    });

    // ================= TABLE SELECT =================
    connect(studentTable, &QTableWidget::cellClicked,
            this, [=](int row, int)
    {
        if (!studentTable->item(row, 0)) return;

        selectedStudentId =
            studentTable->item(row, 0)->text().toInt();

        firstNameInput->setText(
            studentTable->item(row, 2)->text()
        );
    });



//// TO CLEAR THE FORM
connect(clearBtn,
        &QPushButton::clicked,
        this,
        &StudentsWidget::clearForm);

//////  TO SUSPEND A STUDENT

connect(suspendBtn, &QPushButton::clicked, this, [=]()
{
    if(selectedStudentId < 0)
    {
        QMessageBox::warning(
            this,
            "Warning",
            "Please select a student"
        );
        return;
    }

    if(StudentRepository::suspendStudent(selectedStudentId))
    {
        QMessageBox::information(
            this,
            "Success",
            "Student suspended"
        );

        loadStudents();
    }
});

//// TO GRADUATE A STUDENT
connect(graduateBtn, &QPushButton::clicked, this, [=]()
{
    if(selectedStudentId < 0)
    {
        QMessageBox::warning(
            this,
            "Warning",
            "Please select a student"
        );
        return;
    }

    if(StudentRepository::graduateStudent(selectedStudentId))
    {
        QMessageBox::information(
            this,
            "Success",
            "Student graduated"
        );

        loadStudents();
    }
    else{
        QMessageBox::warning(
            this,
            "Error",
            "Failed to graduate student"
        );
    }
});

/// TO ACTIVATE A STUDENT
connect(activateBtn, &QPushButton::clicked, this, [=] (){
   if(selectedStudentId < 0)
    {
        QMessageBox::warning(
            this,
            "Warning",
            "Please select a student"
        );
        return;
    }
    if(StudentRepository::activateStudent(selectedStudentId))
    {
        QMessageBox::information(
            this,
            "Success",
            "Student activated"
        );

        loadStudents();
    }
    else{
        QMessageBox::warning(
            this,
            "Error",
            "Failed to activate student"
        );
    }
});

//// INACTIVE A STUDENT
connect(inactiveBtn, &QPushButton::clicked, this, [=]()
{
    if(selectedStudentId < 0)
    {
        QMessageBox::warning(
            this,
            "Warning",
            "Please select a student"
        );
        return;
    }

    if(StudentRepository::setInactive(selectedStudentId))
    {
        QMessageBox::information(
            this,
            "Success",
            "Student marked inactive"
        );

        loadStudents();
    }
});


}





// ===================== LOAD STUDENTS =====================
void StudentsWidget::loadStudents()
{
    auto list = StudentRepository::getAllStudents();

    studentTable->setRowCount(0);

    for (int i = 0; i < list.size(); i++)
    {
        studentTable->insertRow(i);

        studentTable->setItem(i, 0,
            new QTableWidgetItem(QString::number(list[i].id)));

        studentTable->setItem(i, 1,
            new QTableWidgetItem(list[i].studentId));

        studentTable->setItem(i, 2,
            new QTableWidgetItem(
                list[i].firstName + " " + list[i].lastName
            )
        );

        studentTable->setItem(i, 3,
            new QTableWidgetItem(list[i].className));

        studentTable->setItem(i, 4,
            new QTableWidgetItem(list[i].status));

        studentTable->setItem(i, 5,
            new QTableWidgetItem(list[i].phone));
    }
}

// ===================== CLEAR FORM =====================
void StudentsWidget::clearForm()
{
    firstNameInput->clear();
    lastNameInput->clear();
    genderInput->clear();
    dobInput->clear();
    classInput->clear();
    phoneInput->clear();
    parentNameInput->clear();
    parentPhoneInput->clear();
    addressInput->clear();

    selectedStudentId = -1;
}

// ===================== STUDENT ID GENERATOR =====================
QString StudentsWidget::generateStudentId()
{
    int count = StudentRepository::getStudentCount() + 1;

    return QString("FTS-%1-%2")
        .arg(QDate::currentDate().year())
        .arg(count, 4, 10, QChar('0'));
}


// ===================== SHOW STUDENTS BY CLASS =====================

void StudentsWidget::showClassStudents(QString className)
{
    qDebug()
    << "[STUDENTS WIDGET]"
    << "Loading class:"
    << className;


    QList<Student> students =
        StudentRepository::getStudentsByClass(
            className
        );


    studentTable->setRowCount(0);


    int row = 0;


    for(const Student &student : students)
    {

        studentTable->insertRow(row);


        studentTable->setItem(
            row,
            0,
            new QTableWidgetItem(
                QString::number(student.id)
            )
        );


        studentTable->setItem(
            row,
            1,
            new QTableWidgetItem(
                student.studentId
            )
        );


        studentTable->setItem(
            row,
            2,
            new QTableWidgetItem(
                student.firstName
                + " "
                + student.lastName
            )
        );


        studentTable->setItem(
            row,
            3,
            new QTableWidgetItem(
                student.className
            )
        );


        studentTable->setItem(
            row,
            4,
            new QTableWidgetItem(
                student.status
            )
        );


        studentTable->setItem(
            row,
            5,
            new QTableWidgetItem(
                student.phone
            )
        );


        row++;

    }


    qDebug()
    << "[STUDENTS WIDGET]"
    << "Students found:"
    << students.size();

}