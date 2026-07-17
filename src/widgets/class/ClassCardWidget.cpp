#include "ClassCardWidget.h"

#include "repositories/ClassRepository.h"
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

    setupUI();

    loadStatistics();

}



// Build card UI
void ClassCardWidget::setupUI()
{

    QVBoxLayout *layout =
            new QVBoxLayout(this);



    classNameLabel =
            new QLabel(
                classData.className,
                this
            );


    classNameLabel->setAlignment(
                Qt::AlignCenter
                );



    levelLabel =
            new QLabel(
                "Level: " + classData.level,
                this
            );



    studentsLabel =
            new QLabel(
                "Students: 0",
                this
            );



    teacherLabel =
            new QLabel(
                "Teacher: Not Assigned",
                this
            );



    openButton =
            new QPushButton(
                "Open Class",
                this
            );



    layout->addWidget(classNameLabel);

    layout->addWidget(levelLabel);

    layout->addWidget(studentsLabel);

    layout->addWidget(teacherLabel);

    layout->addWidget(openButton);



    setLayout(layout);



    setMinimumSize(
        220,
        180
    );



    setStyleSheet(
        "QWidget {"
        "background:white;"
        "border-radius:15px;"
        "border:1px solid #dddddd;"
        "}"
        
        "QLabel {"
        "font-size:14px;"
        "}"
        
        "QPushButton {"
        "background:#2563eb;"
        "color:white;"
        "padding:8px;"
        "border-radius:8px;"
        "}"
        
        "QPushButton:hover {"
        "background:#1d4ed8;"
        "}"
    );



    connect(
        openButton,
        &QPushButton::clicked,
        this,
        &ClassCardWidget::openClass
    );

}



// Load data needed for card
void ClassCardWidget::loadStatistics()
{

    int totalStudents =
        StudentRepository::countStudentsInClass(
            classData.className
        );


    studentsLabel->setText(
        "Students: "
        +
        QString::number(totalStudents)
    );

}



// Button clicked
void ClassCardWidget::openClass()
{

    emit classClicked(
        classData.id
    );


}