#include "DatabaseInitializer.h"
#include "DatabaseManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void DatabaseInitializer::initialize()
{
    qDebug() << "Initializing database...";

    // Verify database is open before creating tables
    if (!DatabaseManager::getDatabase().isOpen())
    {
        qDebug() << "Database is not open!";
        return;
    }

    createUsersTable();
    createStudentsTable();

    qDebug() << "Database initialization completed.";
}


///   Creates the users table if it does't exists/
void DatabaseInitializer::createUsersTable()
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

    if (query.exec(sql))
    {
        qDebug() << "Users table created or already exists.";
    }
    else
    {
        qDebug() << "Failed to create users table:";
        qDebug() << query.lastError().text();
    }
}

void DatabaseInitializer::createStudentsTable()
{
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query(db);

    QString sql =
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "student_id TEXT UNIQUE, "
        "first_name TEXT NOT NULL, "
        "last_name TEXT NOT NULL, "
        "gender TEXT, "
        "date_of_birth TEXT, "
        "class_name TEXT, "
        "phone TEXT, "
        "parent_name TEXT, "
        "parent_phone TEXT, "
        "address TEXT, "
        "status TEXT DEFAULT 'ACTIVE', "
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP"
        ")";

    if (!query.exec(sql))
    {
        qDebug() << "Failed to create students table:";
        qDebug() << query.lastError().text();
    }
    else
    {
        qDebug() << "Students table created or already exists.";
    }
}

