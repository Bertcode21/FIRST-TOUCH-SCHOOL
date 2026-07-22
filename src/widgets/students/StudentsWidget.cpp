#include "StudentsWidget.h"

#include "repositories/StudentRepository.h"
#include "models/Class.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QLabel>
#include <QMessageBox>
#include <QDate>

#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

#include <QTableWidget>
#include <QTableWidgetItem>

#include <QDebug>



StudentsWidget::StudentsWidget(QWidget *parent)
    : QWidget(parent)
{

    setupUI();

    loadStudents();

}



// ======================================================
// SETUP UI
// ======================================================

void StudentsWidget::setupUI()
{

    QVBoxLayout *mainLayout =
            new QVBoxLayout(this);



    QLabel *title =
            new QLabel(
                "Student Management",
                this
            );


    title->setStyleSheet(
        "font-size:24px;"
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

    classInput = new QComboBox(this);
    classInput->setEditable(false);

    phoneInput = new QLineEdit();

    parentNameInput = new QLineEdit();

    parentPhoneInput = new QLineEdit();

    addressInput = new QLineEdit();



    form->addWidget(
        new QLabel("First Name"),
        0,
        0
    );

    form->addWidget(
        firstNameInput,
        0,
        1
    );



    form->addWidget(
        new QLabel("Last Name"),
        0,
        2
    );

    form->addWidget(
        lastNameInput,
        0,
        3
    );



    form->addWidget(
        new QLabel("Gender"),
        1,
        0
    );

    form->addWidget(
        genderInput,
        1,
        1
    );



    form->addWidget(
        new QLabel("Date Of Birth"),
        1,
        2
    );

    form->addWidget(
        dobInput,
        1,
        3
    );



    form->addWidget(
        new QLabel("Class"),
        2,
        0
    );

    form->addWidget(
        classInput,
        2,
        1
    );



    form->addWidget(
        new QLabel("Phone"),
        2,
        2
    );

    form->addWidget(
        phoneInput,
        2,
        3
    );



    form->addWidget(
        new QLabel("Parent Name"),
        3,
        0
    );

    form->addWidget(
        parentNameInput,
        3,
        1
    );



    form->addWidget(
        new QLabel("Parent Phone"),
        3,
        2
    );

    form->addWidget(
        parentPhoneInput,
        3,
        3
    );



    form->addWidget(
        new QLabel("Address"),
        4,
        0
    );

    form->addWidget(
        addressInput,
        4,
        1,
        1,
        3
    );



    mainLayout->addLayout(form);



    // ================= BUTTONS =================


    QHBoxLayout *buttonLayout =
            new QHBoxLayout();



    registerBtn =
            new QPushButton(
                "Register Student"
            );


    updateBtn =
            new QPushButton(
                "Update"
            );


    suspendBtn =
            new QPushButton(
                "Suspend"
            );


    graduateBtn =
            new QPushButton(
                "Graduate"
            );


    activateBtn =
            new QPushButton(
                "Activate"
            );


    inactiveBtn =
            new QPushButton(
                "Inactive"
            );


    clearBtn =
            new QPushButton(
                "Clear"
            );



    buttonLayout->addWidget(registerBtn);

    buttonLayout->addWidget(updateBtn);

    buttonLayout->addWidget(suspendBtn);

    buttonLayout->addWidget(graduateBtn);

    buttonLayout->addWidget(activateBtn);

    buttonLayout->addWidget(inactiveBtn);

    buttonLayout->addWidget(clearBtn);



    mainLayout->addLayout(buttonLayout);



    // ================= TABLE =================


    studentTable =
            new QTableWidget(this);



    studentTable->setColumnCount(6);



    studentTable->setHorizontalHeaderLabels(
        {
            "ID",
            "Student ID",
            "Name",
            "Class",
            "Status",
            "Phone"
        }
    );



    studentTable->setSelectionBehavior(
        QAbstractItemView::SelectRows
    );


    studentTable->setEditTriggers(
        QAbstractItemView::NoEditTriggers
    );



    mainLayout->addWidget(studentTable);



    setLayout(mainLayout);





    // ======================================================
    // REGISTER STUDENT
    // ======================================================


    connect(
        registerBtn,
        &QPushButton::clicked,
        this,
        [=]()
    {


        if(!validateStudentInput())
            return;



        Student student;



        student.studentId =
                generateStudentId();



        student.firstName =
                firstNameInput->text().trimmed();



        student.lastName =
                lastNameInput->text().trimmed();



        student.gender =
                genderInput->text().trimmed();



        student.dateOfBirth =
                dobInput->text().trimmed();



        student.className =
                classInput->currentText().trimmed();



        student.phone =
                phoneInput->text().trimmed();



        student.parentName =
                parentNameInput->text().trimmed();



        student.parentPhone =
                parentPhoneInput->text().trimmed();



        student.address =
                addressInput->text().trimmed();



        student.status =
                "ACTIVE";





        if(StudentRepository::createStudent(student))
        {

            QMessageBox::information(
                this,
                "Success",
                "Student registered successfully"
            );



            loadStudents();

            clearForm();


            /// notify other widgets that a new student has been registered
            emit studentRegistered();


        }
        else
        {

            QMessageBox::critical(
                this,
                "Error",
                "Failed to register student"
            );

        }


    });






    // ======================================================
    // SELECT STUDENT FROM TABLE
    // ======================================================


    connect(
        studentTable,
        &QTableWidget::cellClicked,
        this,
        [=](int row,int)
    {


        if(!studentTable->item(row,0))
            return;



        selectedStudentId =
                studentTable
                ->item(row,0)
                ->text()
                .toInt();



        qDebug()
            << "Selected student ID:"
            << selectedStudentId;


    });





    connect(
        clearBtn,
        &QPushButton::clicked,
        this,
        &StudentsWidget::clearForm
    );



}



// ======================================================
// VALIDATE INPUT
// ======================================================

bool StudentsWidget::validateStudentInput()
{


    if(firstNameInput->text().trimmed().isEmpty())
    {

        QMessageBox::warning(
            this,
            "Validation",
            "First name is required"
        );

        return false;

    }



    if(lastNameInput->text().trimmed().isEmpty())
    {

        QMessageBox::warning(
            this,
            "Validation",
            "Last name is required"
        );

        return false;

    }



    if(classInput->currentText().trimmed().isEmpty())
    {

        QMessageBox::warning(
            this,
            "Validation",
            "Class is required"
        );

        return false;

    }



    if(parentNameInput->text().trimmed().isEmpty())
    {

        QMessageBox::warning(
            this,
            "Validation",
            "Parent name is required"
        );

        return false;

    }



    return true;

}





// ======================================================
// LOAD ALL STUDENTS
// ======================================================


void StudentsWidget::loadStudents()
{


    studentsCache =
            StudentRepository::getAllStudents();



    studentTable->setRowCount(0);



    int row = 0;



    for(const Student &student : studentsCache)
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
                +" "
                +student.lastName
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


}




// ======================================================
// SHOW STUDENTS BY CLASS
// ======================================================


void StudentsWidget::showClassStudents(
        QString className
)
{


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
                +" "
                +student.lastName
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


}




// ======================================================
// CLEAR FORM
// ======================================================


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



// ======================================================
// GENERATE ID
// ======================================================


QString StudentsWidget::generateStudentId()
{

    int count =
            StudentRepository::getStudentCount()
            + 1;



    return QString(
        "FTS-%1-%2"
    )
    .arg(
        QDate::currentDate().year()
    )
    .arg(
        count,
        4,
        10,
        QChar('0')
    );

}
bool StudentsWidget::isValidClass(const QString &className)
{
    QStringList allowedClasses =
    {

     /// Nursery classes
     "Nursery 1", "Nursery 1 A", "Nursery 1 B",
     "Nursery 2", "Nursery 2 A", "Nursery 2 B",


      /// Primary school classes
      "Primary 1", "Primary 1 A", "Primary 1 B",
      "Primary 2", "Primary 2 A", "Primary 2 B",
      "Primary 3", "Primary 3 A", "Primary 3 B",
      "Primary 4", "Primary 4 A", "Primary 4 B",
      "Primary 5", "Primary 5 A", "Primary 5 B",
      "Primary 6", "Primary 6 A", "Primary 6 B",


        /// secondary school classes
        "Form 1", "Form 1 A", "Form 1 B",
        "Form 2", "Form 2 A", "Form 2 B",
        "Form 3", "Form 3 A", "Form 3 B",
        "Form 4", "Form 4 A", "Form 4 B",
        "Form 5", "Form 5 A", "Form 5 B",

        /// High school classes
        "Lower 6", "Lower 6 A", "Lower 6 B",
        "Upper 6", "Upper 6 A", "Upper 6 B"
    }; /// we can change based on countries. you can edit here.


    return allowedClasses.contains(className);
}