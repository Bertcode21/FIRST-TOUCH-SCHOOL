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

    qDebug() << "Database initialization completed.";
}

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