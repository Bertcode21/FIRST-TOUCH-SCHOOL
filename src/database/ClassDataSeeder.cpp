#include "ClassDataSeeder.h"

#include "DatabaseManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


void ClassDataSeeder::seed()
{

    qDebug()
        << "[CLASS SEEDER]"
        << "Checking default classes...";


    QSqlQuery check(
        DatabaseManager::getDatabase()
    );


    check.prepare(
        "SELECT COUNT(*) FROM classes"
    );


    if(!check.exec())
    {

        qCritical()
            << "[CLASS SEEDER ERROR]"
            << check.lastError().text();

        return;
    }


    check.next();


    int count =
        check.value(0).toInt();



    if(count > 0)
    {

        qDebug()
            << "[CLASS SEEDER]"
            << "Classes already exist:"
            << count;

        return;
    }




    QStringList classes =
    {

        "Nursery 1",
        "Nursery 2",

        "Primary 1",
        "Primary 2",
        "Primary 3",
        "Primary 4",
        "Primary 5",
        "Primary 6",

        "Form 1",
        "Form 2",
        "Form 3",
        "Form 4",
        "Form 5",

        "Lower Sixth",
        "Upper Sixth"

    };



    QSqlQuery query(
        DatabaseManager::getDatabase()
    );



    for(QString name : classes)
    {


        query.prepare(
            "INSERT INTO classes "
            "("
            "class_name,"
            "level,"
            "capacity,"
            "status"
            ") "
            "VALUES "
            "(?,?,?,?)"
        );



        query.addBindValue(name);


        query.addBindValue(
            name.contains("Primary")
                ? "Primary"
                :
            name.contains("Nursery")
                ? "Nursery"
                :
            "Secondary"
        );


        query.addBindValue(60);


        query.addBindValue(
            "ACTIVE"
        );



        if(!query.exec())
        {

            qWarning()
                << "[CLASS SEEDER]"
                << "Failed:"
                << name
                << query.lastError().text();

        }

        else
        {

            qDebug()
                << "[CLASS SEEDER]"
                << "Created:"
                << name;

        }

    }


    qDebug()
        << "[CLASS SEEDER]"
        << "Default classes created.";

}