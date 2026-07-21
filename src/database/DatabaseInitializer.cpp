#include "DatabaseInitializer.h"

#include "DatabaseManager.h"

#include "UserTableInitializer.h"
#include "StudentTableInitializer.h"
#include "TeacherTableInitializer.h"
#include "FeesTableInitializer.h"
#include "ClassTableInitializer.h"
#include "ClassDataSeeder.h"


#include <QDebug>


void DatabaseInitializer::initialize()
{

    qDebug()
        << "Initializing database...";


    // Check database connection

    if(!DatabaseManager::getDatabase().isOpen())
    {
        qDebug()
            << "Database is not open!";

        return;
    }



    // Initialize all tables

    UserTableInitializer::createTable();


    StudentTableInitializer::createTable();


    TeacherTableInitializer::createTable();


    ClassTableInitializer::initialize();


    FeesTableInitializer::createTable();

    // Seed default data
    ClassDataSeeder::seed();



    qDebug()
        << "Database initialization completed.";

}