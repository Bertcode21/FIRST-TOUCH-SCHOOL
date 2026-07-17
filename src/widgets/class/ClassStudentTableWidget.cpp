#include "ClassStudentTableWidget.h"


#include "repositories/StudentRepository.h"


#include "models/Student.h"


#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>



ClassStudentTableWidget::ClassStudentTableWidget(
        QString className,
        QWidget *parent
    )
    : QWidget(parent),
      className(className)
{

    setupUI();

    loadStudents();

}



// Create table
void ClassStudentTableWidget::setupUI()
{

    QVBoxLayout *layout =
            new QVBoxLayout(this);



    table =
        new QTableWidget(
            this
        );



    table->setColumnCount(6);



    QStringList headers =
    {
        "ID",
        "Student ID",
        "Name",
        "Gender",
        "Parent",
        "Status"
    };



    table->setHorizontalHeaderLabels(
        headers
    );



    table->horizontalHeader()
         ->setStretchLastSection(true);



    table->setSelectionBehavior(
        QAbstractItemView::SelectRows
    );



    table->setEditTriggers(
        QAbstractItemView::NoEditTriggers
    );



    layout->addWidget(table);



    setLayout(layout);

}



// Load students from repository
void ClassStudentTableWidget::loadStudents()
{


    QList<Student> students =
            StudentRepository::getStudentsByClass(
                className
            );



    table->setRowCount(
        students.size()
    );



    int row = 0;



    for(const Student &student : students)
    {


        table->setItem(
            row,
            0,
            new QTableWidgetItem(
                QString::number(student.id)
            )
        );



        table->setItem(
            row,
            1,
            new QTableWidgetItem(
                student.studentId
            )
        );



        table->setItem(
            row,
            2,
            new QTableWidgetItem(
                student.firstName
                +
                " "
                +
                student.lastName
            )
        );



        table->setItem(
            row,
            3,
            new QTableWidgetItem(
                student.gender
            )
        );



        table->setItem(
            row,
            4,
            new QTableWidgetItem(
                student.parentName
            )
        );



        table->setItem(
            row,
            5,
            new QTableWidgetItem(
                student.status
            )
        );


        row++;

    }


}