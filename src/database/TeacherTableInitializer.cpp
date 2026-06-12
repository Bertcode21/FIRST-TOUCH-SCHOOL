#include "TeacherTableInitializer.h"
#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void TeacherTableInitializer::createTable()
{
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query(db);

    QString sql =
        "CREATE TABLE IF NOT EXISTS teachers ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "teacher_id TEXT UNIQUE, "
        "first_name TEXT NOT NULL, "
        "last_name TEXT NOT NULL, "
        "gender TEXT, "
        "date_of_birth TEXT, "
        "subject TEXT, "
        "qualification TEXT, "
        "phone TEXT, "
        "email TEXT, "
        "address TEXT, "
        "status TEXT DEFAULT 'ACTIVE', "
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP"
        ")";

    if (query.exec(sql))
    {
        qDebug() << "Teachers table created or already exists.";
    }
    else
    {
        qDebug() << "Failed to create teachers table:";
        qDebug() << query.lastError().text();
    }
}