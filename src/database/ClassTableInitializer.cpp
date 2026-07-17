#include "ClassTableInitializer.h"

#include "DatabaseManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


void ClassTableInitializer::initialize()
{

    QSqlQuery query(DatabaseManager::getDatabase());


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


    if(!query.exec(sql))
    {

        qDebug()
        << "Failed to create classes table:"
        << query.lastError().text();

    }

    else
    {

        qDebug()
        << "Classes table created or already exists.";

    }

}