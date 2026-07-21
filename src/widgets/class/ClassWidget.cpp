#include "ClassWidget.h"

#include "ClassCardWidget.h"

#include "repositories/ClassRepository.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QLabel>


ClassWidget::ClassWidget(QWidget *parent)
    : QWidget(parent)
{

    qDebug()
        << "[CLASS WIDGET]"
        << "Initializing class widget";


    setupUI();

    loadClasses();

}



// ===============================
// SETUP UI
// ===============================

void ClassWidget::setupUI()
{

    QVBoxLayout *mainLayout =
            new QVBoxLayout(this);



    mainLayout->setContentsMargins(
        10,
        10,
        10,
        10
    );


    mainLayout->setSpacing(15);



    QLabel *title =
            new QLabel(
                "School Classes",
                this
            );


    title->setStyleSheet(
        "font-size:26px;"
        "font-weight:bold;"
        "color:#1E3A8A;"
    );


    mainLayout->addWidget(title);



    container =
            new QWidget(this);



    classLayout =
            new QGridLayout(container);



    classLayout->setSpacing(20);



    scrollArea =
            new QScrollArea(this);



    scrollArea->setWidget(
        container
    );


    scrollArea->setWidgetResizable(
        true
    );



    mainLayout->addWidget(
        scrollArea
    );



    setLayout(mainLayout);

}



// ===============================
// LOAD CLASSES FROM DATABASE
// ===============================

void ClassWidget::loadClasses()
{

    qDebug()
        << "[CLASS WIDGET]"
        << "Loading classes...";



    QList<Class> classes =
            ClassRepository::getAllClasses();



    qDebug()
        << "[CLASS WIDGET]"
        << "Classes received:"
        << classes.size();



    if(classes.isEmpty())
    {

        qDebug()
            << "[CLASS WIDGET ERROR]"
            << "No classes found in database";


        QLabel *empty =
                new QLabel(
                    "No classes available",
                    container
                );


        empty->setStyleSheet(
            "font-size:18px;"
            "color:#64748B;"
        );


        classLayout->addWidget(
            empty,
            0,
            0
        );


        return;
    }



    int row = 0;

    int column = 0;


    const int columnsPerRow = 3;



    for(const Class &schoolClass : classes)
    {


        qDebug()
            << "[CLASS WIDGET]"
            << "Creating card:"
            << schoolClass.className;



        ClassCardWidget *card =
                new ClassCardWidget(
                    schoolClass,
                    this
                );



        connect(
            card,
            &ClassCardWidget::classClicked,
            this,
            [=](Class selectedClass)
            {

                qDebug()
                    << "[CLASS WIDGET]"
                    << "Class selected:"
                    << selectedClass.className
                    << "ID:"
                    << selectedClass.id;



                emit openClassRequested(
                    selectedClass
                );

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



    qDebug()
        << "[CLASS WIDGET]"
        << "Finished loading cards.";

}