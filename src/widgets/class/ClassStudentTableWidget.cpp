#include "ClassStudentTableWidget.h"


#include "repositories/StudentRepository.h"


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




// ===============================
// CREATE TABLE UI
// ===============================

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



    // When a student row is clicked

    connect(
        table,
        &QTableWidget::cellClicked,
        this,
        &ClassStudentTableWidget::onStudentClicked
    );


}



// ===============================
// LOAD STUDENTS
// ===============================

void ClassStudentTableWidget::loadStudents()
{


    studentsList =
        StudentRepository::getStudentsByClass(
            className
        );



    qDebug()

        << "[CLASS STUDENT TABLE]"

        << "Class:"
        << className

        << "Students:"
        << studentsList.size();



    table->setRowCount(
        studentsList.size()
    );



    int row = 0;



    for(const Student &student : studentsList)
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



// ===============================
// STUDENT CLICKED
// ===============================

void ClassStudentTableWidget::onStudentClicked(
        int row,
        int column
)
{

    Q_UNUSED(column);



    if(row < 0 ||
       row >= studentsList.size())
    {
        return;
    }



    Student student =
        studentsList.at(row);



    qDebug()

        << "[CLASS STUDENT TABLE]"

        << "Selected student:"
        << student.firstName
        << student.lastName;



    emit studentSelected(
        student
    );


}