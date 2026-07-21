#include "ClassCardWidget.h"

#include "repositories/StudentRepository.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>


ClassCardWidget::ClassCardWidget(
        Class schoolClass,
        QWidget *parent
    )
    : QWidget(parent),
      classData(schoolClass)
{

    qDebug()
        << "[CLASS CARD]"
        << "Creating card:"
        << classData.className
        << "ID:"
        << classData.id;


    setupUI();

    loadStatistics();

}



// ===============================
// CREATE CARD UI
// ===============================

void ClassCardWidget::setupUI()
{

    QVBoxLayout *layout =
            new QVBoxLayout(this);


    layout->setContentsMargins(
        15,
        15,
        15,
        15
    );

    layout->setSpacing(10);



    // CLASS NAME

    classNameLabel =
            new QLabel(
                classData.className,
                this
            );


    classNameLabel->setAlignment(
        Qt::AlignCenter
    );


    classNameLabel->setStyleSheet(
        "font-size:22px;"
        "font-weight:bold;"
        "color:#1E3A8A;"
    );



    // LEVEL

    levelLabel =
            new QLabel(
                "Level: " + classData.level,
                this
            );


    levelLabel->setAlignment(
        Qt::AlignCenter
    );



    // STUDENTS COUNT

    studentsLabel =
            new QLabel(
                "Students: 0",
                this
            );


    studentsLabel->setAlignment(
        Qt::AlignCenter
    );



    // TEACHER

    teacherLabel =
            new QLabel(
                "Teacher: Not Assigned",
                this
            );


    teacherLabel->setAlignment(
        Qt::AlignCenter
    );



    // BUTTON

    openButton =
            new QPushButton(
                "Open Class",
                this
            );



    layout->addWidget(classNameLabel);

    layout->addWidget(levelLabel);

    layout->addWidget(studentsLabel);

    layout->addWidget(teacherLabel);

    layout->addSpacing(10);

    layout->addWidget(openButton);



    setLayout(layout);



    setMinimumSize(
        240,
        200
    );



    setStyleSheet(

        "ClassCardWidget {"
        "background:white;"
        "border-radius:15px;"
        "border:1px solid #CBD5E1;"
        "}"


        "QLabel {"
        "color:#475569;"
        "font-size:14px;"
        "}"


        "QPushButton {"
        "background:#2563EB;"
        "color:white;"
        "font-weight:bold;"
        "padding:10px;"
        "border-radius:8px;"
        "}"


        "QPushButton:hover {"
        "background:#1D4ED8;"
        "}"

    );



    connect(
        openButton,
        &QPushButton::clicked,
        this,
        &ClassCardWidget::openClass
    );


}



// ===============================
// LOAD CARD STATISTICS
// ===============================

void ClassCardWidget::loadStatistics()
{

    qDebug()
        << "[CLASS CARD]"
        << "Loading statistics for:"
        << classData.className;



    int totalStudents =
            StudentRepository::countStudentsInClass(
                classData.className
            );



    qDebug()
        << "[CLASS CARD]"
        << "Students found:"
        << totalStudents;



    studentsLabel->setText(
        "Students: "
        +
        QString::number(totalStudents)
    );



}



// ===============================
// OPEN CLASS BUTTON
// ===============================

void ClassCardWidget::openClass()
{

    qDebug()
        << "[CLASS CARD]"
        << "Open clicked:"
        << classData.className
        << "ID:"
        << classData.id;



    emit classClicked(
        classData
    );

}