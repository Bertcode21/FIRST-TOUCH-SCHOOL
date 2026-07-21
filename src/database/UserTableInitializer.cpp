#include "UserTableInitializer.h"

#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


void UserTableInitializer::createTable()
{

    QSqlDatabase db = DatabaseManager::getDatabase();

    QSqlQuery query(db);


    QString sql =

        "CREATE TABLE IF NOT EXISTS users ("

        "id INTEGER PRIMARY KEY AUTOINCREMENT, "

        "full_name TEXT NOT NULL, "

        "username TEXT UNIQUE NOT NULL, "

        "password TEXT NOT NULL, "

        "role TEXT NOT NULL, "

        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP"

        ")";



    if(query.exec(sql))
    {

        qDebug()
            << "Users table created or already exists.";

    }
    else
    {

        qDebug()
            << "Failed to create users table:";

        qDebug()
            << query.lastError().text();

    }

}