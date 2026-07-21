#include "StudentProfileWidget.h"


#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>



StudentProfileWidget::StudentProfileWidget(
        Student student,
        QWidget *parent
    )
    : QWidget(parent),
      studentData(student)
{

    setupUI();

    loadStudentInformation();

}




// ===============================
// CREATE UI
// ===============================

void StudentProfileWidget::setupUI()
{


    QVBoxLayout *mainLayout =
            new QVBoxLayout(this);



    QLabel *title =
            new QLabel(
                "Student Profile",
                this
            );


    title->setStyleSheet(
        "font-size:26px;"
        "font-weight:bold;"
        "color:#1E3A8A;"
    );



    mainLayout->addWidget(
        title
    );




    QFrame *card =
            new QFrame(this);



    card->setStyleSheet(

        "QFrame{"
        "background:white;"
        "border-radius:15px;"
        "border:1px solid #CBD5E1;"
        "padding:20px;"
        "}"

    );



    QVBoxLayout *cardLayout =
            new QVBoxLayout(card);



    nameLabel =
            new QLabel();



    studentIdLabel =
            new QLabel();



    genderLabel =
            new QLabel();



    dobLabel =
            new QLabel();



    classLabel =
            new QLabel();



    phoneLabel =
            new QLabel();



    parentNameLabel =
            new QLabel();



    parentPhoneLabel =
            new QLabel();



    addressLabel =
            new QLabel();



    statusLabel =
            new QLabel();




    cardLayout->addWidget(nameLabel);

    cardLayout->addWidget(studentIdLabel);

    cardLayout->addWidget(genderLabel);

    cardLayout->addWidget(dobLabel);

    cardLayout->addWidget(classLabel);

    cardLayout->addWidget(phoneLabel);

    cardLayout->addWidget(parentNameLabel);

    cardLayout->addWidget(parentPhoneLabel);

    cardLayout->addWidget(addressLabel);

    cardLayout->addWidget(statusLabel);




    mainLayout->addWidget(card);



    setLayout(mainLayout);



}



// ===============================
// LOAD STUDENT DATA
// ===============================

void StudentProfileWidget::loadStudentInformation()
{


    nameLabel->setText(
        "Name: "
        +
        studentData.firstName
        +
        " "
        +
        studentData.lastName
    );



    studentIdLabel->setText(
        "Student ID: "
        +
        studentData.studentId
    );



    genderLabel->setText(
        "Gender: "
        +
        studentData.gender
    );



    dobLabel->setText(
        "Date Of Birth: "
        +
        studentData.dateOfBirth
    );



    classLabel->setText(
        "Class: "
        +
        studentData.className
    );



    phoneLabel->setText(
        "Phone: "
        +
        studentData.phone
    );



    parentNameLabel->setText(
        "Parent Name: "
        +
        studentData.parentName
    );



    parentPhoneLabel->setText(
        "Parent Phone: "
        +
        studentData.parentPhone
    );



    addressLabel->setText(
        "Address: "
        +
        studentData.address
    );



    statusLabel->setText(
        "Status: "
        +
        studentData.status
    );

}