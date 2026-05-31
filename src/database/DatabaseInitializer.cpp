#include "DatabaseInitializer.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void DatabaseInitializer::initialize()
{
    qDebug() << "Initializing database...";

    createUsersTable();

    qDebug() << "Database initialization completed.";
}

/// CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT NOT NULL, password TEXT NOT NULL);
void DatabaseInitializer::createUsersTable()
{
    QSqlQuery query;

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
        qDebug() << "Failed to create users table:"
                 << query.lastError().text();
    }
}