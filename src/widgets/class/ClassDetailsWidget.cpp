#include "ClassDetailsWidget.h"


#include "ClassStudentTableWidget.h"
#include "ClassActionBarWidget.h"
#include "../students/StudentProfileWidget.h"

#include "repositories/ClassRepository.h"


#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>



ClassDetailsWidget::ClassDetailsWidget(
        Class schoolClass,
        QWidget *parent
    )
    : QWidget(parent),
      classData(schoolClass)
{

    setupUI();

    loadClassInformation();

}



// Create UI
void ClassDetailsWidget::setupUI()
{

    QVBoxLayout *mainLayout =
            new QVBoxLayout(this);



    /*
        Header information
    */


    classNameLabel =
            new QLabel(this);


    classNameLabel->setStyleSheet(
        "font-size:24px;"
        "font-weight:bold;"
    );



    levelLabel =
            new QLabel(this);



    studentCountLabel =
            new QLabel(this);



    teacherLabel =
            new QLabel(this);



    mainLayout->addWidget(
        classNameLabel
    );


    mainLayout->addWidget(
        levelLabel
    );


    mainLayout->addWidget(
        studentCountLabel
    );


    mainLayout->addWidget(
        teacherLabel
    );



    /*
        Action buttons
    */


    actionBar =
        new ClassActionBarWidget(
            this
        );


    mainLayout->addWidget(
        actionBar
    );



    /*
        Student table
    */


    studentTable =
        new ClassStudentTableWidget(
            classData.className,
            this
        );


    mainLayout->addWidget(
        studentTable
    );
  connect(
    studentTable,
    &ClassStudentTableWidget::studentSelected,
    this,
    [=](Student student)
    {
        qDebug()
            << "[CLASS DETAILS]"
            << "Opening profile for:"
            << student.firstName
            << student.lastName;

        StudentProfileWidget *profile =
            new StudentProfileWidget(student);

        profile->setAttribute(
            Qt::WA_DeleteOnClose
        );

        profile->resize(700, 600);

        profile->show();
    }
);


    setLayout(mainLayout);

}



// Load class data
void ClassDetailsWidget::loadClassInformation()
{

    classNameLabel->setText(
        classData.className
    );


    levelLabel->setText(
        "Level: "
        +
        classData.level
    );



    int count =
        ClassRepository::getStudentCount(
            classData.className
        );



    studentCountLabel->setText(
        "Students: "
        +
        QString::number(count)
    );



    teacherLabel->setText(
        "Teacher ID: "
        +
        QString::number(
            classData.classTeacherId
        )
    );


}