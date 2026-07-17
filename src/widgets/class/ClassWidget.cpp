#include "ClassWidget.h"

#include "repositories/ClassRepository.h"
#include "ClassCardWidget.h"

#include <QVBoxLayout>
#include <QDebug>


ClassWidget::ClassWidget(QWidget *parent)
    : QWidget(parent)
{

    setupUI();

    loadClasses();

}



// Create page layout
void ClassWidget::setupUI()
{

    QVBoxLayout *mainLayout = new QVBoxLayout(this);


    container = new QWidget();


    classLayout = new QGridLayout(container);


    classLayout->setSpacing(20);


    scrollArea = new QScrollArea();


    scrollArea->setWidget(container);

    scrollArea->setWidgetResizable(true);



    mainLayout->addWidget(scrollArea);



    setLayout(mainLayout);

}



// Load classes from database
void ClassWidget::loadClasses()
{

    QList<Class> classes =
            ClassRepository::getAllClasses();



    int row = 0;

    int column = 0;


    const int columnsPerRow = 3;



    for(const Class &schoolClass : classes)
    {


        ClassCardWidget *card =
                new ClassCardWidget(
                    schoolClass,
                    this
                );



        connect(
            card,
            &ClassCardWidget::classClicked,
            this,
            [=](int classId)
            {

                qDebug()
                << "Selected class ID:"
                << classId;


                // Later:
                // open ClassDetailsWidget here

            }
        );



        classLayout->addWidget(
            card,
            row,
            column
        );



        column++;



        if(column >= columnsPerRow)
        {

            column = 0;

            row++;

        }

    }

}