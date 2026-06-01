#include "StudentTableInitializer.h"
#include "database/DatabaseManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void StudentTableInitializer::createTable()
{
    QSqlQuery query(DatabaseManager::getDatabase());

    QString sql =
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "student_id TEXT UNIQUE,"
        "first_name TEXT,"
        "last_name TEXT,"
        "gender TEXT,"
        "dob TEXT,"
        "class_name TEXT,"
        "phone TEXT,"
        "parent_name TEXT,"
        "parent_phone TEXT,"
        "address TEXT,"
        "status TEXT DEFAULT 'ACTIVE'"
        ")";

    if (!query.exec(sql))
    {
        qDebug() << "Student table error:"
                 << query.lastError().text();
    }
    else
    {
        qDebug() << "Students table ready";
    }
}