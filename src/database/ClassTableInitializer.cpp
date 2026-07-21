#include "ClassTableInitializer.h"

#include "DatabaseManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


void ClassTableInitializer::initialize()
{
    qDebug()
        << "[CLASS TABLE]"
        << "Initializing classes table...";


    QSqlDatabase db =
            DatabaseManager::getDatabase();


    if(!db.isOpen())
    {
        qCritical()
            << "[CLASS TABLE ERROR]"
            << "Database is not open";

        return;
    }


    QSqlQuery query(db);


    QString sql = R"(

        CREATE TABLE IF NOT EXISTS classes
        (

            id INTEGER PRIMARY KEY AUTOINCREMENT,

            class_name TEXT UNIQUE NOT NULL,

            level TEXT NOT NULL,

            class_teacher_id INTEGER,

            capacity INTEGER DEFAULT 60,

            academic_year TEXT,

            status TEXT DEFAULT 'ACTIVE',

            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,


            FOREIGN KEY(class_teacher_id)
            REFERENCES teachers(id)

        )

    )";


    qDebug()
        << "[CLASS TABLE]"
        << "Executing create table query";


    if(!query.exec(sql))
    {

        qCritical()
            << "[CLASS TABLE ERROR]"
            << query.lastError().text();

    }
    else
    {

        qDebug()
            << "[CLASS TABLE]"
            << "Classes table ready.";

    }
}